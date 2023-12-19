#pragma once

#include "include\items.h"

namespace tspwos::items {

    class MyItem : public Item {
    public:
        double getWeight() override;
        double getVolume() override;
    };

    class MyItemComposite : public ItemComposite {
    public:
        double getWeight() override;
        double getVolume() override;
    };

}
