#include "WinnerManager.h"


template <typename T>
void WinnerManager<T>::manageWinner(T& player, const std::string& secretWord) {
    std::cout << player.getName()<< " has got 30 extra points!" << std::endl;
    player.setPoints(player.getPoints() + 30);
    std::cout << "Congratulations! Player " << player.getName() << " won! The word was: " << secretWord << std::endl;
    std::cout << "Player " << player.getName() << " has " << player.getPoints() << " points!" << std::endl;

    std::vector<std::unique_ptr<ItemPurchase>> items;
    items.push_back(std::make_unique<ItemPurchase>("Oven", 10));
    items.push_back(std::make_unique<ItemPurchase>("Fridge", 20));
    items.push_back(std::make_unique<ItemPurchase>("Knife", 30));

    while (player.getPoints() >=10) {
        try {
            int itemIndex = 0;
            std::cout << "Choose an item to purchase (3 - Skip): " << std::endl;
            std::cout << "You have " << player.getPoints() << " points." << std::endl;
            for (int i = 0; i < items.size(); i++) {
                std::cout << i << " - " << items[i]->getItemName() << " (" << items[i]->getItemPrice() << " points)"
                          << std::endl;
            }

            try {
                if (!(std::cin >> itemIndex) || itemIndex < 0 || itemIndex > 3) {
                    std::cout << "Invalid input! Please enter a valid number between 0 and 3." << std::endl;

                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw InvalidInputException("   Please enter a valid number between 0 and 3.");
                }
            }
            catch (InvalidInputException &e) {
                std::cerr << e.what() << std::endl;
                continue;
            }

            if (itemIndex == 3) {
                break;
            }

try {
    if (player.getPoints() < items[itemIndex]->getItemPrice()) {
        throw InsufficientPointsException("You don't have enough points to purchase this item!");

    }

    player.setPoints(player.getPoints() - items[itemIndex]->getItemPrice());
    items[itemIndex]->purchaseItem();
    std::cout << "Total points: " << player.getPoints() << std::endl;


    if (player.getPoints() < 0) {
        throw NegativePointsException("You don't have enough points to purchase this item!");
    }


}catch (InsufficientPointsException &e) {
    std::cerr<< e.what() << std::endl;
}

    }
    catch (NegativePointsException &e) {
        std::cerr << e.what() << std::endl;
        break;
    }
    }

}
