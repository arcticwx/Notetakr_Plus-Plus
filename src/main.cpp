#include <iostream>
#include <fstream>

void write(std::string filename, std::string towrite){    
    std::ofstream file{filename};
    
    if(!file){
        std::cerr << "ERROR: file unable to be opened";
        getchar();
    }

    file << towrite << "\n";
    file.close();
    return;
}

void read(std::string filename){
    std::string context;
    
    std::ifstream file{filename};
    while(getline(file, context)){
        std::cout << context << "\n";
    }

    file.close();
    system("pause");
    return;
}

int main(void){
    using namespace std;
    cout << "Welcome to Notetakr++, What option?  ";
    
    string opt;
    cin >> opt;
    cout << "\n";

    if(opt == "write"){
        string name;
        string arg;
        
        cout << "Choose a filename:  ";
        // TODO: Allow multiple word names, using cin.ignore(), and getline() results in first letter of the note to be removed
        cin >> name; 

        cout << "\nWhat Note:  "; 
        cin.ignore(); getline(cin, arg);
        
        write(name, arg);
    } else if(opt == "read"){
        string name;

        cout << "What is the name of the file?  ";  cin >> name;
        
        read(name);
    } else {
        std::cerr << "ERROR: Invalid option";
        return 1;
    }
    
    return 0;
}