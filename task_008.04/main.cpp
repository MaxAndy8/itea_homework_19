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
		else if (first_ch == L'O' && second_ch == L'О'
			|| first_ch == L'o' && second_ch == L'о'
			|| first_ch == L'A' && second_ch == L'А'
			|| first_ch == L'a' && second_ch == L'а'
			|| first_ch == L'I' && second_ch == L'І'
			|| first_ch == L'i' && second_ch == L'і'
			|| first_ch == L'E' && second_ch == L'Е'
			|| first_ch == L'e' && second_ch == L'е'
			|| first_ch == L'H' && second_ch == L'Н'
			|| first_ch == L'C' && second_ch == L'С'
			|| first_ch == L'c' && second_ch == L'с'
			|| first_ch == L'B' && second_ch == L'В'
			|| first_ch == L'K' && second_ch == L'К'
			|| first_ch == L'P' && second_ch == L'Р'
			|| first_ch == L'p' && second_ch == L'р'
			|| first_ch == L'X' && second_ch == L'Х'
			|| first_ch == L'x' && second_ch == L'х'
			|| first_ch == L'T' && second_ch == L'Т'
			|| first_ch == L'M' && second_ch == L'М') {
			rez = true;
		}

		return rez;
	}

	bool operator!=(const SpecialSymbols& other) const {
		return !(*this == other);
	}

	// Оператор вводу
	friend std::wistream& operator>>(std::wistream& in, SpecialSymbols& ch) {

		in >> ch.symbol;
		return in;
	}

	// Оператор виводу
	friend std::wostream& operator<<(std::wostream& out, const SpecialSymbols& ch) {

		out << ch.symbol;
		return out;
	}

};

int main() {

	SetConsoleCP(1251); // ввід
	SetConsoleOutputCP(1251); // вивід

	setlocale(LC_ALL, ""); // ставить 1251

	SpecialSymbols first_CH;
	std::wcout << L"Введіть перший символ: ";
	std::wcin >> first_CH;

	SpecialSymbols second_CH;
	std::wcout << L"Введіть другий символ: ";
	std::wcin >> second_CH;


	if (first_CH == second_CH) {
		std::wcout << L"Символи '" << first_CH << L"' та '" << second_CH << L"' на вигляд співпадають." << std::endl;
	}
	else {
		std::wcout << L"Символи '" << first_CH << L"' та '" << second_CH << L"' на вигляд НЕ співпадають." << std::endl;
	}

	return 0;
}

