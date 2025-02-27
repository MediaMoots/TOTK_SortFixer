#pragma once

#include "fs_types.hpp"

namespace nn::fs {

    /*
        Mount SD card. Must have explicit permission.
        mount: drive to mount to.
    */
    Result MountSdCardForDebug(char const* mount);

    Result MountSdCard(const char *drive);

    /*
    Unmounts the given drive.
    mount: drive to unmount.
*/
    void Unmount(const char* mount);
};