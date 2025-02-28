#pragma once

namespace ui::PouchSortTable
{
    static constexpr int s_getArmorCategoryOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a5693c // 1.2.1
    };
    static constexpr int s_getArmorSeriesOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a569e4 // 1.2.1
    };
}

namespace game::pouchcontent
{
    static constexpr int s_checkActorHasTagOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x0169a308 // 1.2.1
    };
}

namespace game::pouchcontent::PouchMgr
{
    static constexpr int s_sortArmorPouchOffsets[] = {
        0x01a27284, // 1.0.0
        0x01a817b0, // 1.1.0
        0x01a7f0c4, // 1.1.1
        0x01a75ca4, // 1.1.2
        0x01a678b0, // 1.2.0
        0x01a72cd4, // 1.2.1
    };

    static constexpr int s_getPouchCountOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x00d44a08 // 1.2.1
    };

    static constexpr int s_addArmorToArmorInventoryOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a764f4 // 1.2.1
    };

    static constexpr int s_sortArmorBySetOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a76668 // 1.2.1
    };

    static constexpr int s_sortArmorByBodyPartOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a76558 // 1.2.1
    };

    static constexpr int s_sortUpdateGameDataOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a7450c // 1.2.1
    };

    static constexpr int s_sortArmorPouch_unk1Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a76474 // 1.2.1
    };

    static constexpr int s_sortArmorPouch_unk2Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x00ea42ec // 1.2.1
    };

    static constexpr int s_sortArmorPouch_unk3Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x0071d860 // 1.2.1
    };

    static constexpr int s_sortArmorPouch_unk4Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x009fb56c // 1.2.1
    };
    
    static constexpr int s_sortArmorPouch_unk5Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x01a744cc // 1.2.1
    };
}

namespace game::PouchActorInfoTable
{
    static constexpr int s_getRowOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x00b95b98 // 1.2.1
    };
}

namespace gmd::GameDataMgr
{
    static constexpr int s_GMDInstanceOffset_v121 = 0x04721b98;

    static constexpr int s_getStructStructByIndexOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x00942fe8 // 1.2.1
    };
    static constexpr int s_getStructString64Offsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x00d44600 // 1.2.1
    };
    static constexpr int s_getStructEnumOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x00bad788 // 1.2.1
    };
}

namespace sead::BufferedSafeStringBase
{
    static constexpr int s_setStringOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x00b51c14 // 1.2.1
    };
}

namespace pp::PropBuffer
{
    static constexpr int s_getCountOffsets[] = {
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x009fb520 // 1.2.1
    };
}

namespace exking::RSDB::RSDBMgr
{
    static constexpr int s_RSDBMgrInstanceOffset_v121 = 0x046ba270;
}