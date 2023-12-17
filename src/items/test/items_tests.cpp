#include <catch2/catch_test_macros.hpp>

#include "include\items.h"

using namespace tspwos::items;

TEST_CASE("items may not be placed in items", "[items]") {
    auto item1 = std::make_shared<Item>();
    auto item2 = std::make_shared<Item>();
    REQUIRE_THROWS_AS(item1->addComponent(item2), ItemsInvalidOperationException);
    REQUIRE_THROWS_AS(item1->contains(item2), ItemsInvalidOperationException);
}

TEST_CASE("items may not be removed from items", "[items]") {
    auto item1 = std::make_shared<Item>();
    auto item2 = std::make_shared<Item>();
    REQUIRE_THROWS_AS(item1->removeComponent(item2), ItemsInvalidOperationException);
}

TEST_CASE("items may be placed in item composite", "[items]") {
    auto item = std::make_shared<Item>();
    auto container = std::make_shared<ItemComposite>();
    REQUIRE_NOTHROW(container->addComponent(item));
    REQUIRE(true == container->contains(item));
}

TEST_CASE("items may be removed from containers", "[items]") {
    auto item = std::make_shared<Item>();
    auto container = std::make_shared<ItemComposite>();
    container->addComponent(item);
    REQUIRE_NOTHROW(container->removeComponent(item));
    REQUIRE(false == container->contains(item));
}

TEST_CASE("containers may not be placed in items", "[items]") {
    auto item = std::make_shared<Item>();
    auto container = std::make_shared<ItemComposite>();
    REQUIRE_THROWS_AS(item->addComponent(container), ItemsInvalidOperationException);
    REQUIRE_THROWS_AS(item->contains(container), ItemsInvalidOperationException);
}

// jeśli sensowny to dodać: TEST_CASE("containers may not be removed from items", "[items]")
// jeśli sensowny to dodać: TEST_CASE("containers may be placed in containers", "[items]")
// jeśli sensowny to dodać: TEST_CASE("containers may be removed from containers", "[items]")
