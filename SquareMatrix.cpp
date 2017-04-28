#include "SquareMatrix.h"
#include <iostream>
using namespace std;


void SquareMatrix::Transpose()
{
	for (int i = 0; i < order-1; i++) {
		for (int j = i+1; j < order; j++) {
			double tmp = elements[i][j];
			elements[i][j] = elements[j][i];
			elements[j][i] = tmp;
		}
	}
}

//double SquareMatrix::CalcOfDeterminant()
//{
//	const int n = order;
//	int * pVector=new int[n];
//	for (int i = 0; i <= n; i++) {
//		pVector[i] = i;
//	}
//	for (int i = 0; i < n; i++) {
//		double pValue = 0., absA;
//		int iMax = -1;
//		for (int j = i; j < n; j++) {
//			if (absA = fabs(elements[j][i]) > pValue) {
//				pValue = absA;
//				iMax = j;
//			}
//		}
//		if (iMax != i) {
//			//swap in vector
//			int temp = pVector[i];
//			pVector[i] = pVector[iMax];
//			pVector[iMax] = temp;
//			//swap in matrix
//			double * tPtr = elements[i];
//			elements[i] = elements[iMax];
//			elements[iMax] = tPtr;
//			//pivots
//			pVector[n]++;
//
//		}
//		for (int k = i + 1; k < n; k++) {
//			elements[k][i] /= elements[i][i];
//			for (int z = i + 1; z < n; z++) {
//				elements[k][z] -= elements[k][i] * elements[i][k];
//			}
//		}
//
//	}
//	double det = elements[0][0];
//	for (int i = 1; i < n; i++) {
//		det *= elements[i][i];
//		//cerr << elements[i][i] << endl;
//	}
//		if ((pVector[n] - n) % 2 == 0)
//			return det;
//		else
//			return -det;
//	
//}

int * SquareMatrix::LUP()
{
	const int n = order;
	int * pVector = new int[n];
	for (int i = 0; i <= n; i++) {
		pVector[i] = i;
	}
	int i;
	for (i = 0; i < n; i++) {
		double pValue = 0., absA;
		int iMax = i;
		for (int j = i; j < n; j++) {
			if (absA = fabs(elements[j][i]) > pValue) {
				pValue = absA;
				iMax = j;
			}
		}
		if (iMax != i) {
			//swap in vector
			int temp = pVector[i];
			pVector[i] = pVector[iMax];
			pVector[iMax] = temp;
			//swap in matrix
			double * tPtr = elements[i];
			elements[i] = elements[iMax];
			elements[iMax] = tPtr;
			//pivots
			pVector[n]++;

		}
		for (int k = i + 1; k < n; k++) {
			elements[k][i] /= elements[i][i];

			for (int z = i + 1; z < n; z++) {
				elements[k][z] -= elements[k][i] * elements[i][z];
			}
		}

	}
	return pVector;
}

double SquareMatrix::Det()
{
	if (order == 0)
		return 0;
	if (order == 1)
		return elements[0][0];
	if (order == 2)
		return elements[0][0] * elements[1][1] - (elements[1][0] * elements[0][1]);
	if (order > 2) {
		int * pVector = LUP();
		double det = elements[0][0];
		for (int i = 1; i < order; i++) {
			det *= elements[i][i];
			//cerr << elements[i][i] << endl;
		}
		if ((pVector[order] - order) % 2 == 0)
			return det;
		else
			return -det;
	}	
}

void SquareMatrix::Show() const
{
	cout << endl;
	for (int i = 0; i < order; i++) {
		for (int k = 0; k < order; k++) {
			cout.width(4);
			cout << elements[i][k] <<" ";
		}
		cout << endl;
	}
}

void SquareMatrix::setTest()
{
	order = 3;
	elements = new double*[order];
	for (int i = 0; i < order; i++) {
		elements[i] = new double[order];
	}
	elements[0][0] = 1.;
	elements[0][1] = 2.;
	elements[0][2] = 3.;
	elements[1][0] = 0.;
	elements[1][1] = 2.;
	elements[1][2] = 3.;
	elements[2][0] = 0.;
	elements[2][1] = 0.;
	elements[2][2] = 3.;
}

void SquareMatrix::setRand(int n)
{
	order = n;
	elements = new double*[order];
	for (int i = 0; i < order; i++) {
		elements[i] = new double[order];
	}
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			elements[i][j] = rand() % 10;
		}
	}
}

void SquareMatrix::setMatrix(int n, double **& M)
{
	order = n;
	elements = new double*[order];
	for (int i = 0; i < order; i++) {
		elements[i] = new double[order];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			elements[i][j] = M[i][j];
		}
	}

}

SquareMatrix::SquareMatrix(int n)
{
}

SquareMatrix::SquareMatrix()
{
}

SquareMatrix::~SquareMatrix()
{
	delete[]elements;
}
