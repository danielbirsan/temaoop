#include "WinnerManager.h"
#include <memory>
template <class T>
class Checker{
public:
    Checker() = default;
    virtual ~Checker() = default;

    static void throwIfNotPositive(T);
    static void throwIfNotInRange(T, T, T, const std::string& = "Numarul");
};
template <class T>
void Checker<T>::throwIfNotPositive(T value) {
    if (value < 0) {
        throw std::runtime_error("Numarul trebuie sa fie pozitiv!");
    }
}
template <class T>
void Checker<T>::throwIfNotInRange(T value, T a, T b, const std::string& ob_name) {
    if (value<a || value>b) {
        throw std::runtime_error(ob_name+" trebuie sa fie in intervaulul ["+std::to_string(a)+", "+std::to_string(b)+"]");
    }
}

template <typename T>
void WinnerManager<T>::finalizeGame() {
    std::cout << "You have chosen to skip the purchase." << std::endl;
    std::cout << "Thank you for playing!" << std::endl;
}

template <typename T>
void WinnerManager<T>::manageWinner(T& player, const std::string& secretWord) {
    std::cout << player.getName() << " has got 30 extra points!" << std::endl;
    player.earnPoints(player.getPoints() + 30);
    std::cout << "Congratulations! Player " << player.getName() << " won! The word was: " << secretWord << std::endl;
    std::cout << "Player " << player.getName() << " has " << player.getPoints() << " points!" << std::endl;
    ItemPurchaseBuilder builder;
    std::unique_ptr<ItemPurchase> foritem = builder.setItemName("Knife").setItemPrice(10).buildItem();
    std::unique_ptr<ItemPurchase> specialItem = builder.setItemName("Oven").setItemPrice(20).buildItem();
    std::unique_ptr<ItemPurchase> premiumItem = builder.setItemName("Fridge").setItemPrice(30).buildItem();
    std::unique_ptr<ItemPurchase> reducedItem = builder.setItemName("Microwave").setItemPrice(30).setDiscount(7).buildReducedItem();
    static std::vector<std::unique_ptr<ItemPurchase>> purchases;
    static std::vector<std::unique_ptr<ItemPurchase>> boughtItems;
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
            Checker<int>::throwIfNotPositive(purchaseIndex);
            Checker<int>::throwIfNotInRange(purchaseIndex, 0, (int)purchases.size(), "Indexul");

        }

        if (purchaseIndex == (int)purchases.size()) {
            finalizeGame();

            break;
        }

        try {
            auto itemPtr = dynamic_cast<ItemPurchase*>(purchases[purchaseIndex].get());

            if (player.getPoints() < 0 ){
                throw NegativePointsException("You have negative points! You can't buy anything!");
            }
            if (player.getPoints() < itemPtr->getItemPrice()) {
                throw InsufficientPointsException("You don't have enough points to buy this item!");
            }
            if (std::find_if(boughtItems.begin(), boughtItems.end(), [&](const std::unique_ptr<ItemPurchase>& item) {
                return item->getItemName() == itemPtr->getItemName();
            }) != boughtItems.end()) {
                throw PurchaseException("You already bought this item!");
            }

            itemPtr->purchaseItem();
            player.earnPoints(player.getPoints() - itemPtr->getItemPrice());

            std::unique_ptr<ItemPurchase> item = std::make_unique<ItemPurchase>(*itemPtr);
            boughtItems.push_back(std::move(item));


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

