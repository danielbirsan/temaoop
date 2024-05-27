
#ifndef OOP_ITEMPURCHASE_H
#define OOP_ITEMPURCHASE_H

#include <utility>
#include <memory>

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

class ReducedItemPurchase : public ItemPurchase {
private:
    int discount;

public:
    ReducedItemPurchase(std::string nameI, int price, int discountI);

    void purchaseItem() const override;

    [[nodiscard]] int getItemPrice() const override;

        [[nodiscard]] int getDiscount() const;

        [[nodiscard]] std::string getItemName() const override;

};
#endif //OOP_ITEMPURCHASE_H
