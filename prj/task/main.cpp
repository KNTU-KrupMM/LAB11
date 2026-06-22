#include <iostream>
#include <string>
#include "ModulesKrupko.h"

using namespace std;

int main() {
    StackManager stack;
    int choice;

    do {
        cout << "\n========== DYNAMIC STACK (Binary Files) ==========\n";
        cout << "1. Push element to stack\n";
        cout << "2. Pop element from stack\n";
        cout << "3. Save stack to binary file (data.bin)\n";
        cout << "4. Load stack from binary file (data.bin)\n";
        cout << "5. Check if stack is empty\n";
        cout << "0. Exit program\n";
        cout << "==================================================\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name;
                cout << "Enter unique ID: ";
                cin >> id;
                cout << "Enter text name: ";
                cin >> name;

                stack.push(id, name);
                cout << "-> Element [ID: " << id << ", Name: " << name << "] successfully added.\n";
                break;
            }
            case 2: {
                ElementData data;
                if (stack.pop(data)) {
                    cout << "-> Successfully popped element:\n";
                    cout << "   [ID]: " << data.id << "\n";
                    cout << "   [Name]: " << data.name << "\n";
                } else {
                    cout << "-> Execution error: Stack is empty!\n";
                }
                break;
            }
            case 3: {
                if (stack.saveToBinaryFile("data.bin")) {
                    cout << "-> Stack successfully saved to 'data.bin'.\n";
                } else {
                    cout << "-> Error: Failed to save file!\n";
                }
                break;
            }
            case 4: {
                if (stack.loadFromBinaryFile("data.bin")) {
                    cout << "-> Data successfully loaded from 'data.bin'.\n";
                } else {
                    cout << "-> Error: File 'data.bin' is missing or corrupted!\n";
                }
                break;
            }
            case 5:
                if (stack.isEmpty()) {
                    cout << "-> Status: Stack is EMPTY.\n";
                } else {
                    cout << "-> Status: Stack has active elements.\n";
                }
                break;
            case 0:
                cout << "Closing application...\n";
                break;
            default:
                cout << "\a-> Invalid input! Please select option (0-5).\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
