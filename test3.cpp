#include <iostream>
using namespace std;

int N, M;
int arr[5];
int main()
{
    freopen("input2.txt", "r", stdin);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << '\n';
    }
}