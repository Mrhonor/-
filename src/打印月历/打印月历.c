#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#include<math.h>
#define	Sun  0
#define	Mon  1
#define	Tue  2
#define	Wed  3
#define	Thu  4
#define	Fri  5
#define	Sat  6
void Output(int, int);
void form(int, int);
int  is_leap_year(int);
void print_day(int, int,int);
char month_name[12][20] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int  month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int main()
{
	int year, month;
	scanf("%d%d", &year, &month);
	Output(year, month);
	return 0;
}

void Output(int year, int month)
{
	form(year, month);
	int day = 1;
	for (int i = 1; i < year; i++) 
	{
		if (is_leap_year(i))
		{
			day += 2;
		}
		else
			day++;
		if (day > 6)
			day -= 7;
	}
	for(int i = 0;i<month-1;i++)
	{
		day += month_day[i];
	}
	if (is_leap_year(year) && month > 2) day++;
	day %= 7;
	print_day(day, month,year);
}

void form(int year, int month)
{
	printf("%s  %d\n", month_name[month - 1], year);
	printf("     Sun     Mon     Tue     Wed     Thu     Fri     Sat\n");
}

int is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

void print_day(int day, int month,int year)
{
	if (month == 2 && is_leap_year(year))
		month_day[1] = 29;
	switch (day)
	{
	case Sun:
		for (int i = 1; i <= month_day[month-1]; i++)
		{
			printf("%8d", i);
			if (i % 7 == 0) printf("\n");
		}
		if ((day + month_day[month - 1]-1) % 7 != Sat) printf("\n");
		break;

	case Mon:
		printf("        ");
		for (int i = 1; i <= month_day[month-1]; i++)
		{
			printf("%8d", i);
			if (i % 7 == 6) printf("\n");
		}
		if ((day + month_day[month - 1]-1) % 7 != Sat) printf("\n");
		break;

	case Tue:
		printf("                ");
		for (int i = 1; i <= month_day[month-1]; i++)
		{
			printf("%8d", i);
			if (i % 7 == 5) printf("\n");
		}
		if ((day + month_day[month - 1]-1) % 7 != Sat) printf("\n");
		break;

	case Wed:
		printf("                        ");
		for (int i = 1; i <= month_day[month-1]; i++)
		{
			printf("%8d", i);
			if (i % 7 == 4) printf("\n");
		}
		if ((day + month_day[month - 1]-1) % 7 != Sat) printf("\n");
		break;

	case Thu:
		printf("                                ");
		for (int i = 1; i <= month_day[month-1]; i++)
		{
			printf("%8d", i);
			if (i % 7 == 3) printf("\n");
		}
		if ((day + month_day[month - 1]-1) % 7 != Sat) printf("\n");
		break;

	case Fri:
		printf("                                        ");
		for (int i = 1; i <= month_day[month-1]; i++)
		{
			printf("%8d", i);
			if (i % 7 == 2) printf("\n");
		}
		if ((day + month_day[month - 1]-1) % 7 != Sat) printf("\n");
		break;

	case Sat:
		printf("                                                ");
		for (int i = 1; i <= month_day[month-1]; i++)
		{
			printf("%8d", i);
			if (i % 7 == 1) printf("\n");
		}
		if ((day + month_day[month - 1]-1) % 7 != Sat) printf("\n");
		break;
	default:
		break;
	}
	month_day[2] = 28;
}