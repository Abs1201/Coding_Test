#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factorior(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

int sigma(int n) {
	int result = 0;
	for (int i = 0; i <= n; i++) {
		result += i;
	}
	return result;
}

vector<int> check(5);
int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int level = 0;
	for (int i = level; i <= level+1; i++) {
		check.push_back(triangle[level][i]);
		solution(triangle);
	}



	return answer;
}

int main(void) {

	int a = 5;
	cout << factorior(5) << endl;

	return 0;
}