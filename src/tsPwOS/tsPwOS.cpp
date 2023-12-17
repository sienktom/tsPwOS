#include <iostream>

#include "include/tsPwOS.h"

void itemsTest();

int main(int /*argc*/, char* /*argv*/[]) {
    std::cout << "tsPwOS - Przetrwaj w otwartym świecie..." << std::endl;

    itemsTest();

    return EXIT_SUCCESS;
}

void itemsTest() {
    std::cout << "itemsTest..." << std::endl;

    using namespace tspwos::items;

//    auto leaf1 = std::make_shared<Leaf>(); leaf1->name = "leaf1";
//    auto leaf2 = std::make_shared<Leaf>(); leaf2->name = "leaf2";
//    auto leaf3 = std::make_shared<Leaf>(); leaf3->name = "leaf3";
//    auto leaf4 = std::make_shared<Leaf>(); leaf4->name = "leaf4";
//    auto leaf5 = std::make_shared<Leaf>(); leaf5->name = "leaf5";
//    auto leaf6 = std::make_shared<Leaf>(); leaf6->name = "leaf6";
//
//    auto composite1 = std::make_shared<Composite>(); composite1->name = "composite1";
//    auto composite2 = std::make_shared<Composite>(); composite2->name = "composite2";
//    auto composite3 = std::make_shared<Composite>(); composite3->name = "composite3";
//
//    composite3->addComponent(leaf4);
//    composite3->addComponent(leaf5);
//    composite3->addComponent(leaf6);
//
//    composite2->addComponent(leaf2);
//    composite2->addComponent(leaf3);
//    composite2->addComponent(composite3);
//
//    composite1->addComponent(leaf1);
//    composite1->addComponent(composite2);
//
//    composite1->operation();
}
