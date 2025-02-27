#include "binaryoffsethelper.hpp"
#include "utils.hpp"

namespace sort::helpers
{
    char sAppVersion[0x10] = {};
    u32 sAppVersionIndex = 0xffff'ffff;

    u32 InitializeAppVersion()
    {
        /* Get Version */
        nn::oe::DisplayVersion displayVersion;
        nn::oe::GetDisplayVersion(&displayVersion);
        strcpy(sAppVersion, displayVersion.name);

        /* Check for supported app version */
	    sAppVersionIndex = 0xffff'ffff;

        if (strncmp(sAppVersion, GAME_VERSION_1_0_0, 16) == 0)
        {
            sAppVersionIndex = 0;
        }
        else if (strncmp(sAppVersion, GAME_VERSION_1_1_0, 16) == 0)
        {
            sAppVersionIndex = 1;
        }
        else if (strncmp(sAppVersion, GAME_VERSION_1_1_1, 16) == 0)
        {
            sAppVersionIndex = 2;
        }
        else if (strncmp(sAppVersion, GAME_VERSION_1_1_2, 16) == 0)
        {
            sAppVersionIndex = 3;
        }
        else if (strncmp(sAppVersion, GAME_VERSION_1_2_0, 16) == 0)
        {
            sAppVersionIndex = 4;
        }
        else if (strncmp(sAppVersion, GAME_VERSION_1_2_1, 16) == 0)
        {
            sAppVersionIndex = 5;
        }
        return sAppVersionIndex;
    }
}