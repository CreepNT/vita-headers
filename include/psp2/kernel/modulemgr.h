/**
 * \addtogroup Kernel Kernel
 * Modules, Processes, Threads, Memory blocks
 * \{
 */

/**
 * \addtogroup SceModulemgr Module Manager Library
 * Get a list of all loaded modules, Load a module
 */
/** \} */

/**
 * \defgroup SceModulemgrUser User
 *  \ingroup SceModulemgr
 * Exports for User
 *
 * ------------------------
 * ### Using this library in your project ###
 * Include the header file in your project:
 * \code
 * #include <psp2/kernel/modulemgr.h>
 * \endcode
 *
 * Link the library in your makefile:
 * \code
 * -lSceKernel_stub
 * \endcode
 * ------------------------
 * \{
 */

/**
 * \file
 * \brief Header file related to module management
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PSP2_KERNEL_MODULEMGR_H_
#define _PSP2_KERNEL_MODULEMGR_H_

#include <psp2/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief      Return values for plugins `module_start` and `module_stop`
 */
/** @{ */
#define SCE_KERNEL_START_SUCCESS      (0)
#define SCE_KERNEL_START_RESIDENT     SCE_KERNEL_START_SUCCESS
#define SCE_KERNEL_START_NO_RESIDENT  (1)
#define SCE_KERNEL_START_FAILED       (2)

#define SCE_KERNEL_STOP_SUCCESS       (0)
#define SCE_KERNEL_STOP_FAIL          (1)
#define SCE_KERNEL_STOP_CANCEL        SCE_KERNEL_STOP_FAIL
/** @} */

typedef struct
{
	SceUInt size;	//< this structure size (0x18)
	SceUInt perms;	//< probably rwx in low bits
	void *vaddr;	//< address in memory
	SceUInt memsz;	//< size in memory
	SceUInt flags;	//< meanig unknown
	SceUInt res;	//< unused?
} SceKernelSegmentInfo;

typedef struct
{
	SceUInt size;	//< 0x1B8 for Vita 1.x
	SceUInt handle;	//< kernel module handle?
	SceUInt flags;	//< some bits. could be priority or whatnot
	char module_name[28];
	SceUInt unk28;
	void *module_start;
	SceUInt unk30;
	void *module_stop;
	void *exidxTop;
	void *exidxBtm;
	SceUInt unk40;
	SceUInt unk44;
	void *tlsInit;
	SceSize tlsInitSize;
	SceSize tlsAreaSize;
	char path[256];
	SceKernelSegmentInfo segments[4];
	SceUInt type;	//< 6 = user-mode PRX?
} SceKernelModuleInfo;

typedef struct {
	SceSize size;
} SceKernelLMOption;

typedef struct {
	SceSize size;
} SceKernelULMOption;

int sceKernelGetModuleList(int flags, SceUID *modids, int *num);
int sceKernelGetModuleInfo(SceUID modid, SceKernelModuleInfo *info);

SceUID sceKernelLoadModule(char *path, int flags, SceKernelLMOption *option);
int sceKernelUnloadModule(SceUID modid, int flags, SceKernelULMOption *option);

SceUID sceKernelLoadStartModule(char *path, SceSize args, void *argp, int flags, SceKernelLMOption *option, int *status);
int sceKernelStopUnloadModule(SceUID modid, SceSize args, void *argp, int flags, SceKernelULMOption *option, int *status);

typedef struct
{
  SceSize size;
  char versionString[16];
  SceUInt unk_14;
  SceUInt unk_18;
  SceUInt unk_1C;
  SceUInt version;
  SceUInt unk_24;
} SceKernelFwInfo;

int sceKernelGetSystemSwVersion(SceKernelFwInfo *data);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_KERNEL_MODULEMGR_H_ */

/** \} */
