
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
    friend class ItemPurchaseBuilder;
};

class ReducedItemPurchase : public ItemPurchase {
private:
    int discount;

public:
    ReducedItemPurchase(std::string nameI, int price, int discountI);

    void purchaseItem() const override;

    [[nodiscard]] int getItemPrice() const override;


        [[nodiscard]] std::string getItemName() const override;


friend class ItemPurchaseBuilder;
};

class ItemPurchaseBuilder {
private:
    std::string itemName;
    int itemPrice;
    int discount;
    public:
    ItemPurchaseBuilder& setItemName(std::string nameI);


    ItemPurchaseBuilder& setItemPrice(int price) ;
    ItemPurchaseBuilder& setDiscount(int discountI) ;
    std::unique_ptr<ItemPurchase> buildItem() ;
    std::unique_ptr<ReducedItemPurchase> buildReducedItem() ;
};
#endif //OOP_ITEMPURCHASE_H
