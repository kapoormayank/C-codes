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

//Single Inheritance
class Dog : public Animal{
    public:
    void bark(){
        cout<<"The dog are bark."<<endl;
    }
};

//Multilevel Inheritance
class Puppy : public Dog{
    public:
    void flexibity(){
        cout<<"Puppy is very flexible!"<<endl;
    }
};

// Main function
int main(){
    //Mutilevel Inheritance
    cout<<"\n-- Multilevel Inheritance --"<<endl;
    Puppy p1; //Static Memory Allocation
    p1.eat();
    p1.bark();
    p1.flexibity();
    return 0;
}
