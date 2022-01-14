#include <iostream>

using namespace std;

class Rectangle {

private:
	int square;
protected:
	int a, b;
public:
	Rectangle() {
		cout << "Rectangle() - default constructor is called\n";
		a = 1;
		b = 1;
	}

	Rectangle(int a, int b) {
		cout << "Rectangle(int coordX, int coordY) - constructor with arguments is called\n";
		this->a = a;
		this->b = b;

	}

	Rectangle(const Rectangle& rec) {
		cout << "Rectangle() - copy constructor is called\n";
		this->a = rec.a;
		this->b = rec.b;
	}

	virtual void printCoords() {
		cout <<"Rectangle: "<< a << " " << b << endl;
	}

	void calculateSquare() {
		cout<<"Rectangle: calculateSquare() = "<< a * b<<endl;
	}


	virtual ~Rectangle() {
		cout << "~Rectangle() - default destructor is called\n";
		//cout << a << " " << b << endl;;
	}


};

class Cuboid :public Rectangle {
protected:
	int c;
public:
	Cuboid() :Rectangle() {
		cout << "Cuboid() - default constructor is called\n";
		this->c = 1;
	}

	Cuboid(int a, int b, int c) : Rectangle(a, b) {
		cout << "Cuboid() - constructor with arguments is called\n";
		this->c = c;
	}

	Cuboid(const Cuboid& cub) {
		cout << "Cuboid() - copy constructor is called\n";
		this->a = cub.a;
		this->b = cub.b;
		this->c = cub.c;
	}

	void printCoords(){
		cout <<"Cuboid: "<<a << " " << b<< " "<<c<<endl;
	}
	
	void calculateSquare() {
		cout<<"Cuboid: calculateSquare() = "<<a * b * c<<endl;
	}
};




int main(){
	Rectangle* rec = new Rectangle();
	Cuboid* cub = new Cuboid(2,1,4);
	Rectangle* cub2 = new Cuboid(6, 3, 2);
	rec->printCoords();
	cub->calculateSquare();
	cub2->calculateSquare();
	cub->printCoords();
	cub2->printCoords();
	


	return 0;
}