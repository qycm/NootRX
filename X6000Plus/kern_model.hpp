//  Copyright © 2023 ChefKiss Inc. Licensed under the Thou Shalt Not Profit License version 1.5. See LICENSE for
//  details.

#ifndef kern_model_hpp
#define kern_model_hpp
#include <Headers/kern_util.hpp>

struct Model {
    uint16_t rev {0};
    const char *name {nullptr};
};

struct DevicePair {
    uint16_t dev;
    const Model *models;
    size_t modelNum;
};

static constexpr Model dev73A5[] = {
    {0xC0, "AMD Radeon RX 6950 XT"},
};

static constexpr Model dev73AF[] = {
    {0xC0, "AMD Radeon RX 6900 XTXH"},
};

static constexpr Model dev73BF[] = {
    {0xC0, "AMD Radeon RX 6900 XT"},
    {0xC1, "AMD Radeon RX 6800 XT"},
    {0xC3, "AMD Radeon RX 6800"},
};

static constexpr Model dev73DF[] = {
    {0xC0, "AMD Radeon RX 6750 XT"},
    {0xC1, "AMD Radeon RX 6700 XT"},
    {0xC2, "AMD Radeon RX 6800M"},
    {0xC3, "AMD Radeon RX 6800M"},
    {0xC5, "AMD Radeon RX 6700 XT"},
    {0xCF, "AMD Radeon RX 6700M"},
    {0xDF, "AMD Radeon RX 6700"},
    {0xFF, "AMD Radeon RX 6700"},
};

static constexpr Model dev73EF[] = {
    {0xC0, "AMD Radeon RX 6800S"},
    {0xC1, "AMD Radeon RX 6650 XT"},
    {0xC2, "AMD Radeon RX 6700S"},
    {0xC3, "AMD Radeon RX 6650M"},
    {0xC4, "AMD Radeon RX 6650M XT"},
};

static constexpr DevicePair devices[] = {
    {0x73A5, dev73A5, arrsize(dev73A5)},
    {0x73AF, dev73AF, arrsize(dev73AF)},
    {0x73BF, dev73BF, arrsize(dev73BF)},
    {0x73DF, dev73DF, arrsize(dev73DF)},
    {0x73EF, dev73EF, arrsize(dev73EF)},
};

inline const char *getBranding(uint16_t dev, uint16_t rev) {
    for (auto &device : devices) {
        if (device.dev == dev) {
            for (size_t i = 0; i < device.modelNum; i++) {
                auto &model = device.models[i];
                if (model.rev == rev) { return model.name; }
            }
            break;
        }
    }
    return "AMD Radeon RX 6000 Series";
}

#endif /* kern_model_hpp */
