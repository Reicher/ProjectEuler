#include <iostream> 

using namespace std;

int main(int argc, char* argv[])
{
  long long int num( 600851475143 );
  int primes[] = {2, 3, 5, 7, 11, 13, 17};

  for(int i = 0; i < 7; ++i)
    {
      if(primes[i] % num == 0)
	{
	cout << "Prime found: " << primes[i];
	return 0;
	}
    }
  
  for(long long int prime = num/primes[6]; prime > 0; --prime) 
    {
      if( num % prime == 0)
	{
	  cout << "First prime found! " << prime << endl;
	  return 0;
	}
    }
  return 0;
}
