#pragma once
#include <string>
#include <sstream>
#include <iostream>




// Fraction class
class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int day, int month, int year);
        Date(const Date& date);
        ~Date();
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
        int getDay();
        int getMonth();
        int getYear();
        std::string toString();
        Date& operator=(const Date& date);
        friend std::ostream& operator<<(std::ostream& os, const Date& date);
        friend std::istream& operator>>(std::istream& is, Date& date);
        friend bool operator==(const Date& date1, const Date& date2);
        friend bool operator!=(const Date& date1, const Date& date2);
        friend bool operator<(const Date& date1, const Date& date2);
        friend bool operator>(const Date& date1, const Date& date2);
        friend bool operator<=(const Date& date1, const Date& date2);
        friend bool operator>=(const Date& date1, const Date& date2);
        friend Date operator+(const Date& date, int days);
        friend Date operator-(const Date& date, int days);
        friend int operator-(const Date& date1, const Date& date2);
        friend Date operator++(Date& date);
        friend Date operator++(Date& date, int);
        friend Date operator--(Date& date);
        friend Date operator--(Date& date, int);
        friend Date operator+=(Date& date, int days);
        friend Date operator-=(Date& date, int days);
        friend Date operator+(const Date& date, const Date& date2);
        friend Date operator++(Date& date, int days);
        friend Date operator--(Date& date, int days);
        friend Date operator+=(Date& date, const Date& date2);
        friend Date operator-=(Date& date, const Date& date2);
        friend bool operator<(const Date& date, int days);
        friend bool operator>(const Date& date, int days);
        friend bool operator<=(const Date& date, int days);
        friend bool operator>=(const Date& date, int days);
        friend bool operator==(const Date& date, int days);
        friend bool operator!=(const Date& date, int days);
};