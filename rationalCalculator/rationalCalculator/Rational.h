//if not defined statement
//if this hasnt been defined .....define it

#include <iostream>
#include <conio.h>
//include header here as well as in driver
using namespace std;
class Rational
{

	
public:

	//declaring num and dum
	int num;
	int dum;
	Rational();//default constructor
	Rational(int num);//whole number constructor
	Rational(int num, int dum);//both values filled, rational number

	//rational operator is allowing it to overload the operator +,-,*,/, <, >, =
	 Rational operator+(const Rational& FRACTION2);
	 Rational operator-(const Rational& FRACTION2);
	 Rational operator*(const Rational& FRACTION2);
	 Rational operator/(const Rational& FRACTION2);
	 bool operator==(const Rational& FRACTION2);
	 bool operator<(const Rational& FRACTION2);
	 bool operator>(const Rational& FRACTION2);
	 friend ostream& operator<<(ostream& outs, const Rational& FRACTION);
	 void normalize();//putting it to lowest commmon denomator
	 int GCF(int x, int y);
};