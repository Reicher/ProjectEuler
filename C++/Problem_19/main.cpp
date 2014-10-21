#include <iostream>

using namespace std;

bool LeapYear(short year)
{
  return (year % 4 == 0) && (!(year % 100 == 0) || (year % 400 == 0) );
}

short Problem_18()
{
  short DaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  short sundays = 0;
  short weekday = 0; //0 = monday, 6 = sunday
  
  for(short year = 1900; year <= 2000; ++year){
    DaysInMonth[1] = 28 + LeapYear(year); //feb
    
    for(short month = 1; month <= 12; ++month)
      {
	for(short date = 1; date <= DaysInMonth[month-1]; ++date)
	  {
	    if(date == 1 && weekday == 6 && year > 1900){
	      ++sundays; 
	      cout << date << "/" << month << ", " << year << " was a sunday!" << endl;
	    }

	    ++weekday;
	    weekday = weekday % 7;
	    //cout << date << "/" << month << "/" << year << " was a " << weekday << endl;
	  }
      } 
  }
  
  return sundays;
}

int main(int argc, char* argv[])
{
  cout << "There were " << Problem_18() << " sundays that occured the first of a month between 1 jan 1901 and 31 Dec 2000." << endl;
  
  return 0;
}
