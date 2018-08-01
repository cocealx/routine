#include"date.h"
//1  2  3  4  5  6  7  8  9  10 11 12
//31 28 31 30 31 30 31 31 30 31 30 31
//31 29 31 30 31 30 31 31 30 31 30 31

int Date::CountDay(int  yearcur)
{
	int montharr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sumday = 0;
	int year = _year;
	int Sunyear = 0;
	while (year++ < yearcur)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			Sunyear = 366;
		else
		{
			Sunyear = 365;
		}
		sumday += Sunyear;
	}
	return sumday;
}

void Date::CountSpace(int  year, int(&countspace)[12], int (&montharr)[12])
{
	int total = CountDay(year);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		montharr[1] = 29;
	for (int i = 0; i < 12; ++i)
	{
		countspace[i] = (_week + total)%7;
		total += montharr[i];
	}
}void Date::displayonemonth(int year, int month)
{
	int montharr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int countspace[12] = { 0 };
	//获得每个月开始的空格数
	CountSpace(year, countspace, montharr);
	printf("%6d月		\n", month);
	printf("日 一 二 三 四 五 六   \n");
	int i = 0;
	for (; i < countspace[month-1]; ++i)
	{
		printf("   ");
	}
	for (int j = 1; j <= montharr[month-1]; ++j,++i)
	{
		
		if (i>1&&i % 7 == 0)
		{
			printf("\n");
		}	
		printf("%-3d", j);
	}
}
void Date::display(int year,int k)
{
	int montharr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int countspace[12] = { 0 };
	//获得每个月开始的空格数
	CountSpace(year, countspace, montharr);
	for (int i = 0; i < k; i+=3)
	{
		int cur[3] = { 1, 1, 1 };
		int q = 1;
		//printf("%6d月		%6d月		%6d月\n", i+1,i+2,i+3);
		//printf("日 一 二 三 四 五 六   日 一 二 三 四 五 六   日 一 二 三 四 五 六\n");
		for (int x = 0; x<3; )
		{
			for (int z = i; z < i+3&&z<k; ++z)
			{
				int j = 0;
				for (; j < countspace[z] && cur[z % 3]==1; ++j)
				{
					while (q==1)
					{
						for (int n = i; n < i + 3 && n<k; ++n)
						{
							printf("%6d月		",n+1);
						}
						printf("\n");
						for (int n = i; n < i+3 && n<k; ++n)
						{
							printf("日 一 二 三 四 五 六   ");
						}
						printf("\n");
						--q;
					}
					printf("   ");
				}
				for (; j < 7; ++j)
				{
					if (cur[z % 3]>montharr[z])
					{
						++x;
						while (j++ < 7)
						{
							printf("   ");
						}
						break;
					}
					printf("%-3d", cur[z % 3]++);
				}
				cout << "  ";
			}
		cout << endl;
		}
		cout << endl;
	}
}

//Date& Date::operator=(const Date& d)
//{
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//	return *this;
//}

