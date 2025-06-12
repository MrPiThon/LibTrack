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

    void addItem(const Item &item);
    void removeItem(const std::string &itemId);

    std::string name;
    std::vector<Item> items;
    std::string getNextItemId() const;

    std::optional<std::reference_wrapper<Item>> getItem(const std::string& id);
};

#endif //ROOM_H
