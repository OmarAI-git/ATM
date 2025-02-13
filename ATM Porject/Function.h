#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include<fstream>

using namespace std;

namespace Function
{
	enum enCompareDates { Equal = 0, Before = -1, After = 1 };

	struct strDate
	{
		short Year;
		short Month;
		short Day;
	};

	struct strPeriods
	{
		strDate dateStart;
		strDate dateEnds;
	};

	bool IsLeapYear(int Number)
	{
		return ((Number % 100 != 0 && Number % 4 == 0) || Number % 400 == 0);
	}

	short NumberOfDaysInMonth(short month, short year)
	{
		if (month < 1 || month>12)
		{
			return 0;
		}

		/*short monthArray[] = { 0,31,IsLeapYear(year) ? 29 : 28,31,30,31,30,31,31,30,31,30,31 };

		return monthArray[month];*/

		short monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		return(month == 2) ? (IsLeapYear(year) ? 29 : 28) : monthArray[month];
	}

	short NumberOfDaysFromBeginningOfYear(strDate date)
	{
		short totalDays = 0;

		for (int i = 1; i < date.Month; i++)
		{
			totalDays += NumberOfDaysInMonth(i, date.Year);
		}

		totalDays += date.Day;

		return totalDays;
	}

	strDate GetDateDaysFromBeginningOfYear(short days, short year)
	{
		strDate daysDate;

		short remainingDays = days;
		short monthDays = 0;

		daysDate.Year = year;
		daysDate.Month = 1;

		while (true)
		{
			monthDays += NumberOfDaysInMonth(daysDate.Month, year);

			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				daysDate.Month++;
				monthDays = 0;
			}

			else
			{
				daysDate.Day = remainingDays;
				break;
			}
		}

