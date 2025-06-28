//
// Created by Alex on 6/11/2025.
//

#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <map>
#include <string>
#include "Room.h"

class InventoryManager {
public:
    InventoryManager() = default;
    explicit InventoryManager(std::map<std::string, Room> rooms);

    void addRoom(const Room& room);
    void addBookToRoom(const std::string& roomName, const Item& item);
    void removeBookFromRoom(const std::string& roomName, const std::string& itemId);
    void toggleFound(const std::string& roomName, const std::string& itemId);

    const std::map<std::string, Room>& getRooms() const;

    [[nodiscard]] std::string generateReport() const;

    /**
     * Search for items where any field matches (case-insensitive, partial match).
     * @param query: Search term.
     * @param field: "id", "title", "type", "location", or "found" (as string "yes"/"no"/"true"/"false"/"1"/"0").
     * @return Vector of matching Items.
     */
    std::vector<Item> searchByField(const std::string& query, const std::string& field) const;

private:
    std::map<std::string, Room> rooms; // roomName -> Room
};

#endif //INVENTORYMANAGER_H

