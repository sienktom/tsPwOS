#pragma once

#include "include\items.h"

namespace tspwos::items {

    class MyItem : public Item {
    public:
        double getWeight() override;
        double getVolume() override;
        double getCapacity() override;
    };

}
