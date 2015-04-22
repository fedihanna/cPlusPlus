#include "Rational.h" //including my header file


//declaring numerator and denomator as num and dum
//defining rational
Rational::Rational() //default constructor
	:num(0), dum(1){} //num is 0 and dum is 1 because default constructor isnt taking any arguments
Rational::Rational(int num, int dum)// constructor with arguments, declaring num and dum as integers
	: num(num), dum(dum){}
Rational::Rational(int num) //const with int arguement for "num"
	: num(num), dum(1){}

//constructor for the operator when using  +
Rational Rational::operator+(const Rational& FRACTION2){
	//inputs 1 and inputs 2
	Rational in1;
	Rational in2;
	Rational answer;//final answer

	//if the denominators are equal...add them
	//since denominators must be equal
	if(this->dum == FRACTION2.dum) //if the first denomi is eqaul to the second denomi
	{
		//the value for the num of first and second fraction are to be added
		answer.num = this->num + FRACTION2.num;
		answer.dum = this->dum;
	}//end if

	//if the deminators are not equal....make them equal
	else
	{
		//logic for making the denmointors equal
		in1.num = this->num * FRACTION2.dum; //input 1 for the num * fraction2 dum
		in1.dum = this->dum * FRACTION2.dum; //input 1 for the dum * fraction 2 dum
		in2.num = FRACTION2.num * this->dum; // input 2 for the num * fraction 2 num
		in2.dum = FRACTION2.dum * this->dum; // input 2 for the dum * fraction 2 dum
		answer.num = in1.num + in2.num; // answer for the num will be the 2 num,s added together
		answer.dum = in1.dum; // answer for the dum will be the result of the in1 formula
	}//end else

	return answer;//return the final answer
}


//constructor for the operator when using  -
Rational Rational::operator-(const Rational& FRACTION2){
	//inputs 1 and inputs 2
	Rational in1;
	Rational in2;
	Rational answer;//final answer

	if(this->dum == FRACTION2.dum) //if both denomi are equal, 
	{
		answer.num = this->num - FRACTION2.num; //then subtract the fraction1 and fraction 2 nums
		answer.dum = this->dum; //leave the dums the same
	}//end if

	else // if not
	{
		//this logic will take over
		//this logic will make sure that the denomi are the same 
		//by multiplying what goes into the 2 different denomi
		in1.num = this->num * FRACTION2.dum;
		in1.dum = this->dum * FRACTION2.dum;
		in2.num = FRACTION2.num * this->dum;
		in2.dum = FRACTION2.dum * this->dum;
		answer.num = in1.num - in2.num;
		answer.dum = in1.dum;
	}//end else

	return answer;//return the final answer
}


//constructor for the operator when using  *
Rational Rational::operator*(const Rational& FRACTION2){
	Rational in;
	in.num = this->num * FRACTION2.num;
	in.dum = this->dum * FRACTION2.dum;
	return in;
}


//constructor for the operator when using  /
Rational Rational::operator/(const Rational& FRACTION2){
	Rational in;
	in.num = this->num * FRACTION2.dum;
	in.dum = this->dum * FRACTION2.num;
	return in;
}


//boolean for checking if the 2 fractions are equal
bool Rational::operator==(const Rational& FRACTION2){
	bool in; //declaring a value for "in"

	////if the first fraction is equal than the second fraction 
	if ((this->num * FRACTION2.dum) == (this->dum * FRACTION2.num))
	{
		in = true; //then the "in" is true
	}
	else
	{
		in = false; //if not then the "in" is false
	}
	return in; //return a value for "in"
}

//boolean for operator <
bool Rational::operator<(const Rational& FRACTION2){
	bool in; //declraing "in"

	//if the first fraction is less than the second fraction 
	if ((this->num * FRACTION2.dum) < (this->dum * FRACTION2.num))
	{
		in = true; //then the "in" is true
	}
	else
	{
		//if not then the "in" is false
		in = false;
	}
	return in; //return a value for "in"
}


//boolean for operator >
bool Rational::operator>(const Rational& FRACTION2){
	bool in; //declaring "in"

	//if the first fraction is greater than the second fraction  
	if ((this->num * FRACTION2.dum) > (this->dum * FRACTION2.num))
	{
		in = true; //then the "in" is true
	}
	else
	{
		//if not then the "in" is false
		in = false;
	}
	return in; //return a value for "in"
}

ostream& operator<<(ostream& outs, const Rational& FRACTION)
{
	outs << FRACTION.Rational::num << "/" << FRACTION.Rational::dum;
	return outs;
}

//method for reducing fractions
void Rational::normalize()
{
	int gcf = GCF(this->num, this->dum);
	this->num = (this->num / gcf);
	this->dum = (this->dum / gcf);
}

//method for greatest common factor
int Rational::GCF(int num, int dum)
{
	for (;;)//for forever until these conditions are true
		    //so it will keep reducing until it can not go any further
	{
		if (num == 0) return dum;
		dum %= num;
		if (dum == 0) return num;
		num %= dum;
	}
}