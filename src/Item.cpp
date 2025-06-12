//
// Created by Alex on 6/11/2025.
//

#include "../include/Item.h"

#include <string>
#include <utility>

Item::Item(std::string name, std::string  title,
    std::string  type, std::string  location, const bool found)
        : id(std::move(name)), title(std::move(title)), type(std::move(type)),
            location(std::move(location)), found(found) {

}
