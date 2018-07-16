//과제11 삼각형_상속

# include <iostream>
# include <vector>

using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(const int x, const int y)
		: x(x), y(y) {}
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
};

class Shape {
public:
	virtual void print() const = 0;
	virtual float getArea() const = 0;
	virtual ~Shape() {
		cout << "shape소멸자" << endl;
	} // 호출이 안되네..
};

class ShapeList {
private:
	vector<Shape*> list;
public:
	void addShape(Shape* shape) {
		list.push_back(shape);
	}

	void print() const {
		for (vector<Shape*>::const_iterator iteratorShape = list.begin(); iteratorShape != list.end(); ++iteratorShape) {
			Shape* shapePointer = *iteratorShape;
			shapePointer->print();
		}
	}

	float getTotalArea() {
		float totalArea = 0;

		for (vector<Shape*>::const_iterator iteratorShape = list.begin(); iteratorShape != list.end(); ++iteratorShape) {
			Shape* shapePointer = *iteratorShape;
			totalArea += shapePointer->getArea();
		}

		return totalArea;
	}
};


class Rectangle : public Shape {
private:
	Point p1;
	Point p2;
	Point p3;
	Point p4;

public:
	Rectangle(const Point p1, const Point p2, const Point p3, const Point p4)
		: p1(p1), p2(p2), p3(p3), p4(p4) {}
	virtual void print() const {
		cout << "Rectangle: (" << p1.getX() << "," << p1.getY() << ")(" << p2.getX() << "," << p2.getY() << ")(" << \
			p3.getX() << "," << p3.getY() << ")(" << p4.getX() << "," << p4.getY() << ")" << endl;
	}
	virtual float getArea() const {
		float area = ((float)p2.getY() - p1.getY())*p3.getX();
		return area;
	}
};

class Triangle : public Shape {
private:
	Point p1;
	Point p2;
	Point p3;

public:
	Triangle(const Point p1, const Point p2, const Point p3)
		: p1(p1), p2(p2), p3(p3) {}
	virtual void print() const {
		cout << "Triangle: (" << p1.getX() << "," << p1.getY() << ")(" << p2.getX() << "," << p2.getY() << ")(" << \
			p3.getX() << "," << p3.getY() << ")"  << endl;
	}
	virtual float getArea() const {
		float area = ((float)p2.getY() - p1.getY())*p3.getX() / 2;
		return area;
	}
	~Triangle() {
		cout << "triangle소멸자" << endl;
	} //이거도 호출안되네
};

int main() {
	Point p1(0, 0), p2(0, 10), p3(20, 20), p4(20, 30);

	Shape* r = new Rectangle(p1, p2, p3, p4);
	Shape* t = new Triangle(p1, p2, p3);

	ShapeList list;
	list.addShape(r);
	list.addShape(t);

	list.print();
	cout << list.getTotalArea() << endl;

}
