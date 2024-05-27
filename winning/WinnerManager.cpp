#include "WinnerManager.h"

template <typename T>
void WinnerManager<T>::manageWinner(T& player, const std::string& secretWord) {
    std::cout << player.getName() << " has got 30 extra points!" << std::endl;
    player.setPoints(player.getPoints() + 30);

    std::cout << "Congratulations! Player " << player.getName() << " won! The word was: " << secretWord << std::endl;
    std::cout << "Player " << player.getName() << " has " << player.getPoints() << " points!" << std::endl;

    std::unique_ptr<PurchaseManager> itemPurchase = std::make_unique<ItemPurchase>("Knife", 10);
    std::unique_ptr<PurchaseManager> specialItemPurchase = std::make_unique<ItemPurchase>("Oven", 20);
    std::unique_ptr<PurchaseManager> premiumItemPurchase = std::make_unique<ItemPurchase>("Fridge", 30);
    std::unique_ptr<PurchaseManager> reducedItemPurchase = std::make_unique<ItemPurchase>("Microwave", 5);
    static std::vector<std::unique_ptr<PurchaseManager>> purchases;
    std::vector<std::unique_ptr<PurchaseManager>> boughtItems;
    purchases.push_back(std::move(itemPurchase));
    purchases.push_back(std::move(specialItemPurchase));
    purchases.push_back(std::move(premiumItemPurchase));
    purchases.push_back(std::move(reducedItemPurchase));

    while (player.getPoints() > 0) {
        int purchaseIndex = 0;
        std::cout << "You have " << player.getPoints() << " points." << std::endl;
        std::cout << "Choose an item to purchase (4 - Skip):" << std::endl;
        for (unsigned int i = 0; i < purchases.size(); ++i) {
            std::cout << i << " - " << purchases[i]->getItemName() << " (" << purchases[i]->getItemPrice() << " points)" << std::endl;
        }
        if (!(std::cin >> purchaseIndex) || purchaseIndex < 0 || purchaseIndex > 4) {
            std::cout << "Invalid input! Please enter a valid number between 0 and 4." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw InvalidInputException("Invalid input! Please enter a valid number between 0 and 3.");

        }

        if (purchaseIndex == 4) {
            break;
        }

        try {
            auto itemPtr = dynamic_cast<ItemPurchase*>(purchases[purchaseIndex].get());
            if (!itemPtr) {
                throw std::runtime_error("Failed to cast PurchaseManager to ItemPurchase.");
            }
            if (player.getPoints() < 0 ){
                throw NegativePointsException("You have negative points! You can't buy anything!");
            }
            if (player.getPoints() < itemPtr->getItemPrice()) {
                throw InsufficientPointsException("You don't have enough points to buy this item!");
            }
            if (std::find_if(boughtItems.begin(), boughtItems.end(), [&](const std::unique_ptr<PurchaseManager>& item) {
                return item->getItemName() == itemPtr->getItemName();
            }) != boughtItems.end()) {
                throw PurchaseException("You already bought this item!");
            }

            itemPtr->purchaseItem();
            player.setPoints(player.getPoints() - itemPtr->getItemPrice());

            //to fix
            //boughtItems.push_back(std::move(purchases[purchaseIndex]));

        } catch(const NegativePointsException& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (InvalidInputException& e){
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (const InsufficientPointsException& e) {
            std::cerr << "Error: " << e.what() << std::endl;

        } catch (const PurchaseException& e) {
            std::cerr << "General purchase error: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Unexpected error: " << e.what() << std::endl;
        }
    }
}

template class WinnerManager<Player>;
