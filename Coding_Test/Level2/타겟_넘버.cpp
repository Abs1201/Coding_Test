// https://programmers.co.kr/learn/courses/30/lessons/43165
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cal(vector<int> numbers, int target) {
	if (target == 0) return 1;
	else if (numbers.empty()) return 0;

	int tmp;
	tmp = numbers.back();
	numbers.pop_back();

	if (tmp > target) {
		return cal(numbers, target);
	}
	else {
		return cal(numbers, target) + cal(numbers, target - tmp);
	}
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	int sum = 0;
	for (int i = 0; i < numbers.size(); i++) {
		sum += numbers[i];
	}
	int real = sum - target; // real/2가 
	if (real < 1 || real%2 != 0) return 0;
	real /= 2;

	int count = 0;

	answer = cal(numbers, real);

	return answer;
}


int main(void) {

	vector<int> numbers = { 4,1,2,1 };
	int target = 4;

	cout << solution(numbers, target) << endl;


	return 0;
}