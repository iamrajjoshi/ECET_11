//Lab 2_1
//Raj Joshi & Nishil Patel
//Written by Nishil Patel

using namespace std;
#include <iostream>
#include <iomanip>
#include <string>

class Complex
{
	double real;
	double imaginary;
public:
	Complex(double, double);
	Complex add(Complex);
	Complex subtract(const Complex&);
	void show_val();

};

Complex::Complex(double r = 1, double i = 1)
{
	real = r; imaginary = i;
}
Complex Complex::add(Complex num2)
{
	return Complex(real + num2.real, imaginary + num2.imaginary);
}
Complex Complex::subtract(const Complex& num2)
{
	return Complex(real - num2.real, imaginary - num2.imaginary);
}
void Complex::show_val()
{
	cout << "(" << real << ", " << imaginary << ")";
}

int main()
{
	while (true)
	{
		double r, i;
		cout << "Enter Real Part of Complex Number 1: "; cin >> r;
		cout << "\nEnter Imaginary Part of Complex Number 1: "; cin >> i;
		Complex num1(r, i);

		cout << "\n\nEnter Real Part of Complex Number 2: "; cin >> r;
		cout << "\nEnter Imaginary Part of Complex Number 2: "; cin >> i;
		Complex num2(r, i);
		system("cls");

		string option;
		cout << "Number 1: ";
		num1.show_val();
		cout << "\nNumber 2: ";
		num2.show_val();

		cout << "\n\nWhat operation would you like to do (invalid options will default to addition):\n1)Addition\n2)Subtraction (num1 - num2)" << endl;
		cin.ignore();
		getline(cin, option);

		cout << "\nThe Value is: ";
		if (option != "2")
		{
			num1.add(num2).show_val();
		}
		else
		{
			num1.subtract(num2).show_val();
		}
		cout << endl << "Enter to Continue :)  ";
		string pause;
		getline(cin, pause);
	}
	return 0;
}
