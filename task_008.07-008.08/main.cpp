#include <iostream>

class Vectors {
public:
    int vector[2];
    Vectors(int b_begin, int e_end) { vector[0] = b_begin; vector[1] = e_end; }

    // Префіксний декремент
    Vectors& operator--() {
        --vector[0];
        --vector[1];
        return *this;
    }

    // Постфіксний декремент
    Vectors operator--(int) {
        Vectors temp(*this);
        --vector[0];
        --vector[1];
        return temp;
    }
};

int main() {
    system("chcp 1251>nul");

    Vectors vector(5, 7);

    std::cout << "Початковий вектор: " << vector.vector[0] << ", " << vector.vector[1] << std::endl;

    --vector; // Виклик префіксного декременту

    std::cout << "Вектор після префіксного декременту: " << vector.vector[0] << ", " << vector.vector[1] << std::endl;

    Vectors oldVector = vector--;

    std::cout << "Вектор після постфіксного декременту: " << vector.vector[0] << ", " << vector.vector[1] << std::endl;
    std::cout << "Старий вектор (постфіксний): " << oldVector.vector[0] << ", " << oldVector.vector[1] << std::endl;

    return 0;
}
