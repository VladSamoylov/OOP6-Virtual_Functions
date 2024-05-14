#include <iostream>

using namespace std;

class Base {
public:
	virtual void myname() { cout << "This is class Base" << endl; }	
};

class DerA : public Base {
public:
	void myname() override { cout << "This is class DerA" << endl; }
};

class DerB : public Base {
public:
	void myname() override { cout << "This is class DerB" << endl; }
};

class DerAB : public DerA, public DerB {
public:
	void myname() override { cout << "This is class DerAB" << endl; }
};

int main() {
	Base b;
	DerA d1;
	DerB d2;
	DerAB ab;

	b.myname();
	d1.myname();
	d2.myname();
	ab.myname();
	cout << "\n--------\n";

	Base* p[4];
	p[0] = new Base;
	p[1] = new DerA;
	p[2] = new DerB;
	p[3] = static_cast<DerA*>(new DerAB);
	//p[3] = new DerAB;
	p[0]->myname();
	p[1]->myname();
	p[2]->myname();
	p[3]->myname();

	return 0;
}