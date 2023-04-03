#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
				HW 2 (7pts, Due: 10/23 23:59PM)
Provide a class Matrix to complete this code.
You have to implement the following methods:

1. Constructor(s)
Provide one or more constructors that take two integers n and m and create an n by m random matrix.
All n amd m values are limited to 3. No need to use dynamic memory allocation; just use a 3 by 3 array.

2. transpose
This function returns its own transpose matrix.

3. show
This function displays the matrix in the form of an n by m matrix.

4. +
Operator overloading for matrix addition.

5. *
Operator overloading for matrix multiplication.

6. ==
Operator overloading to check if two given matrices are equal.

Submit this file to the LMS.
*/


//Your code goes here.

class Matrix{
	private:
		int**mat;
		int n,m;
	public:
		Matrix(int x, int y){
			n=x;
			m=y;
			
			mat = new int*[n];
			for(int i = 0; i < n; ++i) {
    			mat[i] = new int[m];
				for(int j=0; j<m; j++){
					mat[i][j]= rand()%5;
				}
			}
		}
		Matrix operator+(Matrix);
		Matrix operator*(Matrix);
		bool operator==(Matrix);
		void show();
		Matrix transpose();
};

Matrix Matrix::operator+(Matrix A){
	Matrix temp(n,m);

	if(n!=A.n||m!=A.m){
		cout<<"can't add!";
	}
	
	for(int i =0; i<n;i++){
		for(int j=0; j<m; j++){
			temp.mat[i][j]= mat[i][j]+A.mat[i][j];
		}
	}

	return temp;
}

Matrix Matrix::operator*(Matrix M){
	Matrix temp(n,M.m);
		for(int i = 0; i < n; ++i) {
			for(int j=0; j<m; j++){
				temp.mat[i][j]= 0;
			}
		}

	if(m!=M.n){
		cout<<"can't multiply"; 
		return temp;
	}

	for(int i =0; i<n;i++){
		for(int j=0; j < M.m; j++){
			for(int k=0; k<m; k++){
				temp.mat[i][j] +=mat[i][k]*M.mat[k][j];
			}
		}
	}

	return temp;

}

bool Matrix:: operator==(Matrix E){
	if(m!=E.m||n!=E.n){
		return false;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mat[i][j]!=E.mat[i][j]){
				return false;
			}else continue;
		}
	}
	return true;
}

Matrix Matrix:: transpose(){
	Matrix temp(m,n);
	for(int i=0; i<m; i++){
		for(int j=0; j<n;j++){
			temp.mat[i][j]=mat[j][i];
		}
	}
	return temp;
}

void Matrix:: show(){
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

//DO NOT TOUCH THE MAIN FUNCTION.
int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	Matrix A(2, 3), B(2, 3), C(2, 3), AT(3, 2), BT(3, 2), D(3, 2), E(2, 2), F(2, 2);
	AT = A.transpose();
	BT = B.transpose();
	cout << "A" << endl;
	A.show();
	cout << "=========" << endl;
	cout << "B" << endl;
	B.show();
	cout << "=========" << endl;
	cout << endl << "A " << (A == B ? "==" : "!=") << " B" << endl << endl << endl;

	C = A + B;
	cout << "C = A + B" << endl;
	C.show();
	cout << "=========" << endl;
	D = AT + BT;
	cout << "D = AT + BT" << endl;
	D.show();
	cout << endl << "C " << (C == D.transpose() ? "==" : "!=") << " Transpose of D" << endl << endl << endl;

	E = A * BT;
	cout << "E = A * BT" << endl;
	E.show();
	cout << "=========" << endl;
	F = B * AT;
	cout << "F = B * AT" << endl;
	F.show();
	cout << endl << "E " << (E == F.transpose() ? "==" : "!=") << " Transpose of F" << endl << endl << endl;

	return 0;
}