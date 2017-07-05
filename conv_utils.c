#include "conv_utils.h"

#if defined(USE_hexDigitToChar)  || \
    defined(USE_hexToString)     || \
    defined(USE_decToString)     || \
    defined(USE_longHexToString) || \
    defined(USE_longDecToString)
char hexDigitToChar(unsigned char value)
{
  if (value < 10)
    return '0' + value;

  else if (value < 16)
    return 'A' + value - 10;

  return '!';
}
#endif

#ifdef USE_hexToString
void hexToString(unsigned char value, char *string)
{
  string[0] = hexDigitToChar(value >> 4);
  string[1] = hexDigitToChar(value & 0x0F);
}
#endif

#ifdef USE_longHexToString
void longHexToString(unsigned long value, char *string)
{
  string[0] = hexDigitToChar((value >> 12) & 0xFF);
  string[1] = hexDigitToChar( (value >> 8) & 0x0F);
  string[2] = hexDigitToChar( (value >> 4) & 0x0F);
  string[3] = hexDigitToChar(  value       & 0x0F);
}
#endif

#ifdef USE_decToString
void decToString(unsigned char value, char *string)
{
  if (value < 10)
  {
    string[0] = hexDigitToChar(value);
    string[1] = string[2] = '\0';
  }
  else if (value < 100)
  {
    string[1] = hexDigitToChar(value % 10);
    value /= 10;
    string[0] = hexDigitToChar(value);
    string[2] = '\0';
  }
  else
  {
    string[2] = hexDigitToChar(value % 10);
    value /= 10;
    string[1] = hexDigitToChar(value % 10);
    value /= 10;
    string[0] = hexDigitToChar(value);
  }
}
#endif

#ifdef USE_longDecToString
void longDecToString(unsigned long value, char *string)
{
  char tmp[10];
  unsigned char i, j;

  if (value == 0)
  {
    string[0] = '0';
    string[1] = '\0';
    return;
  }

  i = 0;
  while (value > 0)
  {
    tmp[i] = hexDigitToChar(value % 10);
    value /= 10;
    ++i;
  }

  for (j = 0; j < i; ++j)
    string[j] = tmp[i-j-1];
  string[i] = '\0';
}
#endif

#if defined(USE_charToHexDigit)  || \
    defined(USE_stringToHex)     || \
    defined(USE_stringToDec)     || \
    defined(USE_stringToLongHex) || \
    defined(USE_stringToLongDec)
unsigned char charToHexDigit(char c, unsigned char *value)
{
  if ((c >= '0') && (c <= '9'))
    *value = c - '0';

  else if ((c >= 'a') && (c <= 'f'))
    *value = 10 + c - 'a';

  else if ((c >= 'A') && (c <= 'F'))
    *value = 10 + c - 'A';

  else
    return 0;

  return 1;
}
#endif

#ifdef USE_stringToHex
bool stringToHex(const char *string, unsigned char *value)
{
  unsigned char v;

  if (!charToHexDigit(string[0], &v))
    return 0;

  *value = (v << 4);

  if (!charToHexDigit(string[1], &v))
    return 0;

  *value += v;

  return 1;
}
#endif

#ifdef USE_stringToLongHex
bool stringToLongHex(const char *string, unsigned int *value)
{
  unsigned char v;

  if (!charToHexDigit(string[0], &v))
    return 0;

  *value = (v << 12);

  if (!charToHexDigit(string[1], &v))
    return 0;

  *value += (v << 8);

  if (!charToHexDigit(string[2], &v))
    return 0;

  *value += (v << 4);

  if (!charToHexDigit(string[3], &v))
    return 0;

  *value += v;

  return 1;
}
#endif

#ifdef USE_stringToDec
bool stringToDec(const char *string, unsigned char *value)
{
  unsigned char d3 = 0, d2 = 0, d1 = 0;

  if ((!charToHexDigit(string[0], &d3)) || (d3 > 9))
    return 0;

  if ((string[1] != '\0') && (string[1] != ' '))
  {
    d2 = d3;

    if ((!charToHexDigit(string[1], &d3)) || (d3 > 9))
      return 0;

    if ((string[2] != '\0') && (string[2] != ' '))
    {
      d1 = d2;
      d2 = d3;

      if ((!charToHexDigit(string[2], &d3)) || (d3 > 9))
        return 0;
    }
  }

  if ((d1 > 2) || ((d1 == 2) && (d2 > 5)) || ((d1 == 2) && (d2 == 5) && (d3 > 5)))
    return 0;

  *value = 100 * d1 + 10 * d2 + d3;

  return 1;
}
#endif

#ifdef USE_stringToLongDec
bool stringToLongDec(const char *string, unsigned int *value)
{
  unsigned char d;
  char i;

  *value = 0;

  for (i = 0; i < 9; ++i)
  {
    if ((i > 0) && ((string[i] == '\0') || (string[2] == ' ')))
      break;

    if ((!charToHexDigit(string[0], &d)) || (d > 9))
      return 0;

    *value = (*value) * 10 + d;
  }

  return 1;
}
#endif
