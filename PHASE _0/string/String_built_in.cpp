#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    cout<<str;
}

int main() {
    std::string s;

    // Constructors
    std::string s1;
    std::string s2("Hello");
    std::string s3(s2);
    std::string s4("Hello", 3);
    std::string s5(5, 'a');

    // Assignment
    s = "Hello";
    s = 'a';
    s = s2;

    // Capacity
    s.size();
    s.length();
    s.max_size();
    s.resize(10);
    s.resize(10, 'x');
    s.capacity();
    s.reserve(50);
    s.clear();
    s.empty();

    // Element Access
    s[1];
    s.at(1);
    s.front();
    s.back();

    // Modifiers
    s += '!';
    s += " World";
    s.append(" World");
    s.append("Hello", 3);
    s.push_back('!');
    s.insert(5, " Beautiful");
    s.erase(5, 10);
    s.erase(s.begin() + 5, s.end() - 1);
    s.pop_back();
    s.replace(7, 5, "Universe");

    // String Operations
    s.substr(0, 5);
    char buffer[20];
    s.copy(buffer, 5);
    s.find("World");
    s.rfind("World");
    s.find_first_of("aeiou");
    s.find_last_of("aeiou");
    s.find_first_not_of("aeiou");
    s.find_last_not_of("aeiou");
    s.compare("Hello");

    // Conversion Functions
    s.c_str();
    s.data();

    // String Input and Output
    std::getline(std::cin, s);

    return 0;
}
