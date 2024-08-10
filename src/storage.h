#include "include.h"
#include "csvparser.h"

class storage {
    private:
    // Vector of pointers to item class
    // std::vector<item*> items;

    public:
    const std::string storage_type;
    storage (const std::string & storage_type);
};