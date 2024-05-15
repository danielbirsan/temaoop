
#ifndef OOP_ITEMPURCHASE_H
#define OOP_ITEMPURCHASE_H
#include <utility>

#include "../purchasemanager/purchaseManager.h"


class ItemPurchase : public PurchaseManager {
private:
    std::string itemName;
    int itemPrice;

public:
    explicit ItemPurchase(std::string nameI, int price)
            : itemName(std::move(nameI)), itemPrice(price) {}

    void purchaseItem( ) const override {
        std::cout << "Congrats! You bought: " << itemName << " for " << itemPrice << " points." << std::endl;
    }

    [[nodiscard]] std::string getItemName() const override {
        return itemName;
    }

    [[nodiscard]] int getItemPrice() const {
        return itemPrice;
    }
};


#endif //OOP_ITEMPURCHASE_H
