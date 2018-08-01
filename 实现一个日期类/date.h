#pragma
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 2017, int month = 9, int day = 10,int week=1)
		: _year(year)
		, _month(month)
		, _day(day)
		, _week(week)
	{}

	Date& operator=(const Date& d);

	// ǰ��++ 
	Date& operator++();
	// ����++ 
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	//days��֮������� 
	Date operator+(int days);
	// days��֮ǰ������ 
	Date operator-(int days);

	// ��������֮��ľ��� 
	int operator-(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	//
	int CountDay(int);
	void CountSpace(int, int(&countspacce)[12], int(&montharr)[12]);
	void display(int,int k = 12);
	void displayonemonth(int year, int month);
	const int _year;
	const int _month;
	const int _day;
	const int _week;
};

