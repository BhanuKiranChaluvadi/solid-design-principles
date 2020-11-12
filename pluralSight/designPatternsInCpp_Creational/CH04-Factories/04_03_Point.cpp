#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
  float x;
  float y;

  Point(float x, float y) : x(x), y(y) {}
};

// The above works well, when we wants to initialize the point in cartesian co-ordinates
// What if we want to initialize Point class with polar co-ordinates

class Point {
public:
  float x;
  float y;

  Point(float x, float y) : x(x), y(y) {}
  // Overloading the constructor with same arguements in not possible / smae signature.
  // No input to the consumer, based on the variable names.
  Point(float r, float t) {
    x = r * cos(t);
    y = r * sin(t);
  }
};

// work around - typical approach
enum class PointType {
  cartesian,
  polar
};

class Point {
public: 
  float x;
  float y;

  Point(float a, float b, PointType type = PointType::cartesian) {
    if (type == PointType::cartesian){
      x = a;
      y = b;
    } else {
      x = a * cos(b);
      y = a * sin(b);
    }
  }
};

// problems
// variable name a & b provide no clues about the point type
// becuase of default type, what is they forget to input PointType.
// if/else statements keep on increasing for more cases.
