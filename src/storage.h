#ifndef STORAGE_H
#define STORAGE_H

#include "include.h"
#include "csvparser.h"
#include "screens.h"

class Storage {

    private:
    // Vector of pointers to item class
    std::vector<Item *> items;
    double max_mass_capacity;
    double current_mass_capacity;

    public:
    const std::string storage_type;
    Storage (const std::string & storage_type);
    bool try_add_item (Item * item);
    bool remove_item (Item * item);
    void list_items();
};

class Storage_controller {

    private:
    Storage * storageA;
    Storage * storageB;

    public:
    Storage_controller (Storage * storage);
    Storage_controller (Storage * storageA, Storage * storageB);

    bool select_storage ();
    bool select_item ();
    
    bool item_transfer_loop ();
};

#endif