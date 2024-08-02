#include "include.h"


class Spreadsheet{
    private:
    std::vector<std::vector<std::string>> rows;
    std::vector<std::string> column_names;

    
    std::string file_path;
    bool using_column_names;
    bool parser ();

    public:

    Spreadsheet (std::string path);
    Spreadsheet (std::string path, bool column_names);
    std::string get_cell (int column, int row);
    std::string get_cell (std::string column_name, int row);


};

// Spreadsheet my_spreadsheet("items.csv");