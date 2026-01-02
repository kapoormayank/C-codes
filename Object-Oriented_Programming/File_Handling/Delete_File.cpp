// C++ Demonstrate Read File
#include<iostream>
#include<cstdio> // Header File of File Handling when Delete
using namespace std;

// Main function
int main(){
    try{
        // Delete the opening file
        const char* fileobj=("pokemon.txt");
        if(remove(fileobj)==0){
            cout<<"File Deleted Successfully..."<<endl;
        }else{
            cout<<"File cann't exist!!!"<<endl;
        }
    }catch(const exception& e){
        cout<<"Error: "<<e.what()<<endl;
    }
    return 0;
}
