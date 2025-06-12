//
// Created by Alex on 6/11/2025.
//

#include <utility>

#include "../include/InventoryManager.h"

InventoryManager::InventoryManager(std::map<std::string, Room> rooms)
    : rooms(std::move(rooms)) {

}

void InventoryManager::addBook(const Item& item, const Room& room) {

}

void InventoryManager::removeBook(const Item& item, const Room& room) {

}

void InventoryManager::toggleFound(const Item& item, const Room& room) {
    if (!rooms.contains(item.id)) return;


}
