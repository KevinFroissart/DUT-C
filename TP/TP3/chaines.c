#include <stdio.h>

int mon_strlen(char s[])
{
  int i = 0;
  while(s[i] != '\0') {
    i++;
  }
  return i;
}

int mon_strlen2(const char *s)
{
  int i = 0;
  while (*s != '\0') {
    i++;
    s++;
  }
  return i;
}

int mon_strcmp(const char * s1, const char * s2)
{
  while (*s1 != '\0' && *s2 != '\0') {
    if (*s1 == *s2) {
      s1++;
      s2++;
    } else if (*s1 > *s2) {
      return 1;
    } else if (*s1 < *s2) {
      return -1;
    }
  }
  return 0;
}

int mon_strncmp(const char * s1, const char * s2, int n)
{
  int i = 0;
  while (*s1 != '\0' && *s2 != '\0' && i <= n) {
    if (*s1 == *s2) {
      s1++;
      s2++;
      i++;
    } else if (*s1 > *s2) {
      return 1;
    } else if (*s1 < *s2) {
      return -1;
    }
  }
  return 0;
}

char *mon_strcat(char *s1, const char *s2)
{
int i = 0, j = mon_strlen(s1);
while (s2[i] != '\0'){
s1[j + i]= s2[i];
i++;
}
s1[j + i]= '\0';
return s1;
}

char *mon_strchr(char *s, int c)
{
  while (*s != '\0') {
    if(*s != c) {
      s++;
} else {
return s;
}
  }
return (NULL);
}

char *mon_strstr(const char *haystack, const char *needle)
{
int i;
i = 0;
if (!needle)
  return ((char*)haystack);
while (haystack[i] != '\0')
  {
if (mon_strncmp(&haystack[i], needle, mon_strlen2(needle)) == 0)
  return ((char*)&haystack[i]);
i++;
}
return (NULL);  
}
