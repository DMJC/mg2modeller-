#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[]){

fstream inputfile;

string buffer;

if(argc > 1){
    cout << "Loading Preferences" << endl;
    inputfile.open(argv[1], fstream::in);
	string token;
	string token2;

    while ( !inputfile.eof() || token != "END"){
	getline (inputfile, buffer);
	size_t pos = 0;
	string delimiter = " ";
	while ((pos = buffer.find(delimiter)) != string::npos) {
	    token = buffer.substr(0, pos);
	    token2 = buffer.substr(pos+1, string::npos);
//	    token2 = token2.erase(token2.length()-1);
	    cout << token << " " << token2 << endl;
	    buffer.erase(0, pos + delimiter.length());
	}
/*
	map<string,int>m1;
	m1[0] = "test"
	m1[1] = "interface_type"
	m1[2] = "unknown"

	switch (){
	case '1' :
		cout << "Setting Interface Type to: " << token2 << endl;
	break;
	default:
		cout << "nothing to see here" << endl;
	break;
	}*/
    }
//    cout << "UI Mode: " << ui_mode <<endl;
    cout << "Loaded Preferences" << endl;
    inputfile.close();
	}else{
	    cout << "No file specified, correct usage: ./preferences file.ini" << endl;
	}
}
