#include<iostream>

using namespace std;


struct Renderer
{
  virtual void render_circle(float x, float y, float radius) = 0 ;
};

struct VectorRender : Renderer {
  void render_circle(float x, float y, float radius) override {
    std::cout << "Vector Rendering of a circle of redius " << radius << std::endl;
  }
};

struct ResterRender : Renderer {
  void render_circle(float x, float y, float radius) override {
    std::cout << "Raster Rendering of a circle of redius " << radius << std::endl;
  }
};

struct Shape {
public:
  virtual void draw() = 0;
  virtual void resize(float factor) = 0;
protected:
  Renderer &renderer;
  Shape(Renderer &renderer) : renderer(renderer) {}
};

struct Circle : Shape {
  void draw() override {
    renderer.render_circle(x, y, radius);
  }
  void resize(float factor) override {
    radius *= factor;
  }
  float x, y, radius;
  Circle(Renderer &renderer, float x, float y, float radius) : Shape(renderer), x(x), y(y), radius(radius) {}
};


int main() {


  VectorRender vr;
  Circle vector_circle(vr, 10, 10, 5);
  vector_circle.draw();
  vector_circle.resize(2);

  return 0;
}