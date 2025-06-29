//
// Created by Alex on 6/11/2025.
//

#ifndef ROOM_H
#define ROOM_H
#include <optional>
#include <vector>

#include "Item.h"

class Room {
public:
    Room() = default;
    Room(std::string name, const std::vector<Item> &items);

    /**
     * Add an Item to the Room
     * @param item The Item to be added to the Room
     */
    void addItem(const Item &item);

    /**
     * Remove an Item from the Room, based on Id
     * @param itemId The Id of the Item to be removed
     */
    void removeItem(const std::string &itemId);

    /**
     * The name of the Room
     */
    std::string name;
    /**
     * The Items that are currently being tracked by the Room
     */
    std::vector<Item> items;

    /**
     * A helper function to generate a new Item Id
     * @return A new ItemId
     */
    [[nodiscard]] std::string getNextItemId() const;

    /**
     * Get an Item stored in the Room, via item Id
     * @param id The Item Id
     * @return An optional representing the Item that is found via the Item Id
     */
    std::optional<std::reference_wrapper<Item>> getItem(const std::string& id);
};

#endif //ROOM_H
