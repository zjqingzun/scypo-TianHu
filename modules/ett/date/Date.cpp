#include "Date.h"




// Constructor
Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

// Constructor
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

// Copy constructor
Date::Date(const Date& date) {
    day = date.day;
    month = date.month;
    year = date.year;
}

// Destructor
Date::~Date() {
}

// Set day
void Date::setDay(int day) {
    this->day = day;
}

// Set month
void Date::setMonth(int month) {
    this->month = month;
}

// Set year
void Date::setYear(int year) {
    this->year = year;
}

// Get day
int Date::getDay() {
    return day;
}

// Get month
int Date::getMonth() {
    return month;
}

// Get year
int Date::getYear() {
    return year;
}

// Convert to string
std::string Date::toString() {
    std::stringstream ss;
    ss << day << "/" << month << "/" << year;
    return ss.str();
}

// Assignment operator
Date& Date::operator=(const Date& date) {
    day = date.day;
    month = date.month;
    year = date.year;
    return *this;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}

// Input operator
std::istream& operator>>(std::istream& is, Date& date) {
    is >> date.day >> date.month >> date.year;
    return is;
}

// Equality operator
bool operator==(const Date& date1, const Date& date2) {
    return date1.day == date2.day && date1.month == date2.month && date1.year == date2.year;
}

// Inequality operator
bool operator!=(const Date& date1, const Date& date2) {
    return !(date1 == date2);
}

// Less than operator
bool operator<(const Date& date1, const Date& date2) {
    if (date1.year < date2.year) {
        return true;
    } else if (date1.year == date2.year) {
        if (date1.month < date2.month) {
            return true;
        } else if (date1.month == date2.month) {
            if (date1.day < date2.day) {
                return true;
            }
        }
    }
    return false;
}

// Greater than operator
bool operator>(const Date& date1, const Date& date2) {
    return date2 < date1;
}

// Less than or equal to operator
bool operator<=(const Date& date1, const Date& date2) {
    return date1 < date2 || date1 == date2;
}

// Greater than or equal to operator
bool operator>=(const Date& date1, const Date& date2) {
    return date1 > date2 || date1 == date2;
}

// Addition operator
Date operator+(const Date& date, int days) {
    Date newDate = date;
    newDate += days;
    return newDate;
}

// Subtraction operator
Date operator-(const Date& date, int days) {
    Date newDate = date;
    newDate -= days;
    return newDate;
}

// Subtraction operator
int operator-(const Date& date1, const Date& date2) {
    int days = 0;
    Date date = date1;
    while (date != date2) {
        date--;
        days++;
    }
    return days;
}

// Increment operator
Date operator++(Date& date) {
    date += 1;
    return date;
}

// Increment operator
Date operator++(Date& date, int) {
    Date oldDate = date;
    date += 1;
    return oldDate;
}

// Decrement operator
Date operator--(Date& date) {
    date -= 1;
    return date;
}

// Decrement operator
Date operator--(Date& date, int) {
    Date oldDate = date;
    date -= 1;
    return oldDate;
}

// Addition assignment operator
Date operator+=(Date& date, int days) {
    for (int i = 0; i < days; i++) {
        date++;
    }
    return date;
}

// Subtraction assignment operator
Date operator-=(Date& date, int days) {
    for (int i = 0; i < days; i++) {
        date--;
    }
    return date;
}

// Addition operator
Date operator+(const Date& date, const Date& date2) {
    Date newDate = date;
    newDate += date2;
    return newDate;
}

// Increment operator
Date operator++(Date& date, int days) {
    for (int i = 0; i < days; i++) {
        date++;
    }
    return date;
}

// Decrement operator
Date operator--(Date& date, int days) {
    for (int i = 0; i < days; i++) {
        date--;
    }
    return date;
}

// Addition assignment operator
Date operator+=(Date& date, const Date& date2) {
    date.day += date2.day;
    date.month += date2.month;
    date.year += date2.year;
    return date;
}

// Subtraction assignment operator
Date operator-=(Date& date, const Date& date2) {
    date.day -= date2.day;
    date.month -= date2.month;
    date.year -= date2.year;
    return date;
}

// Less than operator
bool operator<(const Date& date, int days) {
    Date newDate = date;
    newDate += days;
    return newDate < date;
}

// Greater than operator
bool operator>(const Date& date, int days) {
    Date newDate = date;
    newDate += days;
    return newDate > date;
}

// Less than or equal to operator
bool operator<=(const Date& date, int days) {
    return date < days || date == days;
}

// Greater than or equal to operator
bool operator>=(const Date& date, int days) {
    return date > days || date == days;
}

// Equality operator
bool operator==(const Date& date, int days) {
    Date newDate = date;
    newDate += days;
    return newDate == date;
}

// Inequality operator
bool operator!=(const Date& date, int days) {
    return !(date == days);
}

