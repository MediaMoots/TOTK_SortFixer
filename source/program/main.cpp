#include "binaryoffsethelper.hpp"
#include "armor_hooks.hpp"
#include "lib.hpp"
#include "utils.hpp"

extern "C" void exl_main(void *x0, void *x1)
{
    /* Setup hooking enviroment. */
    exl::hook::Initialize();

    char buf[500];
    PRINT("Loading SRTFX (TOTK Sort Fixer)");

    /* Initialize app version */
    int versionIndex = sort::helpers::InitializeAppVersion();
    if (versionIndex == 0xffff'ffff)
    {
        PRINT("SRTFX: Incompatible game version!");
        return;
    }

    PRINT("SRTFX: Version Index %d", sort::helpers::GetAppVersionIndex());
    PRINT("SRTFX: Hooking Functions...");
    sort::armor::InstallHooks();
}

extern "C" NORETURN void exl_exception_entry()
{
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}