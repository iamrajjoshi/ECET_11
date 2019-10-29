#include <iostream>
#include <string>
using namespace std;

class Polynomial
{
private:
	int x4, x3, x2, x1, con;
	string oper;
public:
	Polynomial();
	void setPolynomial(int X4, int X3, int X2, int X1, int C);
	void setBinomial(int X1, int C);
	Polynomial getPolynomial();
	Polynomial operator+(Polynomial&);
	Polynomial operator-(Polynomial&);
	Polynomial operator*(Polynomial&);
	Polynomial operator+=(Polynomial&);
	void display();
};

Polynomial::Polynomial() : x4(0), x3(0), x2(0), x1(0), con(0) {};

Polynomial Polynomial::getPolynomial() {
	Polynomial Poly;
	Poly.x4 = x4;
	Poly.x3 = x3;
	Poly.x2 = x2;
	Poly.x1 = x1;
	Poly.con = con;
	return Poly;
}

void Polynomial::setPolynomial(int E4, int E3, int E2, int E1, int C) {
	x4 = E4;
	x3 = E3;
	x2 = E2;
	x1 = E1;
	con = C;
}

void Polynomial::setBinomial(int x, int c) {
	x1 = x; 
	con = c;
}

Polynomial Polynomial::operator+(Polynomial& tem) {
	Polynomial answer;
	x4 = x4 + tem.x4; x3 = x3 + tem.x3; x2 = x2 + tem.x2; x1 = x1 + tem.x1; con = con + tem.con;
	answer.x4 = x4;
	answer.x3 = x3;
	answer.x2 = x2;
	answer.x1 = x1;
	answer.con = con;
	return answer;
}

Polynomial Polynomial::operator+=(Polynomial& b) {
	Polynomial answer;
	answer.x4 = x4 + b.x4;
	answer.x3 = x3 + b.x3;
	answer.x2 = x2 + b.x2;
	answer.x1 = x1 + b.x1;
	answer.con = con + b.con;
	return answer;
}

Polynomial Polynomial::operator-(Polynomial& b) {
	Polynomial answer;
	answer.x4 = x4 - b.x4;
	answer.x3 = x3 - b.x3;
	answer.x2 = x2 - b.x2;
	answer.x1 = x1 - b.x1;
	answer.con = con - b.con;
	return answer;
}

Polynomial Polynomial::operator*(Polynomial& tem) {
	Polynomial answer;
	answer.x2 = x1 * tem.x1;
	answer.x1 = x1 * tem.con + con * tem.x1;
	answer.con = con * tem.con;
	return answer;
}

void Polynomial::display() {
	string output = "";
	if (x4 != 0) {
		output += to_string(x4);
		output += "x^4 + ";
	}
	if (x3 != 0) {
		output += to_string(x3);
		output += "x^3 + ";
	}
	if (x2 != 0) {
		output += to_string(x2);
		output += "x^2 + ";
	}
	if (x1 != 0) {
		output += to_string(x1);
		output += "x + ";
	}
	if (con != 0) {
		output += to_string(con);
	}
	if (output[output.size() - 2] == '+') {
		output = output.substr(0, output.size() - 2);
	}
	if (output == "") {
		output = "0";
	}
	cout << output << endl;
}


int main()
{
	while (true) {
		Polynomial pol1, pol2, pol3;
		string of;
		cout << "Enter operation: ";
		cin >> of;

		if (of == "+")
		{
			int ab4, ab3, ab2, ab1, con;
			cout << "Enter polynomial 1: ";
			cin >> ab4;
			cin >> ab3;
			cin >> ab2;
			cin >> ab1;
			cin >> con;
			pol1.setPolynomial(ab4, ab3, ab2, ab1, con);
			cout << "Enter polynomial 2: ";
			cin >> ab4;
			cin >> ab3;
			cin >> ab2;
			cin >> ab1;
			cin >> con;
			pol2.setPolynomial(ab4, ab3, ab2, ab1, con);
			pol3 = pol1 + pol2;
			cout << "Poly1 + Poly2: ";
			pol3.display();
		}
		if (of == "+=")
		{
			int ab4, ab3, ab2, ab1, con;
			cout << "Enter polynomial 1: ";
			cin >> ab4;
			cin >> ab3;
			cin >> ab2;
			cin >> ab1;
			cin >> con;
			pol1.setPolynomial(ab4, ab3, ab2, ab1, con);
			cout << "Enter polynomial 2: ";
			cin >> ab4;
			cin >> ab3;
			cin >> ab2;
			cin >> ab1;
			cin >> con;
			pol2.setPolynomial(ab4, ab3, ab2, ab1, con);
			pol3 = (pol1 += pol2);
			cout << "Poly1 += Poly2: ";
			pol3.display();
		}
		if (of == "-")
		{
			int ab4, ab3, ab2, ab1, con;
			cout << "Enter polynomial 1: ";
			cin >> ab4;
			cin >> ab3;
			cin >> ab2;
			cin >> ab1;
			cin >> con;
			pol1.setPolynomial(ab4, ab3, ab2, ab1, con);
			cout << "Enter polynomial 2: ";
			cin >> ab4;
			cin >> ab3;
			cin >> ab2;
			cin >> ab1;
			cin >> con;
			pol2.setPolynomial(ab4, ab3, ab2, ab1, con);
			pol3 = pol1 - pol2;
			cout << "Poly1 - Poly2: ";
			pol3.display();
		}
		if (of == "*")
		{
			int ab1, con;
			cout << "Enter binomial 1: ";
			cin >> ab1;
			cin >> con;
			pol1.setBinomial(ab1, con);
			cout << "Enter binomial 2: ";
			cin >> ab1;
			cin >> con;
			pol2.setBinomial(ab1, con);
			pol3 = pol1 * pol2;
			cout << "Poly1 * Poly2: ";
			pol3.display();
		}

		cout << endl << endl;

		int x;
		cout << "Continue? (enter 0 to continue, or press 1 to exit): ";
		cin >> x;
		if (x == 1)
			break;
		cout << endl;
	}

	return 0;
}