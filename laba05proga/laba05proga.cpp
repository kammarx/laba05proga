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
		cout << "Rectangle(int a, int b) - constructor with arguments is called\n";
		this->a = a;
		this->b = b;

	}

	Rectangle(const Rectangle& rec) {
		cout << "Rectangle(const Rectangle& rec) - copy constructor is called\n";
		this->a = rec.a;
		this->b = rec.b;
	}
	void func1() {//метод будет перекрываться
		cout << "Rectangle: func1()\n";
	}

	void func2() {//метод будет наследоваться
		cout << "Rectangle: func2()\n";
	}

	void func3() {
		cout << "Rectangle: func3()\n";
		func1();
	}
	virtual void printCoords() {
		cout <<"Rectangle: "<< a << " " << b << endl;
	}

	void calculateSquare() {//метод будет перекрываться
		cout << "Rectangle: calculateSquare() = " << a * b << endl;
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
		cout << "Cuboid(int a, int b, int c) - constructor with arguments is called\n";
		this->c = c;
	}

	Cuboid(const Cuboid& cub) {
		cout << "Cuboid(const Cuboid& cub) - copy constructor is called\n";
		this->a = cub.a;
		this->b = cub.b;
		this->c = cub.c;
	}

	void func1() {
		cout << "Cuboid: func1()\n";
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
	Cuboid* cub = new Cuboid();
	Cuboid* cub2 = new Cuboid(2,6,4);
	Rectangle* cub3 = new Cuboid(6, 3, 2);
	cout << endl;
	cub->func3();
	cout << endl;


	cub->func1();
	cub->func2();
	delete cub;

	rec->printCoords();//базовый виртуальный метод
	delete rec;

	cub3->printCoords();//наследуемый виртуальный метод

	cub2->calculateSquare();
	cub3->calculateSquare();

	cub2->printCoords();
	cub3->printCoords();
	
	delete cub2;
	delete cub3;


	return 0;
}