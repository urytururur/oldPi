#include "date_handling.h"

void get(Date_type & date)
{
    std::cin >> date.year;      //bryts HÄR när ctrl+d
    std::cin >> date.month;
    std::cin >> date.day;
}

void Date_type::log()
{
    std::cout << "hej" << std::endl;
}