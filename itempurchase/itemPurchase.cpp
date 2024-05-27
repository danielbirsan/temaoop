#include "itemPurchase.h"

ItemPurchase::ItemPurchase(std::string nameI, int price)
        : itemName(std::move(nameI)), itemPrice(price) {}

void ItemPurchase::purchaseItem() const {
    std::cout << "Congrats! You bought: " << itemName << " for " << itemPrice << " points." << std::endl;
}


std::string ItemPurchase::getItemName() const {
    return itemName;
}

int ItemPurchase::getItemPrice() const {
    return itemPrice;
}


ReducedItemPurchase::ReducedItemPurchase(std::string nameI, int price, int discountI)
        : ItemPurchase(std::move(nameI), price-discountI), discount(discountI) {}


void ReducedItemPurchase::purchaseItem() const {
    std::cout << "Congrats! You bought: " << getItemName() << " for " << getItemPrice() - discount << " points." << std::endl;
}

int ReducedItemPurchase::getItemPrice() const {
    return ItemPurchase::getItemPrice() - discount;
}

int ReducedItemPurchase::getDiscount() const {
    return discount;
}

std::string ReducedItemPurchase::getItemName() const {
    return ItemPurchase::getItemName();
}



