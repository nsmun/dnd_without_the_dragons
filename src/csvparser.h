#include "include.h"


class Spreadsheet{

    private:

    std::vector<std::vector<std::string>> rows;
    std::vector<std::string> column_names;
    std::vector<std::string> column_types;

    std::string file_path;
    bool using_column_names;
    bool parser ();

    public:

    // Constructors
    Spreadsheet (std::string path);
    Spreadsheet (std::string path, bool column_names);

    // Access Methods
    std::string get_cell (int column, int row);
    std::string get_cell (std::string column_name, int row);
    int rows_size();
    std::string get_type (int column);
    std::string get_type (std::string column_name);

    // Modify methods
    bool set_cell (int column, int row, std::string value);
    bool set_cell (std::string column_name, int row, std::string value);
    bool add_row (int row); // Row is inserted in row index
    bool remove_row (int row);
    bool add_column (int column); // column is inserted in row index
    bool add_column (int column, std::string column_name);
    bool remove_column (int column);
    bool remove_column (std::string column_name);
    bool set_column_type (std::string column_type); // Legal variable type exchange only
    bool set_column_type (std::string column_type, bool force); // Double to int with rounding, AND MAYBE base 256 char to int/double conversion LOL

    // Save data to file
    bool save_to_file ();
    bool save_to_file (std::string path);
    bool change_file_path (std::string path);

};

// Spreadsheet my_spreadsheet("items.csv");