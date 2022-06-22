#include <iostream>
using namespace std;

int solution(int queenNum);
bool isAnswer(bool* field, int queenNum);
void fullfillField(bool* field, int queenNum);
bool isAnswer(bool* field, int queenNum);
void initArr(int* arr, int size);
void initArrFrom(int* arr, int size, int index);

int main(void) {

	int queenNum = 5;
	cout << solution(queenNum) << endl;
	//int a = solution(queenNum);

	return 0;
}

int solution(int queenNum) {
	if (queenNum > 12 || queenNum < 0) {
		cout << "ERROR" << endl;
		exit(1);
	}
	if (queenNum == 1) return 1;
	bool* field = new bool[queenNum * queenNum];
	fullfillField(field, queenNum);

	int order = 0;
	int lastIndex = -1;
	int lastedIndex[100];
	initArr(lastedIndex, 100);
	//int lastedIndexIndex = 0;
	bool tf = 1;
	int count = 0;
	int z = 0;
	int tmp = -1;

	while (tf) {

		tf = 0;
		for (int i = 0; i < queenNum * queenNum; i++) { //i = 0~15
			if (*(field + i) == 1) {
				for (int j = i + 1; j < queenNum * queenNum; j++) {											//오른쪽 0  
					if (j / queenNum - i / queenNum > 0) break;
					if (*(field + j) == 1) {
						lastIndex = i;
						tf = 1;
					}
					*(field + j) = 0;
				}
				for (int j = i + queenNum; j < queenNum * queenNum; j += queenNum) {							//밑 세로 0
					*(field + j) = 0;
				}
				int prev = i;
				for (int j = i + queenNum + 1; j < queenNum * queenNum; j += queenNum + 1) {				//밑 대각선 오른쪽 0
					if (j / queenNum - prev / queenNum > 1) {
						break;
					}
					*(field + j) = 0;
					prev = j;
				}
				prev = i;
				for (int j = i + queenNum - 1; j < queenNum * queenNum; j += (queenNum - 1)) {				//밑 대각선 왼쪽 0
					if (j / queenNum - prev / queenNum < 1) {
						break;
					}
					*(field + j) = 0;
					prev = j;
				}
			}
		}



		bool check = isAnswer(field, queenNum);										//정답확인
		if (check) {
			
			cout << *(field + 0) << " ";
			for (int m = 1; m < queenNum * queenNum; m++) {
				if (m / queenNum - (m - 1) / queenNum > 0) cout << endl;
				cout << *(field + m) << " ";
			}
			cout << "\n\n\n";
			count++;
		}


		//cout << "\ntmp: " << tmp << "\nlastIndex: " << lastIndex << endl;
		
		if ((tmp / queenNum - lastIndex / queenNum) > 0) {
			int tmpIndex = 0;
			for (int b = 0; *(lastedIndex + b) < lastIndex; b++) {
				tmpIndex++;
			}
			initArrFrom(lastedIndex, 100, tmpIndex);
		}




		/*
		if ((tmp / queenNum - lastIndex / queenNum) >= 0) {
			int in = 0;
			for (int t = 0; lastedIndex[t] != -1; t++) {
				in++;
			}
			*(lastedIndex + in) = lastIndex;
			cout << "in: " << in << "\t arr: " << *(lastedIndex + in) << endl;
		}
		*/

		int in = 0;
		for (int t = 0; lastedIndex[t] != -1; t++) {
			in++;
		}
		*(lastedIndex + in) = lastIndex;



		fullfillField(field, queenNum);							// field 1로 채우기
		/*
		*(field + lastIndex) = 0;
		for (int j = lastIndex - 1; j >= 0; j--) {															//왼쪽 0  
			if (lastIndex / queenNum - j / queenNum > 0) break;
			*(field + j) = 0;
		}
		*/
		for (int t = 0; lastedIndex[t] != -1; t++) {			//배열것들도 0으로
			*(field + lastedIndex[t]) = 0;
		}

		
		for (int t = 0; lastedIndex[t] != -1; t++) {														//배열들 왼쪽 0
			for (int j = lastedIndex[t] - 1; j >= 0; j--) {
				if (lastedIndex[t] / queenNum - j / queenNum > 0) break;
				*(field + j) = 0;
			}
		}

		tmp = lastIndex;
	}
	return count;
}

void initArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		*(arr + i) = -1;
	}
}
void initArrFrom(int* arr, int size, int index) {
	for (int i = index; i < size; i++) {
		*(arr + i) = -1;
	}
}


bool isAnswer(bool* field, int queenNum) {
	
	bool* check = new bool[queenNum];
	for(int i = 0; i < queenNum; i++){
		*(check + i) = 0;
	}
	for (int i = 0; i < queenNum * queenNum; i++) {
		*(check + i / queenNum) |=  *(field + i);
	}
	bool key = 1;
	for (int i = 0; i < queenNum; i++) {
		key &= *(check + i);
	}
	return key;
	/*
	int count = 0;
	for (int i = 0; i < queenNum * queenNum; i++) {
		if (*(field + i)) { count++; }
	}
	return count == queenNum;
	*/
}


void fullfillField(bool* field, int queenNum) {
	for (int j = 0; j < queenNum * queenNum; j++) {
		*(field + j) = 1;
	}
}


// cout << *(field + 0) << " ";
// for (int m = 1; m < queenNum * queenNum; m++) {
// 	if (m / queenNum - (m - 1) / queenNum > 0) cout << endl;
// 	cout << *(field + m) << " ";
// }
