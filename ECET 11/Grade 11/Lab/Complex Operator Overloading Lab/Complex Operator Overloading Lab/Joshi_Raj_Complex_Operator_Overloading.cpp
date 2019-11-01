//Raj Joshi
//Complex Class

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;


class Complex {
private:
	double real;
	double imaginary;
	double angle;
	double magnitude;

public:
	Complex() : real(-1), imaginary(-1), angle(-1), magnitude(-1) {}
	Complex(double, double);
	Complex operator +(Complex&);
	Complex operator -(Complex&);
	Complex operator *(Complex&);
	Complex operator /(Complex&);
	Complex conjugate(Complex&);
	void toPolar();
	void toRectangle();
	void display(Complex&, Complex&);

};

Complex::Complex(double r, double i) : real(r), imaginary(i), angle(0), magnitude(0) {
	cout << "Complex number is (";
	if (real == 0 && imaginary == 0)
		cout << "0";

	else if (real == 0 && imaginary != 0) {
		if (imaginary < 0)
			cout << "-j" << -imaginary;
		else if (imaginary > 0)
			cout << "j" << imaginary;
	}

	else if (real != 0 && imaginary == 0)
		cout << real;

	else if (real != 0 && imaginary != 0) {
		if (imaginary < 0)
			cout << real << " - j" << -imaginary;
		else if (imaginary > 0)
			cout << real << " + j" << imaginary;
	}
	cout << ")" << endl;
}

Complex Complex::operator +(Complex& b) {
	Complex sum;
	sum.real = real + b.real;
	sum.imaginary = imaginary + b.imaginary;
	return sum;
}

Complex Complex::conjugate(Complex& in) {
	Complex out;
	out.real = in.real;
	out.imaginary = -in.imaginary;
	return out;
}



Complex Complex::operator /(Complex& b) {
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
	a = atan(imaginary / real) * 180 / M_PI;
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
	while (true) {
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

}