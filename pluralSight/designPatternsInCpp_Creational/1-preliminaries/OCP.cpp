/*
 * Open for extension and closed for modification.\
 * closed for modification means there is no reason why you dig into the classes
 * that you have already written.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };

struct Product {
  string name;
  Color color;
  Size size;
  Product(string name, Color color, Size size)
      : name{name}, color{color}, size{size} {}
};

/*
Assume we would like to filter the products based on certain attribute.
*/
struct ProductFilter {
  typedef vector<Product *> Items;
  static Items by_color(const Items items, Color color) {
    Items result;
    for (auto &i : items) {
      if (i->color == color)
        result.push_back(i);
    }
    return result;
  }

  /*
   * Now my requirements are changed and would like to sort by size and
   * we end up replicaiting the entire structure.
   */

  static Items by_size(const Items items, Size size) {
    Items result;
    for (auto &i : items) {
      if (i->size == size)
        result.push_back(i);
    }
    return result;
  }
  /*
   * In future if we decide to fiter by both color & size
   *  And we end up replicating once again
   */

  static Items by_color_and_size(const Items items, Color color, Size size) {
    Items result;
    for (auto &i : items) {
      if (i->color == color && i->size == size)
        result.push_back(i);
    }
    return result;
  }

  /*
   * Instead of opening our class for extension we are actually opening for
   * modification and this is not good. And this violated the open-closed
   * principle. so you should not just jump into you class and modify, its
   * actual behaviour. Its much better to have a filter dynamically arranged.
   */
};

// Specification pattern - used quite a lot in data related access.
template <typename T> struct ISpecification {
  virtual bool is_satisfied(T *item) = 0;
};

template <typename T> struct IFilter {
  typedef vector<T *> Items;
  virtual Items filter(Items items, ISpecification<T> &specification) = 0;
};

struct BetterFilter : public IFilter<Product> {
  typedef vector<Product *> Items;
  Items filter(Items items, ISpecification<Product> &specification) override {
    Items result;
    for (auto &i : items) {
      if (specification.is_satisfied(i))
        result.push_back(i);
    }
    return result;
  }
};

struct ReverseFiter : public IFilter<Product> {};

struct ColorSpecification : public ISpecification<Product> {
  Color color;
  ColorSpecification(Color color) : color{color} {}
  bool is_satisfied(Product *item) override { return item->color == color; }
};

struct SizeSpecification : public ISpecification<Product> {
  Size size;
  SizeSpecification(Size size) : size{size} {}
  bool is_satisfied(Product *item) override { return item->size == size; }
};

template <typename T> struct AndSpecification : public ISpecification<T> {
  ISpecification<T> &first;
  ISpecification<T> &second;
  AndSpecification(ISpecification<T> &first, ISpecification<T> &second)
      : first(first), second(second) {}
  bool is_satisfied(T *item) override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};

int main() {

  Product apple{"kashmir", Color::Red, Size::Large};
  Product tree{"christmas", Color::Green, Size::Small};

  vector<Product *> items{&apple, &tree};

  ColorSpecification green(Color::Green);
  SizeSpecification size(Size::Small);

  BetterFilter bf;
  auto result = bf.filter(items, size);
  // for (auto i : result)
  // cout << i.name << '\n';

  AndSpecification<Product> colorAndSize(size, green);
  result = bf.filter(items, colorAndSize);
  for (auto i : result)
    cout << i->name << '\n';

  return 0;
}

/*
 * closed for modification means there is no reason why you dig into the classes
 * that you have already written. Because bear in mind, if you have already got
 * product filter, you probably got it tested already and after you make the
 * changes, you have to res-test that code, and that is particularly painful
 * when new requirements showup in our project.
 */