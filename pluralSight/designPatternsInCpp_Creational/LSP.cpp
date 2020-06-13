/*
 * Liskov Substitution Principle
 * Objects in program should be replaceable with instances of their subtypes (subclass)
 * w/o altering the correctness of the program
 */

#include <iostream>

using namespace std;

class Rectangle
{
protected:
  int width, height;

public:
  Rectangle(int width, int height) : width(width), height(height) {}
  virtual int GetWidth() const { return width; }
  virtual void SetWidth(const int width)
  {
    this->width = width;
  }
  virtual int GetHeight() const { return height; }
  virtual void SetHeight(const int height) { this->height = height; }
  int Area() const { return width * height; }
};

void process(Rectangle &r)
{
  int w = r.GetWidth();
  r.SetHeight(10);
  std::cout << "expected area = " << (w * 10) << ", got " << r.Area() << '\n';
}

/*
 * Let see how this all breaks down completely. So lets violate LSP.
 */

class Square : public Rectangle
{
public:
  Square(int size) : Rectangle(size, size) {}
  void SetWidth(const int width) override
  {
    this->width = width;
    this->height = width;
  }
  void SetHeight(const int height) override
  {
    this->width = height;
    this->height = height;
  }
};


/*
 * The best way to fix this problem is to never have a square class at all.
 * /

/*
 * Instead of square we can have a RectangleFactory
 * We can also have void setsize function in Rectangle class specific to square but that 
 * voilates the polymorphism. We will discuss this solution in Factories. 
 */
struct RectangleFactory
{
  static Rectangle CreateRectangle(int w, int h);
  static Rectangle CreateSquare(int size);
};

int main()
{
  Rectangle r(5, 5);
  process(r);

  // you should see the problem in here.
  Square s(5);
  process(s);
  return 0;
}

