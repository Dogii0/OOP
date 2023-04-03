#include <iostream>
#include <cstdlib>
#include <ctime>
#define PI 3.14
#define EXIT -1
using namespace std;


/*					HW3 (16pts, 22.11.21.)
Your goal is
1) to complete the class Shape, and
2) to create two classes, Circle and Square, by inheriting from the class Shape,
to make the main function work properly.

Notes.
1. You are NOT ALLOWED to modify the main function.
2. The class Shape is currently incomplete; something must be added or modified.
   You are FREE to modify the class Shape.


The key requirements are listed below:
1. Both Circle and Square are characterized by one integer variable _d which has a different meaning as follows:
	 In Circle, a _d represents the radius of a circle.
	 In Square, a _d represents the length of one side. (Recall: all four sides are the same length.)

2. displayTypeAndArea()
	This function displays the type (either circle or square) and the area of the caller object.
	It may give different results depending on which object is calling it.
	For example, if displayTypeAndArea() is called by a square with _d of 2, then its ouput will be something like "Type: Square, Area: 4".
	And, "Type: Circle, Area: 3.14", if called by a circle with _d of 1.

3. The static variable cnt is employed to keep track of the number of objects.

4. Destructors
	You need to implement destructors for both the base and derived classes (3 in total).
	Recall that the two destructors of a derived class and the base must be called in order, everytime an object is destroyed, otherwise a memory leak will occur.
	Plus, make each destructor show some message such as "[Circle] Destructor Called", so you can see which class is calling it. 
*/


// Complete the Shape class. You are FREE to modify this.
class Shape {
private:
	int _d;
protected:
	static int cnt;
public:
Shape(){_d=0;}
	void setD(int d) { _d = d; }
	int getD() { return _d; }
	static int getCnt() { return cnt; }
	
	virtual void displayTypeAndArea() { cout << "You called the wrong function. There must be something wrong in your code." << endl; }
	virtual ~Shape(){
		cout<<"Shape Destructor"<<endl;
		cnt--;
	}
};

class Circle : public Shape{
	// int area;
public:
	explicit Circle(int i){
		setD(i);
		cnt++;
	}
	void displayTypeAndArea(){cout<<"Type: Circle, Area:"<<getD()*getD()*PI<<endl;}
	~Circle() override{
		cout<<"Circle Destructor"<<endl;
	}
};

class Square : public Shape{
public:
	explicit Square(int d){
		setD(d);
		cnt++;
	}
	void displayTypeAndArea(){cout<<"Type: Square, Area:"<<getD()*getD()<<endl;}
	~Square() override{
		cout<<"Square Destructor"<<endl;
	}
};

// DO NOT TOUCH THE MAIN FUNCTION.
int Shape::cnt = 0;
int main() {
	srand(time(NULL));
	cout << "Press 'c' for circle, 's' for square, and 'q' to quit." << endl;
	cout << "You can create up to 5 objects." << endl << endl;
	Shape* arr[5] = { 0, };									// maximum 5 objects can be created.

	char s;
	int i = 0;
	bool exit = false;
	while (1) {
		i = Shape::getCnt();
		cin >> s;
		switch (s) {
		case 'c':
			arr[i] = new Circle(rand() % 10 + 1);		// A circle is created.
			cout << endl << "Shape[" << i << "] Created" << endl;
			break;
		case 's':
			arr[i] = new Square(rand() % 10 + 1);		// A square is created.
			cout << endl << "Shape[" << i << "] Created" << endl;
			break;
		case 'q':
		default:
			exit = true;								// Otherwise, the loop is terminated.
			break;
		}
		if (true == exit) break;
		if (arr[i] != NULL)
			arr[i]->displayTypeAndArea();				// The type and the area of arr[i] are displayed, e.g., "Type: Square, Area: 4"

		if (5 == Shape::getCnt()) break;
	}

	cout << endl << Shape::getCnt() << " Objects Created" << endl << endl;				// Total # of objects is displayed.

	// delete the all objects
	while (Shape::getCnt() > 0) {
		cout << endl << "Deleting Shape[" << Shape::getCnt() - 1 << "]..." << endl;
		delete arr[Shape::getCnt() - 1];				
	}
	cout << endl << endl << "===BYE===" << endl;
	return 0;
}