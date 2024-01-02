#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cstring>

using namespace std;

int main()
{
    long long tmp[1000];
    memset(tmp, 0x3f, 4*1000);

    cout << tmp[0] << endl;

    int a = 0b00111111;
    int b = 0x3f;
    cout << a << endl;
    cout << b << endl;

    return 0;
}