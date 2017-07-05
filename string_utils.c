#include "string_utils.h"

#ifdef USE_stringLength
unsigned char stringLength(const char *s)
{
  register unsigned char result = 0;
  const char *c = s;

  while (*c != '\0')
  {
    ++result;
    ++c;
  }

  return result;
}
#endif

#ifdef USE_compareStrings
bool compareStrings(const char *s1, const char *s2)
{
  const char *c1 = s1, *c2 = s2;

  do
  {
    if ((*c1 == '\0') && (*c2 == '\0'))
      return 1;

    if (*c1 != *c2)
      return 0;

    c1++, c2++;
  } while (!((*c1 == '\0') ^ (*c2 == '\0')));

  return 0;
}
#endif

#ifdef USE_compareSubstrings
bool compareSubstrings(const char *s1, const char *s2, unsigned char n)
{
  register unsigned char i;
  const char *c1, *c2;

  i = 0;
  c1 = s1;
  c2 = s2;

  do
  {
    if ((*c1 == '\0') && (*c2 == '\0'))
      return 1;

    if (*c1 != *c2)
      return 0;

    c1++, c2++;
    i++;

    if (i >= n)
      return 1;
  } while ( (!((*c1 == '\0') ^ (*c2 == '\0'))) );

  return 0;
}
#endif
