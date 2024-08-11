

#include <iostream>
#include "clsPeriod.h";
using namespace std;

int main()
{  
    
    clsPeriod Period1(clsDate(1, 1, 2024), clsDate(30, 1, 2024));
    Period1.Print();
    cout << "\nOverlap between two Periods are: " << Period1.IsOverlapPeriods()) << endl;
    cout << "\nPeriod Length in Days: " << Period1.PeriodLengthInDays(true) << endl;
    cout << "\nNumber Of Days are overlaping between two Periods are: " << Period1.CountOverlapDays(clsPeriod(clsDate(15, 1, 2024), clsDate(10, 2, 2024)))<< endl;
    cout << "\nNumber Of Days are overlaping between two Periods are: " << Period1.CountOverlapDays(clsPeriod(clsDate(1, 1, 2024), clsDate(30, 1, 2024)), clsPeriod(clsDate(15, 1, 2024), clsDate(10, 2, 2024))) << endl;

    system("pause>0");
    return 0;
}









