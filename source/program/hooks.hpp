#pragma once

#include "binaryoffsethelper.hpp"
#include "config.hpp"
#include "lib.hpp"
#include "types.hpp"
#include "utils.hpp"

namespace gmd::GameDataMgr
{
	static void **GetInstancePtr()
	{
		switch (sort::helpers::GetAppVersionIndex())
		{
		// case 0: // 1.0.0
		// 	return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v100, s_RootCallbackOffset_v100>();
		// case 1: // 1.1.0
		// 	return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v110, s_RootCallbackOffset_v110>();
		// case 2: // 1.1.1
		// 	return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v111, s_RootCallbackOffset_v111>();
		// case 3: // 1.1.2
		// 	return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v112, s_RootCallbackOffset_v112>();
		// case 4: // 1.2.0
		// 	return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v120, s_RootCallbackOffset_v120>();
		case 5: // 1.2.1
			return exl::util::pointer_path::FollowSafe<void *, s_GMDInstanceOffset_v121>();
		default: // Default to latest version
			return exl::util::pointer_path::FollowSafe<void *, s_GMDInstanceOffset_v121>();
		}
	}
}

namespace exking::RSDB::RSDBMgr
{
	static void **GetInstancePtr()
	{
		switch (sort::helpers::GetAppVersionIndex())
		{
		// case 0: // 1.0.0
		// 	return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v100, s_RootCallbackOffset_v100>();
		// case 1: // 1.1.0
		// 	return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v110, s_RootCallbackOffset_v110>();
		// case 2: // 1.1.1
		// 	return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v111, s_RootCallbackOffset_v111>();
		// case 3: // 1.1.2
		// 	return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v112, s_RootCallbackOffset_v112>();
		// case 4: // 1.2.0
		// 	return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v120, s_RootCallbackOffset_v120>();
		case 5: // 1.2.1
			return exl::util::pointer_path::FollowSafe<void *, s_RSDBMgrInstanceOffset_v121>();
		default: // Default to latest version
			return exl::util::pointer_path::FollowSafe<void *, s_RSDBMgrInstanceOffset_v121>();
		}
	}
}

HOOK_DEFINE_INLINE(sortArmorsInfo1){
	static void Callback(exl::hook::InlineCtx * ctx){

		char buf[500];
PRINT("sortArmorsInfo1");
PRINT("sortArmorsInfo1 x0: %lu", ctx->X[0]);
PRINT("sortArmorsInfo1 x1: %lu", ctx->X[1]);
PRINT("sortArmorsInfo1 x2: %lu", ctx->X[2]);
PRINT("sortArmorsInfo1 x3: %lu", ctx->X[3]);
// PRINT("sortArmorsInfo1 x4: %lu", ctx->X[4]);

PRINT("sortArmorsInfo1 x1 char: %s", (char *)&ctx->X[1]);
PRINT("sortArmorsInfo1 x1 char: %s", (char *)*((char **)ctx->X[1]));
PRINT("sortArmorsInfo1 x1 char: %s", (char *)ctx->X[1]);

// PRINT("sortArmorsInfo1 My GMD: %lu", (uintptr_t)gmd::GameDataMgr::GetInstancePtr());

return;
}
}
;

// ui::PouchSortTable
namespace ui::PouchSortTable
{
	HOOK_DEFINE_TRAMPOLINE(getArmorCategory){
		static pp::TypedParam::PropBuffer* Callback(pp::TypedParam::PouchSortTable* param_1){
			char buf[500];
	PRINT("getArmorCategory");
	return Orig(param_1);
}
}
;

HOOK_DEFINE_TRAMPOLINE(getArmorSeries){
	static pp::TypedParam::PropBuffer* Callback(pp::TypedParam::PouchSortTable* param_1){
		char buf[500];
PRINT("getArmorSeries");
return Orig(param_1);
}
}
;
}

// game::pouchcontent
namespace game::pouchcontent
{
	HOOK_DEFINE_TRAMPOLINE(checkActorHasTag){
		static uint Callback(uintptr_t param_1, uintptr_t param_2){
			char buf[500];
	PRINT("checkActorHasTag");
	return Orig(param_1, param_2);
}
}
;
}

