#include "lib.hpp"
#include "utils.hpp"
#include "hooks.hpp"
#include "binaryoffsethelper.hpp"

static char armor_buffer_1[0x1c0 * 512]; // 448 * 512
static char armor_buffer_2[0x1c0 * 512]; // 448 * 512

static constexpr int s_sortArmorsOffsets[] = {
    0x01a27284, // 1.0.0
    0x01a817b0, // 1.1.0
    0x01a7f0c4, // 1.1.1
    0x01a75ca4, // 1.1.2
    0x01a678b0, // 1.2.0
    0x01a72cd4, // 1.2.1
};

HOOK_DEFINE_TRAMPOLINE(sortArmors){
    static void Callback(uintptr_t param_1, uintptr_t param_2, int param_3){

        char buf[500];
PRINT("sortArmors");

memset(armor_buffer_1, 0, sizeof(armor_buffer_1));
memset(armor_buffer_2, 0, sizeof(armor_buffer_2));

Orig(param_1, param_2, param_3);

return;
}
}
;

HOOK_DEFINE_INLINE(editBuffer1){
    static void Callback(exl::hook::InlineCtx * ctx){

        char buf[500];
PRINT("editBuffer1");

ctx->X[9] = (uint64_t)armor_buffer_1;

return;
}
}
;

HOOK_DEFINE_INLINE(editBuffer2){
    static void Callback(exl::hook::InlineCtx * ctx){

        char buf[500];
PRINT("editBuffer2");

ctx->X[8] = (uint64_t)armor_buffer_2;

return;
}
}
;

HOOK_DEFINE_INLINE(increaseFirstLoopCap){
    static void Callback(exl::hook::InlineCtx * ctx){

        char buf[500];
PRINT("increaseFirstLoopCap");
PRINT("increaseFirstLoopCap: %u", ctx->W[10]);

ctx->W[10] = 512; // 255

return;
}
}
;

HOOK_DEFINE_INLINE(increaseSecondLoopCap){
    static void Callback(exl::hook::InlineCtx * ctx){

        char buf[500];
PRINT("increaseSecondLoopCap");
PRINT("increaseSecondLoopCap: %u", ctx->W[10]);

ctx->W[10] = 512; // 255

return;
}
}
;

HOOK_DEFINE_INLINE(increaseFinalCap){
    static void Callback(exl::hook::InlineCtx * ctx){

        char buf[500];
PRINT("increaseFinalCap");
PRINT("increaseFinalCap: %u", ctx->W[8]);

ctx->W[8] = 512; // 256

return;
}
}
;

HOOK_DEFINE_INLINE(sortArmorsChange4){
    static void Callback(exl::hook::InlineCtx * ctx){

        char buf[500];
PRINT("sortArmorsChange4");
PRINT("sortArmorsChange4: %u", ctx->W[9]);

ctx->W[9] = 512; // 256

return;
}
}
;

HOOK_DEFINE_INLINE(sortArmorsLoop1){
    static void Callback(exl::hook::InlineCtx * ctx){

        char buf[500];
PRINT("sortArmorsLoop1");

return;
}
}
;

HOOK_DEFINE_INLINE(sortArmorsLoop2){
    static void Callback(exl::hook::InlineCtx * ctx){

        char buf[500];
PRINT("sortArmorsLoop2");

return;
}
}
;

HOOK_DEFINE_INLINE(sortArmorsLoop3){
    static void Callback(exl::hook::InlineCtx * ctx){

        char buf[500];
PRINT("sortArmorsLoop3");

return;
}
}
;

HOOK_DEFINE_INLINE(sortArmorsInfo1){
    static void Callback(exl::hook::InlineCtx * ctx){

        char buf[500];
PRINT("sortArmorsInfo1");
PRINT("sortArmorsInfo1: %lu", ctx->X[8]);

PRINT("sortArmorsInfo1 My GMD: %lu", (uintptr_t)gmd::GameDataMgr::GetInstancePtr());

return;
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
    sortArmors::InstallAtOffset(sort::helpers::GetAppVersionOffset(s_sortArmorsOffsets));

    // editBuffer1::InstallAtOffset(0x01a72d5c);
    // editBuffer2::InstallAtOffset(0x01a72da4);


    // increaseFirstLoopCap::InstallAtOffset(0x01a72d54);
    // increaseSecondLoopCap::InstallAtOffset(0x01a73230);
    // increaseFinalCap::InstallAtOffset(0x01a7327c);

    // sortArmorsChange4::InstallAtOffset(0x01a7629c);

    // sortArmorsLoop1::InstallAtOffset(0x01a72d70);
    // sortArmorsLoop2::InstallAtOffset(0x01a73254);

    // sortArmorsLoop3::InstallAtOffset(0x01a762b0);

    sortArmorsInfo1::InstallAtOffset(0x01a72d14);
}

extern "C" NORETURN void exl_exception_entry()
{
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}