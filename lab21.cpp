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
	return ComplexNumber((real*c.real)-(imag*c.imag),(real*c.imag)+(imag*c.real));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber(((real*c.real)+(imag*c.imag))/(pow(c.real,2)+pow(c.imag,2)),((imag*c.real)-(real*c.imag))/(pow(c.real,2)+pow(c.imag,2)));
}

ComplexNumber operator+(double s,const ComplexNumber &c){
	return ComplexNumber(s+c.real,c.imag);
}

ComplexNumber operator-(double s,const ComplexNumber &c){
	return ComplexNumber(s-c.real,-c.imag);
}

ComplexNumber operator*(double s,const ComplexNumber &c){
	return ComplexNumber(s*c.real,s*c.imag);
}

ComplexNumber operator/(double s,const ComplexNumber &c){
	return ComplexNumber((s*c.real)/(pow(c.real,2)+pow(c.imag,2)),(-(s*c.imag))/(pow(c.real,2)+pow(c.imag,2)));
}

bool ComplexNumber::operator==(const ComplexNumber &c){
    if(real==c.real && imag==c.imag) return true ;
    else return false ;
}

ComplexNumber operator==(double s,const ComplexNumber &c){
	if(s==c.real && s==c.imag) return true ;
    else return false ;
}

double ComplexNumber::abs(){
    return sqrt(pow(real,2)+pow(imag,2));
}

double ComplexNumber::angle(){
	return atan2 (imag,real) * 180 /M_PI;


}

ostream & operator<<(ostream &os,const ComplexNumber &c){
	if(c.real==0&&c.imag==0) return os<< "0";
	else if(c.real==0) return os<< c.imag << "i";
	else if(c.imag>0) return os<< c.real << "+" << c.imag << "i";
	else if(c.imag==0) return os<< c.real ;
	else if(c.imag<0) return os<< c.real << c.imag << "i";
	else return os<< c.imag << "i";
	
}