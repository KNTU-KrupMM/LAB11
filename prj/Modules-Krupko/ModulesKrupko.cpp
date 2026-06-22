#include "ModulesKrupko.h"
#include <cmath>
#include <string>
#include <fstream>
#include <cstring>

// ============================================================================
// À¿¡Œ–¿“Œ–Õ¿ –Œ¡Œ“¿ π8
// ============================================================================

double s_calculation(double x, double y, double z) {
    double pi = 3.14159265358979323846;

    double term1 = std::abs(std::sin(std::abs(y - z * z)));
    double term2 = std::sqrt(x);
    double base = std::pow(y * z, x) + (y / (2 * pi));

    double term3;
    if (base < 0) {
        term3 = -std::pow(-base, 1.0 / 3.0);
    } else {
        term3 = std::pow(base, 1.0 / 3.0);
    }

    return term1 + term2 - term3;
}

std::string get_developer_name() {
    return " ÛÔÍÓ Ã‡ÍÒËÏ \xC2\xA9";
}

std::string check_logical(char a, char b) {
    if ((a + 7) == b) {
        return "true";
    }
    return "false";
}

// ============================================================================
// À¿¡Œ–¿“Œ–Õ¿ –Œ¡Œ“¿ π9
// ============================================================================

TornadoInfo task9_1_tornado(int wind_speed) {
    TornadoInfo info = {"Unknown", "Unknown"};

    if (wind_speed >= 64 && wind_speed <= 116) {
        info.category = "F0"; info.frequency = "38,9 %";
    } else if (wind_speed >= 117 && wind_speed <= 180) {
        info.category = "F1"; info.frequency = "35,6 %";
    } else if (wind_speed >= 181 && wind_speed <= 253) {
        info.category = "F2"; info.frequency = "19,4 %";
    } else if (wind_speed >= 254 && wind_speed <= 332) {
        info.category = "F3"; info.frequency = "4,9 %";
    } else if (wind_speed >= 333 && wind_speed <= 418) {
        info.category = "F4"; info.frequency = "1,1 %";
    } else if (wind_speed >= 419 && wind_speed <= 512) {
        info.category = "F5"; info.frequency = "ÏÂÌ¯Â 0,1 %";
    } else {
        info.category = "œÓÁ‡ ¯Í‡ÎÓ˛"; info.frequency = "-";
    }
    return info;
}

TemperatureInfo task9_2_temperature(double t1, double t2, double t3, double t4, double t5, double t6) {
    TemperatureInfo info;
    info.avg_celsius = (t1 + t2 + t3 + t4 + t5 + t6) / 6.0;
    info.avg_fahrenheit = 32.0 + (9.0 / 5.0) * info.avg_celsius;
    return info;
}

int task9_3_bits(unsigned short N) {
    int bit_D0 = N & 1;
    int count_zeros = 0;
    int count_ones = 0;

    unsigned short temp = N;
    for (int i = 0; i < 16; i++) {
        if (temp & 1) count_ones++;
        else count_zeros++;
        temp >>= 1;
    }

    return (bit_D0 == 0) ? count_zeros : count_ones;
}

// ============================================================================
// À¿¡Œ–¿“Œ–Õ¿ –Œ¡Œ“¿ π10
// ============================================================================

void task10_1_calc(double *x, double *y) {
    if (*x >= 0) {
        *x = *x + 2.0;
        *y = *y + 1.0;
    } else {
        *x = *x - 1.0;
        *y = *y - 2.0;
    }
}

// ============================================================================
// À¿¡Œ–¿“Œ–Õ¿ –Œ¡Œ“¿ π11
// ============================================================================

StackManager::StackManager() {
    top = nullptr;
}

StackManager::~StackManager() {
    clear();
}

void StackManager::push(int id, const std::string& nameStr) {
    Node* newNode = new Node;
    newNode->info.id = id;
    std::strncpy(newNode->info.name, nameStr.c_str(), sizeof(newNode->info.name) - 1);
    newNode->info.name[sizeof(newNode->info.name) - 1] = '\0';

    newNode->next = top;
    top = newNode;
}

bool StackManager::pop(ElementData& outElement) {
    if (isEmpty()) return false;

    Node* temp = top;
    outElement = temp->info;
    top = top->next;

    delete temp;
    return true;
}

bool StackManager::isEmpty() const {
    return top == nullptr;
}

void StackManager::clear() {
    ElementData dummy;
    while (pop(dummy));
}

bool StackManager::saveToBinaryFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) return false;

    Node* current = top;
    int count = 0;
    while (current) {
        count++;
        current = current->next;
    }

    file.write(reinterpret_cast<const char*>(&count), sizeof(count));

    current = top;
    while (current) {
        file.write(reinterpret_cast<const char*>(&current->info), sizeof(ElementData));
        current = current->next;
    }

    file.close();
    return true;
}

bool StackManager::loadFromBinaryFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) return false;

    clear();

    int count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(count));

    if (count <= 0) {
        file.close();
        return true;
    }

    ElementData* tempArray = new ElementData[count];
    for (int i = 0; i < count; i++) {
        file.read(reinterpret_cast<char*>(&tempArray[i]), sizeof(ElementData));
    }

    for (int i = count - 1; i >= 0; i--) {
        push(tempArray[i].id, tempArray[i].name);
    }

    delete[] tempArray;
    file.close();
    return true;
}
