#include "include/items.h"

namespace tspwos::items {

    void Item::addComponent(const ItemPtr& /*newItem*/) {
        throw ItemsInvalidOperationException{};
    }

    void Item::removeComponent(const ItemPtr& /*existingComponent*/) {
        throw ItemsInvalidOperationException{};
    }

}
