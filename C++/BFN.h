#include <string>
#include <list>
#include <afxwin1.inl>

using namespace std;

#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
   ( std::ostringstream() << std::dec << x ) ).str()

//Big fucking integer number
//Maximum 4294967291 numbers
class BFN
{
public:
   BFN();
   ~BFN();

   BFN(string num);
   BFN toThePowerOf(unsigned long long e);
   list<char> getNumber() const { return m_num; }

   unsigned long long sumMeUp() const;
   BFN& operator=( const BFN& other );

   friend ostream& operator<<(ostream& output, const BFN& num);
   friend BFN operator+(const BFN &num1, const BFN &num2);
   friend BFN operator*(const BFN &num1, const unsigned long long &multi);

private:
   void trim();

   long m_maxAccuracy; 
   short m_sign;

   list<char> m_num;
};



