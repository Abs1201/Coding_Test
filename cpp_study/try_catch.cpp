#include <iostream>
using namespace std;

int main(void){
    try{
        int num1;
        cout << "Enter first number: " << endl;
        cin >> num1;

        int num2; 
        cout << "Enter second number: " << endl;
        cin >> num2;

        if(num2==0){
            throw 0;
        }
        cout << num1/num2 << endl;
        
    }catch(int x){
        cout << "you can't divide by " << x << endl;
    }

    // int n1, n2;
    // cout << "Enter first number: ";
    // cin >> n1;
    // cout << "Enter second number: ";
    // cin >> n2;
    // if(n2==0){
    //     cout << "you can't divide by " << n2 << endl;
    // }
    // else{
    //     cout << n1/n2 << endl;
    // }


    return 0;
}
