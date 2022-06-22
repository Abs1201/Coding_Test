//실패율 내림차순, 같으면 낮은 스테이지 먼저
#include <iostream>
using namespace std;

typedef struct tagIntDouble{
	int i;
	double d;
}IntDouble;


int* descendSort(int* arr, int arrLen){
	for(int i = 0; i < arrLen; i++){
		for(int j = i; j < arrLen; j++){
			if(*(arr+i) < *(arr+j)){
				int tmp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = tmp;
			}
		}
	}
	return arr;
}

IntDouble* descendSort_d(IntDouble* arr, int arrLen){
	for(int i = 0; i < arrLen; i++){
		for(int j = i; j < arrLen; j++){
			if(arr[i].d < arr[j].d){
				IntDouble tmp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = tmp;
			}
		}
	}
	return arr;
}

IntDouble* ascendSort_i(IntDouble* arr, int arrLen){
	for(int i = 0; i < arrLen; i++){
		for(int j = i; j < arrLen; j++){
			if(arr[i].i > arr[j].i){
				IntDouble tmp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = tmp;
			}
		}
	}
	return arr;
}



IntDouble* rule(IntDouble* arr, int arrLen){//실패율 같을때 낮은스테이지 먼저
	for(int i = 0; i < arrLen; i++){
		for(int j = i; j < arrLen; j++){
			if(arr[i].d == arr[j].d){
				if(arr[i].i > arr[j].i){
					IntDouble tmp = *(arr+i);
					*(arr+i) = *(arr+j);
					*(arr+j) = tmp;
				}
			}
		}
	}
	return arr;
}

// int* quickSort(int* arr, int arrLen){
// 	if(arrLen%2 == 1){
// 		int standard = *(arr+arrLen/2+1);
// 		for(int i = 0; i < arrLen/2+1; i++){
// 			if(*(arr+i) > *(arr+arrLen/2+1)){
				
// 			}
// 		}
// 		for(int i = arrLen/2+2; i < arrLen; i++){
// 			if(*(arr+i) < *(arr+arrLen/2+1)){
				
// 			}
// 		}
// 	}
// }

int* solution(int N, int* stages, int playerN) {	//N == 스테이지의 개수
	int playerNum = playerN;
	//for(int i = 0; );					//일단 변수로 잡고 품
	
	int remainNum = playerNum;
	double* failureRate = new double[N];
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < playerNum; j++) {
			if (*(stages + j) == i+1){ count++; }
			//cout << "i: " << i << " j: " << j << "    " << *(stages+j) << " " << i+1 << endl;
		}
		*(failureRate + i) = (double)count / (double)remainNum;
		
		//cout << i+1 << ' ' << *(failureRate+i) << ' ' << count << ' ' << remainNum << endl;
		
		remainNum -= count;
		count = 0;
	}
	
	IntDouble* failureRateWithIndex = new IntDouble[N];
	for(int i = 0; i < N; i++){
		failureRateWithIndex[i].d = *(failureRate+i);
		failureRateWithIndex[i].i = i+1;
	}
	
	
	
	for(int i = 0; i <N; i++){
		cout << failureRateWithIndex[i].d << ' ' << failureRateWithIndex[i].i << endl;
	}
	
	failureRateWithIndex = descendSort_d(failureRateWithIndex, N);
	failureRateWithIndex = rule(failureRateWithIndex, N);
	cout << endl;
	
	
	for(int i = 0; i <N; i++){
		cout << failureRateWithIndex[i].d << ' ' << failureRateWithIndex[i].i << endl;
	}
	cout << endl;
	
	int* answer = new int[N];
	for(int i = 0; i < N; i++){
		*(answer+i) = failureRateWithIndex[i].i;
	}

	return answer;
}

int main(void) {

	int arr[] = { 1,2,3,4,3,3,3 };
	
	int* answer = solution(5, arr, 7);
	
	for(int i = 0; i < 5; i++){
		cout << *(answer+i) << endl;
	}
	
	
	
	delete []answer;
	
	return 0;
}