// game::pouchcontent::PouchMgr
namespace game::pouchcontent::PouchMgr
{
	HOOK_DEFINE_TRAMPOLINE(getPouchCount){
		static int Callback(long param_1, uint param_2){
			char buf[500];
	PRINT("getPouchCount");
	return Orig(param_1, param_2);
}
}
;

HOOK_DEFINE_TRAMPOLINE(addArmorToArmorInventory){
	static void Callback(uintptr_t armorInventory, uintptr_t armorData){
		char buf[500];
PRINT("addArmorToArmorInventory");
Orig(armorInventory, armorData);
return;
}
}
;

HOOK_DEFINE_TRAMPOLINE(sortArmorBySet){
	static void Callback(int param_1, long param_2, long *param_3){
		char buf[500];
PRINT("sortArmorBySet");
Orig(param_1, param_2, param_3);
return;
}
}
;

HOOK_DEFINE_TRAMPOLINE(sortArmorByBodyPart){
	static void Callback(int param_1, long param_2, long *param_3){
		char buf[500];
PRINT("sortArmorByBodyPart");
Orig(param_1, param_2, param_3);
return;
}
}
;

HOOK_DEFINE_TRAMPOLINE(sortUpdateGameData){
	static void Callback(uintptr_t param_1, int param_2, uint param_3, long param_4){
		char buf[500];
PRINT("sortUpdateGameData");
Orig(param_1, param_2, param_3, param_4);
return;
}
}
;

HOOK_DEFINE_TRAMPOLINE(sortArmorPouch_unk1){
	static void Callback(uint32_t *param_1){
		char buf[500];
PRINT("sortArmorPouch_unk1");
Orig(param_1);
return;
}
}
;

HOOK_DEFINE_TRAMPOLINE(sortArmorPouch_unk2){
	static void Callback(pp::TypedParam::PropBuffer* param_1){
		char buf[500];
		
PRINT("sortArmorPouch_unk2");
//PRINT("sortArmorPouch_unk2: %d", param_1->mMax);
Orig(param_1);
return;
}
}
;

HOOK_DEFINE_TRAMPOLINE(sortArmorPouch_unk3){
	static void Callback(long *param_1){
		char buf[500];
PRINT("sortArmorPouch_unk3");
Orig(param_1);
return;
}
}
;

HOOK_DEFINE_TRAMPOLINE(sortArmorPouch_unk4){
	static void Callback(long *param_1, uintptr_t param_2){
		// 		char buf[500];
		// PRINT("sortArmorPouch_unk4");
		Orig(param_1, param_2);
return;
}
}
;

HOOK_DEFINE_TRAMPOLINE(sortArmorPouch_unk5){
	static void Callback(long **param_1, long **param_2){
		char buf[500];
PRINT("sortArmorPouch_unk5");
Orig(param_1, param_2);
return;
}
}
;
}

// game::PouchActorInfoTable
namespace game::PouchActorInfoTable
{
	HOOK_DEFINE_TRAMPOLINE(getRow){
		static void Callback(uintptr_t param_1, uintptr_t *param_2){
			// 		char buf[500];
			// PRINT("getRow");
			Orig(param_1, param_2);
	return;
}
}
;
}

// gmd::GameDataMgr
namespace gmd::GameDataMgr
{
	HOOK_DEFINE_TRAMPOLINE(getStructStructByIndex){
		static uintptr_t Callback(void *param_1, long *param_2, long *param_3, uint param_4, int param_5){
			// 		char buf[500];
			// PRINT("getStructStructByIndex");
			return Orig(param_1, param_2, param_3, param_4, param_5);
}
}
;

HOOK_DEFINE_TRAMPOLINE(getStructString64){
	static uintptr_t Callback(void *param_1, char **param_2, long *param_3, uint param_4){
		char buf[500];
PRINT("getStructString64");
return Orig(param_1, param_2, param_3, param_4);
}
}
;

HOOK_DEFINE_TRAMPOLINE(getStructEnum){
	static uintptr_t Callback(long param_1, uint32_t *param_2, long *param_3, uint param_4){
		// 		char buf[500];
		// PRINT("getStructEnum");
		return Orig(param_1, param_2, param_3, param_4);
}
}
;
}

