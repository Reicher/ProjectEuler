#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <math.h>
#include <string>
#include <iosfwd>
#include <list>

using namespace std;

list<string> ReadFromFile(const char *filename)
{
   list<string> stringList;
   string line, name;

   ifstream myfile (filename);
   if (myfile.is_open())
   {
      while ( myfile.good() )
      {
         getline (myfile,line);
         for(unsigned short c = 0; c < line.length(); ++c){
            if(line[c] != '"' && line[c] != ',')
               name += line[c];
            else if(name.length() > 0){
               stringList.push_back(name);
               name = "";
            }
         }
      }
      myfile.close();
   }

   return stringList;
}
double GetPosition(string name)
{
   double posValue = 0;
   for(unsigned short c = 0; c < name.size(); ++c)
   {
      double val = ( ( name[c] - 65.0) )/ pow(10.0, c*2);
      posValue += val;
   }

   return posValue;
}

bool compare_case (std::string first, std::string second)
{
   return GetPosition(first) < GetPosition(second);
}

int NameScore(string name)
{
  int sum = 0;
  for(int c = 0; c < name.size(); ++c)
    sum += name[c] - 64;

  return sum;
}

unsigned long long sumOfNameScores(list<string> *names)
{
  unsigned long long sum = 0;
  short n = 1;
  for(list<string>::iterator it = names->begin(), itEnd = names->end(); it != itEnd; ++it)
    {
      sum += NameScore(*it) * n;

      if(n == 938){
	cout << "938: " << *it << " scored: 938 * " << NameScore(*it) << endl;
      }

      ++n;
    }
  return sum; 
}

unsigned long long Problem_22(const char *filename)
{
   list <string> Names = ReadFromFile(filename);
   Names.sort(compare_case);

   return sumOfNameScores(&Names);
}

int main(int argc, char* argv[])
{
  string filename = "names.txt";
  cout << "Sum of all names in file " << filename << ": " << Problem_22(filename.c_str()) << endl;
  
}
