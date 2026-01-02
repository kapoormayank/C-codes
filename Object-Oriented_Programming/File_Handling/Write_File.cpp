// C++ Demonstrate Write File
#include<iostream>
#include<fstream> // Header File of File Handling
using namespace std;

// Main function
int main(){
    try{
        // ofstream use for write the file and open the file
        ofstream fileobj("pokemon.txt");
        fileobj<<"Pikachu"<<endl;
        fileobj<<"Charizard"<<endl;
        fileobj<<"Grey Ninja"<<endl;
        fileobj<<"Lucario"<<endl;
        fileobj<<"Screptile"<<endl;
        fileobj<<"Venusur"<<endl;
        fileobj<<"Garchomp"<<endl;
        fileobj<<"Metagross"<<endl;
        fileobj<<"Goodra"<<endl;
        fileobj<<"Talon Flame"<<endl;
        cout<<"Successfully data inserted in your txt file........"<<endl;
        // close the open file
        fileobj.close();
    }catch(const exception& e){
        cout<<"Error: "<<e.what()<<endl;
    }
    return 0;
}
