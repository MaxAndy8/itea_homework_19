#include <iostream>

class Matrix2x2 {
public:
    int values[2][2]{0};

    // ����������� �� �������������
    Matrix2x2() {}
};

// �������� �����
std::istream& operator>>(std::istream& in, Matrix2x2& matrix) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            in >> matrix.values[i][j];
        }
    }
    return in;
}

// �������� ������
std::ostream& operator<<(std::ostream& out, const Matrix2x2& matrix) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            out << matrix.values[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

int main() {
    system("chcp 1251>nul");

    Matrix2x2 matrix;

    std::cout << "������ �������� ��� ������� 2x2:" << std::endl;
    std::cin >> matrix;

    std::cout << "���� ������� 2x2:" << std::endl;
    std::cout << matrix;

    return 0;
}
