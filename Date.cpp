#include <iostream>

#include "Date.h"

using namespace std;

Date::Date()
{
	day = -1;
	month = -1;
	year = -1;
}

Date::Date(int dayn, int monthn, int yearn)
{
	day = dayn;
	month = monthn;
	year = yearn;
}

bool Date::isTrue()
{
	if (month > 12)
	{
		return false;
	}
	if (day > 31) //jezeli dni nie jest za duzo
	{
		return false;
	}
	if (month == 2 && day > 29) //jezeli jestesmy w lutym i ktos wpisal za duzo dni
	{
		return false;
	}
	if (month == 2 && day > 28 && year%4 != 0) //jezeli jestesmy w lutym w rok nieprzestepny
	{
		return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) //jezeli ktorys z tych miesiecy i liczba dni za duza
	{
		return false;
	}
	return true;
}

void Date::printDate()
{
	cout << day << " ";
	switch (month)
	{
	case 1:
	{
		cout << "stycznia ";
		break;
	}
	case 2:
	{
		cout << "lutego ";
		break;
	}
	case 3:
	{
		cout << "marca ";
		break;
	}
	case 4:
	{
		cout << "kwietnia ";
		break;
	}
	case 5:
	{
		cout << "maja ";
		break;
	}
	case 6:
	{
		cout << "czerwca ";
		break;
	}
	case 7:
	{
		cout << "lipca ";
		break;
	}
	case 8:
	{
		cout << "sierpnia ";
		break;
	}
	case 9:
	{
		cout << "wrzesnia ";
		break;
	}
	case 10:
	{
		cout << "pazdziernika ";
		break;
	}
	case 11:
	{
		cout << "listopada ";
		break;
	}
	default:
	{
		cout << "grudnia ";
		break;
	}
	}
	cout << year << "\n";
}

void Date::getCurrentDate()
{
	struct tm now; //tutaj zostanie zapisana aktualna data
	time_t currentTime = time(0);
	localtime_s(&now, &currentTime);
	year = now.tm_year + 1900;
	month = now.tm_mon + 1;
	day = now.tm_mday;
}

int Date::countLeapYears() //do liczenia r??nicy mi?dzy datami - obliczanie lat przest?pnych
{
	int years = year;
	if (month <= 2)
		years--;
	return years / 4;
}

int Date::countDifference(Date dt2) //funkcja do liczenia dni mi?dzy datami
{
	const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	long int n1 = year * 365 + day;
	for (int i = 0; i < month - 1; i++)
		n1 += monthDays[i];
	n1 += this->countLeapYears();
	long int n2 = dt2.year * 365 + dt2.day;
	for (int i = 0; i < dt2.month - 1; i++)
		n2 += monthDays[i];
	n2 += dt2.countLeapYears();
	return abs(n2 - n1);
}

