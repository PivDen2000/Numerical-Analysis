#include <iostream>
#include <cmath>
using namespace std;

double eps = pow(10, -3);

//Relax
double f1(double x) {
	return x * x * x - 5 * x * x - 4 * x + 20;
}
double df1(double x) {
	return 3 * x * x - 10 * x - 4;
}
void relaxMethod() {
	cout << "f(x) = x^3 - 5x^2 - 4x + 20\neps = 10^-3" << endl << endl;

	cout << "f(-3) = " << f1(-3) << endl;
	cout << "f(-1) = " << f1(-1) << endl;
	cout << "f(-3)*f(-1) < 0" << endl << endl;

	cout << "f'(x) = 3x^2 - 10x - 4 > 0 for x in [-3, -1]\nand monotonically decreasing, because\nf''(x) = 6x - 10 < 0 for x in [-3, -1]" << endl << endl;

	cout << "f'(-3) = " << df1(-3) << " = M1" << endl;
	cout << "f'(-1) = " << df1(-1) << " = m1" << endl;

	double M1 = df1(-3);
	double m1 = df1(-1);

	double z0 = -1.5;

	double tau = 2 / (m1 + M1);
	double q = (M1 - m1) / (M1 + m1);
	double n = floor(log(-z0 / eps) / log(1. / q)) + 1;

	cout << "tau = 2/(M1+m1) = " << tau << endl;
	cout << "q = (M1-m1)/(M1+m1) = " << q << endl;
	cout << "z0 = -1.5\nn = ln(|z0|/eps)/ln(1/q) = " << n << endl << endl;

	cout << "xn = x{n-1} - tau*f(x{n-1})" << endl << endl;

	double xi = z0;
	cout << fixed;
	cout.precision(21);
	for (int i = 0; i <= n; i++) {
		cout << i << "	" << xi << "	" << f1(xi) << endl;
		xi = xi - tau*f1(xi);
	}

	cout << "Answer: " << xi << endl;
}

//Newton
double f2(double x){
	return x * x * x - 8 * x * x + 9 * x + 18;
}
double df2(double x) {
	return 3 * x * x - 16 * x + 9;
}
double ddf2(double x) {
	return 6 * x - 16;
}
void NewtonMethod() {
	cout << "f(x) = x^3 - 8x^2 + 9x + 18\neps = 10^-3" << endl << endl;


	cout << "f(-1.25) = " << f2(-1.25) << endl;
	cout << "f(-0.75) = " << f2(-0.75) << endl;
	cout << "f(-1.25)*f(-0.75) < 0" << endl << endl;

	cout << "f'(x) = 3x^2 - 16x + 9 > 0 for x in [-1.25, -0.75]\nand monotonically decreasing, because\nf''(x) = 6x - 16 < 0 for x in [-1.25, -0.75]" << endl << endl;

	double m1 = abs(df2(-0.75));
	double M2 = abs(ddf2(-1.25));

	cout << "min|f'(x)| = f'(-0.75) = " << m1 << " = m1" << endl;
	cout << "max|f''(x)| = |f''(-1.25)| = " << M2 << " = M2" << endl << endl;

	double x0 = -0.75;
	double abs = 0.5;

	cout << "x0 = -0.75\n|x0-x*| <= 0.5" << endl;

	double q = (M2*abs) / (2*m1);
	cout << "q = M2*|x0-x*| / 2m1 = " << q << " < 1" << endl;

	int n = floor(log2(log(abs / eps) / log(1 / q)) + 1) + 1;
	cout << "n = floor(log2(log(abs / eps) / log(1 / q)) + 1) + 1 = " << n << endl << endl;

	cout << fixed;
	cout.precision(5);
	for (int i = 0; i <= n; i++) {
		cout << i << '	' << x0 << '	' << f2(x0) << endl;
		x0 = x0 - f2(x0) / df2(x0);
	}

	cout << "Answer: " << x0 << endl;

}

//tangent
double f3(double x) {
	return x * x * x - 4 * x * x - 15 * x + 18;
}
double df3(double x) {
	return 3 * x * x - 8 * x - 15;
}
double ddf3(double x) {
	return 6 * x - 8;
}
void tangentMethod() {
	cout << "f(x) = x^3 - 4x^2 - 15x + 18\neps = 10^-3" << endl << endl;

	cout << "f(-3.25) = " << f3(-3.25) << endl;
	cout << "f(-2.25) = " << f3(-2.25) << endl;
	cout << "f(-3.25)*f(-2.25) < 0" << endl << endl;

	cout << "f'(x) = 3x^2 - 8x - 15 > 0 for x in [-3.25, -2.25]\nand monotonically decreasing, because\nf''(x) = 6x - 8 < 0 for x in [-3.25, -2.25]" << endl << endl;

	double m1 = abs(df3(-2.25));
	double M2 = abs(ddf3(-3.25));

	cout << "min|f'(x)| = f'(-2.25) = " << m1 << " = m1" << endl;
	cout << "max|f''(x)| = |f''(-3.25)| = " << M2 << " = M2" << endl << endl;

	double abs = 0.5;

	cout << "for x0 in [-3.25, -2.75]: |x0-x*| <= 0.5" << endl;

	double q = (M2 * abs) / (2 * m1);
	cout << "q = M2*|x0-x*| / 2m1 = " << q << " < 1" << endl;
	int n = floor(log2(log(abs / eps) / log(1 / q)) + 1) + 1;
	cout << "n = floor(log2(log(abs / eps) / log(1 / q)) + 1) + 1 = " << n << endl << endl;

	cout << fixed;
	cout.precision(5);

	double x0 = -2.75 - (-3.25 - (-2.75)) / (f3(-3.25) - f3(-2.25)) * f3(-3.25);
	double x1 = x0 - (-3.25 - x0) / (f3(-3.25) - f3(x0)) * f3(x0);
	double x2 = 0;
	cout << 0 << '	' << x0 << '	' << f3(x0) << endl;
	cout << 1 << '	' << x1 << '	' << f3(x1) << endl;
	for (int i = 2; i <= n; i++) {
		x2 = x0 - (x1 - x0) * f3(x0) / (f3(x1) - f3(x0));
		x0 = x1;
		x1 = x2;
		cout << i << '	' << x2 << '	' << f3(x2) << endl;
	}

	cout << "Answer: " << x2 << endl;
}
int main() {

	relaxMethod();
	cout << endl;
	NewtonMethod();
	cout << endl;
	tangentMethod();

	system("pause");
	return 0;
}