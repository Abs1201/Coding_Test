// https://programmers.co.kr/learn/courses/30/lessons/77485
#include <string>
#include <vector>
#include <iostream>

#define max_num 10001

using namespace std;

int getSmaller(int a, int b) {
	return (a < b) ? a : b;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;

	vector<vector<int>> matrix(rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i].push_back(i * columns + (j + 1));
		}
	}
	vector<vector<int>> matrix2(rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix2[i].push_back(i * columns + (j + 1));
		}
	}

	

	int tmp = max_num;
	for (int k = 0; k < queries.size(); k++) {
		
		for (int i = queries[k][0] - 1; i <= queries[k][2] - 1; i++) {
			
			for (int j = queries[k][1] - 1; j <= queries[k][3] - 1; j++) {
				if (j == queries[k][1] - 1 && i == queries[k][2] - 1) {
					tmp = getSmaller(matrix[i][j], tmp);
					matrix2[i][j] = matrix[i][j + 1]; // 좌하귀 우->좌
				}
				else if (j == queries[k][1] - 1 && i == queries[k][0] - 1) {
					tmp = getSmaller(matrix[i][j], tmp);										// 시작 // tmp == matrix[i][j]
					matrix2[i][j] = matrix[i + 1][j]; // 좌상귀 하->상
				}
				else if (i == queries[k][0] - 1) {
					tmp = getSmaller(matrix[i][j], tmp);
					matrix2[i][j] = matrix[i][j - 1]; // 상귀 좌->우
				}
				else if (j == queries[k][1] - 1) {
					tmp = getSmaller(matrix[i][j], tmp);
					matrix2[i][j] = matrix[i + 1][j]; // 좌귀 하->상
				}
				else if (j == queries[k][3] - 1) {
					tmp = getSmaller(matrix[i][j], tmp);
					matrix2[i][j] = matrix[i - 1][j]; // 우귀 상->하
				}
				else if (i == queries[k][2] - 1) {
					tmp = getSmaller(matrix[i][j], tmp);
					matrix2[i][j] = matrix[i][j + 1]; // 하귀 우->좌
				}
			}
		}
		answer.push_back(tmp);
		matrix.clear();
		matrix.resize(rows);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[i].push_back(matrix2[i][j]);
			}
		}
		tmp = max_num;
	}

	return answer;
}

int main(void) {
	vector<vector<int>> queries = { {2,2,5,4},{3,3,6,6},{5,1,6,3} };
	vector<int> result = solution(6, 6, queries);
	 
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}