// sead::BufferedSafeStringBase
namespace sead::BufferedSafeStringBase
{
	HOOK_DEFINE_TRAMPOLINE(setString){
		static int Callback(sead::BufferedSafeStringBaseChar *param_1, char **param_2, long param_3){
			int result = Orig(param_1, param_2, param_3);
			// 		char buf[500];
			// PRINT("setString: %s", param_1->mString.string);
			return result;
}
}
;
}

// pp::PropBuffer
namespace pp::PropBuffer
{
	HOOK_DEFINE_TRAMPOLINE(getCount){
		static int Callback(pp::TypedParam::PropBuffer* param_1){
			// 		char buf[500];
			// PRINT("getCount");
			return Orig(param_1);
}
}
;
}

HOOK_DEFINE_TRAMPOLINE(sortArmorPouch){
	static void Callback(long param_1, uintptr_t param_2, int param_3){
		char buf[500];
PRINT("sortArmorPouch");
// Get singleton instances
void **gmdInstance = gmd::GameDataMgr::GetInstancePtr();
void **rsdbInstance = exking::RSDB::RSDBMgr::GetInstancePtr();

// Access structure members using offsets
long *plVar12 = (long *)(param_1 + 0x1fc18);
uint32_t uVar1 = *(uint32_t *)(param_1 + 0x188);
if (uVar1 > 1)
	uVar1 = 0; // Clamp to 0 or 1

// Retrieve pouch sort table and armor metadata
pp::TypedParam::PouchSortTable* pouchSortTablePtr = *(pp::TypedParam::PouchSortTable **)(*plVar12 + 0x150);
pp::TypedParam::PropBuffer* armorCategory = ui::PouchSortTable::getArmorCategory::Callback(pouchSortTablePtr);
pp::TypedParam::PropBuffer* armorSeries = ui::PouchSortTable::getArmorSeries::Callback(pouchSortTablePtr);

PRINT("mWeaponCategoryIsPresent: %s\n", (pouchSortTablePtr->mWeaponCategoryIsPresent & 1U) ? "true" : "false");
PRINT("mArmorCategoryIsPresent: %s\n", (pouchSortTablePtr->mArmorCategoryIsPresent & 1U) ? "true" : "false");
PRINT("mMaterialBowAttachmentTag: %s", pouchSortTablePtr->mMaterialBowAttachmentTag.string);

PRINT("armorCategory: %d",armorCategory->mCount);
PRINT("armorSeries: %d",armorSeries->mCount);

// Temporary data structures for sorting
struct ArmorSortInfo
{
	uint32_t index;											  // Armor index
	uint32_t category;										  // Armor category or type
	char padding[0x38 * sizeof(long) - 2 * sizeof(uint32_t)]; // Adjust size
};
ArmorSortInfo auStack_1c868[256] = {};
long puStack_1c880[256] = {0}; // Array of indices or pointers
int uStack_1c888 = 0;		   // Counter for items
uint32_t uStack_20f48 = 0;	   // Armor type or enum-derived value

// Additional variables for list building
struct Node
{
	uint32_t value;
	uint32_t padding;
	Node *next;
	Node *previous;
};
Node nodes[256] = {};
Node *pplStack_1e0b8 = nodes;
Node *ppppppplStack_1e0d0 = nullptr;
int iStack_1e0c0 = 0;
int iStack_1e0a8 = 256;

// Process each armor item in the pouch
int pouchCount = game::pouchcontent::PouchMgr::getPouchCount::Callback(param_1, 4);
PRINT("pouchCount: %d", pouchCount);

struct uStack_1c898_struct
{
	char uStack_1c898_buffer[4096 * 2] = {0};
};

if (pouchCount > 0)
{
	for (int i = 0; i < pouchCount; i++)
	{
		uStack_1c898_struct uStack_1c898;

		ulong uVar9 = gmd::GameDataMgr::getStructStructByIndex::Callback(
			*gmdInstance, (long *)&uStack_1c898, (long *)(param_1 + uVar1 * 0xc0 + 0x48), 0x4290322e, i);

		if ((uVar9 & 1) == 0)
			break;

		char *pcStack_1c8a0 = nullptr;
		uVar9 = gmd::GameDataMgr::getStructString64::Callback(
			*gmdInstance, &pcStack_1c8a0, (long *)&uStack_1c898, 0x25efa387);

		if ((uVar9 & 1) == 0 || *pcStack_1c8a0 == '\0')
			continue;

		PRINT("pcStack_1c8a0: %s", pcStack_1c8a0);

		// Initialize temporary array
		uint32_t uStack_21100[2] = {0};
		game::pouchcontent::PouchMgr::sortArmorPouch_unk1::Callback(uStack_21100);
		uStack_21100[0] = i;

		sead::BufferedSafeStringBaseChar alStack_210f8 = {};
		char alStack_210f8_buffer[256] = {};
		alStack_210f8.mBufferSize = 256;
		alStack_210f8.mString.bufCapacity = 256;
		alStack_210f8.mString.string = alStack_210f8_buffer;
		sead::BufferedSafeStringBase::setString::Callback(&alStack_210f8, &pcStack_1c8a0, 0xffffffff);

		PRINT("alStack_210f8: %s", alStack_210f8.mString.string);

		// Category processing
		pp::TypedParam::PropBuffer* plVar10 = ui::PouchSortTable::getArmorCategory::Callback(pouchSortTablePtr);
		PRINT("pouchSortTablePtr: %lu", pouchSortTablePtr);

		game::pouchcontent::PouchMgr::sortArmorPouch_unk2::Callback(plVar10);

		PRINT("plVar10: %lu", plVar10);

		long ppppppplStack_1e0d0 = 0;
		uint32_t uStack_1e0bc = 0;
		long pppppppplStack_1e0c8 = 0;
		bool hasTag = false;
		do
		{
			uVar9 = game::pouchcontent::checkActorHasTag::Callback((uintptr_t)&pcStack_1c8a0, pppppppplStack_1e0c8);
			if ((uVar9 & 1) != 0)
			{
				hasTag = true;
				break;
			}
			game::pouchcontent::PouchMgr::sortArmorPouch_unk3::Callback(&ppppppplStack_1e0d0);
			pppppppplStack_1e0c8 = 0; // Simplified exit condition
		} while (pppppppplStack_1e0c8 != 0 || uStack_1e0bc != 0);

		
		if (!hasTag)
		{
			int iVar6 = pp::PropBuffer::getCount::Callback(plVar10);
			game::pouchcontent::PouchMgr::sortArmorPouch_unk4::Callback((long*)plVar10, iVar6 - 1);
		}

		sead::BufferedSafeStringBaseChar auStack_20fe8 = {};
		char auStack_20fe8_buffer[256] = {};
		auStack_20fe8.mBufferSize = 256;
		auStack_20fe8.mString.bufCapacity = 256;
		auStack_20fe8.mString.string = auStack_20fe8_buffer;
		sead::BufferedSafeStringBase::setString::Callback(&auStack_20fe8, &pcStack_1c8a0, -1);

		PRINT("auStack_20fe8: %s", auStack_20fe8.mString.string);

		// Series processing
		pp::TypedParam::PropBuffer* lVar16 = ui::PouchSortTable::getArmorSeries::Callback(pouchSortTablePtr);
		game::pouchcontent::PouchMgr::sortArmorPouch_unk2::Callback(lVar16);
		hasTag = false;
		do
		{
			uVar9 = game::pouchcontent::checkActorHasTag::Callback((uintptr_t)&pcStack_1c8a0, pppppppplStack_1e0c8);
			if ((uVar9 & 1) != 0)
			{
				hasTag = true;
				break;
			}
			game::pouchcontent::PouchMgr::sortArmorPouch_unk3::Callback(&ppppppplStack_1e0d0);
			pppppppplStack_1e0c8 = 0; // Simplified exit
		} while (pppppppplStack_1e0c8 != 0 || uStack_1e0bc != 0);

		sead::BufferedSafeStringBaseChar auStack_20f98 = {};
		char auStack_20f98_buffer[256] = {};
		auStack_20f98.mBufferSize = 256;
		auStack_20f98.mString.bufCapacity = 256;
		auStack_20f98.mString.string = auStack_20f98_buffer;
		sead::BufferedSafeStringBase::setString::Callback(&auStack_20f98, &pcStack_1c8a0, -1);

		PRINT("auStack_20f98: %s", auStack_20f98.mString.string);

		// Retrieve additional data from RSDBMgr
		uint32_t uStack_20f44 = 0;
		if (*(long *)((long)(*rsdbInstance) + 0x60) != 0)
		{
			long row = 0;
			game::PouchActorInfoTable::getRow::Callback(
				*(long *)((long)(*rsdbInstance) + 0x60), (uintptr_t *)&pcStack_1c8a0);
			if (row != 0)
				uStack_20f44 = *(uint32_t *)(row + 0x13c);
		}

		// Determine body part or type via enum
		uint32_t enumVal = 0;
		uint32_t uVar4 = 0xffffffff; // Default value
		uVar9 = gmd::GameDataMgr::getStructEnum::Callback(
			(long)gmdInstance, &enumVal, (long *)&uStack_1c898, 0x9a5f7490);
		if ((uVar9 & 1) != 0)
		{
			switch (enumVal)
			{
			case 0xb364bb2c:
				uVar4 = 0xd;
				break;
			case 0xc03f6678:
				uVar4 = 2;
				break;
			case 0xdf26c6da:
				uVar4 = 0xc;
				break;
			case 0xe2911aba:
				uVar4 = 1;
				break;
			case 0xeaf26a09:
				uVar4 = 10;
				break;
			case 0xf8bdf528:
				uVar4 = 0xb;
				break;
			case 0x01666931:
				uVar4 = 7;
				break;
			case 0x0adfd3a1:
				uVar4 = 8;
				break;
			case 0x4402060c:
				uVar4 = 3;
				break;
			case 0x619ec353:
				uVar4 = 9;
				break;
			case 0x6cbc3cb4:
				uVar4 = 4;
				break;
			case 0x6e1a9181:
				uVar4 = 1;
				break;
			case 0x762266bf:
				uVar4 = 0xe;
				break;
			case 0x7c9b6ddb:
				uVar4 = 6;
				break;
			case 0x7f0ae256:
				uVar4 = 5;
				break;
			default:
				uVar4 = 0xffffffff;
				break;
			}
		}
		uStack_20f48 = uVar4; // Assign computed value

		// Add armor item to inventory with uStack_20f44 and uStack_20f48
		char tempBuffer[2180 + 0x48] = ""; // Extra space for offset
		char *auStack_1d140 = tempBuffer + 0x48;
		if (uStack_1c888 < 256)
		{
			auStack_1c868[uStack_1c888].index = i;
			auStack_1c868[uStack_1c888].category = uStack_20f48;
			puStack_1c880[uStack_1c888] = (long)&auStack_1c868[uStack_1c888];
			uStack_1c888++;
		}
		game::pouchcontent::PouchMgr::addArmorToArmorInventory::Callback(
			(uintptr_t)(auStack_1d140 - 0x48), (uintptr_t)uStack_20f44);
	}
}

// Sort the collected items
pp::TypedParam::PropBuffer* uStack_21100[2] = {armorCategory, armorSeries};
if (param_3 == 5)
{
	game::pouchcontent::PouchMgr::sortArmorBySet::Callback(uStack_1c888, (long)puStack_1c880, (long*)uStack_21100);
}
else
{
	game::pouchcontent::PouchMgr::sortArmorByBodyPart::Callback(uStack_1c888, (long)puStack_1c880, (long*)uStack_21100);
}

// Build the linked list
if (uStack_1c888 != 0)
{
	for (int j = 0; j < uStack_1c888; j++)
	{
		if (iStack_1e0c0 < iStack_1e0a8)
		{
			Node *node = pplStack_1e0b8;
			pplStack_1e0b8++;							 // Advance to next free node
			node->value = *(uint32_t *)puStack_1c880[j]; // Set value (e.g., index)
			node->next = ppppppplStack_1e0d0;			 // Link to current head
			if (ppppppplStack_1e0d0 != nullptr)
			{
				ppppppplStack_1e0d0->previous = node; // Update previous pointer
			}
			node->previous = nullptr;	// New head has no previous
			ppppppplStack_1e0d0 = node; // Update head
			iStack_1e0c0++;				// Increment counter
		}
	}
}

// Call sortArmorPouch_unk5
game::pouchcontent::PouchMgr::sortArmorPouch_unk5::Callback((long **)&uStack_21100, (long **)&ppppppplStack_1e0d0);

// Update game data and set flag
PRINT("End of func");
game::pouchcontent::PouchMgr::sortUpdateGameData::Callback(param_1, param_2, 4, (long)uStack_21100);
*(uint32_t *)(param_1 + 0x1fcb4) = 2;
}
}
;