/*
 * Interface Segregation Principle
 * No Client (some body who is end user / some one who consumes your code and that
 * includes other classes) should not be forced to depend on methods (member
 * fuctions) it doesn't use. Many small interfaces are better than single large
 * interface.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

// Lets suppose we have a bunch of documents
struct Document;

/*
 * some where i want to create a virtual kind of multi-functionsal device, which
 * is able to print, fax, scan and so on, these documents. so efficientively I
 * make an interface, first of all, remember that in previous examples we
 * agreedwith abstractions rather than concrete implementation. so we are gonna
 * have an interface
 */

struct IMachine {
  virtual void print(vector<Document *> docs) = 0;
  virtual void fax(vector<Document *> docs) = 0;
  virtual void scan(vector<Document *> docs) = 0;
};

/*
 * Now we have an interface of course, we would have a concrete implementation,
 * or maybe its not you that  has this implementation, may be we gave this
 * interface to somebody, and we said "Hey of you want to have this, if you want
 * his to be part of the overall code, then you have to implement this interface
 * and feed me the concrete realization." . so some body takes this code and
 * they make the multi-functional peripheral, as it's called, by inheriting and
 * implementing all the stuff
 */

// client side
struct MPF : public IMachine {
  void print(vector<Document *> docs) override;
  void fax(vector<Document *> docs) override;
  void scan(vector<Document *> docs) override;
};

/*
 * As per ISP this is actually a bad idea, and there are several reasons. First
 * of all, every time when you cahnge a particular chunk of functoinality, like
 * you change just the printing mechanism with out touching the scanning or
 * faxing mechanism, you would have to recompile, because this is part of the
 * overall code, it's part of a single kind of block. So this is pain.
 *
 * The second issue us that perhaps the client doesn't necessarly needs this,
 * and the idea here is that they just need the print functionality to work,
 * they don't really want implement or even deal with the other parts of
 * interface. May be they have no idea how to impement it, but you on your end
 * trigger those parts of the functionality anyway, there by resulting in some
 * cataclysmic explosion or something. so this is another problem.
 *
 * Finally the issue here is that, you know, you are forcing the implementer to
 * implement too much, essentially, you are forcing them to implement these
 * functionality and get you functionality that they may not necessarly need.
 *
 * So The interface segregation principle is all about breaking this kind of
 * monolithic monstrocity, and doing it in a piece-wise fashion.
 */

/*
 * I guess the above interface violates many principles SRP - Its performing
 * many tasks like printing, fax, scan - if we change one we have to re-compile
 * all the class. OCP - Its is open for modification and closed for extension If
 * new features show's up in our project - we need to add more functions to the
 * class and needed to be recompiled. ISP - If the end user needs only printing
 * & scannig but not fax we are actually forcing it to have a fax implemented or
 * use it some way.
 */

// This can be templated as well
// Instead of passing the documents <T>

// we can also have a single Inerface class with virtual function perform action
// and overridded by each separate implementations of print, fax & scan
struct IPrinter {
  virtual void print(vector<Document *>) = 0;
};

struct IFaxer {
  virtual void fax(vector<Document *>) = 0;
};

struct IScanner {
  virtual void scan(vector<Document *>) = 0;
};

// Actual concrete Implementation
struct Printer : public IPrinter {
  void print(vector<Document *>) override {
    cout << " perform print. " << '\n';
  }
};

struct Faxer : public IFaxer {
  void fax(vector<Document *>) override { cout << " perform fax. " << '\n'; }
};

struct Scanner : public IScanner {
  void scan(vector<Document *>) override { cout << " perform scan. " << '\n'; }
};

/*
 * What we can do now is, if somebody asks us just the printing functionality or
 * just the scanning functionality, we don't have to give them this large
 * complicated object. Instead we give them smaller objects, or indeed if they
 * ask for 'IPrinter', we just give them a printer for example (this is some
 * thing you do in dependency injection setting. )
 */

struct IMachine : public IPrinter, public IFaxer, public IScanner {};

// Decorator pattern - Machine can actually be decorator
struct Machine : public IMachine {
  IPrinter &printer;
  IFaxer &faxer;
  IScanner &scanner;

  Machine(IPrinter &print, IFaxer &fax, IScanner &scan)
      : printer(print), faxer(fax), scanner(scan) {}

  void print(vector<Document *> docs) override { printer.print(docs); }
  void fax(vector<Document *> docs) override { faxer.fax(docs); }
  void scan(vector<Document *> docs) override { scanner.scan(docs); }
};

// If we need a color printer the need to implement and the
// IMachine & Machine Interface doesn't change.
struct ColorPrinter : public IPrinter {};
