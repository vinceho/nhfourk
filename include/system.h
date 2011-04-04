/*	SCCS Id: @(#)system.h	3.4	2001/12/07	*/
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef SYSTEM_H
#define SYSTEM_H

#if !defined(__cplusplus)

#include <sys/types.h>

#endif /* !__cplusplus */

/* You may want to change this to fit your system, as this is almost
 * impossible to get right automatically.
 * This is the type of signal handling functions.
 */
#if (defined(_MSC_VER) || defined(WIN32))
# define SIG_RET_TYPE void (__cdecl *)(int)
#endif

#ifndef SIG_RET_TYPE
# define SIG_RET_TYPE void (*)()
#endif

#if !defined(__cplusplus)

#if defined(BSD) || defined(RANDOM)
# ifdef random
# undef random
# endif
# if !defined(LINUX)
extern  long random(void);
# endif
# if (!defined(bsdi) && !defined(__FreeBSD__)) || defined(RANDOM)
extern void srandom(unsigned int);
# else
#  if !defined(bsdi) && !defined(__FreeBSD__)
extern int srandom(unsigned int);
#  endif
# endif
#else
extern long lrand48(void);
extern void srand48(long);
#endif /* BSD || RANDOM */

#if !defined(BSD)
/* real BSD wants all these to return int */
extern void exit(int);
extern void free(void *);
extern void perror(const char *);
#endif
extern void qsort(void *,size_t,size_t,int(*)(const void *,const void *));

#if !defined(__GNUC__)
/* may already be defined */

# ifndef bsdi
extern long lseek(int,long,int);
# endif
# ifndef bsdi
extern int write(int, const void *,unsigned);
# endif

extern int unlink(const char *);

#endif /* !__GNUC__ */

/* The POSIX string.h is required to define all the mem* and str* functions */
#include <string.h>

#if defined(SYSV)
extern unsigned sleep(unsigned);
#endif

extern char *getenv(const char *);
extern char *getlogin(void);
extern pid_t getpid(void);
extern uid_t getuid(void);
extern gid_t getgid(void);

/*# string(s).h #*/

# if !defined(SVR4)
extern int vsprintf(char *, const char *, va_list);
extern int vfprintf(FILE *, const char *, va_list);
extern int vprintf(const char *, va_list);
# endif


extern int tgetent(char *,const char *);
extern void tputs(const char *,int,int (*)(void));
extern int tgetnum(const char *);
extern int tgetflag(const char *);
extern char *tgetstr(const char *,char **);
extern char *tgoto(const char *,int,int);

/* time functions */

extern struct tm *localtime(const time_t *);

extern time_t time(time_t *);

#endif /*  !__cplusplus */

#endif /* SYSTEM_H */
