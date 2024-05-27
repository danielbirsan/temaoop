
#ifndef OOP_ITEMPURCHASE_H
#define OOP_ITEMPURCHASE_H

#include <utility>

#include "../purchasemanager/purchaseManager.h"

class ItemPurchase : public PurchaseManager {
private:
    std::string itemName;
    int itemPrice;

public:
    explicit ItemPurchase(std::string nameI, int price);

    void purchaseItem() const override;

    [[nodiscard]] std::string getItemName() const override;

    [[nodiscard]] int getItemPrice() const override;

};

#endif //OOP_ITEMPURCHASE_H
