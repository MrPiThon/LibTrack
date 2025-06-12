//
// Created by Alex on 6/11/2025.
//

#ifndef CSVHANDLER_H
#define CSVHANDLER_H
#include <map>

#include "Room.h"

class CSVHandler {
public:
    static std::map<std::string, Room> readInventoryFromCSV(const std::string& path);
    static void writeInventoryToCSV(const std::string& path, const std::map<std::string, Room>& rooms);
};

#endif //CSVHANDLER_H
