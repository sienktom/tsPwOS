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

}
