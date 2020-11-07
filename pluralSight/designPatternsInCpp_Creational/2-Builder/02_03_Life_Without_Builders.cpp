// Life Without Builders

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

int main() {

    // Let imagine we are building a extremely trivial web server.
    // And the webserver serves html - Lets serve a paragraph
    // <p>hello</p>

    auto text = "hello";
    string output;
    output += "<p>";
    output += text;
    output += "</p>";
    cout << output << endl;

    // Above: Not exciting but it is what we wanted. 
    // only problem is we are putting lot of effort in typing all of it.

    printf("<p>%s</p>", text); 

    // Above is simpler but no way general. Not user friendly for end users
    // to make their own pages

    // Lets output list of words
    // <ul><li>hello</li><li>world</li></ul>
    string words[] = {"hello", "world"};
    ostringstream oss;
    oss<< "<ul>";
    for(auto w : words)
        oss << " <li>" << w << "</li>";
    oss<< "</ul>";
    printf(oss.str().c_str());

    // we are essentially getting the output but we are getting by a painful 
    // fashion b/c we are concatenating / piping the string into output stream
    // And it would be nice,if it's done in object oriented way.

    return 0;
}
