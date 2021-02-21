#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

class String {
public:
  String(const string& cs) : s(cs) {
  }

  String to_lower() const {
    string ss(s);
    boost::to_lower(ss);
    return ss;
  }

  vector<string> split(const string& delimeter=" ") const {
    vector<string> parts;
    boost::split(parts, s, boost::is_any_of(delimeter), boost::token_compress_on);
    return parts;
  }

private:
  string s;
};


int main() {

  /* With out an adaptor
  string s{"Hello   World"};
  boost::to_lower(s);

  vector<string> parts;
  boost::split(parts, s, boost::is_any_of(" "));
  for (const auto& p : parts )
    cout << "<" << p << ">" << endl; 

  */

  // Using Adaptor
  String s{"Hello   World"};
  auto parts = s.to_lower().split();
  for (const auto& p : parts )
    cout << "<" << p << ">" << endl;
    
  return 0;
}