#include <iostream>
#include <vector>

class RangeArray {
private:
    std::vector<int> array;
    int size;

public:
    RangeArray(std::vector<int> arr) : array(arr), size(arr.size()) {}

    int& operator[](int index) {
        if (size == 0) {            
            throw std::out_of_range("Помилка: масив порожній!");
        }

        if (index >= 0) {
            return array[index % size];
        }
        else {
            return array[(size - (-index) % size) % size];
        }
    }
};

int main() {
    system("chcp 1251>nul");

    std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    RangeArray range(arr);

    std::cout << "Елементи масиву по колу вперед та назад:" << std::endl;
    for (int i = -30; i <= 30; i++) {
        std::cout << "range[" << i << "] = " << range[i] << std::endl;
    }

    return 0;
}
