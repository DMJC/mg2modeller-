#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

fstream inputfile;

int ui_mode;

if(argc > 1){
    cout << "Loading Preferences" << endl;
    inputfile.open(argv[1], fstream::in);
    while ( !inputfile.eof() ){
//	getline (ui_mode);
    }
    cout << "UI Mode: " << ui_mode <<endl;
    cout << "Loaded Preferences" << endl;
    inputfile.close();
}else{
    cout << "No file specified, correct usage: ./preferences file.ini" << endl;
}
}
