//
// Created by Alex on 6/11/2025.
//

#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H
#include <map>

#include "Room.h"

class InventoryManager {
public:
    InventoryManager() = default;
    explicit InventoryManager(std::map<std::string, Room> rooms);

    static void addBook(const Item& item, const Room& room);
    static void removeBook(const Item &item, const Room &room);
    static void toggleFound(const Item &item, const Room &room);
    static std::string generateReport();
private:
    std::map<std::string, Room> rooms;
};

#endif //INVENTORYMANAGER_H
