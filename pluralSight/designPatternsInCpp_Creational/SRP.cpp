#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Journal {
  string title;
  vector<string> entries;

  explicit Journal(const string &title) : title{title} {}

  void add(const string &entry) { entries.push_back(entry); }

  /*
  Adding some of the functions which are not the responsibiity of the journal.
  */
  void save(const string &filename) {
    ofstream ofs(filename);
    for (auto &s : entries)
      ofs << s << '\n';
  }
};

/*
  How ever the problem is that it is not really the responsibiity of the journal
  to save itself. And typically what we want to do is we want to may be have a
  separate component actually take care of the saving. Because the problem is
  when ever we decide to save things differently or we want to save things to a
  different format, for example or different medium, then we would have to jump
  into journal class and alter the journal and recompile it, which could be a
  bit painful, and we could do with out it.

  Instead of having the save function in Journal class, we could do it we could
  have a separate component, so some sort of persistence manager.
  */

struct PersistenceManager {
  static void save(const Journal &j, const string &filename) {
    ofstream ofs(filename);
    for (auto &s : j.entries)
      ofs << s << '\n';
  }
};

/*
  This is a much better approach b/c if we need to change the way of saving the
  journal then we can do it in persistence Manager, with out actually changing
  the journal. And this kind of sums up the idea of SRP. Journal has the
  responsibility of keeping the entries where as the persistence Manager has the
  responsibility of persisting those entries
*/

/*
class should have basically one reason to change, we should not change it when
it is taking on some other responsibility. Which could be handled else where.
Journal has the responsibility of keeping the entries where as the persistence
Manager has the responsibility of persisting those entries
*/