// C++ program to demonstrate Template class
#include<iostream>
using namespace std;

// Syntax of Template
template<typename T>
// Template using in a class
class Demo{
    // Data member and private access(specifier|| modifier)
    T content;
    public:
    // Setter and Getter functions
    void setDemo(T c){
        content=c;
    }
    T getDemo(){
        return content;
    }
};

// Main function
int main(){
    Demo<int> d1;
    d1.setDemo(100);
    cout<<d1.getDemo()<<endl;
    Demo<string> d;
    d.setDemo("Hello Templates");
    cout<<d.getDemo()<<endl;
    return 0;
}
