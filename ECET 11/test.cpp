//Garrett Seo 
//Complex Class

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
#define PI 3.14159265
class Complex {
private:
	double real;
	double imaginary;
	double angle;
	double magnitude;

public:
	Complex(double x, double y);
	Complex();
	Complex operator +(Complex&);
	Complex operator -(Complex&);
	Complex operator *(Complex&);
	Complex operator /(Complex&);
	void toPolar();
	void toRectangle();
	void display(Complex&, Complex&);
	Complex conjugate(Complex);
};
Complex::Complex() {}
Complex::Complex(double x, double y) {
	real = x;
	imaginary = y;
	cout << "Complex number: ";
	if (real == 0 && imaginary == 0)
		cout << "0" << endl;
	else if (real == 0 && imaginary != 0)
	{
		if (imaginary < 0)
		{
			cout << "-j" << -imaginary << endl;
		}
		else if (imaginary > 0)
		{
			cout << "j" << imaginary << endl;
		}
	}
	else if (real != 0 && imaginary == 0)
	{
		cout << real << endl;
	}
	else if (real != 0 && imaginary != 0)
	{
		if (imaginary < 0)
		{
			cout << real << " - j" << -imaginary << endl;
		}
		else if (imaginary > 0)
		{
			cout << real << " + j" << imaginary << endl;
		}
	}
}
Complex Complex::conjugate(Complex x) {
	Complex newconj;
	newconj.real = x.real;
	newconj.imaginary = -x.imaginary;
	return newconj;
}
Complex Complex::operator /(Complex& b)
{

	Complex quot;
	Complex temp = b;
	Complex conj = conjugate(temp);
	Complex div = b * conj;
	double a1, b1, a2, b2;
	a1 = real;
	b1 = imaginary;
	a2 = conj.real;
	b2 = conj.imaginary;
	quot.real = (a1 * a2 - b1 * b2) / div.real;
	quot.imaginary = (a1 * b2 + a2 * b1) / div.real;
	return quot;
}
Complex Complex::operator *(Complex& b) {
	double a1, b1, a2, b2;
	a1 = real;
	b1 = imaginary;
	a2 = b.real;
	b2 = b.imaginary;
	Complex prod;

	prod.real = a1 * a2 - b1 * b2;
	prod.imaginary = a1 * b2 + a2 * b1;
	return prod;
}
Complex Complex::operator +(Complex& b) {
	Complex sum;
	sum.real = real + b.real;
	sum.imaginary = imaginary + b.imaginary;
	return sum;
}
Complex Complex::operator -(Complex& b) {
	Complex diff;
	diff.real = real - b.real;
	diff.imaginary = imaginary - b.imaginary;
	return diff;
}
void Complex::display(Complex& one, Complex& two) {
	Complex sum, diff, prod, quot;
	sum = one + two;
	cout << "\nSum: " << endl;
	sum.toPolar();
	sum.toRectangle();
	cout << "\nDifference: " << endl;
	diff = one - two;
	diff.toPolar();
	diff.toRectangle();
	cout << "\nProduct: " << endl;
	prod = one * two;
	prod.toPolar();
	prod.toRectangle();
	cout << "\nQuotient: " << endl;
	if (two.real == 0 && two.imaginary == 0)
		cout << "Undefined" << endl;
	else
	{
		prod = one / two;
		prod.toPolar();
		prod.toRectangle();
	}
}
void Complex::toPolar() {
	double a;
	double m;
	a = atan(imaginary / real) * 180 / PI;
	if (real == 0 && imaginary == 0)
	{
		m = 0;
		a = 0;
	}
	else if (real >= 0 && imaginary >= 0)
	{
	}
	else if (real <= 0 && imaginary >= 0)
	{
		a = 180 + a;
	}
	else if (real >= 0 && imaginary <= 0)
	{
		a = 360 + a;
	}
	else if (real <= 0 && imaginary <= 0)
	{
		a = 180 + a;
	}

	angle = a;
	m = sqrt(real * real + imaginary * imaginary);
	magnitude = m;
	cout << "Polar form is: Magnitude " << magnitude << " | " << angle << " degrees" << endl;
}
void Complex::toRectangle() {
	cout << "Rectangular form is: ";
	if (real == 0 && imaginary == 0)
		cout << "0" << endl;
	else if (real == 0 && imaginary != 0)
	{
		if (imaginary < 0)
		{
			cout << "-j" << -imaginary << endl;
		}
		else if (imaginary > 0)
		{
			cout << "j" << imaginary << endl;
		}
	}
	else if (real != 0 && imaginary == 0)
	{
		cout << real << endl;
	}
	else if (real != 0 && imaginary != 0)
	{
		if (imaginary < 0)
		{
			cout << real << " - j" << -imaginary << endl;
		}
		else if (imaginary > 0)
		{
			cout << real << " + j" << imaginary << endl;
		}
	}
}
int main()
{
	float a1, b1, a2, b2;
	cout << "Enter the real part of complex number 1: ";
	cin >> a1;
	cout << "Enter the imaginary part of complex number 1: ";
	cin >> b1;
	Complex one(a1, b1);
	cout << "Enter the real part of complex number 2: ";
	cin >> a2;
	cout << "Enter the imaginary part of complex number 2: ";
	cin >> b2;
	Complex two(a2, b2);
	Complex finish;
	finish.display(one, two);
	system("pause");


}