#pragma once

namespace sort
{
    static constexpr int s_arraySize = 600;
    static char s_armorSortInfo[s_arraySize * 0x1c0] = {0};
    static void *s_armorSortInfoPtrs[s_arraySize] = {0};
    static char s_sortInfo[s_arraySize * 0x18] = {0};
    static char s_sortInfoDouble[(s_arraySize * 0x18) * 2] = {0};

    static constexpr int s_sortArmorPouchOffsets[] = {
        0x01a27284, // 1.0.0
        0x01a817b0, // 1.1.0
        0x01a7f0c4, // 1.1.1
        0x01a75ca4, // 1.1.2
        0x01a678b0, // 1.2.0
        0x01a72cd4, // 1.2.1
    };

    // Bounds Patches
    static constexpr int s_setArraySizeX9Offsets[] = {
        0x0,
        0x01a81884,
        0x01a7f198,
        0x01a75d78,
        0x01a67984,
        0x01a72da8 // 1.2.1
    };

    static constexpr int s_setArraySizeW8Offsets[] = {
        0x0,
        0x01a81d58,
        0x01a7f66c,
        0x01a7624c,
        0x01a67e58,
        0x01a7327c // 1.2.1
    };

    static constexpr int s_setDoubleArraySizeW8Offsets[] = {
        0x0,
        0x01a82fe0,
        0x01a808f4,
        0x01a774d4,
        0x01a690e0,
        0x01a74504 // 1.2.1
    };

    // Buffer Patches
    static constexpr int s_setArmorSortInfoX8Offsets[] = {
        0x0,
        0x01a81844,
        0x01a7f158,
        0x01a75d38,
        0x01a67944,
        0x01a72d68 // 1.2.1
    };

    static constexpr int s_setArmorSortInfoPtrX8Offsets[] = {
        0x0,
        0x01a81880,
        0x01a7f194,
        0x01a75d74,
        0x01a67980,
        0x01a72da4 // 1.2.1
    };

    static constexpr int s_setSortInfoX8Offsets[] = {
        0x0,
        0x01a81d28,
        0x01a7f63c,
        0x01a7621c,
        0x01a67e28,
        0x01a7324c // 1.2.1
    };

    static constexpr int s_setDoubleSortInfoX8Offsets[] = {
        0x0,
        0x01a82fd4,
        0x01a808e8,
        0x01a774c8,
        0x01a690d4,
        0x01a744f8 // 1.2.1
    };
}