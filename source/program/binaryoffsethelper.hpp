#pragma once

#include "lib.hpp"
#include "nn.hpp"

namespace sort::helpers
{
    const char GAME_VERSION_1_0_0[] = "1.0.0";
    const char GAME_VERSION_1_1_0[] = "1.1.0";
    const char GAME_VERSION_1_1_1[] = "1.1.1";
    const char GAME_VERSION_1_1_2[] = "1.1.2";
    const char GAME_VERSION_1_2_0[] = "1.2.0";
    const char GAME_VERSION_1_2_1[] = "1.2.1";

    extern char sAppVersion[0x10];
    extern u32  sAppVersionIndex;

    u32 InitializeAppVersion();

    ALWAYS_INLINE u32 GetAppVersionIndex() { return sAppVersionIndex; }
    ALWAYS_INLINE int GetAppVersionOffset(const int *offset_array) { return offset_array[GetAppVersionIndex()]; }
}
