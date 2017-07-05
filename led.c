/* SFR and other definitions for (89C)52 */
#ifdef SDCC
#include <mcs51/at89x52.h>
#else
#include <regx52.h>
#endif

/* String & string-int conversion functions */
#include "string_utils.h"
#include "conv_utils.h"


/* Serial receiver variables */
#define RI_BUFFER_SIZE 25
__idata char RI_BUFFER[RI_BUFFER_SIZE];
__data unsigned char RI_LEN = 0;
__bit RI_LINE = 0;

/* Serial transmitter variables */
const char* TI_DATA = 0;
__bit TI_BUSY = 0;


/* Events associated with T0 interrupt */
enum T0Event
{
  T0_OTHER = 0,/* Other event */
  T0_OVERFLOW, /* Receive buffer overflow */
  T0_ENTER     /* Return (enter) pressed */
};
/* The event */
__data unsigned char T0_EVENT = T0_OTHER;


/* Latch controls */
#define LATCH_OE P3_4
#define LATCH_LE P3_5

/* LED status in display mode */
__data unsigned char DISPLAY_TABLE[8];

/* Display time delay data */
#define DELAY_COUNT 10


/* Initialization */
void init(void)
{
  register unsigned char i;

  /* Initial values for control lines */
  P1 = 0x0;
  LATCH_LE = 0;
  LATCH_OE = 1;

  /* Initial LED states - all on */
  for (i = 0; i < 8; i++)
    DISPLAY_TABLE[i] = 0xFF;

  /* Serial: mode 1, enable receiver */
  SCON = 0x50;

  /* T2: baudrate: 9600 baud/s at 11.0592 MHz */
  RCAP2H = 0xFF;
  RCAP2L = 0xDC;

  /* T2: serial TX & RX */
  T2CON = 0x34;

  /* Enable serial and T0, T1 interrupts */
  IE = 0x9A;

  /* Serial higher, T0, T1 lower */
  IP = 0x10;

  /* T1 mode 2 (auto-reload) for 0.1 ms */
  TMOD = 0x21;
  TH1 = TL1 = (~100) + 1;
  TR1 = 1;
}

/* Serial interrupt handler */
void serialInterrupt(void) __interrupt 4 __using 1
{
  register char c;

  /* Transmitter event */
  if (TI)
  {
    TI = 0;

    TI_BUSY = 1;

    if (*TI_DATA == '\0')
    {
      TI_BUSY = 0;
      return;
    }

    SBUF = *TI_DATA;
    ++TI_DATA;
  }
  /* Receiver event */
  else
  {
    RI = 0;

    /* Ignore input when processing line or transmitting data */
    if (RI_LINE || TI_BUSY)
      return;

    c = SBUF;

    /* Enter */
    if (c == '\r')
    {
      T0_EVENT = T0_ENTER;
      TF0 = 1;
      return;
    }

    if (RI_LEN >= RI_BUFFER_SIZE - 2)
    {
      T0_EVENT = T0_OVERFLOW;
      TF0 = 1;
      return;
    }

    /* Only printable chars */
    if ((c > 0x1F) && (c < 0x7F))
    {
      RI_BUFFER[RI_LEN] = c;
      ++RI_LEN;
    }
    /* Other chars ignored */
  }
}

/* T0 interrupt handler */
#ifdef SDCC
#pragma save
#pragma nogcse
#endif
void timer0Interrupt(void) __interrupt 1 __using 1
{
  const char *error = "E";

  switch (T0_EVENT)
  {
    case T0_OVERFLOW:
    {
      T0_EVENT = T0_OTHER;

      /* Clear line */
      RI_LEN = 0;
      RI_BUFFER[RI_LEN] = '\0';
      RI_LINE = 1;

      /* Send error message */
      TI_DATA = error;
      TI_BUSY = 1;
      TI = 1;
      while (TI_BUSY) ;

      break;
    }
    case T0_ENTER:
    {
      T0_EVENT = T0_OTHER;

      /* Null-terminate line and indicate line availability */
      RI_BUFFER[RI_LEN] = '\0';
      RI_LEN = 0;
      RI_LINE = 1;

      break;
    }
  }
  T0_EVENT = T0_OTHER;
}
#ifdef SDCC
#pragma restore
#endif

/* T1 interrupt handler */
void timer1Interrupt(void) __interrupt 3 __using 2
{
  static unsigned char count = DELAY_COUNT;
  static unsigned char layer = 0;

  --count;
  if (count == 0)
  {
    /* Initial state - disable control latch input & output */
    LATCH_LE = 0;
    LATCH_OE = 1;

    /* Enable data latch #1 LE through writing to control latch (layers disabled) */
    P1 = 0x1F;
    LATCH_LE = 1;
    LATCH_LE = 0;

    /* Write to data latch #1 (toggle OE = toggle LE of data latch #1) */
    P1 = DISPLAY_TABLE[2 * layer];
    LATCH_OE = 0;
    LATCH_OE = 1;

    /* Enable data latch #2 LE through writing to control latch (layers disabled) */
    P1 = 0x2F;
    LATCH_LE = 1;
    LATCH_LE = 0;

    /* Write to data latch #2 (toggle OE = toggle LE of data latch #2) */
    P1 = DISPLAY_TABLE[2 * layer + 1];
    LATCH_OE = 0;
    LATCH_OE = 1;

    /* Write layer encoding to control latch */
    P1 = (~(1 << layer)) & 0x0F;
    LATCH_LE = 1;
    LATCH_LE = 0;

    /* Enable control latch output = display layer */
    LATCH_OE = 0;

    ++layer;
    if (layer > 3)
      layer = 0;

    count = DELAY_COUNT;
  }
}

