/*
 * Monads are design patterns in functional programming
 * Functional design pattern - May be Monad
 */

#include <iostream>
#include <string>
using namespace std;

/*
 *
 */

struct Address
{
  /*
   * A typical house address is a number and street name and so on... but
   * if you have a castle for example - that probably doesn't have a house number.
   * But you have a house name. In this case instead of a steet name/number, 
   * you have a house name. But the house name may be optional.
   * How do you represent this optionality ?? Lots of ways of doing it
   * 1. pointer which is a nullptr and based on if (nullptr) do some thing.
   *    If the value is missing we can have a boost optional value
   * 2. Just a string with no value. If (string = "") 
   */
  string* house_name = nullptr;
};

/*
 * Now the person with a optional address. So here is the situation. 
 * A person with an optional address and address with optional house name.
 */

struct Person
{
  Address* address = nullptr;
};

/*
 * Lets suppose at some point we decide to write a fucntion. Lets say its
 * prints the house name.
 */

void old_print_house_name(Person* p) {
  // This could be dangerous b/c the person / address/house_name can be nullptr 
  cout <<  *p->address->house_name << endl;
  // Ugliest solution
  if (p != nullptr && p->address != nullptr && p->address->house_name != nullptr)
      cout <<  *p->address->house_name << endl;
}

/*
 * Here we are lucky, we have only 3 stages to drill down. But in cases like
 * compilers and parsers, where we need to drill down deep to a particular
 * structure. we will be in trouble using this kind of notation is silly.
 * What can we do about it ?
 * In functional land, we can actually reformuated the very process of 
 * drilling down into some structure and make it in a fucntional way.
 * And this what "May be Monad" is all about.
 */

// template can be person/address/houe_name  -- forward declaring it here.
template<typename T> struct Maybe;

/* The only reason this exsits is b/c 
 * we dont want to write Maybe<Person> / Maybe<Address> etc. It kill the fun.
 * We want to specify just Maybe(p);
 * This is factory function on the kind of global scope. The reason is
 * here, we get type deductions, so even though I cannot make a \
 * 'Maybe(p)' but we can may 'maybe(p)' and this is valid and type deduced.
 */
template<typename T> Maybe<T> maybe(T* context)  {
  return Maybe<T>(context);
}
/*
 * What is maybe monad ? 
 * Weel, essentially it's a construct which keeps the context, it keeps the
 * current thing we are drilling into.
 */
template<typename T> struct Maybe{
  T* context;

  explicit Maybe(T* const context) : context{context} {
  }

  template <typename Func> 
  auto With(Func evaluator) {
    if (context == nullptr) {
      Maybe<typename remove_pointer<decltype(evaluator(context))>::type>(nullptr);
    } else {
      return maybe(evaluator(context));
    }
  }

  template<typename Func>
  auto Do(Func action) {
    if (context != nullptr) action(context);
    return *this;
  }

};


void print_house_name(Person* p) {
  maybe(p)
   .With([](auto x) { return x->address; })
   .With([](auto x) { return x->house_name; })
   .Do([](auto x) { cout << *x << endl;});
}

int main(){
  Person p;
  p.address = new Address;
  p.address->house_name = new string ("Otto Baches Vej 13");

  print_house_name(&p);

  delete p.address->house_name;
  delete p.address;

  Person p2;
  print_house_name(&p2);

  Person p3;
  p3.address = new Address;

  print_house_name(&p3);

  delete p3.address->house_name;
  delete p3.address;

  return 0;
}