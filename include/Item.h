//
// Created by Alex on 6/11/2025.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item() = default;
    Item(std::string  id, std::string  title,
        std::string  type, std::string  location, bool found);

    std::string id;
    std::string title;
    std::string type;
    std::string location;
    bool found{};
    [[nodiscard]] std::string toString() const;
};

#endif //ITEM_H
