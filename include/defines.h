/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef  DEFINES_H

#ifdef   DEBUG_ALLOC
#define   ALLOC(n)       \
      ({ \
        void* ret = malloc(n); \
        printf( "MEMDEBUG ALLOC: " __FILE__ ":%d  %p size:%d\n", __LINE__, ret, (n) ); \
        ret;  \
      })

#define   REALLOC(p,s)    \
     ({ \
        void* ret = realloc( p, s ); \
        printf( "MEMDEBUG REALLOC: " __FILE__ ":%d  %p = %p size:%d\n", __LINE__, p, ret, s ); \
        ret;  \
      })
#define   FREE(p) ({ \
        printf( "MEMDEBUG FREE: " __FILE__ ":%d  %p\n",__LINE__,  p ); \
        free(p); })

#define  STRDUP(s)  (\
      { \
        char* ret = strdup(s);\
        printf( "MEMDEBUG STRDUP: " __FILE__ ":%d   %p <<  %p len:%d\n",__LINE__ , ret, s, strlen(s) ); \
        ret;  \
      })

#define  STRNDUP(s,n)  (\
      { \
        char* ret = strndup(s,n); \
        printf( "MEMDEBUG STRNDUP: " __FILE__ ":%d   %p size:%d\n", __LINE__, ret, n ); \
        ret;  \
      })

#else
#define   ALLOC(n)       malloc(n)
#define   REALLOC(p,s)   realloc(p,s)
#define   FREE(p)        free(p)
#define   STRDUP(s)      strdup(s)
#define   STRNDUP(s,n)   strndup(s,n)
#endif


#endif
