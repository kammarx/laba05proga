#include <iostream>

using namespace std;

class Rectangle {

private:
	int square;
protected:
	int coordX, coordY;
public:
	Rectangle() {
		cout << "Rectangle() - default constructor is called\n";
		coordX = 1;
		coordY = 1;
	}

	Rectangle(int coordX, int coordY) {
		cout << "Rectangle() - constructor with arguments is called\n";
		this->coordX = coordX;
		this->coordY = coordY;

	}

	Rectangle(const Rectangle& rec) {
		this->coordX = rec.coordX;
		this->coordY = rec.coordY;
	}
};



int main(){


	return 0;
}