// https://programmers.co.kr/learn/courses/30/lessons/42576
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {

	std::sort(begin(participant), end(participant));
	std::sort(begin(completion), end(completion));

	string answer = "";

	cout << "p_size: " << size(participant) << endl;
	cout << "c_size: " << size(completion) << endl;

	for (int i = 0; i < size(participant); i++) {
		if (participant[i] != completion[i]) {
			answer = participant[i];
			break;
		}
	}
	return answer;
}

int main(void) {

	vector<string> participant{ "jack", "tom", "jake", "tina" };
	vector<string> completion{ "tom", "jake", "tina" };

	string answer = solution(participant, completion);

	cout << answer << endl;







	return 0;
}
