// C++ demonstration of Exception Handling
#include<iostream>
using namespace std;

// Main function
int main(){
    int dividend,divisor,quotient;
    cout<<"Enter Dividend: ";
    cin>>dividend;
    cout<<"Enter Divisor: ";
    cin>>divisor;
    try{
        if(divisor==0){
            throw "Error: Division by zero is not allowed."; //Throwing an exception
        }else{
            quotient=dividend/divisor;
            cout<<"Quotient: "<<quotient<<endl;
        }
    }catch(const char* msg){
        cerr<<msg<<endl; //Displaying the error message
    }
    return 0;
}
