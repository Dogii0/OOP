#include <iostream>
#include <cstdlib>
using namespace std;

/*
				HW 1 (7pts, Due: 10/1 23:59PM)
Provide a class Matrix to complete this code.
This class should support the following methods:

1. void create()
This function takes two integers (say n and m) from user input and allocates memory blocks for an n by m matrix. (NOT m by n !!!).
You may want to use dynamic memory allocation.

2. void destory()
This function releases the allocated memory blocks.

3. void display()
This function displays the matrix in the form of an n by m matrix.

4. void set()
This function sets the values of the matrix to non-zero integers between 0 and 5. You may want to use rand() for this.

5. void transpose()
This function displays the transpose of the matrix in the form of an m by n matrix.

6. int getMax()
This function returns the maximum value of the matrix.

7. bool isSquare()
This function checks if the matrix is a square matrix or not.

Submit this file to the LMS.
*/

//Your code goes here.

class Matrix{
	int**mat;
	int n,m;
	public:
		void create();
		void destroy();
		void set();
		void display();
		void transpose();
		int getMax();
		bool isSquare();
};

void Matrix:: create(){
	cout<<"please enter the numbers:"<<endl;
	cin>>n;
	cin>>m;
	mat = (int **)malloc(n * sizeof(int*));
	for(int i = 0; i < n; i++) mat[i] = (int *)malloc(m * sizeof(int));
}

void Matrix::destroy(){
	free(mat);
}

void Matrix::display(){
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Matrix::set(){
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			mat[i][j]=rand()%5;
		}
	}
}
void Matrix::transpose(){
	cout<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n;j++){
			cout<<mat[j][i]<<" ";
		}
		cout<<endl;
	}
}

int Matrix:: getMax(){
	int max=0;
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			if(mat[i][j]>max)
			max=mat[i][j];
		}
	}

	return max;
}

bool Matrix:: isSquare(){
	if (m==n) return 1;
	else return 0;
}


//DO NOT TOUCH THE MAIN FUNCTION.
int main() {

	for (int i = 0; i < 3; i++) {
		Matrix* A = new Matrix;
		cout << "====Matrix A[" << i << "]====" << endl << endl;
		A->create();
		A->set();
		A->display();
		A->transpose();
		cout << "Maximum value: " << A->getMax() << endl;
		cout << "Matrix A[" << i << "] is " << (A->isSquare() ? "" : "not ") << "a square matrix." << endl;
		A->destroy();
		delete A;
		cout << endl << "==== Bye!!! ====" << endl << endl;
	}

	return 0;
}