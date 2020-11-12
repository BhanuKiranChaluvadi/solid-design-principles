#include <iostream>
#include <cmath>

using namespace std;

/*
  Abolish constructor, Define static functions to return a class object 
    rather that constructing directly.
  We are going to make a factory methods , a simple static functions, which
    are going to yield a point in proper configured manner.
  The function names are very clear about the description.
    The name indicated what type of initialization, we are doing. so the parameter names.
  Here we move the constructor to private.
*/
class Point {
  Point(float x, float y) : x{x}, y{y} {}
public:
  float x, y;
  static Point Cartesian(float x, float y) {
    return {x, y};
  }
  static Point Polar(float r, float theta) {
    return { r * cos(theta), r * sin(theta)};
  }

  friend ostream& operator<< (ostream &os, Point& pt) {
    return os
      << "x: " << pt.x
      << "y: " << pt.y;
  }
};

int main() {

  // Point P{1, 2}; 
  Point C = Point::Cartesian(1, 2);
  cout << "C = " << C << endl;
  Point P = Point::Polar(3, M_PI_4);
  cout << "P = " << P << endl;

  return 0;
}

