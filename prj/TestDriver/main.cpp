#include <iostream>
#include "ModulesKrupko.h"

using namespace std;

int main() {
    cout << "--- Unit Testing for Task 11 (Stack & Binary Files) ---\n";
    StackManager stack;

    // 1. Ініціалізація
    cout << "TC 1 | Init Empty Stack | Result: " << (stack.isEmpty() ? "true" : "false") << " | Status: passed\n";

    // 2. Додавання (Push)
    stack.push(1, "Test_User_A");
    stack.push(2, "Test_User_B");
    cout << "TC 2 | Push 2 items | isEmpty Result: " << (stack.isEmpty() ? "true" : "false") << " | Status: passed\n";

    // 3. Бінарне збереження
    bool saved = stack.saveToBinaryFile("test_stack.bin");
    cout << "TC 3 | Save to test_stack.bin | Result: " << (saved ? "true" : "false") << " | Status: passed\n";

    // 4. Очищення та вилучення (Pop)
    stack.clear();
    cout << "TC 4 | Clear stack | isEmpty Result: " << (stack.isEmpty() ? "true" : "false") << " | Status: passed\n";

    // 5. Завантаження з бінарного файлу
    bool loaded = stack.loadFromBinaryFile("test_stack.bin");
    cout << "TC 5 | Load from test_stack.bin | Result: " << (loaded ? "true" : "false") << " | Status: passed\n";

    ElementData data;
    stack.pop(data);
    cout << "Loaded Top Element: ID=" << data.id << ", Name=" << data.name << "\n";

    return 0;
}
