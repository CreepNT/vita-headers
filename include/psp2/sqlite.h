/**
 * \usergroup{SceSqlite}
 * \usage{psp2/sqlite.h,-lSceSqlite_stub}
 */

/**
 * \file
 * \brief Header file which defines sqlite related variables and functions
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PSP2_SQLITE_H_
#define _PSP2_SQLITE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
	void *(*xMalloc)(int);
	void *(*xRealloc)(void*,int);
	void (*xFree)(void*);
}SceSqliteMallocMethods;

/**
 * Wrapper for sqlite3_config(SQLITE_CONFIG_MALLOC)
 *
 * @param[in] methods - A proper set of memory allocation methods
 *
 * @return 0 on success, < 0 on error.
*/
int sceSqliteConfigMallocMethods(SceSqliteMallocMethods* methods);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_SQLITE_H_ */

