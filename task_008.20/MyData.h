#ifndef MY_DATA_H
#define MY_DATA_H

#include <iostream>

namespace MY {

    class Data {
    private:
        static const int daysInMonth[];

        bool isLeapYear(int p_year) const;
        int  daysFromStartOfEra() const;
        void dateFromDays(int totalDays);

    private:
        char day;
        char month;
        int year;

    public:
        Data(int y, char m, char d);

        int operator-(const Data& other) const;

        Data& operator-(const int days);
        Data& operator+(const int days);

        friend std::ostream& operator<<(std::ostream& out, const Data& data);
        
    };

}  // namespace MY

#endif // MY_DATA_H
