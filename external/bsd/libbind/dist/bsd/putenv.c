/*	$NetBSD: putenv.c,v 1.1.1.2 2012/09/09 16:07:43 christos Exp $	*/

#ifndef LINT
static const char rcsid[] = "Id: putenv.c,v 1.2 2005/04/27 04:56:11 sra Exp ";
#endif

#include "port_before.h"
#include "port_after.h"

/*%
 * To give a little credit to Sun, SGI,
 * and many vendors in the SysV world.
 */

#if !defined(NEED_PUTENV)
int __bindcompat_putenv;
#else
int
putenv(char *str) {
	char *tmp;

	for (tmp = str; *tmp && (*tmp != '='); tmp++)
		;

	return (setenv(str, tmp, 1));
}
#endif

/*! \file */
