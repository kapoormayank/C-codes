// C++ program to demonstrate all types of Inheritance
#include<iostream>
using namespace std;

// Base Class
class Animal{
    public:
    void eat(){
        cout<<"This animal eats food."<<endl;
    }
};

// Base class for Multiple Inheritance
class Speed{
    public:
    void speed(){
        cout<<"Speed of animal!"<<endl;
    }
};

//Multiple Inheritance
class fitness : public Animal,public Speed{
    public:
    void fast(){
        cout<<"Fast animal!"<<endl;
    }
};

// Main function
int main(){
    //Mutliple Inheritance
    cout<<"\n-- Multiple Inheritance --"<<endl;
    fitness f1; //Static Memory Allocation
    f1.eat();
    f1.speed();
    f1.fast();
    return 0;
}
