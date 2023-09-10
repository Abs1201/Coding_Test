#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    ofstream of("d");
    // of.open("of.txt");
    if(of.is_open()){
        cout << "ok" << endl;
        of << "this is test filett.\n";
        of.close();
    }
    else{
        cout << "wrong access" << endl;
    }
    

    return 0;
}