//// 前置++ 
//Date&  Date::operator++()
//{
//	switch (_month)
//	{
//	case 1:
//	case 3:
//	case 5:
//	case 7:
//	case 8:
//	case 10:
//	case 12:
//	{
//			   if (_day == 31)
//			   {
//				   if (_month == 12)
//				   {
//					   _year += 1;
//					   _day = 1;
//					   _month = 1;
//				   }
//				   else
//				   {
//					   _day = 1;
//					   _month += 1;
//				   }
//			   }
//			   else
//			   {
//				   _day += 1;
//			   }
//			   break;
//	}
//	case 2:
//	{
//			  if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
//			  {
//				  if (_day == 29)
//				  {
//					  _month += 1;
//					  _day = 1;
//				  }
//				  else
//				  {
//					  _day += 1;
//				  }
//			  }
//			  else
//			  {
//				  if (_day == 28)
//				  {
//					  _month += 1;
//					  _day = 1;
//				  }
//				  else
//				  {
//					  _day += 1;
//				  }
//			  }
//			  break;
//	}
//
//	default:
//	{
//			   if (_day == 30)
//			   {
//
//					   _day = 1;
//					   _month += 1;
//			   }
//			   else
//			   {
//				   _day += 1;
//			   }
//			   break;
//	}
//    }
//	return *this;
//}
//// 后置++ 
//Date Date:: operator++(int)
//{
//	Date temp(*this);
//	++(*this);
//	return temp;
//}
//Date&  Date::operator--()
//{
//	if (_day == 1)
//	{
//		switch (_month)
//		{
//		case 1:
//		{
//					  _year -= 1;
//					  _month = 12;
//					  _day = 31;
//					  break;
//		}
//		case 2://1 3 5 7 8 10 12
//		case 4:
//		case 6:
//		case 8:
//		case 9:
//		case 11:
//		{
//				   _month -= 1;
//				   _day = 31;
//				   break;
//		}
//		case 3:
//		{
//				  if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
//				  {
//					  _month -= 1;
//					  _day = 29;
//				  }
//				  else
//				  {
//					  _month -= 1;
//					  _day = 28;
//				  }
//				  break;
//		}
//
//		default:
//		{
//				 _month -= 1;
//				 _day = 30;
//				 break;
//		}
//		}	
//	}
//	else
//	{
//		_day -= 1;
//	}
//	return *this;
//}
//Date  Date::operator--(int)
//{
//	Date temp(*this);
//	--(*this);
//	return temp;
//	
//}
//
////days天之后的日期 
//Date  Date::operator+(int days)
//{
//	int i = 0;
//	for (; i < days; i++)
//	{
//		++(*this);
//	}
//	return *this;
//}
//// days天之前的日期 
//Date  Date::operator-(int days)
//{
//	int i = 0;
//	for (; i < days; i++)
//	{
//		--(*this);
//	}
//	return *this;
//}
//
//// 两个日期之间的距离 
//int  Date::operator-(const Date& d)
//{
//	 Date max;
//	 Date min;
//	 int i = 0;
//	if (_year == d._year)
//	{
//		
//		max = _month>d._month ? *this : d;
//	    min = _month<d._month ? *this : d;
//		i = min._month;
//	}
//	else
//	{
//		 max = _year>d._year ? *this : d;
//		 min = _year<d._year ? *this : d;
//	}
//	int count = 0;
//	if (max._year != min._year)
//	{
//		i = min._month;
//		for (; i< 13; ++i)
//		{
//			switch (i)
//			{
//			case 1:
//			case 3:
//			case 5:
//			case 7:
//			case 8:
//			case 10:
//			case 12:
//				count += 31;
//				break;
//			case 2:
//				if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
//					count += 29;
//				else
//					count += 28;
//				break;
//			default:
//				count += 30;
//				break;
//			}
//		}
//		count -= min._day;
//		++min._year;
//		i = 1;
//		min._day = 0;
//	}
//	while (max._year != min._year)
//	{
//		if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
//		{
//			count += 366;
//		}
//		else
//		{
//			count += 365;
//		}
//		min._year += 1;
//	}
//	
//	for (;i< max._month; ++i)
//	{
//		switch (i)
//		{
//		case 1:
//		case 3:
//		case 5:
//		case 7:
//		case 8:
//		case 10 :
//		case 12:
//			count += 31;
//			break;
//		case 2:
//			if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
//				count += 29;
//			else
//				count += 28;
//			break;
//		default:
//			count += 30;
//			break;
//		}
//	}
//	count -= min._day;
//	count += max._day;
//	return count;
//
//}
//bool  Date::operator==(const Date& d)
//{
//	if (_day == d._day&&_month == d._month&&_year == d._year)
//		return true;
//	return false;
//}
//bool  Date::operator!=(const Date& d)
//{
//	if (_day == d._day&&_month == d._month&&_year == d._year)
//		return false;
//	return true;
//}