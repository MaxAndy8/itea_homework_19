#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdexcept>

namespace MY {

    template <typename T>
    class Stack {
    private:
        // Внутрішній клас для вузлів односвязного списку
        class Node {
        public:
            T data;
            Node* next;

            Node(const T& value) : data(value), next(nullptr) {}
        };

        Node* topNode;
        size_t stackSize; // Лічильник елементів

    public:
        Stack() : topNode(nullptr), stackSize(0) {}

        // Додати елемент в стек
        void push(const T& value) {
            Node* newNode = new Node(value);
            if (topNode == nullptr) {
                topNode = newNode;
            }
            else {
                newNode->next = topNode;
                topNode = newNode;
            }
            stackSize++;
        }

        // Видалити та повернути верхній елемент
        T pop() {
            if (!isEmpty()) {
                Node* poppedNode = topNode;
                topNode = topNode->next;
                T poppedValue = poppedNode->data;
                delete poppedNode;
                stackSize--;
                return poppedValue;
            }
            else {
                throw std::out_of_range("Стек порожній");
            }
        }

        // Перевірити, чи стек порожній
        bool isEmpty() const {
            return topNode == nullptr;
        }

        // Отримати розмір стеку
        size_t size() const {
            return stackSize;
        }

        // Отримати верхній елемент без видалення
        T top() const {
            if (!isEmpty()) {
                return topNode->data;
            }
            else {
                throw std::out_of_range("Стек порожній");
            }
        }

        ~Stack() {
            while (!isEmpty()) {
                pop();
            }
        }
    };

}

#endif
