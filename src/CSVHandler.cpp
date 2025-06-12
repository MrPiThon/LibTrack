//
// Created by Alex on 6/11/2025.
//

#include "../include/CSVHandler.h"

#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>

std::map<std::string, Room> CSVHandler::readInventoryFromCSV(const std::string &path) {
    std::ifstream file(path);
    std::map<std::string, Room> roomMap;

    if (!file.is_open()) {
        std::cerr << "Error opening file " << path << std::endl;
        return roomMap;
    }

    std::string line;
    bool isHeader = true;

    while (std::getline(file, line)) {
        if (isHeader) { isHeader = false; continue; }

        std::stringstream ss(line);
        std::string id, title, type, location, foundStr;

        auto trim = [](std::string& s) {
            s.erase(0, s.find_first_not_of(" \t\r\n"));
            s.erase(s.find_last_not_of(" \t\r\n") + 1);
        };

        std::getline(ss, id, ','); trim(id);
        std::getline(ss, title, ','); trim(title);
        std::getline(ss, type, ','); trim(type);
        std::getline(ss, location, ','); trim(location);
        std::getline(ss, foundStr); trim(foundStr);

        bool found = (foundStr == "Yes");

        Item item(id, title, type, location, found);

        if (roomMap.contains(location)) {
            roomMap[location].addItem(item);
        } else {
            Room r(location, { item } );
            roomMap[location] = r;
        }
    }

    file.close();
    return roomMap;
}

void CSVHandler::writeInventoryToCSV(const std::string &path, const std::map<std::string, Room>& rooms) {
    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << path << std::endl;
        return;
    }

    file << "ID,Title,Type,Location,Found\n";

    for (const auto &room: rooms | std::views::values) {
        for (const auto& item : room.items) {
            file << item.toString() << "\n";
        }
    }

    file.close();
}

