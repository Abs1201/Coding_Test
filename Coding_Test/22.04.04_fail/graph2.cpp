#include <string>
#include <vector>
#include <iostream>
using namespace std;

using namespace std;

int max(int a, int b){
	return (a > b) ? a : b;
}

bool checkVisited(int n, vector<int> visited){
	int size = visited.size();
	for(int i = 0; i < size; i++){
		if(n == visited[i]) return 1;
	}
	return 0;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
	
	vector<vector<int>> graph(n);
	
	for(int i = 0; i < n; i++){
		graph[edge[i][0]-1].push_back(edge[i][1]-1);
		graph[edge[i][1]-1].push_back(edge[i][0]-1);
	}
	//if(nextNode == NULL || nextNode->nextNode == visited) break;
	
	int start = 0;
	int tmp = 0;
	int lenght = 0;
	vector <int> visited(n);
	vector<vector<int>> graph_copied(n);
	bool isvisited = 0;
	while(1){
		graph_copied = graph;				//graph vector copied! (check necessary)
		visited.push_back(0);
		
		
		
		while(1){
			tmp = graph_copied[start].pop_front(); //pop from front!
			isvisited = checkVisited(tmp, visited);
			
			if(isvisited == 0) break;
		}
		
		length++;
		
		start = tmp;
		
		
		
	}
	
	
	
	
	
	
	
	
	
    return answer;
}





int main(void){
	
	
	
	
	vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
	int n = 6;
	
	cout << solution(n, edge);
	
	
	
	
	
	
	return 0;
}