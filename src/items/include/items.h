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
        virtual double getWeight() = 0;
        virtual double getVolume() = 0;
        virtual double getCapacity() = 0;
        virtual void addComponent(const ItemPtr& newItem);
        virtual void removeComponent(const ItemPtr& existingComponent);
        //virtual std::shared_ptr<Component> getChild(size_t index);
        //std::string name{};
        virtual bool contains(const ItemPtr& item);
    };

    class ItemComposite : public Item {
    public:
        double getWeight() override;
        double getVolume() override;
        double getCapacity() override;
        void addComponent(const ItemPtr& newItem) override;
        void removeComponent(const ItemPtr& existingComponent) override;
        //std::shared_ptr<Component> getChild(size_t index) override;
        bool contains(const ItemPtr& item) override;
    protected:
        std::vector<ItemPtr> children{};
    };


    class SmallStone : public Item {
    public:
        static constexpr double DEFAULT_WEIGHT = 100;
        static constexpr double DEFAULT_VOLUME = 100;
        double getWeight() override;
        double getVolume() override;
        double getCapacity() override;
    };


    class SmallChest : public ItemComposite {
    public:
        static constexpr double DEFAULT_WEIGHT = 350;
        static constexpr double DEFAULT_VOLUME = 5000;
        static constexpr double DEFAULT_CAPACITY = 4800;
        double getWeight() override;
        double getVolume() override;
        double getCapacity() override;
    };

}
