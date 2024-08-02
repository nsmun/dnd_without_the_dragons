#include "csvparser.h"



bool Spreadsheet::parser () {
    FILE* csv_file = fopen(file_path.c_str(), "r");

    if (csv_file == NULL) {
        std::cerr << "Unable to open file" << std::endl;
        return false;
    }

    int character;
    bool done = false;
    std::vector<std::string> row;
    std::string cell;


    while (done == false) {
        character = std::getc(csv_file);
        switch (character) {
            case EOF:
                std::cout << "You have reached the end" << std::endl;
                done = true;
                break;
            // 10 in Ascii is End of line (\n)
            case 10:
                row.push_back(cell);
                cell.clear();
                rows.push_back(row);
                row.clear();
                break;
            // 44 in Ascii is ','
            case 44:
                row.push_back(cell);
                cell.clear();
                break;
            default:
                cell += char(character);
                break;
        }
    }

    if (using_column_names && !rows.empty()) {
        column_names = rows.front();
        rows.erase(rows.begin());
    }

    // std::cout << "Loop for vector:" << std::endl;
    // for (int i = 0; i < rows.size(); i++) {
    //     for (int x = 0; x < rows[i].size(); x++) {
    //         std::cout << rows[i][x] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // Close the file
    fclose(csv_file);

    return true;
}


Spreadsheet::Spreadsheet(std::string path) {
    file_path = path;
    using_column_names = true;
    parser();
}

Spreadsheet::Spreadsheet(std::string path, bool column_names) {
    file_path = path;
    using_column_names = column_names;
    parser();
}

std::string Spreadsheet::get_cell (int column, int row) {
    if (rows.empty()) return "";
    if (column < 0 || column >= rows.front().size()) return "";
    if (row < 0 || row >= rows.size()) return "";
    return rows[row][column];

}





std::string Spreadsheet::get_cell (std::string column_name, int row){
    if (rows.empty()) return "";
    int column = -1;
    for (int i = 0; i < column_names.size(); i++) {
        if (column_names[i] == column_name) column = i;
    }
    if (column < 0) return "";
    if (row < 0 || row >= rows.size()) return "";
    return rows[row][column];
}


// Spreadsheet my_spreadsheet("items.csv");