//
// Created by Alex on 6/11/2025.
//

#include "../include/InventoryManager.h"

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

const std::map<std::string, Room>& InventoryManager::getRooms() const {
    return rooms;
}
