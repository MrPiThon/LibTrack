//
// Created by Alex on 6/11/2025.
//

#ifndef CSVHANDLER_H
#define CSVHANDLER_H
#include <map>

#include "Room.h"

/**
 * Handles all conversions to CSV/files
 */
class CSVHandler {
public:
    /**
     * @brief Reads the inventory from a CSV file
     * @param path The file path to read from
     * @return A map from std::string (room name) to Room.
     */
    static std::map<std::string, Room> readInventoryFromCSV(const std::string& path);

    /**
     * @brief Converts a map of std::string (room name) and Room to a CSV file
     * @param path The file path to write to
     * @param rooms A map from std::string (room name) to Room, to convert to a file
     */
    static void writeInventoryToCSV(const std::string& path, const std::map<std::string, Room>& rooms);
};

#endif //CSVHANDLER_H
