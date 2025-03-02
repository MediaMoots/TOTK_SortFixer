#pragma once

#include "binaryoffsethelper.hpp"
#include "config.hpp"
#include "lib.hpp"
#include "types.hpp"
#include "utils.hpp"

HOOK_DEFINE_TRAMPOLINE (SortArmorPouch)
{
    static void Callback(long param_1, uintptr_t param_2, int param_3)
    {
        char buf[500];
        PRINT("SRTFX: sortArmorPouch");

        memset(sort::s_armorSortInfo, 0, sizeof(sort::s_armorSortInfo));
        memset(sort::s_armorSortInfoPtrs, 0, sizeof(sort::s_armorSortInfoPtrs));
        memset(sort::s_sortInfo, 0, sizeof(sort::s_sortInfo));
        memset(sort::s_sortInfoDouble, 0, sizeof(sort::s_sortInfoDouble));

        for (u32 i = 0; i < sort::s_arraySize - 1; ++i)
            *reinterpret_cast<void **>(&sort::s_armorSortInfo[i * 0x1c0]) = &sort::s_armorSortInfo[(i + 1) * 0x1c0];
        *reinterpret_cast<void **>(&sort::s_armorSortInfo[(sort::s_arraySize - 1) * 0x1c0]) = nullptr;

        for (u32 i = 0; i < sort::s_arraySize - 1; ++i)
            *reinterpret_cast<void **>(&sort::s_sortInfo[i * 0x18]) = &sort::s_sortInfo[(i + 1) * 0x18];
        *reinterpret_cast<void **>(&sort::s_sortInfo[(sort::s_arraySize - 1) * 0x18]) = nullptr;

        for (u32 i = 0; i < sort::s_arraySize - 1; ++i)
            *reinterpret_cast<void **>(&sort::s_sortInfoDouble[i * 0x18]) = &sort::s_sortInfoDouble[(i + 1) * 0x18];
        *reinterpret_cast<void **>(&sort::s_sortInfoDouble[(sort::s_arraySize - 1) * 0x18]) = nullptr;

        Orig(param_1, param_2, param_3);
    }
};

// Hook 2: 0x7101a72d68
HOOK_DEFINE_INLINE (SetArmorSortInfoX8)
{
    static void Callback(exl::hook::InlineCtx * ctx)
    {
        char buf[500];
        PRINT("SRTFX: SetArmorSortInfoX8 called");
        ctx->X[8] = (uint64_t)sort::s_armorSortInfo;
    }
};

// Hook 3: 0x7101a72da4
HOOK_DEFINE_INLINE (SetArmorSortInfoPtrX8)
{
    static void Callback(exl::hook::InlineCtx * ctx)
    {
        char buf[500];
        PRINT("SRTFX: SetArmorSortInfoPtrX8 called");
        ctx->X[8] = (uint64_t)sort::s_armorSortInfoPtrs;
    }
};

// Hook 4: 0x7101a72da8
HOOK_DEFINE_INLINE (SetArraySizeX9)
{
    static void Callback(exl::hook::InlineCtx * ctx)
    {
        char buf[500];
        PRINT("SRTFX: SetArraySizeX9 called");
        ctx->X[9] = ((uint64_t)sort::s_arraySize) << 32;
    }
};

// Hook 6: 0x7101a7324c
HOOK_DEFINE_INLINE (SetSortInfoX8)
{
    static void Callback(exl::hook::InlineCtx * ctx)
    {
        char buf[500];
        PRINT("SRTFX: SetSortInfoX8 called");
        ctx->X[8] = (uint64_t)sort::s_sortInfo;
    }
};

// Hook 7: 0x7101a7327c
HOOK_DEFINE_INLINE (SetArraySizeW8)
{
    static void Callback(exl::hook::InlineCtx * ctx)
    {
        char buf[500];
        PRINT("SRTFX: SetArraySizeW8 called");
        ctx->W[8] = sort::s_arraySize;
    }
};

// Hook 8: 0x7101a744f8
HOOK_DEFINE_INLINE (SetDoubleSortInfoX8)
{
    static void Callback(exl::hook::InlineCtx * ctx)
    {
        char buf[500];
        PRINT("SRTFX: SetDoubleSortInfoX8 called");
        ctx->X[8] = (uint64_t)sort::s_sortInfoDouble;
    }
};

// Hook 9: 0x7101a74504
HOOK_DEFINE_INLINE (SetDoubleArraySizeW8)
{
    static void Callback(exl::hook::InlineCtx * ctx)
    {
        char buf[500];
        PRINT("SRTFX: SetDoubleArraySizeW8 called");
        ctx->W[8] = sort::s_arraySize * 2;
    }
};

void InstallHooks()
{
    // Main Function Hook
    SortArmorPouch::InstallAtOffset(sort::helpers::GetAppVersionOffset(sort::s_sortArmorPouchOffsets));

    SetArraySizeX9::InstallAtOffset(sort::helpers::GetAppVersionOffset(sort::s_setArraySizeX9Offsets));

    SetArraySizeW8::InstallAtOffset(sort::helpers::GetAppVersionOffset(sort::s_setArraySizeW8Offsets));

    SetDoubleArraySizeW8::InstallAtOffset(sort::helpers::GetAppVersionOffset(sort::s_setDoubleArraySizeW8Offsets));

    SetArmorSortInfoX8::InstallAtOffset(sort::helpers::GetAppVersionOffset(sort::s_setArmorSortInfoX8Offsets));

    SetArmorSortInfoPtrX8::InstallAtOffset(sort::helpers::GetAppVersionOffset(sort::s_setArmorSortInfoPtrX8Offsets));

    SetSortInfoX8::InstallAtOffset(sort::helpers::GetAppVersionOffset(sort::s_setSortInfoX8Offsets));

    SetDoubleSortInfoX8::InstallAtOffset(sort::helpers::GetAppVersionOffset(sort::s_setDoubleSortInfoX8Offsets));
}