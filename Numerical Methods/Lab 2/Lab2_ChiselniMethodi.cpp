#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

//Gauss
#define N 4
char sign(double x) {
	if (x < 0) {
		return '-';
	};
	return '+';
}
void INPUT1(double A1[N][N], double b1[N]) {

	for (int i = 0; i < N; i++) {
		cout << "Input row number " << i + 1 << endl;
		for (int j = 0; j < N; j++) {
			cin >> A1[i][j];
		}
	}

	cout << "Input vector of results" << endl;
	for (int i = 0; i < N; i++) {
		cin >> b1[i];
	}
}
void OUTPUT1(double A1[N][N], double b1[N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << sign(A1[i][j]) <<abs(A1[i][j])<<' ';
		}
		cout << '	' << sign(b1[i]) << abs(b1[i]) << endl;
	}
	cout << endl;
}
void COPY1(double A1[N][N], double b1[N], double At[N][N], double bt[N]) {
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			At[i][j] = A1[i][j];
		}
		bt[i] = b1[i];
	}
}
void Gauss(double A1[N][N], double b1[N], double x1[N]) {
	
	double A[N][N] = {};
	double b[N] = {};
	COPY1(A1, b1, A, b);

	for (int i = 0; i < N; i++) {
		double temp = A[i][i];
		for (int j = 0; j < N; j++) {
			A[i][j] /= temp;
		}
		b[i] /= temp;

		double koef;
		for (int k = 0; k < N; k++) {
			if (k != i) {
				koef = -A[k][i];
				for (int j = 0; j < N; j++) {
					A[k][j] += koef * A[i][j];
				}
				b[k] += koef * b[i];
			}
		}
		cout << "Step: " << i + 1 << endl;
		OUTPUT1(A, b);
	}
	for (int i = 0; i < N; i++) {
		x1[i] = b[i];
	}
}

//Sqrt
#define M 3
#define complex complex<double>
void OUTPUTMATRIX(complex A[M][M]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
void INPUT2(complex A[M][M], complex b[]) {

	for (int i = 0; i < M; i++) {
		cout << "Input row number " << i + 1 << endl;
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	cout << "Input vector of results" << endl;
	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}
}
void OUTPUT2(complex A[M][M], complex b[]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << ' ';
		}
		cout << '	' << b[i] << endl;
	}
	cout << endl;
}
void COPY2(complex A2[M][M], complex b2[M], complex At[M][M], complex bt[M]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			At[i][j] = A2[i][j];
		}
		bt[i] = b2[i];
	}
}
void ComplexGauss(complex T2[M][M], complex b2[N], complex x2[N]) {

	complex T[M][M] = {};
	complex b[M] = {};
	COPY2(T2, b2, T, b);

	for (int i = 0; i < M; i++) {
		complex temp = T[i][i];
		for (int j = 0; j < M; j++) {
			T[i][j] /= temp;
		}
		b[i] /= temp;

		complex koef;
		for (int k = 0; k < M; k++) {
			if (k != i) {
				koef = -T[k][i];
				for (int j = 0; j < N; j++) {
					T[k][j] += koef * T[i][j];
				}
				b[k] += koef * b[i];
			}
		}
		cout << "Step: " << i + 1 << endl;
		OUTPUT2(T, b);
	}
	for (int i = 0; i < M; i++) {
		x2[i] = b[i];
	}
}
void Sqrt(complex A2[M][M], complex b2[M], complex x2[M]) {
	complex A[M][M] = {};
	complex b[M] = {};
	complex T[M][M] = {};
	complex TT[M][M] = {};

	COPY2(A2, b2, A, b);

	for (int i = 0; i < M; i++){
		complex temp(0,0);
		for (int k = 0; k < i; k++) {
			temp += pow(T[k][i],2);
		}
		complex half(0.5, 0);
		T[i][i] = pow(A[i][i] - temp , half);

		temp = complex(0,0);
		for (int j = i + 1; j < M; j++) {
			for (int k = 0; k < i; k++) {
				temp += T[k][i] * T[k][j];
			}
			T[i][j] = (A[i][j] - temp) / T[i][i];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			TT[i][j] = T[j][i];
		}
	}

	cout << "T Matrix:" << endl;
	OUTPUTMATRIX(T);
	cout << "T-Transpose Matrix:" << endl;
	OUTPUTMATRIX(TT);

	complex y2[M] = {};
	cout << "Task: Find y-vector with T-Transpose Matrix" << endl;
	OUTPUT2(TT, b2);
	ComplexGauss(TT, b2, y2);

	cout << "Task: Find x-vector with T Matrix" << endl;
	OUTPUT2(T, y2);
	ComplexGauss(T, y2, x2);
};

int main() {
	cout << fixed;
	cout.precision(2);

	//Gauss
	double A1[N][N] = { {4,3,1,0},{-2,2,6,1},{0,5,2,3},{0,1,2,7} };
	double b1[N] = {29,38,48,56};
	
	//INPUT(A1, b1);

	cout << "Task: Gauss`s Method" << endl;
	OUTPUT1(A1, b1);

	double x1[N] = {};
	Gauss(A1, b1, x1);

	cout << "Answer:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << 'x' << i+1 << " = " << x1[i] << endl;
	}
	cout << endl;
	
	//Sqrt
	complex A2[M][M] = { {5,2,0},{2,2,4},{0,4,3} };
	complex b2[M] = { 5,22,20 };

	//INPUT(A2, b2);

	cout << "Task: Square Root Method" << endl;
	OUTPUT2(A2, b2);

	complex x2[M] = {};
	Sqrt(A2, b2, x2);

	cout << "Answer:" << endl;
	for (int i = 0; i < M; i++)
	{
		cout << 'x' << i + 1 << " = " << x2[i] << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}