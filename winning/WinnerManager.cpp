#include "WinnerManager.h"


template <typename T>
void WinnerManager<T>::finalizeGame() {
    std::cout << "You have chosen to skip the purchase." << std::endl;
    std::cout << "Thank you for playing!" << std::endl;
}

template <typename T>
void WinnerManager<T>::manageWinner(T& player, const std::string& secretWord) {
    std::cout << player.getName() << " has got 30 extra points!" << std::endl;
    player.setPoints(player.getPoints() + 30);
    std::cout << "Congratulations! Player " << player.getName() << " won! The word was: " << secretWord << std::endl;
    std::cout << "Player " << player.getName() << " has " << player.getPoints() << " points!" << std::endl;
    ItemPurchaseBuilder builder;
    std::unique_ptr<ItemPurchase> foritem = builder.setItemName("Knife").setItemPrice(10).buildItem();
    std::unique_ptr<ItemPurchase> specialItem = builder.setItemName("Oven").setItemPrice(20).buildItem();
    std::unique_ptr<ItemPurchase> premiumItem = builder.setItemName("Fridge").setItemPrice(30).buildItem();
    std::unique_ptr<ItemPurchase> reducedItem = builder.setItemName("Microwave").setItemPrice(30).setDiscount(7).buildReducedItem();

    static std::vector<std::unique_ptr<PurchaseManager>> purchases;
    std::vector<std::unique_ptr<PurchaseManager>> boughtItems;
    purchases.push_back(std::move(foritem));
    purchases.push_back(std::move(specialItem));
    purchases.push_back(std::move(premiumItem));
    purchases.push_back(std::move(reducedItem));

    while (player.getPoints() > 9) {
        int purchaseIndex = 0;
        std::cout << "You have " << player.getPoints() << " points." << std::endl;
        std::cout << "Choose an item to purchase "<< " ( "<<purchases.size()<<" - Skip):" << std::endl;
        for (unsigned int i = 0; i < purchases.size(); ++i) {
            std::cout << i << " - " << purchases[i]->getItemName() << " (" << purchases[i]->getItemPrice() << " points)" << std::endl;
        }
        if (!(std::cin >> purchaseIndex) || purchaseIndex < 0 || purchaseIndex > (int)purchases.size()){

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw InvalidInputException(" Bad luck!");

        }

        if (purchaseIndex == (int)purchases.size()) {
            finalizeGame();

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


            auto* item = new ItemPurchase(itemPtr->getItemName(), itemPtr->getItemPrice());
            boughtItems.push_back(std::unique_ptr<PurchaseManager>(item));

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
template class WinnerManager<EasyPlayer>;
template class WinnerManager<HardPlayer>;
template class WinnerManager<MediumPlayer>;

