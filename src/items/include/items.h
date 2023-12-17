#pragma once

#include <exception>
#include <memory>

namespace tspwos::items {

    class ItemsInvalidOperationException : public std::exception {};

    class Item;
    using ItemPtr = std::shared_ptr<Item>;

    class Item {
    public:
        virtual void addComponent(ItemPtr newItem);
        //virtual void operation() = 0;
        //virtual void removeComponent(std::shared_ptr<Component> existingComponent);
        //virtual std::shared_ptr<Component> getChild(size_t index);
        //std::string name{};
    };

    //class ItemComposite : public Item {
    //public:
        //void operation() override;
        //void addComponent(ItemPtr newItem) override;
        //void removeComponent(std::shared_ptr<Component> existingComponent) override;
        //std::shared_ptr<Component> getChild(size_t index) override;
    //private:
        //std::vector<std::shared_ptr<Component>> children{};
    //};

}
