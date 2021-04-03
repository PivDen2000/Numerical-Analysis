//variant 10
#include<iostream>
using namespace std;

//midpoint
//n >= 50
//Int(0,variant)((variant % 6)*x^4+(variant % 5)*x^2-(variant % 4)*x)dx
//Int(0,10)(4*x^4-2*x)dx = 79900
double f1(double x, int variant) {
	return variant % 6 * pow(x, 4) + (variant % 5) * pow(x, 2) - (variant % 4) * x;
}
double midpoint(int n = 50, int variant = 10) {
	double I = 0;
	double h = (double)variant / (double)n;
	double k = 0.5;
	while (k <= n - 0.5) {
		I += h * (f1(k * h, variant));
		k++;
	}
	return I;
}

//Simpson's formula
//eps = 0.001
//Integral(0,variant/2)((variant % 4)*x^4+(variant % 3)*x^2+(variant % 2)*x)dx
//Integral(0,5)(2*x^4+x^2)dx = 1291.667
double f2(double x, int variant) {
	return (variant % 4) * pow(x, 4) + (variant % 3) * pow(x, 2) + (variant % 2) * x;
}
int factorial(int n) {
	return (n == 0) || (n == 1) ? 1 : n * factorial(n - 1);
}
double simpson(int variant = 10, double eps = 0.001) {
	double I = 0;
	int n = ceil(pow((double)(variant % 4) * factorial(4) * pow((double)variant/2, 5) / (2880*eps), 0.25));
	double h = ((double)variant / 2) / (2 * n);

	int k = 1;
	while (k <= 2 * n - 1) {
		I += h / 3 * (f2((k - 1) * h, variant) + 4 * f2(k * h, variant) + f2((k + 1) * h, variant));
		k += 2;
	}
	return I;
}

int main() {
	int variant = 10;

	//midpoint
	int n = 100; // >= 50
	cout << "Calculate Integral by the midpoint method:" << endl;
	cout << "Integral(0,10)(4*x^4-2*x)dx = "; // 79900
	cout << midpoint(n, variant) << endl;

	cout << endl;
	cout << fixed;
	cout.precision(3);

	//Simpson's formula
	double eps = 0.001;
	cout << "Calculate Integral by the Simpson's formula:" << endl;
	cout << "Integral(0,5)(2*x^4+x^2)dx = "; // 1291.667
	cout << simpson(variant, eps) << endl;

	system("pause");
	return 0;
}