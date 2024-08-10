#include "screens.h"
class item{
    public:

};

class weapon : public item{
    public:
};

class clothing : public item{
    public:
};

class consumable : public item{
    public:
};

item* chest(Spreadsheet & chestsheet) {
    // Set chest item
    int selected_row = rand() % chestsheet.rows_size();
    
    // Prompt player for choice
    std::cout << "You have found a chest containing " << chestsheet.get_cell("name", selected_row) << std::endl;
    std::string input;
    std::cout << "Would you like to take this item? [Y] or [N]" << std::endl;
    while (true) {
        std::cin >> input;
        if (input == "N") return NULL;
        else if (input == "Y") break;
        else std::cout << "Please provide a correct response: [Y] or [N]" << std::endl;
    }

    // Player has chosen to take the item, create the object and return
    item* chest_item = NULL;
    if (chestsheet.get_cell("type", selected_row) == "weapon") chest_item = new weapon;
    else if (chestsheet.get_cell("type", selected_row) == "armour") chest_item = new clothing;
    else if (chestsheet.get_cell("type", selected_row) == "heal") chest_item = new consumable;
    else std::cerr << "unrecognised item type" << std::endl;
    return chest_item;
}