#include <stdio.h>

int date_to_year(int year, int month, int day, int current_year, int current_month, int current_day);
int days_from_month(int birth_month, int birth_day, int current_month, int current_day);
int leap_counter(int birth_year, int current_year);

int main(void)	{
	int year, month, day, current_year, current_month, current_day;
	
	fprintf(stdout,"Enter the year you were born, the numerical value of the month you were born, and the day of the month: \n");
	fscanf(stdin," %d %d %d", &year, &month, &day);
	month -= 1;
	fprintf(stdout,"%d %d %d\n", year, month, day);
	fprintf(stdout,"Enter the current year, numerical month, and day of the month:\n");
	fscanf(stdin,"%d %d %d", &current_year, &current_month, &current_day);
	current_month -= 1;
	fprintf(stdout,"You've been alive for %d days\n",date_to_year(year, month, day, current_year, current_month, current_day));
	
	return 0;
}

int date_to_year(int year, int month, int day, int current_year, int current_month, int today)	{
	int total_days;

	if(current_month != month)	{
		total_days += days_from_month(month,day,current_month,today);
	}
	else	{
  	if(day > today)	{
  		total_days += day - today;
  	}
  	else	{
  		total_days += today - day;
		}    
	}
	
	if(current_month != month)	{
		year += 1;
	}
	total_days += leap_counter(year,current_year) + (365 * (current_year - year));
	
	return total_days;
}

int days_from_month(int birth_month, int birth_day, int current_month, int current_day)	{
	int starting_month, month_day_count, month_counter, counted_days;
	int month_days[] ={31,28,31,30,31,30,31,31,30,31,30,31};
	month_counter = birth_month;

  starting_month = current_month;
  if(birth_month != current_month)	{
  	counted_days = (month_days[birth_month] - birth_day) + current_day;
  	for(month_counter = birth_month; month_counter < 11; month_counter++)	{
  		counted_days += month_days[month_counter];
  		fprintf(stdout,"%d \n",month_day_count);
  	}
  	if(current_month != 0){
  		for(month_counter = 0; month_counter < current_month; month_counter++)	{
  			counted_days += month_days[month_counter];
  		}
  	}
  }
	return counted_days;
}

int leap_counter(int birth_year,int current_year)	{
	int leap_counter, starting_year = 0;
	
	for(starting_year = birth_year; starting_year < current_year; starting_year++)	{
  	if(starting_year % 4 == 0||starting_year % 100 == 0||starting_year % 400 ==0)	{
  		leap_counter +=1;
  	}
  	fprintf(stdout," %d %d\n",leap_counter,starting_year);
  }

	return leap_counter;
}
