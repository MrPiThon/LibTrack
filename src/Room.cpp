//
// Created by Alex on 6/11/2025.
//

#include <utility>
#include "../include/Room.h"

#include <algorithm>
#include <iomanip>
#include <optional>
#include <sstream>

Room::Room(std::string name, const std::vector<Item>& items)
    : name(std::move(name)), items(items) {
}

void Room::addItem(const Item& item) {
    items.push_back(item);
}

void Room::removeItem(const std::string &itemId) {
    std::erase_if(items,
                  [&](const Item& i) { return i.id == itemId; });
}

std::optional<std::reference_wrapper<Item>> Room::getItem(const std::string& id) {
    for (Item& i : items) {
        if (i.id == id) return i;
    }
    return std::nullopt;
}

std::string Room::getNextItemId() const {
    int maxId = 0;
    for (const auto& item : items) {
        try {
            if (const int numericId = std::stoi(item.id); numericId > maxId) maxId = numericId;
        } catch (...) {
            continue;
        }
    }

    std::ostringstream oss;
    oss << std::setw(3) << std::setfill('0') << (maxId + 1);
    return oss.str();
}

