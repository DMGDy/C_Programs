#include <stdio.h>

int date_to_year(int year, int month, int day, int current_year, int current_month, int current_day);
int days_from_month(int birth_month, int birth_day, int current_month, int current_day);
int leap_counter(int birth_year, int current_year);

int main(void)	{
	int year, month, day, current_year, current_month, current_day;
	
	fprintf(stdout,"Enter the year you were born, the numerical value of the month you were born, and the day of the month: \n");
	fscanf(stdin," %d %d %d", &year, &month, &day);
	month -= 1;
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
	if((year % 4 == 0 || year % 100 == 0 || year % 400 == 0) && month == 1 && day == 29)	{
  	total_days += 1;
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
  starting_month = current_month - 1;

  if(birth_month != current_month)	{
  	counted_days = (month_days[birth_month] - birth_day) + current_day;
		month_counter = birth_month;
  	while(month_counter < 11)	{
			month_counter += 1;
  		counted_days += month_days[month_counter];
  	}
  	if(current_month != 0){
			month_counter = 0;
  		while(month_counter < current_month)	{
  			counted_days += month_days[month_counter];
				month_counter += 1;
  		}
  	}
  }
	return counted_days;
}

int leap_counter(int birth_year,int current_year)	{
	int leap_counter, starting_year = 0;
	
	for(starting_year = birth_year ; starting_year < current_year; starting_year++)	{
  	if(starting_year % 4 == 0||starting_year % 100 == 0||starting_year % 400 == 0)	{
  		leap_counter +=1;
  	}
  }

	return leap_counter;
}
