#include <iostream>
#include <cmath>
using namespace std;

#define N 4
const double eps = 0.1;
char sign(double x) {
	if (x < 0) {
		return '-';
	};
	return '+';
}
void INPUT(double A[N][N], double b[N]) {

	for (int i = 0; i < N; i++) {
		cout << "Input row number " << i + 1 << endl;
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	cout << "Input vector of results" << endl;
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}
}
void OUTPUT(double A[N][N], double b[N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << sign(A[i][j]) << abs(A[i][j]) << ' ';
		}
		cout << '	' << sign(b[i]) << abs(b[i]) << endl;
	}
	cout << endl;
}

//Yakobi
void Jacobi(int n, double A[N][N], double b[], double x[])
{
	double TempX[N] = {0,0,0,0};
	double norm = 0;
	int k = 1;

	cout << "0)	";
	for (int i = 0; i < n; i++) {
		cout << 'x' << i << " = " << 0 << ' ';
	}
	cout << endl;

	do {
		for (int i = 0; i < n; i++) {
			TempX[i] = b[i];
			for (int g = 0; g < n; g++) {
				if (i != g)
					TempX[i] -= A[i][g] * x[g];
			}
			TempX[i] /= A[i][i];
		}
		norm = fabs(x[0] - TempX[0]);
		for (int h = 0; h < n; h++) {
			if (fabs(x[h] - TempX[h]) > norm)
				norm = fabs(x[h] - TempX[h]);
			x[h] = TempX[h];
		}
		cout << k << ")	";
		for (int i = 0; i < n; i++) {
			cout << 'x' << i << " = " << x[i] << ' ';
		}
		cout << endl;

		k++;
	} while (norm > eps);

}

//Zeidel
void Zeidel(int n, double A[N][N], double b[], double x[])
{
	double TempX[N] = { 0,0,0,0 };
	double norm = 0;
	int k = 1;

	cout << "0)	";
	for (int i = 0; i < n; i++) {
		cout << 'x' << i << " = " << 0 << ' ';
	}
	cout << endl;

	do {
		for (int i = 0; i < n; i++) {
			TempX[i] = b[i];
			for (int g = 0; g < n; g++) {
				if (i != g)
					TempX[i] -= A[i][g] * TempX[g];
			}
			TempX[i] /= A[i][i];
		}
		norm = fabs(x[0] - TempX[0]);
		for (int h = 0; h < n; h++) {
			if (fabs(x[h] - TempX[h]) > norm)
				norm = fabs(x[h] - TempX[h]);
			x[h] = TempX[h];
		}
		cout << k << ")	";
		for (int i = 0; i < n; i++) {
			cout << 'x' << i << " = " << x[i] << ' ';
		}
		cout << endl;

		k++;
	} while (norm > eps);

}

int main() {
	cout << fixed;
	cout.precision(1);

	//Jacobi
	double A1[N][N] = { {6,3,1,0},{3,5,0,2},{1,0,3,1},{0,2,1,5} };
	double b1[N] = { 25,31,19,35 };

	//INPUT(A1, b1);

	cout << "Task: Jacobi`s Method" << endl;
	OUTPUT(A1, b1);

	double x1[N] = {};
	Jacobi(N, A1, b1, x1);
	cout << endl;

	cout << "Answer:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << 'x' << i + 1 << " = " << x1[i] << endl;
	}
	cout << endl;
	
	//Zeidel
	double A2[N][N] = { {5,1,1,0},{1,2,0,0},{1,0,4,2},{0,0,2,3} };
	double b2[N] = { 17,8,28,23 };

	//INPUT(A1, b1);

	cout << "Task: Zeidel`s Method" << endl;
	OUTPUT(A2, b2);

	double x2[N] = {};
	Zeidel(N, A2, b2, x2);
	cout << endl;

	cout << "Answer:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << 'x' << i + 1 << " = " << x2[i] << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}