#include <iostream>
#include <string>
using namespace std;


class A {
public:
	int a;
	A() {
		a = 42;
	}
	void step1() {
		a++;
	}
	virtual void step2() {
		a--;
	}
	void run() {
		step1();
		step2();
		cout << a;
	}
};

class B: public A {
public:
	void step2() {
		a++;
	}
};
int main() {
	B b;
	b.run();
	cout << endl <<sizeof(A) << endl;
	return 0;
}   