#ifndef UTIL_H
#define UTIL_H

#include <string.h>

#include "config.h"

typedef struct {
    int start; /* Byte at which the match starts */
    int end; /* and where it ends */
} match;

typedef struct {
    long total_bytes;
    long total_files;
    long total_matches;
    struct timeval time_start;
    struct timeval time_end;
} ag_stats;

void generate_skip_lookup(const char *find, size_t f_len, size_t skip_lookup[], int case_sensitive);
char* boyer_moore_strnstr(const char *s, const char *find, const size_t s_len, const size_t f_len, const size_t skip_lookup[]);
char* boyer_moore_strncasestr(const char *s, const char *find, const size_t s_len, const size_t f_len, const size_t skip_lookup[]);

int invert_matches(match matches[], int matches_len, const int buf_len);

int is_binary(const void* buf, const int buf_len);
int is_regex(const char* query);
int is_fnmatch(const char* filename);
int binary_search(const char* needle, char **haystack, int start, int end);

#ifndef HAVE_STRLCAT
size_t strlcat(char *dest, const char *src, size_t size);
#endif
#ifndef HAVE_STRLCPY
size_t strlcpy(char *dest, const char *src, size_t size);
#endif
#ifndef HAVE_GETLINE
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif
#ifndef HAVE_STRNDUP
char * strndup (const char *s, size_t n);
#endif

#if defined __NetBSD__ || defined __OpenBSD__ || defined __FreeBSD__ || defined __bsdi__ || defined __DragonFly__ || defined BSD || defined _SYSTYPE_BSD || defined __APPLE__
#define AG_OS_BSD
#endif

#endif
