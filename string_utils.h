#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#ifndef bool
#define bool unsigned char
#endif

/* String utilities replacing stdlib functions */

/* Returns the length of string */
#ifdef USE_stringLength
unsigned char stringLength(const char *s);
#endif

#ifdef USE_compareStrings
/* Compares two strings: returns 1 on equal, 0 on not equal */
bool compareStrings(const char *s1, const char *s2);
#endif

#ifdef USE_compareSubstrings
/* Compares two substrings: returns 1 on equal, 0 on not equal */
bool compareSubstrings(const char *s1, const char *s2, unsigned char n);
#endif

#endif // STRING_UTILS_H
