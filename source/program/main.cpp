#include "lib.hpp"
#include "utils.hpp"
#include "hooks.hpp"
#include "binaryoffsethelper.hpp"

HOOK_DEFINE_INLINE(info1){
    static void Callback(exl::hook::InlineCtx * ctx){
        char buf[500];
PRINT("info1");
}
}
;

HOOK_DEFINE_INLINE(info2){
    static void Callback(exl::hook::InlineCtx * ctx){
        char buf[500];
PRINT("info2");
}
}
;

HOOK_DEFINE_INLINE(info3){
    static void Callback(exl::hook::InlineCtx * ctx){
        char buf[500];
PRINT("info3");
}
}
;

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

    // sortUpdateGameData::InstallAtOffset(0x01a7450c);

    info1::InstallAtOffset(0x01a764f4);
    // info2::InstallAtOffset(0x01a73388);
    // info3::InstallAtOffset(0x01a73390);

    installHooks();
}

extern "C" NORETURN void exl_exception_entry()
{
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}