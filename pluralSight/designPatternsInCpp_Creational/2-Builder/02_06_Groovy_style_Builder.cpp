#include <iostrem>
#include <sstream>
#include <vector>
#include <utility>

using namespace std;

struct Tag
{
    string name;
    string text;
    vector<Tag> childern;
    vector<pair<string, string>> attributes;

    friend ostream& operator<< (ostream &os, Tag& tag) {
        os << "<" << tag.name;

        for(auto &att : tag.attributes) {
            os << " " << att.first << "=\"" << att.second << "\"";
        }
        if(tag.childern.size() == 0 && tag.text.length() == 0) {
            os << "/>" << endl;
        } else {
            os << ">" << endl;

            if (tag.text.length()) 
                os << tag.text << endl;

            for (const auto& child : tag.childern ) 
                os << child;

            os << "</" << tag.name << ">" << endl;
        }

        return os;
    }
protected:
    explicit Tag (const string& name, const string& text) :
        name(name), text(text) {}
    explicit Tag(const string&name, const vector<Tag>& childern) {

    }
};

struct P : Tag
{
    explicit P (const string& text) : Tag("p", text) { }
    explicit P(initializer_list<Tag> childern) :Tag("p", childern) {}
};

struct  IMG : Tag
{
    explicit IMG (const string& url) : Tag("img", "") 
    {
        attributes.emplace_back(make_pair("src", url));
    }

    
};

int main(){

    cout << 
        P {
            IMG {"http://a.com/b.png"},
            P{"Hello"}
        }
        << endl;
    
    return 0;
}