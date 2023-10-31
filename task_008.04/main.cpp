#include <iostream>
#include <Windows.h>

class SpecialSymbols {
private:
	wchar_t symbol;

public:
	SpecialSymbols(wchar_t ch = L' ') : symbol(ch) {}

	bool operator==(const SpecialSymbols& other) const {

		wchar_t first_ch = this->symbol < other.symbol ? this->symbol : other.symbol;
		wchar_t second_ch = this->symbol >= other.symbol ? this->symbol : other.symbol;


		bool rez = false;
		if (first_ch == second_ch) {
			rez = true;
		}
		else if (first_ch == L'O' && second_ch == L'�'
			|| first_ch == L'o' && second_ch == L'�'
			|| first_ch == L'A' && second_ch == L'�'
			|| first_ch == L'a' && second_ch == L'�'
			|| first_ch == L'I' && second_ch == L'�'
			|| first_ch == L'i' && second_ch == L'�'
			|| first_ch == L'E' && second_ch == L'�'
			|| first_ch == L'e' && second_ch == L'�'
			|| first_ch == L'H' && second_ch == L'�'
			|| first_ch == L'C' && second_ch == L'�'
			|| first_ch == L'c' && second_ch == L'�'
			|| first_ch == L'B' && second_ch == L'�'
			|| first_ch == L'K' && second_ch == L'�'
			|| first_ch == L'P' && second_ch == L'�'
			|| first_ch == L'p' && second_ch == L'�'
			|| first_ch == L'X' && second_ch == L'�'
			|| first_ch == L'x' && second_ch == L'�'
			|| first_ch == L'T' && second_ch == L'�'
			|| first_ch == L'M' && second_ch == L'�') {
			rez = true;
		}

		return rez;
	}

	bool operator!=(const SpecialSymbols& other) const {
		return !(*this == other);
	}

	// �������� �����
	friend std::wistream& operator>>(std::wistream& in, SpecialSymbols& ch) {

		in >> ch.symbol;
		return in;
	}

	// �������� ������
	friend std::wostream& operator<<(std::wostream& out, const SpecialSymbols& ch) {

		out << ch.symbol;
		return out;
	}

};

int main() {

	SetConsoleCP(1251); // ���
	SetConsoleOutputCP(1251); // ����

	setlocale(LC_ALL, ""); // ������� 1251

	SpecialSymbols first_CH;
	std::wcout << L"������ ������ ������: ";
	std::wcin >> first_CH;

	SpecialSymbols second_CH;
	std::wcout << L"������ ������ ������: ";
	std::wcin >> second_CH;


	if (first_CH == second_CH) {
		std::wcout << L"������� '" << first_CH << L"' �� '" << second_CH << L"' �� ������ ����������." << std::endl;
	}
	else {
		std::wcout << L"������� '" << first_CH << L"' �� '" << second_CH << L"' �� ������ �� ����������." << std::endl;
	}

	return 0;
}

