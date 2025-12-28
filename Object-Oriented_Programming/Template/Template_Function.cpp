// C++ program to demonstrate Template function
#include<iostream>
using namespace std;

// Template Function
template<typename T>
// Function using by the Template
T add(T a,T b){
    return a+b;
}

// Main function
int main(){
    int a=6,b=7;
    int sum=add(a,b);
    cout<<"Sum of Integers: "<<sum<<endl;
    return 0;
}
