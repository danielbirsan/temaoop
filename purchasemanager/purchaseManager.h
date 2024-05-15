

#ifndef OOP_PURCHASEMANAGER_H
#define OOP_PURCHASEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class PurchaseManager {
public:
    virtual ~PurchaseManager() = default;

    virtual void purchaseItem() const = 0;

    [[nodiscard]] virtual std::string getItemName() const = 0;

    [[nodiscard]] virtual int getItemPrice() const = 0;
};


#endif //OOP_PURCHASEMANAGER_H