		return daysDate;
	}

	strDate GetDateAfterAddingDays(strDate date, short daysAdd)
	{
		short remainingDays = daysAdd + NumberOfDaysFromBeginningOfYear(date);
		date.Month = 1;
		short daysMonth = 0;

		while (true)
		{
			daysMonth = NumberOfDaysInMonth(date.Month, date.Year);

			if (remainingDays > daysMonth)
			{
				remainingDays -= daysMonth;
				date.Month++;

				if (date.Month > 12)
				{
					date.Year++;
					date.Month = 1;
				}

			}

			else
			{
				date.Day = remainingDays;
				break;
			}
		}

		return date;
	}

	void PrintFileContenet(string FileName)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::in);//Read Mode.

		if (MyFile.is_open())
		{

			string line;

			while (getline(MyFile, line))
			{
				cout << line << endl;
			}
			MyFile.close();
		}
	}

	void ReadArray(int Array[], int length)
	{
		Array[length];
		for (int i = 0; i < length; i++)
		{
			cout << "Enter element [" << i + 1 << "] : ";
			cin >> Array[i];
		}
	}

	int RandomNumber(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}

	int ReadNumber(string Message)
	{
		int Number;
		cout << Message;
		cin >> Number;
		return Number;
	}

	short NumberOfDaysInYear(short year)
	{
		return IsLeapYear(year) ? 366 : 365;
	}

	short NumberOfHoursInYear(short year)
	{
		return 24 * NumberOfDaysInYear(year);
	}

	int NumberOfMinutesInYear(short year)
	{
		return NumberOfHoursInYear(year) * 60;
	}

	int NumberOfSecondsInYear(short year)
	{
		return NumberOfMinutesInYear(year) * 60;
	}

	short IndexDay(short day, short month, short year)
	{
		short a, m, y, d;

		a = ((14 - month) / 12);//or I can use abs((14 - month) / 12)
		y = year - a;
		m = month + 12 * a - 2;

		d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}

	string DayOfWeek(short day, short month, short year)
	{
		string dayOfWeek[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

		return dayOfWeek[IndexDay(day, month, year)];
	}

	string MonthOfYear(short month)
	{
		string monthOfYear[] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

		return monthOfYear[month];
	}

	void PrintMonthCalendar(short month, short year)
	{
		int numberOfDays;

		//Index of the day from 0 to 6
		int current = IndexDay(1, month, year);

		numberOfDays = NumberOfDaysInMonth(month, year);

		printf("\n-------------------%s----------------------\n", MonthOfYear(month).c_str());

		// Print the columns    
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		// Print appropriate spacesint i; 
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= numberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				printf("\n");
				i = 0;
			}

		}

		printf("\n--------------------------------------------\n");

	}

	void PrintYearCalendar(short year)
	{
		printf("\n--------------------------------------------\n");
		printf("\t     Calendar - %d\n", year);
		printf("--------------------------------------------\n");

		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, year);
			printf("\n");
		}

		return;
	}

	string ReadString(string Message)
	{
		string word;
		cout << Message;
		getline(cin >> ws, word);
		return word;
	}

	char ReadCharacter(string Message)
	{
		char letter;
		cout << Message;
		cin >> letter;
		return letter;
	}

	char InvertCharcter(char letter)
	{
		return isupper(letter) ? tolower(letter) : toupper(letter);
	}

	string InvertAllCharacter(string name)
	{
		for (int i = 0; i < name.length(); i++)
		{
			name[i] = isupper(name[i]) ? tolower(name[i]) : toupper(name[i]);
		}
		return name;
	}

	short CountUpperLetter(string name)
	{
		short count = 0;
		for (short i = 0; i < name.length(); i++)
		{
			if (isupper(name[i]))
				count++;
		}
		return count;

	}

	short CountLowerLetter(string name)
	{
		short count = 0;
		for (short i = 0; i < name.length(); i++)
		{
			if (islower(name[i]))
				count++;
		}
		return count;
	}

	short CountCharacter(string name, char letter, bool matchCase)
	{
		short count = 0;
		for (short i = 0; i < name.length(); i++)
		{
			if (matchCase)
			{
				if (name[i] == letter)
				{
					count++;
				}
			}
			else
			{
				if (tolower(name[i]) == tolower(letter))
				{
					count++;
				}
			}
		}
		return count;
	}

	bool IsVowel(char letter)
	{
		letter = tolower(letter);
		return (letter == 'a' || letter == 'o' || letter == 'u' || letter == 'e' || letter == 'i');
	}

	string JoinString(vector <string> vS, string Punctuation)
	{
		string joinString = "";

		for (string& S : vS)
		{
			joinString = joinString + S + Punctuation;
		}

		return joinString.substr(0, joinString.length() - Punctuation.length());

	}

	string JoinString(string arr[], short length, string Punctuation)
	{
		string joinString = "";
		for (short i = 0; i < length; i++)
		{
			joinString = joinString + arr[i] + Punctuation;
		}
		return joinString.substr(0, joinString.length() - Punctuation.length());
	}

	vector <string> SpiltFunction(string S1, string delimiter)
	{
		vector <string> spilt;
		string sWord;
		short pos = 0;

		cout << endl << endl;
		// use find() function to get the position of the delimiter
		while ((pos = S1.find(delimiter)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);

			if (sWord != delimiter)
			{
				spilt.push_back(sWord);
			}

			S1.erase(0, pos + delimiter.length());// erase() until position and move to next word
		}

		if (S1 != delimiter)
		{
			spilt.push_back(S1);// it adds last word of the string
		}

		return spilt;
	}

	bool IsDate1BeforeDate2(strDate Date1, strDate Date2)
	{

		return	(Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	bool CompareDatesEquals(strDate Date1, strDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day ? true : false) : false) : false;

	}

	strDate ReadFullDate()
	{
		strDate date;

		date.Year = Function::ReadNumber("\nPlease enter a year? ");
		date.Month = Function::ReadNumber("\nPlease enter a month? ");
		date.Day = Function::ReadNumber("\nPlease enter a day? ");

		return date;
	}

	bool IsLastDayInMonth(short year, short month, short day)
	{
		return day == Function::NumberOfDaysInMonth(month, year);
	}

	bool IsLastMonthInYear(short month)
	{
		return month == 12;
	}

	void SwapDates(strDate& date1, strDate& date2)
	{
		strDate temp;
		temp.Year = date1.Year;
		temp.Month = date1.Month;
		temp.Day = date1.Day;

		date1.Year = date2.Year;
		date1.Month = date2.Month;
		date1.Day = date2.Day;

		date2.Year = temp.Year;
		date2.Month = temp.Month;
		date2.Day = temp.Day;
	}

	strDate IncreaseDateByOneDay(strDate& date)
	{
		if (IsLastDayInMonth(date.Year, date.Month, date.Day))
		{
			if (IsLastMonthInYear(date.Month))
			{

				date.Month = 1;
				date.Day = 1;
				date.Year++;
			}
			else
			{
				date.Month++;
				date.Day = 1;
			}
		}

		else
		{
			date.Day++;
		}

		return date;
	}

	short GetDifferenceInDays(strDate Date1, strDate Date2, bool IncludeEndDay = false)
	{
		short diffDays = 0;
		short swapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			swapFlagValue = -1;

		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			diffDays++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IncludeEndDay ? ++diffDays * swapFlagValue : diffDays * swapFlagValue;
	}

	strDate GetSystemDate()
	{
		strDate Date;

		time_t t = time(0);

		tm* now = localtime(&t);

		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;
	}

	strDate IncreaseDateByXDays(strDate& date, short days)
	{
		for (short i = 1; i <= days; i++)
		{
			date = IncreaseDateByOneDay(date);
		}
		return date;
	}

	strDate IncreaseDateByOneWeek(strDate& date)
	{
		for (int i = 1; i <= 7; i++)
		{
			date = IncreaseDateByOneDay(date);
		}
		return date;
	}

	strDate IncreaseDateByXWeeks(strDate& date, short weeks)
	{
		for (short i = 1; i <= weeks; i++)
		{
			date = IncreaseDateByOneWeek(date);
		}
		return date;
	}

	strDate IncreaseDateByOneMonth(strDate& date)
	{
		if (date.Month == 12)
		{
			date.Month = 1;
			date.Year++;
		}
		else
		{
			date.Month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022

		short numberOfDay = Function::NumberOfDaysInMonth(date.Month, date.Year);

		if (date.Day > numberOfDay)
		{
			date.Day = numberOfDay;
		}

		return date;
	}

	strDate IncreaseDateByXMonths(strDate& date, short month)
	{
		for (int i = 1; i <= month; i++)
		{
			date = IncreaseDateByOneMonth(date);
		}

		return date;
	}

	strDate IncreaseDateByOneYear(strDate& date)
	{
		date.Year++;
		return date;
	}

	strDate IncreaseDateByXYears(strDate& date, short year)
	{
		for (short i = 1; i <= year; i++)
		{
			date = IncreaseDateByOneYear(date);
		}
		return date;
	}

	strDate IncreaseDateByXYearsFaster(strDate& date, short year)
	{
		date.Year += year;
		return date;
	}

	strDate IncreaseDateByOneDecade(strDate& date)
	{
		date.Year += 10;
		return date;
	}

	strDate IncreaseDateByXDecades(strDate& date, short decade)
	{
		for (short i = 1; i <= decade * 10; i++)
		{
			date = IncreaseDateByOneYear(date);
		}
		return date;
	}

	strDate IncreaseDateByXDecadesFaster(strDate& date, short decade)
	{
		date.Year += (10 * decade);
		return date;
	}

	strDate IncreaseDateByOneCentury(strDate& date)
	{
		date.Year += 100;
		return date;
	}

	strDate IncreaseDateByOneMillennium(strDate& date)
	{
		date.Year += 1000;
		return date;
	}

	strDate DecreaseDateByOneDay(strDate& date)
	{
		if (date.Day == 1)
		{
			if (date.Month == 1)
			{

				date.Month = 12;
				date.Day = 31;
				date.Year--;
			}
			else
			{
				date.Month--;
				date.Day = Function::NumberOfDaysInMonth(date.Month, date.Year);
			}
		}

		else
		{
			date.Day--;
		}

		return date;
	}

	strDate DecreaseDateByXDays(strDate& date, short days)
	{
		for (short i = 1; i <= days; i++)
		{
			date = DecreaseDateByOneDay(date);
		}
		return date;
	}

	strDate DecreaseDateByOneWeek(strDate& date)
	{
		for (int i = 1; i <= 7; i++)
		{
			date = DecreaseDateByOneDay(date);
		}
		return date;
	}

	strDate DecreaseDateByXWeeks(strDate& date, short weeks)
	{
		for (short i = 1; i <= weeks; i++)
		{
			date = DecreaseDateByOneWeek(date);
		}
		return date;
	}

	strDate DecreaseDateByOneMonth(strDate& date)
	{
		if (date.Month == 1)
		{
			date.Month = 12;
			date.Year--;
		}
		else
		{
			date.Month--;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
		// be 28/2/2022

		short numberOfDay = Function::NumberOfDaysInMonth(date.Month, date.Year);

		if (date.Day > numberOfDay)
		{
			date.Day = numberOfDay;
		}

		return date;
	}

	strDate DecreaseDateByXMonths(strDate& date, short month)
	{
		for (int i = 1; i <= month; i++)
		{
			date = DecreaseDateByOneMonth(date);
		}

		return date;
	}

	strDate DecreaseDateByOneYear(strDate& date)
	{
		date.Year--;
		return date;
	}

	strDate DecreaseDateByXYears(strDate& date, short year)
	{
		for (short i = 1; i <= year; i++)
		{
			date = DecreaseDateByOneYear(date);
		}
		return date;
	}

	strDate DecreaseDateByXYearsFaster(strDate& date, short year)
	{
		date.Year -= year;
		return date;
	}

	strDate DecreaseDateByOneDecade(strDate& date)
	{
		date.Year -= 10;
		return date;
	}

	strDate DecreaseDateByXDecades(strDate& date, short decade)
	{
		for (short i = 1; i <= decade * 10; i++)
		{
			date = DecreaseDateByOneYear(date);
		}
		return date;
	}

	strDate DecreaseDateByXDecadesFaster(strDate& date, short decade)
	{
		date.Year -= (10 * decade);
		return date;
	}

	strDate DecreaseDateByOneCentury(strDate& date)
	{
		date.Year -= 100;
		return date;
	}

	strDate DecreaseDateByOneMillennium(strDate& date)
	{
		date.Year -= 1000;
		return date;
	}

	short IndexDay(strDate date)
	{
		short a, m, y, d;

		a = ((14 - date.Month) / 12);//or I can use abs((14 - month) / 12)
		y = date.Year - a;
		m = date.Month + 12 * a - 2;

		d = (date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}

	string DayName(strDate date)
	{
		short day = IndexDay(date);

		string dayOfWeek[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

		return dayOfWeek[day];
	}

	bool IsEndOfWeek(strDate date)
	{
		return IndexDay(date) == 6;
	}

	bool IsWeekEnd(strDate date)
	{
		short index = IndexDay(date);

		if (index == 5 || index == 6)
			return true;

		return false;
	}

	bool IsBusinessDay(strDate date)
	{
		if (!IsWeekEnd(date))
			return true;

		return false;
	}

	short DaysUntilTheEndOfWeek(strDate date)
	{
		short index = IndexDay(date);
		return 6 - index;
	}

	short DaysUntilTheEndOfMonth(strDate date)
	{
		return  Function::NumberOfDaysInMonth(date.Month, date.Year) - date.Day;
	}

	short DaysUntilTheEndOfYear(strDate date)
	{
		if (Function::IsLeapYear(date.Year))
		{
			return 366 - NumberOfDaysFromBeginningOfYear(date);
		}
		else
		{
			return 365 - NumberOfDaysFromBeginningOfYear(date);
		}

	}

	short ActualVacation(strDate date1, strDate date2)
	{
		short dayNumber = 0, index = 0;

		while (!CompareDatesEquals(date1, date2))
		{
			if (!IsWeekEnd(date1))//or I can use IsBusinessDay() Function it's the same answer.
			{
				dayNumber++;
			}

			date1 = IncreaseDateByOneDay(date1);
		}
		return dayNumber;
	}

	strDate CalculateVacationReturnDate(strDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		//in case the data  is weekend keep adding one day util you reach business day
		//we get rid of all weekends before the first business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}
	
	strDate DateAfterVacation(strDate date, short vacation)
	{
		short equal = 0;

		while (equal != vacation)
		{
			if (IsBusinessDay(date))
			{
				equal++;
			}

			date = IncreaseDateByOneDay(date);
		}
		return date;
	}

	enCompareDates CompareDates(strDate date1, strDate date2)//I can use the short data type for this function.
	{
		if (IsDate1BeforeDate2(date1, date2))
		{
			return enCompareDates::Before;
		}
		else if (CompareDatesEquals(date1, date2))
		{
			return enCompareDates::Equal;
		}

		return enCompareDates::After;
	}

	strPeriods ReadPeriods()
	{
		strPeriods period;

		cout << "\nEnter Date Start:\n";
		period.dateStart = ReadFullDate();

		cout << "\nEnter Date Ends:\n";
		period.dateEnds = ReadFullDate();

		return period;
	}

	bool IsOverlapPeriods(strPeriods Peroid1, strPeriods Peroid2)
	{
		if ((CompareDates(Peroid1.dateEnds, Peroid2.dateStart) == enCompareDates::Before) ||
			(CompareDates(Peroid1.dateStart, Peroid2.dateEnds) == enCompareDates::After))
		{
			return false;
		}
		return true;

	}

	short PeriodLength(strPeriods period, bool include = false)
	{
		/*short days = 0;

		while (IsDate1BeforeDate2(period.dateStart,period.dateEnds))
		{
			days++;
			IncreaseDateByOneDay(period.dateStart);
		}

		if (include)
		{
			days++;
		}

		return days;*/

		return GetDifferenceInDays(period.dateStart, period.dateEnds, include);
	}

	bool IsDateWithInPeriod(strPeriods period, strDate date)
	{
		return (CompareDates(period.dateStart, date) == enCompareDates::Before
			&&
			CompareDates(period.dateEnds, date) == enCompareDates::After);
	}

	short OverlapLength(strPeriods Period1, strPeriods Period2)
	{
		int period1Length = PeriodLength(Period1, true);
		int period2Length = PeriodLength(Period2, true);
		int overlapDays = 1;

		if (!IsOverlapPeriods(Period1, Period2))
		{
			return 0;
		}

		if (period1Length < period2Length)
		{
			while (IsDate1BeforeDate2(Period1.dateStart, Period1.dateEnds))
			{
				if (IsDateWithInPeriod(Period2, Period1.dateStart))
				{
					overlapDays++;
				}

				Period1.dateStart = IncreaseDateByOneDay(Period1.dateStart);
			}
		}

		else
		{
			while (IsDate1BeforeDate2(Period2.dateStart, Period2.dateEnds))
			{
				if (IsDateWithInPeriod(Period1, Period2.dateStart))
				{
					overlapDays++;
				}

				Period2.dateStart = IncreaseDateByOneDay(Period2.dateStart);
			}
		}

		return overlapDays;
	}

	bool IsValidateDate(strDate date)
	{
		/*if (date.Month == 2)
		{
			if (Function::IsLeapYear(date.Year))
			{
				if (date.Day>29)
				{
					return false;
				}
			}
			else
			{
				if (date.Day>28)
				{
					return false;
				}
			}
		}*/


		if (date.Day > Function::NumberOfDaysInMonth(date.Month, date.Year) || date.Day < 1)
		{
			return false;
		}
		else if (date.Month > 12 || date.Month < 1)
		{
			return false;
		}

		return true;
	}

	strDate StringToDate(string date)
	{
		vector<string> sDate;
		sDate = Function::SpiltFunction(date, "/");

		strDate Date;

		Date.Day = stoi(sDate.at(0));
		Date.Month = stoi(sDate.at(1));
		Date.Year = stoi(sDate.at(2));

		return Date;
	}

	string DateToString(strDate date)
	{
		return to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year);
	}

	string ReplaceWordInString(string S, string stringToReplace, string sReplaceTo)
	{
		short pos = S.find(stringToReplace);

		while (pos != std::string::npos)
		{
			S = S.replace(pos, stringToReplace.length(), sReplaceTo);

			pos = S.find(stringToReplace);//find next.
		}

		return S;
	}

	string FormatDate(strDate date, string format = "dd/mm/yyyy")
	{
		string formatDateString = "";

		formatDateString = ReplaceWordInString(format, "dd", to_string(date.Day));
		formatDateString = ReplaceWordInString(formatDateString, "mm", to_string(date.Month));
		formatDateString = ReplaceWordInString(formatDateString, "yyyy", to_string(date.Year));

		return formatDateString;
	}

	string PrintNewDate(strDate date)
	{
		return (to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year));
	}
}