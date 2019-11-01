//Lab 2_2
//Raj Joshi & Nishil Patel
//Written by Nishil Patel
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Rational
{
	void reduce();
	int denom, numer;
public:
	Rational(int = 1, int = 2);
	Rational add(Rational);
	Rational sub(Rational);
	Rational mult(Rational);
	Rational div(Rational);
	void show_decimal();
	void show_val();

};

Rational::Rational(int num, int den) { numer = num; denom = den; reduce(); }
void Rational::reduce()
{
	int x, y;
	int orig;
	bool negFlag;
	if (numer == 0)
	{
		denom = 1;
		return;
	}
	if (numer > 0 && denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}

	if (numer < 0 && denom < 0)
	{
		numer = abs(numer); denom = abs(denom);
	}

	if (numer > denom)
	{
		x = abs(numer);
		y = abs(denom);
	}

	else if (denom > numer)
	{
		x = abs(denom);
		y = abs(numer);
	}

	else
	{
		numer = 1; denom = 1;
		return;
	}

	orig = y;
	while (y != 1)
	{
		if (x % y == 0 && orig % y == 0)
		{
			numer /= y;
			denom /= y;
			return;
		}

		y--;
	}

}
Rational Rational::add(Rational num)
{
	Rational sum(numer * num.denom + num.numer * denom, denom * num.denom);
	sum.reduce();
	return sum;
}
Rational Rational::sub(Rational num)
{
	Rational dif(numer * num.denom - num.numer * denom, denom * num.denom);
	dif.reduce();
	return dif;
}
Rational Rational::mult(Rational num)
{
	Rational pro(numer * num.numer, denom * num.denom);
	pro.reduce();
	return pro;
}
Rational Rational::div(Rational num)
{
	Rational quo(numer * num.denom, denom * num.numer);
	quo.reduce();
	return quo;
}

void Rational::show_val()
{
	if (numer)
		cout << numer << '/' << denom;
	else
		cout << "0";
}

void Rational::show_decimal()
{
	double n = numer;
	double d = denom;
	double decimal = n / d;
	cout << decimal;
}


int main()
{
	while (true)
	{
		Rational num1, num2;
		bool error;
		do
		{
			error = false;
			string n, d;
			cout << "Enter Numerator of Rational Number 1: "; getline(cin, n);
			cout << "\nEnter Denominator Part of Rational Number 1: "; getline(cin, d);
			if ((isdigit(n.front()) || isdigit(n[1])) && (isdigit(d.front()) || isdigit(d[1])) && stoi(d) != 0)
			{
				num1 = Rational(stoi(n), stoi(d));
			}

			else
				error = true;
			cout << "\n\nEnter Numerator Part of Rational Number 2: "; getline(cin, n);
			cout << "\nEnter Denominator Part of Rational Number 2: "; getline(cin, d);
			if ((isdigit(n.front()) || isdigit(n[1])) && (isdigit(d.front()) || isdigit(d[1])) && stoi(d) != 0)
			{
				num2 = Rational(stoi(n), stoi(d));
			}

			else
				error = true;
#ifdef __linux__
			system("clear");
#else
			system("cls");
#endif

			if (error)
				cout << "Invalid Entry\n\n";
		} while (error);


		string option;
		cout << "Number 1: ";
		num1.show_val();
		cout << "\nNumber 2: ";
		num2.show_val();

		cout << "\n\nWhat operation would you like to do (invalid options will default to addition):\n1)Addition\n2)Subtraction (num1 - num2)" << endl;
		cout << "3)Multiplication\n4)Division (num1 / num2)\n";

		getline(cin, option);
		Rational answer;
		string operation;

		if (option == "2")
		{
			answer = num1.sub(num2);
			operation = "Subtraction";
		}
		else if (option == "3")
		{
			answer = num1.mult(num2);
			operation = "Multiplication";
		}
		else if (option == "4")
		{
			answer = num1.div(num2);
			operation = "Division";
		}
		else
		{
			answer = num1.add(num2);
			operation = "Addition";
		}

#ifdef __linux__
		system("clear");
#else
		system("cls");
#endif

		cout << "Number 1: ";
		num1.show_val();
		cout << "\nNumber 2: ";
		num2.show_val();
		cout << endl << "Operation: " << operation << endl;

		cout << "\nDisplay the value (invalid options will default to fraction) as a \n1)Fraction \n2)Decimal\n";
		string display;
		getline(cin, display);
		cout << "\nThe Value is: ";
		if (display == "2")
		{
			answer.show_decimal();
		}
		else
		{
			answer.show_val();
		}

		cout << endl << "Enter to Continue :)  ";
		string pause;
		getline(cin, pause);
#ifdef __linux__
		system("clear");
#else
		system("cls");
#endif

	}
	return 0;
}
