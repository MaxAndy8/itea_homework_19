#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdexcept>

namespace MY {

    template <typename T>
    class Stack {
    private:
        // �������� ���� ��� ����� ������������ ������
        class Node {
        public:
            T data;
            Node* next;

            Node(const T& value) : data(value), next(nullptr) {}
        };

        Node* topNode;
        size_t stackSize; // ˳������� ��������

    public:
        Stack() : topNode(nullptr), stackSize(0) {}

        // ������ ������� � ����
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

        // �������� �� ��������� ������ �������
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
                throw std::out_of_range("���� �������");
            }
        }

        // ���������, �� ���� �������
        bool isEmpty() const {
            return topNode == nullptr;
        }

        // �������� ����� �����
        size_t size() const {
            return stackSize;
        }

        // �������� ������ ������� ��� ���������
        T top() const {
            if (!isEmpty()) {
                return topNode->data;
            }
            else {
                throw std::out_of_range("���� �������");
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
