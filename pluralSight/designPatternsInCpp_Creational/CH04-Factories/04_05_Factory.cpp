#include <iostream>
#include <cmath>

using namespace std;

/*
 * Previous factory method works fine if the object construction is simple.
 * If the object construction is complicated, we may decide to move to 
 * separate class or externalized (factory).
 * A Factory would be a separate component effectively that would take 
 * care of a particular object.
 */

class Point {
  Point(float x, float y) : x{x}, y{y} {}
public:
  float x, y;

  friend class PointFactory;
  friend ostream& operator<< (ostream &os, Point& pt) {
    return os
      << "x: " << pt.x
      << "y: " << pt.y;
  }
};

class PointFactory {
public:
  static Point Cartesian(float x, float y) {
    return {x, y};
  }
  static Point Polar(float r, float theta) {
    return { r * cos(theta), r * sin(theta)};
  }
};
int main() {

  // Point P{1, 2}; 
  Point C = PointFactory::Cartesian(1, 2);
  cout << "C = " << C << endl;
  Point P = PointFactory::Polar(3, M_PI_4);
  cout << "P = " << P << endl;

  return 0;
}

