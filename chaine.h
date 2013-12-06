#include <stdio.h>

#ifdef STRLEN_PTR
int mon_strlen(const char *s);
#else
int mon_strlen(const char s[]);
#endif
int mon_strcmp(const char * s1, const char * s2);
int mon_strncmp(const char * s1, const char * s2, int n);
char *mon_strcat( char *s1, const char *s2);
char *mon_strchr(const char *s, int c);
char *mon_strstr(const char *haystack,const char *needle);
