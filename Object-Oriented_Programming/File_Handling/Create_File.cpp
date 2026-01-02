// C++ Demonstrate Create File
#include<iostream>
#include<fstream> // Header File of File Handling
using namespace std;

// Main function
int main(){
    try{
        // ofstream use for create the file
        ofstream fileobj("pokemon.txt");
        cout<<"Successfully your txt file are create..."<<endl;
        // close the open file
        fileobj.close();
    }catch(const exception& e){
        cout<<"Error: "<<e.what()<<endl;
    }
    return 0;
}
