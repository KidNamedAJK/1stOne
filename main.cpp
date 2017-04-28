#include "SquareMatrix.h"
#include <iostream>
using namespace std;

void menu(SquareMatrix &X);
void menuHMatrix(SquareMatrix &X);
void menuRMatrix(SquareMatrix &X);
void menuT(SquareMatrix &X);
void menuDet(SquareMatrix &X);
void menuShow(SquareMatrix &X);

void main() {
	SquareMatrix X;
	//X.setTest();
	////FOR MENU
	//double ** elements = new double*[3];
	//for (int i = 0; i < 3; i++) {
	//	elements[i] = new double[3];
	//}
	//for (int i = 0; i < 3; i++) {
	//	cout <<i<<" Row" << endl;
	//	for (int j = 0; j < 3; j++) {
	//		cout << "type cf";
	//		cin >> elements[i][j];
	//	}
	//	cout << endl;
	//}
	//// CODE	
	//X.setMatrix(3, elements);
	//X.Show();

	//X.setRand(3);
	//X.Show();
	//cout << X.Det() << endl;

	//X.setRand(4);
	//X.Show();
	//cout << X.Det() << endl;
	//
	//X.setRand(5);
	//X.Transpose();
	//X.Show();
	//cout << X.Det() << endl;
	menu(X);
}

void menu(SquareMatrix &X) {
	int choice;

	do
	{
		cout << endl
			<< " 1 - Write matrix by hand.\n"
			<< " 2 - Generate random matrix in order by.\n"
			<< " 3 - Transpose matrix.\n"
			<< " 4 - Show Matrix.\n"
			<<" 5 - Determent of matrix.\n"
			<< " 6 - Exit.\n"
			<< " Enter your choice and press return: ";
		cin >> choice;

		switch (choice)
		{
		case 1:			
			menuHMatrix(X);
			break;
		case 2:			
			menuRMatrix(X);
			break;
		case 3:			
			menuT(X);
			break;
		case 4:			
			menuShow(X);
			break;
		case 5:
			cout << endl;
			menuDet(X);
			break;
		case 6:
			cout << "End of Program.\n";
			break;
		default:
			cout << "Not a Valid Choice. \n"
				<< "Choose again.\n";
			break;
		}

	} while (choice != 6);

}

void menuHMatrix(SquareMatrix &X) {	
	int n;
	cout << "Write down order of matrix"<<endl;
	cin >> n;
	double ** elementz = new double*[n];
	for (int i = 0; i < n; i++) {
		elementz[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		cout << i << " Row" << endl;
		for (int j = 0; j < n; j++) {
			cout << "cf: ";
			cin >> elementz[i][j];
		}
		cout << endl;
	}
	X.setMatrix(n,elementz);
}
void menuRMatrix(SquareMatrix &X) {
	cout << "Write down order of matrix"<<endl;
	int n;
	cin >> n;
	X.setRand(n);
}
void menuT(SquareMatrix &X) {
	X.Transpose();
}
void menuDet(SquareMatrix &X) {
	cout << X.Det() << endl;
}
void menuShow(SquareMatrix &X) {
	cout << "Matrix" << endl;
	X.Show();
}