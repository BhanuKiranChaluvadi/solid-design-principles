// Life Without Builders

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

struct HtmlBuilder;

struct HtmlElement
{
    string name;
    string text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement(){}
    HtmlElement(const string& name, const string& text) 
        : name{name}, text{text}
    {
    }

    string str(int indent = 0) const 
    {   
        ostringstream oss;
        string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0) {
            oss << string(indent_size * (indent + 1 ), ' ') << text << endl;
        }
        for (const auto& e : elements ) {
            oss << e.str(indent + 1);
        }

        oss << i << "</" << name << ">" << endl;
        
        return oss.str();
    }

    static HtmlBuilder build(string root_name) ;
    static unique_ptr<HtmlBuilder> create(string root_name) ;
};



struct HtmlBuilder
{   
    HtmlBuilder(string root_name) 
    {
        root.name = root_name;
    }

    HtmlBuilder& add_child(string child_name, string child_text) 
    {
        HtmlElement e(child_name, child_text);
        root.elements.emplace_back(e);
        return *this;
    }

    HtmlBuilder* add_child_2(string child_name, string child_text) 
    {
        HtmlElement e(child_name, child_text);
        root.elements.emplace_back(e);
        return this;
    }

    string str() const 
    {   
        return root.str();
    }

    operator HtmlElement() { return root; };

    // operator unique_ptr<HtmlElement>() { return make_unique<HtmlElement>(root);}

    HtmlElement root;
};

HtmlBuilder HtmlElement::build(string root_name) 
{
    return HtmlBuilder(root_name);
}

unique_ptr<HtmlBuilder> HtmlElement::create(string root_name) 
{
    return make_unique<HtmlBuilder>(root_name);
}

int main()
{
    HtmlBuilder builder("ul");
    builder.add_child("li", "hello")
        .add_child("li", "world");

    // HtmlElement e = builder;

    HtmlElement e = HtmlElement::build("ul").add_child("li", "hello");

    HtmlElement ee = *(HtmlElement::create("ul")->add_child_2("li", "hello"));

    cout << e.str() << endl;

    // cout << builder.str() << endl;

    return 0;
}
