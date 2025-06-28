//
// Created by Alex on 6/11/2025.
//

#include "../include/InventoryManager.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>

InventoryManager::InventoryManager(std::map<std::string, Room> rooms)
    : rooms(std::move(rooms)) {}

void InventoryManager::addRoom(const Room& room) {
    rooms[room.name] = room;
}

void InventoryManager::addBookToRoom(const std::string& roomName, const Item& item) {
    rooms[roomName].addItem(item);
}

void InventoryManager::removeBookFromRoom(const std::string& roomName, const std::string& itemId) {
    rooms[roomName].removeItem(itemId);
}

void InventoryManager::toggleFound(const std::string& roomName, const std::string& itemId) {
    if (!rooms.contains(roomName)) {
        std::cerr << "Room -> " << roomName << " <- not found" << std::endl;
        return;
    }

    auto& room = rooms[roomName];
    const auto itemOpt = room.getItem(itemId);
    if (!itemOpt.has_value()) {
        std::cerr << "[WARN] Item ID not found: " << itemId << "\n";
        return;
    }

    auto& item = itemOpt.value().get();
    item.found = !item.found;
}

std::string InventoryManager::generateReport() const {
    std::ostringstream oss;
    for (const auto& [roomName, room] : rooms) {
        oss << "Room: " << roomName << "\n";
        for (const auto& item : room.items) {
            oss << "  - " << item.toString() << "\n";
        }
    }
    return oss.str();
}

static bool icontains(const std::string& data, const std::string& query) {
    // Case-insensitive substring match
    return std::search(
        data.begin(), data.end(),
        query.begin(), query.end(),
        [](char c1, char c2) { return std::tolower(c1) == std::tolower(c2); }
    ) != data.end();
}

std::vector<Item> InventoryManager::searchByField(const std::string& query, const std::string& field) const {
    std::vector<Item> results;
    for (const auto& [roomName, room] : rooms) {
        for (const auto& item : room.items) {
            if (field == "id" && icontains(item.id, query)) {
                results.push_back(item);
            } else if (field == "title" && icontains(item.title, query)) {
                results.push_back(item);
            } else if (field == "type" && icontains(item.type, query)) {
                results.push_back(item);
            } else if (field == "location" && icontains(item.location, query)) {
                results.push_back(item);
            } else if (field == "found") {
                std::string boolQuery = query;
                std::transform(boolQuery.begin(), boolQuery.end(), boolQuery.begin(), ::tolower);
                bool lookingFor = (boolQuery == "yes" || boolQuery == "true" || boolQuery == "1");
                if (item.found == lookingFor) results.push_back(item);
            }
        }
    }
    return results;
}

const std::map<std::string, Room>& InventoryManager::getRooms() const {
    return rooms;
}
