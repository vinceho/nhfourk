/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/* NetHack may be freely redistributed.  See license for details. */


/* since this file is also used in auxiliary programs, don't include all the
 * function declarations for all of nethack
 */
#define EXTERN_H	/* comment line for pre-compiled headers */
#include "config.h"

char *fmt_ptr(const void *,char *);
long *alloc(unsigned int);
extern void panic(const char *,...);


long *alloc(unsigned int lth)
{
	void * ptr;

	ptr = malloc(lth);
	if (!ptr) panic("Memory allocation failure; cannot get %u bytes", lth);
	return (long *) ptr;
}


/* format a pointer for display purposes; caller supplies the result buffer */
char *fmt_ptr(const void * ptr, char *buf)
{
	sprintf(buf, "%p", (void *)ptr);
	return buf;
}


/*alloc.c*/
