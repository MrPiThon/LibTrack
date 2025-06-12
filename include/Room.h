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

        std::string name;

        void addItem(const Item& item) const;
        void removeItem(const Item& item) const;
        [[nodiscard]] std::optional<Item> getItem(const std::string& id) const;
    private:
        std::vector<Item> items;
    };

    #endif //ROOM_H
