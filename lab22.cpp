#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here.
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(real*c.real - imag*c.imag,
	                     real*c.imag + imag*c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double denom = c.real*c.real + c.imag*c.imag;
	return ComplexNumber((real*c.real + imag*c.imag)/denom,
	                     (imag*c.real - real*c.imag)/denom);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	return (real==c.real && imag==c.imag);
}

double ComplexNumber::abs(){
	return sqrt(real*real + imag*imag);
}

double ComplexNumber::angle(){
	return atan2(imag, real) * 180.0 / 3.141592653589793;
}

ComplexNumber operator+(double d, const ComplexNumber &c){
	return ComplexNumber(d+c.real, c.imag);
}

ComplexNumber operator-(double d, const ComplexNumber &c){
	return ComplexNumber(d-c.real, -c.imag);
}

ComplexNumber operator*(double d, const ComplexNumber &c){
	return ComplexNumber(d*c.real, d*c.imag);
}

ComplexNumber operator/(double d, const ComplexNumber &c){
	double denom = c.real*c.real + c.imag*c.imag;
	return ComplexNumber((d*c.real)/denom,
	                     (-d*c.imag)/denom);
}

bool operator==(double d, const ComplexNumber &c){
	return (c.real==d && c.imag==0);
}

ostream& operator<<(ostream &os, const ComplexNumber &c){
	if(c.real==0 && c.imag==0){
		os << 0;
	}
	else if(c.imag==0){
		os << c.real;
	}
	else if(c.real==0){
		os << c.imag << "i";
	}
	else{
		os << c.real;
		if(c.imag>0) os << "+";
		os << c.imag << "i";
	}
	return os;
}