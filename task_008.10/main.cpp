#include <iostream>
#include <iomanip>

class Accumulation
{
protected:
    double account = 0.0;
public:
    Accumulation() {}
        
    void setAccount(double value)
    {
        account = value;
    }

    double getAccount() const
    {
        return account;
    }

    Accumulation& operator()(double coefficient)
    {
        account *= coefficient;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Accumulation& accumulation)
    {
        std::ios_base::fmtflags flags = out.flags(); // Зберігаємо поточні прапорці виведення
        out << std::fixed << std::setprecision(2) << accumulation.account;
        out.flags(flags);                            // Відновлюємо попередні прапорці виведення
        return out;
    }
};

int main()
{
    Accumulation accumulation;

    std::cout << std::fixed << std::setprecision(2);   // Встановлюємо виведення з точністю до двох знаків після коми

    std::cout << accumulation         << std::endl;    // Виведе 0.00

    accumulation.setAccount(25.14);

    std::cout << accumulation         << std::endl;    // Виведе 0.00
    std::cout << accumulation(300000) << std::endl;    // Помножить на 3.0, виведе 0.00
    std::cout << accumulation(400000) << std::endl;    // Помножить на 4.0, виведе 0.00

    return 0;
}
