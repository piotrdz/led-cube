#ifndef CONV_UTILS_H
#define CONV_UTILS_H

#ifndef bool
#define bool unsigned char
#endif

/* String-number conversion utilities */

/* ---- Value  ->  String / Char ---- */

#if defined(USE_hexDigitToChar)  || \
    defined(USE_hexToString)     || \
    defined(USE_decToString)     || \
    defined(USE_longHexToString) || \
    defined(USE_longDecToString)
/* Converts value 0-15 to ASCII hex character 0-9, A-F */
char hexDigitToChar(unsigned char value);
#endif

#ifdef USE_hexToString
/* Converts value 0 -- 255 to 2-digit ASCII hex string (leading chars zeroed) */
void hexToString(unsigned char value, char *string);
#endif

#ifdef USE_longHexToString
/* Converts value 0 -- 2^32-1 to 4-digit ASCII hex string (leading chars zeroed) */
void longHexToString(unsigned long value, char *string);
#endif

#ifdef USE_decToString
/* Converts value 0 -- 255 to 1- to 3-digit ASCII dec string (trailing chars nullified) */
void decToString(unsigned char value, char *string);
#endif

#ifdef USE_longDecToString
/* Converts value 0 -- 2^32-1 to 1- to 9-digit ASCII dec string (trailing chars nullified) */
void longDecToString(unsigned long value, char *string);
#endif

/* ---- String / Char  ->  Value ---- */

#if defined(USE_charToHexDigit)  || \
    defined(USE_stringToHex)     || \
    defined(USE_stringToDec)     || \
    defined(USE_stringToLongHex) || \
    defined(USE_stringToLongDec)
/* Converts ASCII hex character: 0-9, a-f, A-F to value 0-15, 0xFF on error */
unsigned char charToHexDigit(char c, unsigned char *value);
#endif

#ifdef USE_stringToHex
/* Converts 2-character ASCII hex string to value 0 -- 255, 1 on success, 0 on failure */
bool stringToHex(const char *string, unsigned char *value);
#endif

#ifdef USE_stringToLongHex
/* Converts 4-character ASCII hex string to value 0 -- 2^32-1, 1 on success, 0 on failure */
bool stringToLongHex(const char *string, unsigned int *value);
#endif

#ifdef USE_stringToDec
/* Converts 1- to 3-character ASCII dec string to value 0 -- 255, 1 on success, 0 on failure */
bool stringToDec(const char *string, unsigned char *value);
#endif

#ifdef USE_stringToLongDec
/* Converts 1- to 9-character ASCII dec string to value 0 -- 2^32-1, 1 on success, 0 on failure */
bool stringToLongDec(const char *string, unsigned int *value);
#endif

#endif // CONV_UTILS_H
