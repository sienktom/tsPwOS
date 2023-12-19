#include <catch2/catch_test_macros.hpp>

#include "items_tests.h"

using namespace tspwos::items;


double MyItem::getWeight() {
    return 0.0;
}

double MyItem::getVolume()  {
    return 0.0;
}

double MyItem::getCapacity()  {
    return 0.0;
}


TEST_CASE("items may not be placed in items", "[items]") {
    auto item1 = std::make_shared<MyItem>();
    auto item2 = std::make_shared<MyItem>();
    REQUIRE_THROWS_AS(item1->addComponent(item2), ItemsInvalidOperationException);
    REQUIRE_THROWS_AS(item1->contains(item2), ItemsInvalidOperationException);
}

TEST_CASE("items may not be removed from items", "[items]") {
    auto item1 = std::make_shared<MyItem>();
    auto item2 = std::make_shared<MyItem>();
    REQUIRE_THROWS_AS(item1->removeComponent(item2), ItemsInvalidOperationException);
}

TEST_CASE("items may be placed in item composite", "[items]") {
    auto item = std::make_shared<MyItem>();
    auto container = std::make_shared<ItemComposite>();
    REQUIRE_NOTHROW(container->addComponent(item));
    REQUIRE(true == container->contains(item));
}

TEST_CASE("items may be removed from item composite", "[items]") {
    auto item = std::make_shared<MyItem>();
    auto container = std::make_shared<ItemComposite>();
    container->addComponent(item);
    REQUIRE_NOTHROW(container->removeComponent(item));
    REQUIRE(false == container->contains(item));
}

TEST_CASE("item composite may not be placed in items", "[items]") {
    auto item = std::make_shared<MyItem>();
    auto container = std::make_shared<ItemComposite>();
    REQUIRE_THROWS_AS(item->addComponent(container), ItemsInvalidOperationException);
    REQUIRE_THROWS_AS(item->contains(container), ItemsInvalidOperationException);
}

TEST_CASE("item composite may not be removed from items", "[items]") {
    auto item = std::make_shared<MyItem>();
    auto container = std::make_shared<ItemComposite>();
    REQUIRE_THROWS_AS(item->removeComponent(container), ItemsInvalidOperationException);
}

TEST_CASE("item composite may be placed in item composite", "[items]") {
    auto container1 = std::make_shared<ItemComposite>();
    auto container2 = std::make_shared<ItemComposite>();
    REQUIRE_NOTHROW(container1->addComponent(container2));
    REQUIRE(true == container1->contains(container2));
}

TEST_CASE("item composite may be removed from item composite", "[items]") {
    auto container1 = std::make_shared<ItemComposite>();
    auto container2 = std::make_shared<ItemComposite>();
    container1->addComponent(container2);
    REQUIRE_NOTHROW(container1->removeComponent(container2));
    REQUIRE(false == container1->contains(container2));
}


TEST_CASE("small stone has its own default weight and volume and zero capacity", "[items]") {
    auto smallStone = std::make_shared<SmallStone>();
    REQUIRE(SmallStone::DEFAULT_WEIGHT == smallStone->getWeight());
    REQUIRE(SmallStone::DEFAULT_VOLUME == smallStone->getVolume());
    REQUIRE(0 == smallStone->getCapacity());
}
