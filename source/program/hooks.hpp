#pragma once

#include "binaryoffsethelper.hpp"
#include "config.hpp"
#include "lib.hpp"
#include "types.hpp"
#include "utils.hpp"

static constexpr int arraySize = 300;
static char armorSortInfo[arraySize * 0x1c0] = {0};
static void *armorSortInfoPtrs[arraySize] = {0};
static char sortInfo[arraySize * 0x18] = {0};
static char sortInfoDouble[(arraySize * 0x18) * 2] = {0};

HOOK_DEFINE_TRAMPOLINE(sortArmorPouch){
	static void Callback(long param_1, uintptr_t param_2, int param_3){
		char buf[500];
PRINT("sortArmorPouch");

memset(armorSortInfo, 0, sizeof(armorSortInfo));
memset(armorSortInfoPtrs, 0, sizeof(armorSortInfoPtrs));
memset(sortInfo, 0, sizeof(sortInfo));
memset(sortInfoDouble, 0, sizeof(sortInfoDouble));

for (u32 i = 0; i < arraySize - 1; ++i)
	*reinterpret_cast<void **>(&armorSortInfo[i * 0x1c0]) = &armorSortInfo[(i + 1) * 0x1c0];
*reinterpret_cast<void**>(&armorSortInfo[(arraySize - 1) * 0x1c0]) = nullptr;

for (u32 i = 0; i < arraySize - 1; ++i)
	*reinterpret_cast<void **>(&sortInfo[i * 0x18]) = &sortInfo[(i + 1) * 0x18];
*reinterpret_cast<void**>(&sortInfo[(arraySize - 1) * 0x18]) = nullptr;

for (u32 i = 0; i < arraySize - 1; ++i)
	*reinterpret_cast<void **>(&sortInfoDouble[i * 0x18]) = &sortInfoDouble[(i + 1) * 0x18];
*reinterpret_cast<void**>(&sortInfoDouble[(arraySize - 1) * 0x18]) = nullptr;

Orig(param_1, param_2, param_3);
}
}
;

// Hook 1: 0x7101a72d54
HOOK_DEFINE_INLINE(SetArraySizeW10){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
PRINT("SetArraySizeW10 called");
PRINT("Setting W10 to: %d", arraySize - 1);
ctx->W[10] = arraySize - 1;
}
}
;

// Hook 2: 0x7101a72d68
HOOK_DEFINE_INLINE(SetArmorSortInfoX8){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
PRINT("SetArmorSortInfoX8 called");
PRINT("SetArmorSortInfoX8: %lu", (uint64_t)armorSortInfo);
ctx->X[8] = (uint64_t)armorSortInfo;
}
}
;

// Hook 11: 0x7101a72d98
HOOK_DEFINE_INLINE(SetCalculatedSizeX9){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
uint64_t calculated = ((arraySize - 1) * 0x1c0) + 0x20;
PRINT("SetCalculatedSizeX9 called");
PRINT("Setting W9 to calculated: %lu", calculated);
ctx->X[9] = calculated;
}
}
;

// Hook 3: 0x7101a72da4
HOOK_DEFINE_INLINE(SetArmorSortInfoPtrX8){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
PRINT("SetArmorSortInfoPtrX8 called");
PRINT("Setting X8 to pointer array: %lu", (uint64_t)armorSortInfoPtrs);
ctx->X[8] = (uint64_t)armorSortInfoPtrs;
}
}
;

// Hook 4: 0x7101a72da8
HOOK_DEFINE_INLINE(SetArraySizeX9){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
PRINT("SetArraySizeX9 called");
PRINT("Setting X9 to shifted size: %lu", ((uint64_t)arraySize) << 32);
ctx->X[9] = ((uint64_t)arraySize) << 32;
}
}
;

// Hook 5: 0x7101a73230
HOOK_DEFINE_INLINE(SetArraySizeW10_2){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
PRINT("SetArraySizeW10_2 called");
PRINT("Setting W10 to: %d", arraySize - 1);
ctx->W[10] = arraySize - 1;
}
}
;

