#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    int n[3];
    memset(n, 0x3f, sizeof(n));
    cout << n[2];

    return 0;
}