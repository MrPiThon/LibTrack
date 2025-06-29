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

    /**
     * The Id of an item, used for tracking
     */
    std::string id;
    /**
     * The name/display name/title of the item
     */
    std::string title;
    /**
     * The type of the item (e.g. book)
     */
    std::string type;
    /**
     * The location of the book (e.g. maintenance room)
     */
    std::string location;
    /**
     * A boolean representing the found status of the Item
     */
    bool found{};

    /**
     * Get a formatted string representing all Item data
     * @return A string representing the Items data
     */
    [[nodiscard]] std::string toString() const;
};

#endif //ITEM_H