// Hook 6: 0x7101a7324c
HOOK_DEFINE_INLINE(SetSortInfoX8){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
PRINT("SetSortInfoX8 called");
PRINT("sortInfo size: %lu", sizeof(sortInfo));
PRINT("Setting X8 to pointer: %p", sortInfo);
ctx->X[8] = (uint64_t)sortInfo;
}
}
;

// Hook 7: 0x7101a7327c
HOOK_DEFINE_INLINE(SetArraySizeW8){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
PRINT("SetArraySizeW8 called");
PRINT("Setting W8 to: %d", arraySize);
ctx->W[8] = arraySize;
}
}
;

// Hook 8: 0x7101a744f8
HOOK_DEFINE_INLINE(SetDoubleSortInfoX8){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
PRINT("SetDoubleSortInfoX8 called");
PRINT("Setting X8 to double pointer: %lu", (uint64_t)sortInfoDouble);
ctx->X[8] = (uint64_t)sortInfoDouble;
}
}
;

// Hook 9: 0x7101a74504
HOOK_DEFINE_INLINE(SetDoubleArraySizeW8){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
PRINT("SetDoubleArraySizeW8 called");
PRINT("Setting W8 to double size: %d", arraySize * 2);
ctx->W[8] = arraySize * 2;
}
}
;

// Hook 10: 0x7101a7326c
HOOK_DEFINE_INLINE(SetCalculatedSizeW9){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
uint32_t calculated = ((arraySize - 1) * 0x18) + 0x2c;
PRINT("SetCalculatedSizeW9 called");
PRINT("Setting W9 to calculated: %d", calculated);
ctx->W[9] = calculated;
}
}
;

// Hook 12: 0x7101a74500
HOOK_DEFINE_INLINE(SetDoubleCalculatedSizeW9){
	static void Callback(exl::hook::InlineCtx * ctx){
		char buf[500];
uint32_t calculated = (((arraySize * 2) - 1) * 0x18) + 0x2c;
PRINT("SetDoubleCalculatedSizeW9 called");
PRINT("Setting W9 to double calculated: %d", calculated);
ctx->W[9] = calculated;
}
}
;

// Hook 13: 0x7101a78238
// HOOK_DEFINE_INLINE(SetArraySizeW8_2){
// 	static void Callback(exl::hook::InlineCtx * ctx){
// 		char buf[500];
// PRINT("SetArraySizeW8_2 called");
// PRINT("Setting W8 to: %d", arraySize);
// ctx->W[8] = arraySize;
// }
// }
// ;

// Hook 14: 0x7101a76510
// HOOK_DEFINE_INLINE(SetArmorSortInfoX20){
// 	static void Callback(exl::hook::InlineCtx * ctx){
// 		char buf[500];
// PRINT("SetArmorSortInfoX20 called");
// PRINT("Setting X20 to: %lu", (uint64_t)armorSortInfo[currentIndex]);
// PRINT("X20 name: %s", armorSortInfo[currentIndex].name.mString);
// ctx->X[20] = (uint64_t)armorSortInfo[currentIndex];
// currentIndex++;
// }
// }
// ;

void installHooks()
{
	SetArraySizeW10::InstallAtOffset(0x01a72d54);
	SetArraySizeX9::InstallAtOffset(0x01a72da8);
	SetCalculatedSizeW9::InstallAtOffset(0x01a7326c);
	SetArraySizeW10_2::InstallAtOffset(0x01a73230);
	SetArraySizeW8::InstallAtOffset(0x01a7327c);
	SetDoubleArraySizeW8::InstallAtOffset(0x01a74504);
	SetCalculatedSizeX9::InstallAtOffset(0x01a72d98);
	SetDoubleCalculatedSizeW9::InstallAtOffset(0x01a74500);

	SetArmorSortInfoPtrX8::InstallAtOffset(0x01a72da4);
	SetDoubleSortInfoX8::InstallAtOffset(0x01a744f8);

	SetArmorSortInfoX8::InstallAtOffset(0x01a72d68);
	SetSortInfoX8::InstallAtOffset(0x01a7324c);

	// SetArmorSortInfoX20::InstallAtOffset(0x01a76510);
	// SetArraySizeW8_2::InstallAtOffset(0x01a78238);
}