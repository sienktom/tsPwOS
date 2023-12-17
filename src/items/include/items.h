#pragma once

#include <exception>
#include <memory>
#include <vector>

namespace tspwos::items {

    class ItemsInvalidOperationException : public std::exception {};

    class Item;
    using ItemPtr = std::shared_ptr<Item>;

    class Item {
    public:
        //virtual void operation() = 0;
        virtual void addComponent(const ItemPtr& newItem);
        virtual void removeComponent(const ItemPtr& existingComponent);
        //virtual std::shared_ptr<Component> getChild(size_t index);
        //std::string name{};
        virtual bool contains(const ItemPtr& item);
    };

    class ItemComposite : public Item {
    public:
        //void operation() override;
        void addComponent(const ItemPtr& newItem) override;
        void removeComponent(const ItemPtr& existingComponent) override;
        //std::shared_ptr<Component> getChild(size_t index) override;
        bool contains(const ItemPtr& item) override;
    private:
        std::vector<ItemPtr> children{};
    };

}
