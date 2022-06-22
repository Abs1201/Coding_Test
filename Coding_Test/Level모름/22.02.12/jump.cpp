#include <iostream>
using namespace std;

unsigned int solution(int fieldSize);
int factorior(int n);

int main(void){
	
	cout << solution(2000) << endl;
	
	
	return 0;
}

// int solution(int fieldSize){
// 	int a = fieldSize/2;
// 	int b = fieldSize%2;
// 	int sum = 0;
// 	int tmp = 0;
// 	for(; a >= 0; a--){
// 		tmp = factorior(a+b)/(factorior(a)*factorior(b));
// 		b += 2;
// 		sum += tmp;
// 	}
// 	return sum%1234567;
// }

unsigned int solution (int fieldSize){
	if(fieldSize == 1) return 1;
	if(fieldSize == 2) return 2;
	int prev1 = 1;
	int prev2 = 2;
	int sum = 0;
	for(int i = 3; i <= fieldSize; i++){
		sum = prev1 + prev2;
		prev1 = prev2;
		prev2 = sum;
	}
	return sum;
}



int factorior(int n){
	
	int result = 1;
	for(; n > 0; n--){
		result *= n;
	}
	return result;
}