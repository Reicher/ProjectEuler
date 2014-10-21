#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <list>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

string zeroTo19[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven"
		     , "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen"
		     , "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

string twentyTo90[8] = {"twenty", "thirty", "Forty", "fifty"
		       , "sixty", "Seventy", "Eighty", "Ninety"};

class Number
{
public:
   Number(short num) : m_num(num) {};
   short getNum(){return m_num;};
   string toWords()
   {
      short left = m_num;
      string words = "";

      if(left >= 1000)
      {
         short multi = left / 1000;
         words += zeroTo19[multi] + " thousand";
         left -= (1000 * multi);
         if(left)
            words += " and ";
      }
      if(left >= 100)
      {
         short multi = left / 100;
         words += zeroTo19[multi] + " hundred";
         left -= (100 * multi);
         if(left)
            words += " and ";
      }
      if(left >= 20)
      {
         short multi = left / 10;
         words += twentyTo90[multi-2];
         left -= (10 * multi);
         if(left)
            words += "-";
      }
      if(left)
      {
         words += zeroTo19[left];
         left -= 0;
      }
      m_words = words;
      return words;
   }
   string Trimmed()
   {
      string trimmed = "";
      for(unsigned int i = 0; i < m_words.size(); ++i)
      {
         if(m_words[i] != ' ' && m_words[i] != '-')
            trimmed += m_words[i];
      }

      return trimmed;
   }

private:
   short m_num;
   string m_words;
};

int main(int argc, char* argv[])
{
  
  int n = atoi(argv[1]);
  Number* num;
  int sum = 0;
  for(int i = 1; i <= n; ++i)
    {
      num = new Number(i);
      cout << i << ": " << num->toWords() << " = " << num->Trimmed().size() << endl; 
      sum += num->Trimmed().size();
    }

  cout << endl << "1 - " << n << " = " << sum << " trimmed letters" << endl;
  
  return 0;
}
