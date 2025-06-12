**Team Info**
Team Name: LibTrack

Team Members:
Alex - Solo Developer (Individual Submission)

**Project Requirements & Stakeholder Analysis**
The CIAT Library Inventory Tracking System aims to streamline the library’s annual inventory check by managing thousands of resources across different rooms. Stakeholders include:

- **Library Staff**: Want a simple way to mark items found/not found.
- **Librarians/Managers**: Need to track item locations, add/remove items, and generate reports.
- **IT/Admins**: Require compatibility with existing CSV-based inventory tools.

Key system requirements:
- Maintain a master list of inventory items.
- Group items by room/section.
- Support manual updates and toggling of item presence.
- Import/export inventory via `.csv`.
- Generate printable reports.

**Stakeholder Questions**
1. What item details are essential beyond title, type, and location?
2. Should item IDs be globally unique or unique per room?
3. How should errors in the CSV (missing or malformed entries) be handled?
4. Would future support for scanned barcodes or QR codes be beneficial?
5. Should the report format be compatible with existing documentation tools?

**Why Agile?**
Agile was chosen because it supports rapid iteration and user feedback. By building a CLI prototype early, core functionality could be tested quickly. New features (e.g., auto-ID assignment, input validation) were added based on usage needs, reflecting Agile principles such as:

- Responding to change over following a rigid plan
- Continuous feedback via runtime behavior
- Building working software early and often

**Communication Plan**
- Channel: GitHub + Discord for code and discussion
- Frequency: Daily code commits, weekly check-ins
- Tools: Git for version tracking, CLion IDE, C++ standard library

**User Stories & Task Breakdown**
• As a library staff member, I want to view items by room, so I can check off inventory efficiently.
• As a librarian, I want to toggle the "found" status, so I can track items during inventory checks.
• As an admin, I want to export data to CSV, so I can archive and analyze inventory history.
• As a librarian, I want to add or remove items from rooms, so I can keep inventory accurate.
• As a developer, I want to automatically assign new item IDs, so there are no duplicates or errors.

- Build Item and Room data structures
- Build CSV import/export system
- Display inventory by room
- Implement toggle system
- Add item addition/removal with ID generation
- Format output and validate input
- Write CLI logic for interactive use
- Write debugging tools and reports

**User Story Prioritization**
| Priority   | User Story                                                     |
| ---------- | -------------------------------------------------------------- |
| **Must**   | View items by room                                             |
| **Must**   | Toggle "found" status                                          |
| **Must**   | Export inventory to CSV                                        |
| **Should** | Add/remove items via CLI                                       |
| **Should** | Auto-generate padded item IDs                                  |
| **Could**  | Add room validation before actions                             |
| **Won’t**  | Implement barcode scanning or mobile interface in this version |

**Initial Prototype Description**
The initial prototype is a command-line C++ program that manages library inventory by room. It allows users to:

- View current items grouped by room
- Toggle the “found” status of any item
- Add new items with auto-generated IDs
- Remove items by ID
- Export the current inventory state to a CSV file

This implementation uses standard library containers (`std::map`, `std::vector`), file I/O (`std::ifstream`, `std::ofstream`), and input handling with validation. IDs are formatted to always be three-digit padded strings.

**Risk Identification and Management Plan**
| Risk                                      | Mitigation Strategy                                         |
| ----------------------------------------- | ----------------------------------------------------------- |
| Input errors (bad room name, invalid ID)  | Added input validation before each action                   |
| Data not saving or overwriting improperly | Confirmed file closes properly; tested output CSV manually  |
| Non-unique IDs                            | IDs are auto-generated and zero-padded to ensure uniqueness |
| Future scalability (adding new features)  | Used modular design: Room, Item, Manager, CSVHandler, etc.  |
| Incompatible CSV formats                  | Stuck to flat `,`-based format with strict column order     |

**Stand-Up Meetings and Scope Creep Control**
Though this was a solo project, I practiced Agile-like stand-up routines by doing iterative development. I frequently reviewed progress after each feature and adjusted scope accordingly.

Scope creep was avoided by focusing on essential features first (view, toggle, export), and only adding extras (add/remove, input validation, ID formatting) once the core was stable.

**Lessons Learned from this Assignment**
Through this project, I improved my understanding of C++ modular design, user input validation, and file I/O. 
I also gained practical experience translating real-world requirements into a working system and managing scope through iterative development. 
The CLI prototype met all functional goals while remaining extensible for future upgrades like a GUI or database integration.
