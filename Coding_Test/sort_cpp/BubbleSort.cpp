#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

class Timer{
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
    void elapsed(){
        
    }
}

void bubbleSort(int* arr, int size){

}

int main(void){
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    int arr[5] = {3,2,1,5,6};

    bubbleSort(arr, 5);
    for(auto& e: arr){
        cout << e << " ";
    }

    std::chrono::duration<double>sec = std::chrono::system_clock::now() - start;


    return 0;
}