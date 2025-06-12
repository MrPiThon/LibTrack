//
// Created by Alex on 6/11/2025.
//

#include <utility>
#include "../include/Room.h"
#include <optional>

Room::Room(std::string name, const std::vector<Item>& items)
    : name(std::move(name)), items(items) {
}

void Room::addItem(const Item& item) const {
    if (Room::getItem(item.id).has_value()) return;
    // TODO: Figure out why this does not work?
    // Get addItem and removeItem functioning
}

void Room::removeItem(const Item& item) const {
    if (!Room::getItem(item.id).has_value()) return;

}

std::optional<Item> Room::getItem(const std::string& id) const {
    for (const Item &i : items) {
        if (i.id == id) return i;
    }

    return std::nullopt;
}
