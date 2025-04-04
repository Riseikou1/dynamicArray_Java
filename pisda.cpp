#include <iostream>
#include <fstream>
#include <ctime>    
using namespace std;

int getDaysInMonth(int month, int year) {
    const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
        return 29; 
    }
    return daysInMonth[month - 1];
}

void printCalendar(int month, int year) {
    struct tm firstDay = { 0 };
    firstDay.tm_year = year - 1900;  
    firstDay.tm_mon = month - 1;     
    firstDay.tm_mday = 1;            
    mktime(&firstDay);              

    int startingDay = firstDay.tm_wday; 
    int daysInMonth = getDaysInMonth(month, year); 

    cout << year << " " << month << "\n";

    for (int i = 0; i < startingDay; i++) {
        cout << "0 ";
    }

    for (int day = 1; day <= daysInMonth; day++) {
        cout << day;
        if ((startingDay + day) % 7 != 0) { 
            cout << " "; 
        } else {
            cout << endl; 
        }
    }

    int remainingDays = (startingDay + daysInMonth) % 7;
    if (remainingDays != 0) {
        for (int i = remainingDays; i < 6; i++) { 
            cout << "0 ";  
        }
        cout << "0";  
    }
    cout << endl;
}

int main() {
    int itercount;
    ifstream infile("inputt.txt");

    infile >> itercount;

    for (int i = 0; i < itercount; i++) {
        int year, month;
        infile >> year >> month; 

        printCalendar(month, year); 
    }

    return 0;
}
