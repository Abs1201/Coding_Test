#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    clock_t start = clock();
    for (int i = 0; i < 500; i++) {
        for (int k = 0; k < 50; k++);
    }
    clock_t end = clock();
    
    cout << "걸린 시간 : \n";
    cout << difftime(end, start) / 1000.0 << " 초\n";
    cout << (double)(end - start) / 1000.0 <<  " 초\n";
    cout << (int)(end - start) / CLOCKS_PER_SEC << " 초\n";
    
    cout << "============================================\n";


    time_t temp;
    struct tm* timeinfo;

    time(&temp);
    timeinfo = localtime(&temp);
    
    cout << "현재 시간 : " << asctime(timeinfo);
    cout << "현재 년도 : " << 1900 + timeinfo->tm_year << "\n";
    cout << "현재 월 : " << 1 + timeinfo->tm_mon  << "\n";
    cout << "현재 일 : " << timeinfo->tm_mday << "\n";

    return 0;
}