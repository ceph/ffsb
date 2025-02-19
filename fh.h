/*
 *   Copyright (c) International Business Machines Corp., 2001-2004
 *
 *   This program is free software;  you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY;  without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 *   the GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program;  if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef _FH_H_
#define _FH_H_

#include <inttypes.h>
#include "ffsb.h"

struct ffsb_thread;
struct ffsb_fs;

int fhopenread(char *, struct ffsb_thread *, struct ffsb_fs *);
int fhopenwrite(char *, struct ffsb_thread *, struct ffsb_fs *);
int fhopencreate(char *, struct ffsb_thread *, struct ffsb_fs *);
int fhopenappend(char *, struct ffsb_thread *, struct ffsb_fs *);

void fhread(int, void *, uint64_t, struct ffsb_thread *, struct ffsb_fs *);

/* can only write up to size_t bytes at a time, so size is a uint32_t */
void fhwrite(int, void *, uint32_t, struct ffsb_thread *, struct ffsb_fs *);
void fhseek(int, uint64_t, int, struct ffsb_thread *, struct ffsb_fs *);
void fhclose(int, struct ffsb_thread *, struct ffsb_fs *);

int writefile_helper(int, uint64_t, uint32_t, char *, struct ffsb_thread *,
		     struct ffsb_fs *);
void fhstat(char *name, ffsb_thread_t *ft, ffsb_fs_t *fs);

#endif /* _FH_H_ */
