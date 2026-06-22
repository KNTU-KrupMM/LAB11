#ifndef MODULES_KRUPKO_H
#define MODULES_KRUPKO_H

#include <string>

// ============================================================================
// À¿¡Œ–¿“Œ–Õ¿ –Œ¡Œ“¿ π8
// ============================================================================
double s_calculation(double x, double y, double z);
std::string get_developer_name();
std::string check_logical(char a, char b);

// ============================================================================
// À¿¡Œ–¿“Œ–Õ¿ –Œ¡Œ“¿ π9
// ============================================================================
struct TornadoInfo {
    std::string category;
    std::string frequency;
};

struct TemperatureInfo {
    double avg_celsius;
    double avg_fahrenheit;
};

TornadoInfo task9_1_tornado(int wind_speed);
TemperatureInfo task9_2_temperature(double t1, double t2, double t3, double t4, double t5, double t6);
int task9_3_bits(unsigned short N);

// ============================================================================
// À¿¡Œ–¿“Œ–Õ¿ –Œ¡Œ“¿ π10
// ============================================================================
void task10_1_calc(double *x, double *y);

// ============================================================================
// À¿¡Œ–¿“Œ–Õ¿ –Œ¡Œ“¿ π11
// ============================================================================
struct ElementData {
    int id;
    char name[50];
};

struct Node {
    ElementData info;
    Node* next;
};

class StackManager {
private:
    Node* top;

public:
    StackManager();
    ~StackManager();

    void push(int id, const std::string& nameStr);
    bool pop(ElementData& outElement);
    bool isEmpty() const;
    void clear();

    bool saveToBinaryFile(const std::string& filename) const;
    bool loadFromBinaryFile(const std::string& filename);
};

#endif // MODULES_KRUPKO_H
