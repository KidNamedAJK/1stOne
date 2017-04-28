#pragma once
class SquareMatrix
{
	int order;
	double ** elements;
	int * LUP();
public:
	void Transpose();	
	double Det();
	void Show()const;
	void setTest();
	void setRand(int n);
	void setMatrix(int n, double **&M);
	SquareMatrix();
	SquareMatrix(int n);
	~SquareMatrix();
};

