#pragma once

#include <nn/nn_common.hpp>

namespace nn::oe {

    struct DisplayVersion {
        char name[16];
    };

    void GetDisplayVersion(DisplayVersion*);
}