/* Transmits a string through serial port */
/* Disable GCSE for this code */
#ifdef SDCC
#pragma save
#pragma nogcse
#endif
void sendString(const char *string)
{
  while (TI_BUSY) ;

  TI_DATA = string;
  TI_BUSY = 1;
  TI = 1;
}
#ifdef SDCC
#pragma restore
#endif

/* Main */
void main(void)
{
  register unsigned char i;
  unsigned char lineLength;
  unsigned char x, y, z;
  unsigned char *byte;
  unsigned char mask;
  unsigned int delay;

  init();

  for (;;)
  {
    if (RI_LINE)
    {
      RI_LINE = 0;

      lineLength = stringLength(RI_BUFFER);

      if (lineLength == 0)
        continue;

      /* Write all layers */
      if (compareSubstrings(RI_BUFFER, "W", 1))
      {
        if (stringLength(RI_BUFFER) != 17)
        {
          sendString("E");
          break;
        }

        for (i = 0; i < 8; ++i)
        {
          if (!stringToHex(&RI_BUFFER[2*i + 1], &DISPLAY_TABLE[i]))
          {
            sendString("E");
            break;
          }
        }

        if (i == 8)
          sendString("A");
      }
      /* Clear all LEDs */
      else if (compareStrings(RI_BUFFER, "R"))
      {
        for (i = 0; i < 8; ++i)
          DISPLAY_TABLE[i] = 0x00;

        sendString("A");
      }
      /* Write single layer */
      else if (compareSubstrings(RI_BUFFER, "L", 1))
      {
        if (stringLength(RI_BUFFER) != 6)
        {
          sendString("E");
          break;
        }

        i = RI_BUFFER[1] - '1';
        if (i > 3)
        {
          sendString("E");
          break;
        }

        if (!stringToHex(&RI_BUFFER[2], &DISPLAY_TABLE[2*i]))
        {
          sendString("E");
          break;
        }

        if (!stringToHex(&RI_BUFFER[4], &DISPLAY_TABLE[2*i+1]))
        {
          sendString("E");
          break;
        }

        sendString("A");
      }
      /* Set/clear/flip single LED */
      else if ((compareSubstrings(RI_BUFFER, "S", 1)) ||
                (compareSubstrings(RI_BUFFER, "C", 1)) ||
                (compareSubstrings(RI_BUFFER, "F", 1)))
      {
        if (stringLength(RI_BUFFER) != 4)
        {
          sendString("E");
          break;
        }

        x = RI_BUFFER[1] - '1';
        y = RI_BUFFER[2] - '1';
        z = RI_BUFFER[3] - '1';
        if ((x > 3) || (y > 3) || (z > 3))
        {
          sendString("E");
          break;
        }

        if (y > 2)
          byte = &DISPLAY_TABLE[2 * z + 1];
        else
          byte = &DISPLAY_TABLE[2 * z];

        if ((y == 1) || (y == 3))
          mask = 0x10 << x;
        else
          mask = 0x01 << x;

        if (RI_BUFFER[0] == 'S')
          *byte = (*byte) | mask;

        else if (RI_BUFFER[0] == 'C')
          *byte = (*byte) & (~mask);

        else
          *byte = ((*byte) & (~mask)) | ((~(*byte)) & mask);

        sendString("A");
      }
      /* Self-test */
      else if (compareStrings(RI_BUFFER, "T"))
      {
        #define TEST_DELAY 30000

        for (i = 0; i < 8; ++i)
          DISPLAY_TABLE[i] = 0x00;

        for (i = 0; i < 64; ++i)
        {
          DISPLAY_TABLE[i/8] |= 1 << (i % 8);

          for (delay = 0; delay < TEST_DELAY; ++delay) ;

          DISPLAY_TABLE[i/8] &= ~(1 << (i % 8));
        }

        for (i = 0; i < 4; ++i)
        {
          DISPLAY_TABLE[2*i] = 0xFF;
          DISPLAY_TABLE[2*i+1] = 0xFF;

          for (delay = 0; delay < TEST_DELAY; ++delay) ;

          DISPLAY_TABLE[2*i] = 0x00;
          DISPLAY_TABLE[2*i+1] = 0x00;
        }

        sendString("A");
      }
      /* Other message - error */
      else
      {
        sendString("E");
      }
    }
  }
}
