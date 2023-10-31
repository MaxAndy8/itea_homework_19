#include "MyStack.h"
#include <iostream>

int main() {
    system("chcp 1251>nul");

    MY::Stack<int> myStack;

    int n;
    std::cout << "¬вед≥ть к≥льк≥сть значень дл€ надсиланн€ в стек: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        std::cout << "¬вед≥ть значенн€ " << i + 1 << ": ";
        std::cin >> value;
        myStack.push(value);
    }

    int m;
    std::cout << "¬вед≥ть к≥льк≥сть елемент≥в дл€ отриманн€ ≥з стеку та в≥дображенн€: ";
    std::cin >> m;

    std::cout << "¬м≥ст стеку: ";
    try {
        for (int i = 0; i < m; i++) {
            std::cout << myStack.top() << " ";
            myStack.pop();
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
