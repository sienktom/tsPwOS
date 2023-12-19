#include <algorithm>

#include "include/items.h"

namespace tspwos::items {

    void Item::addComponent(const ItemPtr& /*newItem*/) {
        throw ItemsInvalidOperationException{};
    }

    void Item::removeComponent(const ItemPtr& /*existingComponent*/) {
        throw ItemsInvalidOperationException{};
    }

    bool Item::contains(const ItemPtr& /*item*/) {
        throw ItemsInvalidOperationException{};
    }

    double Item::getTotalWeight() {
        return getWeight();
    }

    double Item::getCapacity() {
        return 0.0;
    }

    double Item::getTotalCapacity() {
        return getCapacity();
    }


    void ItemComposite::addComponent(const ItemPtr& newItem) {
        if(newItem) {
            children.push_back(newItem);
        }
    }

    void ItemComposite::removeComponent(const ItemPtr& existingComponent) {
        for (auto it = children.begin(); it != children.end();) {
            if(*it == existingComponent) {
                it = children.erase(it);
            } else {
                ++it;
            }
        }
    }

    bool ItemComposite::contains(const ItemPtr& item) {
        return std::find(children.begin(), children.end(), item) != children.end();
    }

    double ItemComposite::getCapacity() {
        return Item::getCapacity();
    }

    double ItemComposite::getTotalWeight() {
        auto weight = getWeight();
        for(const auto& component : children) {
            weight += component->getWeight();
        }
        return weight;
    }

    double ItemComposite::getTotalCapacity() {
        auto capacity = getCapacity();
        for(const auto& component : children) {
            capacity -= component->getVolume();
        }
        return capacity;
    }


    double SmallStone::getWeight() {
        return SmallStone::DEFAULT_WEIGHT;
    }

    double SmallStone::getVolume() {
        return SmallStone::DEFAULT_VOLUME;
    }


    double SmallChest::getWeight() {
        return SmallChest::DEFAULT_WEIGHT;
    }

    double SmallChest::getVolume() {
        return SmallChest::DEFAULT_VOLUME;
    }

    double SmallChest::getCapacity() {
        return SmallChest::DEFAULT_CAPACITY;
    }

}
