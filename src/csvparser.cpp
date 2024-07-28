#include "include.h"


class Spreadsheet{
    private:
    std::vector<std::vector<std::string>> rows;
    std::vector<std::string> column_names;
    std::string file_path;
    bool using_column_names;
    bool parser () {
        std::ifstream file(file_path);

        if (!file.is_open()) {
            std::cerr << "Unable to open file" << std::endl;
            return false;
        }

        std::string line;

        while (std::getline(file, line)) {
            std::cout << line << std::endl;

            std::string cell;

            while (std::getline(line, cell, ',')) {
                
            }
    }

    // Close the file
    file.close();
        
    }

    public:
    Spreadsheet (std::string path) {
        file_path = path;
        using_column_names = true;
    }

    Spreadsheet (std::string path, bool column_names) {
        file_path = path;
        using_column_names = column_names;
    }

};

// Spreadsheet my_spreadsheet("items.csv");