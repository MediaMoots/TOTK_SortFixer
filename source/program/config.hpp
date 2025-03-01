#pragma once

namespace sort
{
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
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a72da8 // 1.2.1
    };

    static constexpr int s_setArraySizeW8Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a7327c // 1.2.1
    };

    static constexpr int s_setDoubleArraySizeW8Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a74504 // 1.2.1
    };

    // Buffer Patches
    static constexpr int s_setArmorSortInfoX8Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a72d68 // 1.2.1
    };

    static constexpr int s_setArmorSortInfoPtrX8Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a72da4 // 1.2.1
    };

    static constexpr int s_setSortInfoX8Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a7324c // 1.2.1
    };

    static constexpr int s_setDoubleSortInfoX8Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a744f8 // 1.2.1
    };
}