// C++ Demonstrate Read File
#include<iostream>
#include<fstream> // Header File of File Handling
using namespace std;

// Main function
int main(){
    try{
        // ifstream use for read the file and open the file
        ifstream fileobj("pokemon.txt");
        string line;
        if(fileobj.is_open()){
            cout<<"Read the your txt file: "<<endl;
            while(getline(fileobj,line)){
                cout<<line<<endl;
            }
    }else{
        cout<<"File cann't exist!!!!"<<endl;
    }
        // close the open file
        fileobj.close();
    }catch(const exception& e){
        cout<<"Error: "<<e.what()<<endl;
    }
    return 0;
}
