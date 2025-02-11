#include <iostream>
#include <memory>

// Abstract base class
class Shape
{
public:
	virtual ~Shape()
	{
		std::cout << "Destructing Shape\n";
	} // Virtual destructor
	virtual double area() = 0;
};

static const double PI = 3.1415;

// Concrete subclass: Circle
class Circle : public Shape
{
public:
	explicit Circle(double radius): radius{radius} {};
	double area() override
	{
		std::cout << "Computing the area of a Circle of radius " << radius << "\n";
		return radius * radius * PI;
	}
	const double Radius()
	{
		return radius;
	}
private:
	double radius{0.0};
};

// Concrete subclass: Rectangle
class Rectangle : public Shape
{
public:
	Rectangle (double width, double height): width{width}, height{height} {}
	double area() override
	{
		std::cout << "Computing the area of a " << width << " by " << height <<
		          " Rectangle.\n";
		return width * height;
	}
	const double Width()
	{
		return width;
	}
	const double Height()
	{
		return height;
	}
private:
	double width{0.0};
	double height{0.0};
};


double totalArea(Shape **shapes, size_t n)
{
	double sumAreas = 0;
	for (size_t i = 0; i < n; i++) {
		sumAreas += shapes[i]->area();
	}
	return sumAreas;
}


struct Point {
	int x;
	int y;
};


void draw(Circle &c, Point center)
{
	std::cout << "Drawing a circle of radius " << c.Radius() << " centered at (" <<
	          center.x << ", " << center.y << ").\n";

}

void draw(Rectangle &r, Point topLeft)
{
	std::cout << "Drawing a " << r.Width() << " by " << r.Height() <<
	          " rectangle "
	          << " with top-left corner at (" <<
	          topLeft.x << ", " << topLeft.y << ").\n";
}


int main()
{
	Shape *c = new Circle(2);
	Shape *r = new Rectangle(3, 4);

	double area = c->area();
	std::cout << "Area = " << area << std::endl;
	area = r->area();
	std::cout << "Area = " << area << std::endl;


	Shape *shapes[2] = {c, r};
	double ta = totalArea(shapes, 2);

	std::cout << "Total area is " << ta << std::endl;

	delete shapes[0];
	delete shapes[1];


	Circle cobj{2};
	Rectangle robj{3, 4};
	draw(cobj, Point{0, 0});
	draw(robj, Point{0, 0});


	return 0;
}

