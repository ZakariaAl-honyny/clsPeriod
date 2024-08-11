#pragma once
#include"clsDate.h"

using namespace std;

class clsPeriod
{
private:
        clsDate _StartDate;
        clsDate _EndDate;

public:

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->_StartDate = StartDate;
        this->_EndDate = EndDate;
    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {
        if (clsDate::CompareDates(Period1._StartDate, Period2._EndDate) == clsDate::enDatesCompare::After ||
            clsDate::CompareDates(Period1._EndDate, Period2._StartDate) == clsDate::enDatesCompare::Before)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool IsOverlapPeriods(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }
   
    void Print()
    {
        cout << "Period Start:";
        _StartDate.Print();

        cout << "Period End  :";
        _EndDate.Print();

    }

   static int PeriodLengthInDays(clsPeriod Period, bool IncludingEndDay = false)
   {
       return clsDate::GetDifferenceInDays(Period._StartDate, Period._EndDate, IncludingEndDay);
   }
   
   int PeriodLengthInDays(bool IncludingEndDay = false)
   {
       return PeriodLengthInDays(*this, IncludingEndDay);
   }

   static int CurrentDateToEndDatePeriodLengthInDays(clsDate EndDatePeriod, bool IncludingEndDate = false)
   {
       return clsDate::GetDifferenceInDays(clsDate::GetSystemDate(), EndDatePeriod, IncludingEndDate);
   }

    static bool IsDateInPeriod(clsDate Date, clsPeriod Period)
    {
        //return (clsDate::CompareDates(Date, Period._StartDate) == clsDate::enDatesCompare::After && clsDate::CompareDates(Date, Period._EndDate) == clsDate::enDatesCompare::Before);
        //Or any one the same result
        return !(clsDate::CompareDates(Date, Period._StartDate) == clsDate::enDatesCompare::Before || clsDate::CompareDates(Date, Period._EndDate) == clsDate::enDatesCompare::After);
    }

    bool IsDateInPeriod(clsDate Date)
    {
        return IsDateInPeriod(Date, *this);
    }

    static short CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
    {
        int Period1Length = PeriodLengthInDays(Period1);
        int Period2Length = PeriodLengthInDays(Period2);
        int OverlapDays = 0;

        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        if (Period1Length < Period2Length)
        {

            while (clsDate::IsDate1BeforeDate2(Period1._StartDate, Period1._EndDate))
            {

                if (IsDateInPeriod(Period1._StartDate, Period2))
                    OverlapDays++;

                Period1._StartDate = clsDate::AddOneDay(Period1._StartDate);
            }
        }

        else
        {
            while (clsDate::IsDate1BeforeDate2(Period2._StartDate, Period2._EndDate))
            {

                if (IsDateInPeriod(Period2._StartDate, Period1))
                    OverlapDays++;

                Period2._StartDate = clsDate::AddOneDay(Period2._StartDate);
            }
        }

        return OverlapDays;
    }

    short CountOverlapDays(clsPeriod Period2)
    {
        return CountOverlapDays(*this, Period2);
    }
};

