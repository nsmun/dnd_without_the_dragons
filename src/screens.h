#include "include.h"
#include "csvparser.h"

class Item {
    public:
    std::unordered_map<std::string, std::variant<int, double, std::string>> item_details;
};

class weapon : public Item {
    public:
    weapon(Spreadsheet & chestsheet, int selected_row) {
        item_details["name"] = std::string(chestsheet.get_cell("name", selected_row));
        item_details["stat"] = atoi(chestsheet.get_cell("stat", selected_row).c_str());
        item_details["wear_min"] = atoi(chestsheet.get_cell("wear_min", selected_row).c_str());
        item_details["wear_max"] = atoi(chestsheet.get_cell("wear_max", selected_row).c_str());
        item_details["mass"] = atoi(chestsheet.get_cell("mass", selected_row).c_str());
        item_details["stackable"] = atoi(chestsheet.get_cell("stackable", selected_row).c_str());
    }
};

class clothing : public Item{
    public:
    clothing(Spreadsheet & chestsheet, int selected_row) {
        item_details["name"] = std::string(chestsheet.get_cell("name", selected_row));
        item_details["stat"] = atoi(chestsheet.get_cell("stat", selected_row).c_str());
        item_details["wear_min"] = atoi(chestsheet.get_cell("wear_min", selected_row).c_str());
        item_details["wear_max"] = atoi(chestsheet.get_cell("wear_max", selected_row).c_str());
        item_details["mass"] = atoi(chestsheet.get_cell("mass", selected_row).c_str());
        item_details["stackable"] = atoi(chestsheet.get_cell("stackable", selected_row).c_str());
    }
};

class consumable : public Item{
    public:
    consumable(Spreadsheet & chestsheet, int selected_row) {
        item_details["name"] = std::string(chestsheet.get_cell("name", selected_row));
        item_details["stat"] = atoi(chestsheet.get_cell("stat", selected_row).c_str());
        item_details["wear_min"] = atoi(chestsheet.get_cell("wear_min", selected_row).c_str());
        item_details["wear_max"] = atoi(chestsheet.get_cell("wear_max", selected_row).c_str());
        item_details["mass"] = atoi(chestsheet.get_cell("mass", selected_row).c_str());
        item_details["stackable"] = atoi(chestsheet.get_cell("stackable", selected_row).c_str());
    }
};

Item* chest(Spreadsheet & chestsheet) {
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
    Item* chest_item = NULL;
    if (chestsheet.get_cell("type", selected_row) == "weapon") chest_item = new weapon(chestsheet, selected_row);
    else if (chestsheet.get_cell("type", selected_row) == "armour") chest_item = new clothing(chestsheet, selected_row);
    else if (chestsheet.get_cell("type", selected_row) == "heal") chest_item = new consumable(chestsheet, selected_row);
    else std::cerr << "unrecognised item type" << std::endl;
    return chest_item;
}