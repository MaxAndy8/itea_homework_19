#include "MyStack.h"
#include <iostream>

int main() {
    system("chcp 1251>nul");

    MY::Stack<int> myStack;

    int n;
    std::cout << "������ ������� ������� ��� ���������� � ����: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        std::cout << "������ �������� " << i + 1 << ": ";
        std::cin >> value;
        myStack.push(value);
    }

    int m;
    std::cout << "������ ������� �������� ��� ��������� �� ����� �� �����������: ";
    std::cin >> m;

    std::cout << "���� �����: ";
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
