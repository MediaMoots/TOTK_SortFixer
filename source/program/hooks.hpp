#pragma once

#include "binaryoffsethelper.hpp"
#include "config.hpp"
#include "lib.hpp"
#include "utils.hpp"

namespace gmd::GameDataMgr {
static void** GetInstancePtr()
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
		return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v121>();
	default: // Default to latest version
		return exl::util::pointer_path::FollowSafe<void*, s_GMDInstanceOffset_v121>();
	}
}
}