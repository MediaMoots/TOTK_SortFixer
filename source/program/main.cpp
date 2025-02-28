#include "lib.hpp"
#include "utils.hpp"
#include "hooks.hpp"
#include "binaryoffsethelper.hpp"

extern "C" void exl_main(void *x0, void *x1)
{
    /* Setup hooking enviroment. */
    exl::hook::Initialize();

    char buf[500];
    PRINT("Loading Sort Fixer");

    /* Initialize app version */
    int versionIndex = sort::helpers::InitializeAppVersion();
    if (versionIndex == 0xffff'ffff)
    {
        PRINT("Sort: Incompatible game version!");
        return;
    }

    PRINT("Sort: Version Index %d", sort::helpers::GetAppVersionIndex());

    PRINT("Sort: Hooking Functions...");
    sortArmorPouch::InstallAtOffset(sort::helpers::GetAppVersionOffset(game::pouchcontent::PouchMgr::s_sortArmorPouchOffsets));
    //sortArmorsInfo1::InstallAtOffset(0x01a72e50);

    game::pouchcontent::PouchMgr::sortArmorPouch_unk1::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::pouchcontent::PouchMgr::s_sortArmorPouch_unk1Offsets));
    
    game::pouchcontent::PouchMgr::sortArmorPouch_unk2::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::pouchcontent::PouchMgr::s_sortArmorPouch_unk2Offsets));
    
    game::pouchcontent::PouchMgr::sortArmorPouch_unk3::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::pouchcontent::PouchMgr::s_sortArmorPouch_unk3Offsets));
    
    game::pouchcontent::PouchMgr::sortArmorPouch_unk4::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::pouchcontent::PouchMgr::s_sortArmorPouch_unk4Offsets));
    
    game::pouchcontent::PouchMgr::sortArmorPouch_unk5::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::pouchcontent::PouchMgr::s_sortArmorPouch_unk5Offsets));
    
    ui::PouchSortTable::getArmorCategory::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(ui::PouchSortTable::s_getArmorCategoryOffsets));
    
    ui::PouchSortTable::getArmorSeries::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(ui::PouchSortTable::s_getArmorSeriesOffsets));
    
    game::pouchcontent::checkActorHasTag::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::pouchcontent::s_checkActorHasTagOffsets));
    
    game::pouchcontent::PouchMgr::getPouchCount::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::pouchcontent::PouchMgr::s_getPouchCountOffsets));
    
    game::pouchcontent::PouchMgr::addArmorToArmorInventory::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::pouchcontent::PouchMgr::s_addArmorToArmorInventoryOffsets));
    
    game::pouchcontent::PouchMgr::sortArmorBySet::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::pouchcontent::PouchMgr::s_sortArmorBySetOffsets));
    
    game::pouchcontent::PouchMgr::sortArmorByBodyPart::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::pouchcontent::PouchMgr::s_sortArmorByBodyPartOffsets));
    
    game::pouchcontent::PouchMgr::sortUpdateGameData::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::pouchcontent::PouchMgr::s_sortUpdateGameDataOffsets));
    
    game::PouchActorInfoTable::getRow::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(game::PouchActorInfoTable::s_getRowOffsets));
    
    gmd::GameDataMgr::getStructStructByIndex::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(gmd::GameDataMgr::s_getStructStructByIndexOffsets));
    
    gmd::GameDataMgr::getStructString64::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(gmd::GameDataMgr::s_getStructString64Offsets));
    
    gmd::GameDataMgr::getStructEnum::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(gmd::GameDataMgr::s_getStructEnumOffsets));
    
    sead::BufferedSafeStringBase::setString::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(sead::BufferedSafeStringBase::s_setStringOffsets));
    
    pp::PropBuffer::getCount::InstallAtOffset(
        sort::helpers::GetAppVersionOffset(pp::PropBuffer::s_getCountOffsets));

    
}

extern "C" NORETURN void exl_exception_entry()
{
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}