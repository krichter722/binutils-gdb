/* strstr - find first occurrence of wanted in s

   Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation.
   
   This file is part of GAS, the GNU Assembler.
   
   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.
   
   GAS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to
   the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* If your compiler is really ansi, then you don't need this. */

#if __STDC__ != 1

#define SIZET int

#define	NULL	0

#include <string.h>

char *				/* found string, or NULL if none */
    strstr(s, wanted)
char *s;
char *wanted;
{
	register char *scan;
	register SIZET len;
	register char firstc;
	
	/*
	 * The odd placement of the two tests is so "" is findable.
	 * Also, we inline the first char for speed.
	 * The ++ on scan has been moved down for optimization.
	 */
	firstc = *wanted;
	len = strlen(wanted);
	for (scan = s; *scan != firstc || strncmp(scan, wanted, len) != 0; )
	    if (*scan++ == '\0')
		return(NULL);
	return(scan);
} /* strstr() */

#endif /* not __STDC__ */

/* end of strstr.c */
