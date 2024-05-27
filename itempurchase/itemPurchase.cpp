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
    std::cout << "Congrats! You bought: " << getItemName() << " for " << getItemPrice() << " points " <<"with "<<discount<<" reduced points." << std::endl;
}

int ReducedItemPurchase::getItemPrice() const {
    return ItemPurchase::getItemPrice();
}


std::string ReducedItemPurchase::getItemName() const {
    return ItemPurchase::getItemName();
}


ItemPurchaseBuilder& ItemPurchaseBuilder::setItemName(std::string nameI) {
    itemName = std::move(nameI);
    return *this;
}

ItemPurchaseBuilder& ItemPurchaseBuilder::setItemPrice(int price) {
    itemPrice = price;
    return *this;
}

ItemPurchaseBuilder& ItemPurchaseBuilder::setDiscount(int discountI) {
    discount = discountI;
    return *this;
}

std::unique_ptr<ItemPurchase> ItemPurchaseBuilder::buildItem() {

     return std::make_unique<ItemPurchase>(itemName, itemPrice);
}
std::unique_ptr<ReducedItemPurchase> ItemPurchaseBuilder::buildReducedItem() {
    return std::make_unique<ReducedItemPurchase>(itemName, itemPrice, discount);
}







