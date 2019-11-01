// Lab 4_3
//Raj Joshi & Nishil Patel
//Written by Nishil Patel

#include<iostream>
using namespace std;

class Polynomial
{
private:
	int c[5];
public:
	Polynomial(int[]);
	void setCoefficients(int[]);
	int* getCoefficients();
	void displayPolynomial();
	Polynomial operator+(Polynomial&);
	Polynomial operator-(Polynomial&);
	Polynomial operator*(Polynomial&);
	void operator+=(Polynomial&);
};

Polynomial::Polynomial(int c[]) {
	for (int i = 0; i < 5; i++)
		this->c[i] = c[i];
}

void Polynomial::setCoefficients(int c[]) {
	for (int i = 0; i < 5; i++)
		this->c[i] = c[i];
}

int* Polynomial::getCoefficients() {return c;}

void Polynomial::displayPolynomial()
{
	bool first = true;
	for (int i = 0; i < 5; i++) {
		if (c[i] != 0) {
			if (c[i] > 0 && !first)
				cout << " + ";
			if (c[i] < 0)
				cout << " - ";
			if (abs(c[i]) != 1 || i == 4)
				cout << abs(c[i]);
			if (4 - i != 0) {
				first = false;
				cout << "x";
				if (4 - i != 1)
					cout << "^" << 4 - i;
			}
		}
	}
	cout << endl;
}

Polynomial Polynomial::operator+(Polynomial& a) {
	int nP[5];
	for (int i = 0; i < 5; i++)
		nP[i] = c[i] + a.c[i];
	return Polynomial(nP);
}

Polynomial Polynomial::operator-(Polynomial& s) {
	int nP[5];
	for (int i = 0; i < 5; i++)
		nP[i] = c[i] - s.c[i];
	return Polynomial(nP);
}

Polynomial Polynomial::operator*(Polynomial& m) {
	int nP[5];
	nP[0] = 0;
	nP[1] = 0;
	nP[2] = c[3] * m.c[3];
	nP[3] = c[3] * m.c[4] + c[4] * m.c[3];
	nP[4] = c[4] * m.c[4];
	return Polynomial(nP);
}

void Polynomial::operator+=(Polynomial& a) {
	for (int i = 0; i < 5; i++)
		c[i] += a.c[i];
}

int main()
{
	while (true) {
		int c[5];

		cout << "Enter first polynomial: ";
		for (int i = 0; i < 5; i++)
			cin >> c[i];
		Polynomial p1(c);
		cout << "P1: ";
		p1.displayPolynomial();
		cout << endl;

		cout << "Enter second polynomial: ";
		for (int i = 0; i < 5; i++)
			cin >> c[i];
		Polynomial p2(c);
		cout << "P2: ";
		p2.displayPolynomial();
		cout << endl;

		cout << "P1 + P2 = ";
		(p1 + p2).displayPolynomial();

		cout << "P1 - P2 = ";
		(p1 - p2).displayPolynomial();

		cout << "P1 += P2 = ";
		p1 += p2;
		(p1).displayPolynomial();

		int bin1[5] = { 0, 0, 0 }, bin2[5] = { 0, 0, 0 };
		cout << "\nEnter 2 binomials in order to multiply them (linear term followed by a space followed by constant term).\n" << endl;

		cout << "Enter first binomial: ";
		cin >> bin1[3] >> bin1[4];
		Polynomial b1(bin1);
		b1.displayPolynomial();
		cout << endl;

		cout << "Enter second binomial: ";
		cin >> bin2[3] >> bin2[4];
		Polynomial b2(bin2);
		b2.displayPolynomial();
		cout << endl;

		cout << "P1 * P2 = ";
		(b1 * b2).displayPolynomial();
		cout << endl;

		system("pause");
		system("cls");
	}
	return 0;
}