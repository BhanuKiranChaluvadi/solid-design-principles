#include <iostream>
#include <cmath>

using namespace std;

/*
 * The PointFactory itself, is not worth instantiating because there is 
 * nothing to call. If we were to remove static keyword then ofcourse 
 * we can make an PointFactor object and call functions. Separete PF 
 * (point factory) object make sense if we want to send PF to some othe place.
 * 
 * But in other cases it might be argued that we don't really need a separate 
 * component in terms of API.
 * 
 * We do want to somehow take out the process of creation into separate class.
 * But we don't necessarly want this class to be available to other users of API.
 * We dont want them instantiating lots of these things and call their own function.
 * 
 * How to get best of bothe worlds ? Separate class but open to initialization by 
 * users / expose to user. Make PF class private inside Point class.  PF class 
 * doesn't make sense if Point class doesn't exsist.
 */
class Point {
  Point(float x, float y) : x{x}, y{y} {}

  class PointFactory {
  public:
    static Point Cartesian(float x, float y) {
      return {x, y};
    }
    static Point Polar(float r, float theta) {
      return { r * cos(theta), r * sin(theta)};
    }
  };

public:
  float x, y;

  static PointFactory Factory;

  friend ostream& operator<< (ostream &os, Point& pt) {
    return os
      << "x: " << pt.x
      << " y: " << pt.y;
  }
};


int main() {

  // PointFactory pf;
  // auto P = pf.Cartesian(1, 2);

  // Point::PointFactory pf;
  //   auto P = Point::Factory::Cartesian(1, 2); // Closing this route since private class

  auto P = Point::Factory.Cartesian(1, 2);
  cout << P << endl;

  return 0;
}

