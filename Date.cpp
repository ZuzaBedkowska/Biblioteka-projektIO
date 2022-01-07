#include <iostream>
#include "Date.h"

using namespace std;

bool Date::isTrue()
{
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
