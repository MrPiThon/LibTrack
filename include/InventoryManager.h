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

    /**
     * Adds a Room to the Managers tracked rooms
     * @param room The room to add
     */
    void addRoom(const Room& room);

    /**
     * Adds a Book to a specified Room
     * @param roomName The name of the Room, used for tracking
     * @param item The Item to add to the Room
     */
    void addBookToRoom(const std::string& roomName, const Item& item);

    /**
     * Removes a Book from a Room, based on ItemId
     * @param roomName The name of the Room, used for tracking
     * @param itemId The Id of the Item to be removed
     */
    void removeBookFromRoom(const std::string& roomName, const std::string& itemId);

    /**
     * Toggles the found state of an Item, based on ItemId
     * @param roomName The name of the Room, used for tracking
     * @param itemId The Id of the Item to be toggled
     */
    void toggleFound(const std::string& roomName, const std::string& itemId);

    /**
     * Get the rooms currently tracked by the manager
     * @return A map from std::string to Room, consisting of all Rooms tracked by the manager
     */
    [[nodiscard]] const std::map<std::string, Room>& getRooms() const;

    /**
     * Generate a report to display all room information
     * @return A string representing the report of each room
     */
    [[nodiscard]] std::string generateReport() const;

    /**
     * Search for items where any field matches (case-insensitive, partial match).
     * @param query: Search term.
     * @param field: "id", "title", "type", "location", or "found" (as string "yes"/"no"/"true"/"false"/"1"/"0").
     * @return Vector of matching Items.
     */
    [[nodiscard]] std::vector<Item> searchByField(const std::string& query, const std::string& field) const;

private:
    /**
     * An internal map storing rooms
     */
    std::map<std::string, Room> rooms; // roomName -> Room
};

#endif //INVENTORYMANAGER_H

