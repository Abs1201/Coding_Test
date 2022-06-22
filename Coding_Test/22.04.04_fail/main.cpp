#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Vertex{
private:
	int data;
	bool visited;
	Edge* AdjacencyList;
	
public:
	int getData(){
		return data;
	}
	bool visited(){
		return visited;
	}
	Edge* getAdjacencyList(){
		return AdjacencyList;
	}
	
	void setData(int newData){
		data = newData;
	}
	void setVisited(bool visited){
		visited = visited;
	}
	void setAdjacencyList(Edge* newAdjacencyList){
		AdjacencyList = newAdjacencyList;
	}
	
};












int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    return answer;
}

int main(void){
	
	vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
	
	cout << solution(6, edge);
	
	return 0;
}