#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Box {
public:
    T content;

    void setContent(T newContent) {
        content = newContent;
    }

    T getContent() {
        return content;
    }
};

template <typename T>


        T maxx(T a, T b)
        {
            T x;
            x=(a>b)?a:b;
            return x;
        }


int main() {
    Box<int> intBox;
    intBox.setContent(123);
    std::cout << intBox.getContent() << std::endl;

    Box<std::string> stringBox;
    stringBox.setContent("Hello Templates");
    std::cout << stringBox.getContent() << std::endl;




        int a=4;
        int b=3;
        int c=maxx(a,b);
        cout<<c;


}



