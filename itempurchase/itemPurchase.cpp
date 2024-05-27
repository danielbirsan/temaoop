#include "ItemPurchase.h"

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

