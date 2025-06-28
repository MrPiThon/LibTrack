#include <algorithm>
#include <iostream>
#include <limits>
#include "../include/CSVHandler.h"
#include "../include/InventoryManager.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool isValidId(const std::string& id) {
    return !id.empty() && std::ranges::all_of(id, ::isdigit);
}

int main() {
    const std::string inputPath = "../data/inventory.csv";
    const std::string outputPath = "../data/updated_inventory.csv";

    InventoryManager manager(CSVHandler::readInventoryFromCSV(inputPath));
    bool continueLoop = true;
    bool searching = false;

    while (continueLoop) {
        std::cout << "\n========== CIAT Library Inventory ==========\n";
        std::cout << "[1] View Inventory Report\n";
        std::cout << "[2] Toggle Found Status of Item\n";
        std::cout << "[3] Add Item\n";
        std::cout << "[4] Remove Item\n";
        std::cout << "[5] Search Item\n";
        std::cout << "[9] Exit\n";
        std::cout << "===========================================\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        switch (choice) {
            case 1: {
                std::cout << "\n--- Inventory Report ---\n";
                std::cout << manager.generateReport() << "\n";
                break;
            }

            case 2: {
                std::string roomName, itemId;

                std::cout << "Enter room name: ";
                std::getline(std::cin >> std::ws, roomName);

                if (!manager.getRooms().contains(roomName)) {
                    std::cerr << "Error: Room not found.\n";
                    break;
                }

                std::cout << "Enter Item ID: ";
                std::getline(std::cin >> std::ws, itemId);

                if (!isValidId(itemId)) {
                    std::cerr << "Error: Invalid Item ID format.\n";
                    break;
                }

                manager.toggleFound(roomName, itemId);
                std::cout << "Item toggled.\n";
                break;
            }

            case 3: {
                std::string roomName, itemTitle, itemType;

                std::cout << "Enter room name: ";
                std::getline(std::cin >> std::ws, roomName);

                if (!manager.getRooms().contains(roomName)) {
                    std::cerr << "Error: Room not found.\n";
                    break;
                }

                std::cout << "Enter item title: ";
                std::getline(std::cin >> std::ws, itemTitle);
                if (itemTitle.empty()) {
                    std::cerr << "Error: Item title cannot be empty.\n";
                    break;
                }

                std::cout << "Enter item type: ";
                std::getline(std::cin >> std::ws, itemType);
                if (itemType.empty()) {
                    std::cerr << "Error: Item type cannot be empty.\n";
                    break;
                }

                std::map<std::string, Room>::mapped_type room = manager.getRooms().at(roomName);
                const std::string nextId = room.getNextItemId();

                manager.addBookToRoom(roomName, Item(nextId, itemTitle, itemType, roomName, true));
                std::cout << "Item added with ID: " << nextId << "\n";
                break;
            }

            case 4: {
                std::string roomName, itemId;

                std::cout << "Enter room name: ";
                std::getline(std::cin >> std::ws, roomName);

                if (!manager.getRooms().contains(roomName)) {
                    std::cerr << "Error: Room not found.\n";
                    break;
                }

                std::cout << "Enter Item ID: ";
                std::getline(std::cin >> std::ws, itemId);

                if (!isValidId(itemId)) {
                    std::cerr << "Error: Invalid Item ID format.\n";
                    break;
                }

                manager.removeBookFromRoom(roomName, itemId);
                std::cout << "Item removed (if it existed).\n";
                break;
            }

            case 5: {
                searching = true;
                while (searching) {
                    std::cout << "\n========== FindIt ==========\n";
                    std::cout << "[1] Search by Item ID\n";
                    std::cout << "[2] Search by Item Title\n";
                    std::cout << "[3] Search by Item Type\n";
                    std::cout << "[4] Search by Location\n";
                    std::cout << "[5] Search by Found Status (yes/no)\n";
                    std::cout << "[9] Cancel Search\n";
                    std::cout << "===========================================\n";
                    std::cout << "Enter choice: ";

                    int c;
                    std::cin >> c;
                    clearInput();

                    if (c == 9) {
                        searching = false;
                        break;
                    }

                    std::string field, query;
                    switch (c) {
                        case 1: field = "id";       std::cout << "Enter Item ID (or part): "; break;
                        case 2: field = "title";    std::cout << "Enter Item Title (or part): "; break;
                        case 3: field = "type";     std::cout << "Enter Item Type (or part): "; break;
                        case 4: field = "location"; std::cout << "Enter Location (or part): "; break;
                        case 5: field = "found";    std::cout << "Enter Found Status (yes/no): "; break;
                        default:
                            std::cerr << "Invalid choice.\n";
                            continue;
                    }
                    std::getline(std::cin >> std::ws, query);

                    // Perform the search
                    if (auto results = manager.searchByField(query, field); results.empty()) {
                        std::cout << "No items found matching your query.\n";
                    } else {
                        std::cout << "\n--- Search Results ---\n";
                        for (const auto& item : results) {
                            std::cout << item.toString() << "\n";
                        }
                    }
                    searching = false;
                }
                break;
            }

            case 9: {
                continueLoop = false;
                break;
            }

            default:
                std::cerr << "Invalid choice. Please enter 1, 2, 3, 4, or 9.\n";
                break;
        }
    }

    CSVHandler::writeInventoryToCSV(outputPath, manager.getRooms());
    std::cout << "Inventory saved to: " << outputPath << "\n";
    std::cout << "Goodbye!\n";

    return 0;
}
