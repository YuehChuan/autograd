#include <iostream>
#include "Tensor.h"

using namespace std;

int main() {
	Tensor x(2,1);
	(*x)(0, 0) = 0.2;
	(*x)(1, 0) = 0.4;
	x.grad().setZero();

	Tensor w(2, 2);
	(*w)(0, 0) = 0.1;
	(*w)(1, 0) = -0.3;
	(*w)(0, 1) = 0.5;
	(*w)(1, 1) = 0.8;
	w.grad().setZero();

	Tensor F = w*x;
	F.backward();

	cout <<"F value: " << endl;
	cout <<  F << endl;
	cout << " " << endl;
	cout <<"F grad: "<<  endl;
	cout << F.grad() << endl;
	cout << " " << endl;

	cout << "w value: "  << endl;
	cout <<  w << endl;
	cout << " " << endl;
	cout << "w grad: "  << endl;
	cout <<  w.grad() << endl;
	cout << " " << endl;

	cout << "x value: " << endl;
	cout  << x << endl;
	cout << " " << endl;
	cout << "x grad: "  << endl;
	cout <<  x.grad() << endl;
	cout << " " << endl;

	return 0;
}
