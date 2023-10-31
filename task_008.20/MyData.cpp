#include "MyData.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

namespace MY {

    const int Data::daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    //---------------------------------------------
    bool Data::isValidDate() const {
        if (month < 1 || month > 12 || day < 1) {
            return false;
        }

        // Перевірка на високосний рік (29 днів у лютому)
        if (month == 2 && isLeapYear(year)) {
            if (day > 29) {
                return false;
            }
        }
        else {
            if (day > daysInMonth[month - 1]) {
                return false;
            }
        }

        return true;
    }
    //---------------------------------------------
    bool Data::isLeapYear(int p_year) const {
        return (p_year % 4 == 0 && p_year % 100 != 0) || (p_year % 400 == 0);
    }
    //---------------------------------------------
    int  Data::daysFromStartOfEra() const {

        int totalDays = (year - 1) * 365;

        for (int i = 1; i < year; ++i) {
            if (isLeapYear(i)) {
                totalDays += 1;
            }
        }

        for (int i = 1; i < month; ++i) {
            totalDays += daysInMonth[i - 1];
            if (i == 2 && isLeapYear(year)) {
                totalDays += 1;
            }
        }

        totalDays += day;

        return totalDays;
    }
    //---------------------------------------------
    void Data::dateFromDays(int totalDays) {
        
        year = 1;
        while (totalDays > 365) {
            if (isLeapYear(year)) {
                if (totalDays > 366) {
                    totalDays -= 366;
                }
                else {
                    break;
                }
            }
            else {
                totalDays -= 365;
            }
            year++;
        }

        month = 1;
        while (totalDays > daysInMonth[month - 1]) {
            if (month == 2 && isLeapYear(year)) {
                if (totalDays > 29) {
                    totalDays -= 29;
                }
                else {
                    break;
                }
            }
            else {
                totalDays -= daysInMonth[month - 1];
            }
            month++;
        }

        day = static_cast<char>(totalDays);
        
    }
    //---------------------------------------------
    Data::Data(int y, char m, char d) : day(d), month(m), year(y) {
        if (!isValidDate()) {
            throw std::invalid_argument("Некоректна дата.");
        }
    }
    //---------------------------------------------
    int Data::operator-(const Data& other) const {
        int days1 = daysFromStartOfEra()      ;
        int days2 = other.daysFromStartOfEra();
        return days1 - days2;
    }
    //---------------------------------------------
    Data& Data::operator-(const int p_days) {

        int days = daysFromStartOfEra();
        days -= p_days;

        dateFromDays(days);
        return *this;
    }
    //---------------------------------------------
    Data& Data::operator+(const int p_days) {
        
        int days = daysFromStartOfEra();
        days += p_days;

        dateFromDays(days);
        return *this;
    }
    //---------------------------------------------
    std::ostream& operator<<(std::ostream& out, const Data& data) {

        std::ios_base::fmtflags flags = out.flags(); // Зберігаємо поточні прапорці виведення
        out << std::setw(4) << std::setfill('0') << data.year << "."
            << std::setw(2) << static_cast<int>(data.month) << "."
            << std::setw(2) << static_cast<int>(data.day);
        out.flags(flags);

        return out;
    }
    //---------------------------------------------

}  // namespace MY

