#include "BFN.h"
#include <stdlib.h>
#include <iostream>

BFN::BFN( string num )
: m_maxAccuracy(static_cast<char>(string().max_size()))
, m_sign(1)
{
   if(num[0] == '-')
   {
      m_sign = -1;
      num.erase(0, 1);
   }

   for(unsigned long c = 0; c < (unsigned long)num.size(); ++c)
      m_num.push_back(num[c]);

   trim();
}

BFN::BFN()
: m_maxAccuracy(static_cast<char>(string().max_size()))
{
}

BFN::~BFN()
{

}

void BFN::trim()
{
   long toTtrim = 0;
   for(list<char>::const_iterator it = m_num.begin(), itEnd = m_num.end(); it != itEnd;)
      if(*it == '0')
      {
         ++it;
         m_num.pop_front();
      }
      else
         break;

   if(m_num.empty())
      m_num.push_back('0');
}

BFN BFN::toThePowerOf( unsigned long long e )
{
   BFN before;
   BFN tmp("0");

   for(int i = 1; i < e; ++i)
   {
      BFN before = *this;
      tmp = before * 2;
      this->m_num = tmp.getNumber();
   }
   return tmp;
}

BFN& BFN::operator=( const BFN& other ) {
   m_maxAccuracy = other.m_maxAccuracy;
   m_sign = other.m_sign;
   m_num = other.m_num;

   return *this;
}

unsigned long long BFN::sumMeUp() const
{
   unsigned long long sum = 0;
   for(list<char>::const_iterator it = m_num.begin(), itEnd = m_num.end(); it != itEnd;++it)
   {
      sum = sum + *it - '0';
   }
   return sum;
}

ostream& operator<<(ostream& output, const BFN& num) {
   for(list<char>::const_iterator it = num.m_num.begin(), itEnd = num.m_num.end(); it != itEnd; ++it)
      output << *it;

   return output;
}

BFN operator+(const BFN &num1, const BFN &num2)
{
   list<char>::const_reverse_iterator it1 = num1.m_num.rbegin();
   list<char>::const_reverse_iterator it2 = num2.m_num.rbegin();
   list<char>::const_reverse_iterator it1End = num1.m_num.rend();
   list<char>::const_reverse_iterator it2End = num2.m_num.rend();

   string ans = "";
   string tmp;
   bool carry = 0;
   short num;

   while(it1 != it1End || it2 != it2End || carry)
   {
      num = 0;

      if(it1 != it1End && it2 != it2End )
         num = *it1 + *it2 - (2 * '0');
      else if(it1 != it1End)
         num = *it1 - '0';
      else if(it2 != it2End)
         num = *it2 - '0';

      num += carry;
      tmp = SSTR(num);
      carry = (tmp.size() > 1);
      tmp.erase(0, carry);

      ans += tmp;

      if(it1 != it1End)
         ++it1;
      if(it2 != it2End)
         ++it2;
   }

   ans = string ( ans.rbegin(), ans.rend() );

   return BFN(ans);
}


BFN operator*(const BFN &num1, const unsigned long long &multi)
{
   BFN sum("0");
   for(int i = 0; i < multi; ++i)
   {
      sum = sum + num1;
   }
   return sum;
}

