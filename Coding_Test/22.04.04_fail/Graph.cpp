#include <iostream>
using namespace std;

class Edge;

class Vertex {
private:
	int data = 0;
	char data_c = '\0';
	bool visited = 0;
	Vertex* next;
	Edge* AdjacencyList;

public:
	Vertex(int data = 0) : data(data) { next = NULL, AdjacencyList = NULL; }
	Vertex(char data_c) : data_c(data_c) { next = NULL, AdjacencyList = NULL; }


	int getData() {
		return data;
	}
	void setData(int newData) {
		data = newData;
	}
	char getData_c() {
		return data_c;
	}
	void setData_c(char newData_c) {
		data_c = newData_c;
	}
	bool getVisited() {
		return visited;
	}
	void setVisited(bool v) {
		visited = v;
	}
	Vertex* getNext() {
		return next;
	}
	void setNext(Vertex* newNext) {
		next = newNext;
	}
	Edge* getAdjacencyList() {
		return AdjacencyList;
	}
	void setAdjacencyList(Edge* newAdjacencyList) {
		AdjacencyList = newAdjacencyList;
	}
	
	void addAdjacencyList(Edge* newEdge);



	~Vertex();

};

class Edge {
private:
	Vertex* from = NULL;
	Vertex* target = NULL;
	Edge* next = NULL;

public:
	Edge(Vertex* from = NULL, Vertex* target = NULL) : from(from), target(target) { next = NULL; }

	Edge* getNext() {
		return next;
	}
	void setNext(Edge* newEdge) {
		next = newEdge;
	}

	~Edge();
};

void Vertex::addAdjacencyList(Edge* newEdge) {
	Edge* AdjacencyListPtr = AdjacencyList;

	if (AdjacencyListPtr == NULL) {
		AdjacencyListPtr = newEdge;
	}
	else {
		while (AdjacencyListPtr != NULL) {
			AdjacencyListPtr = AdjacencyListPtr->getNext();
		}
		AdjacencyListPtr = newEdge;
	}
}

class Graph {
private:
	Vertex* vertexList;
	Edge* edgeList;

public:
	Graph(Vertex* vertexList = NULL, Edge* edgeList = NULL) : vertexList(vertexList), edgeList(edgeList) {}

	Vertex* getVertexList() {
		return vertexList;
	}
	void setVertexList(Vertex* newVertexList) {
		vertexList = newVertexList;
	}
	Edge* getEdgeList() {
		return edgeList;
	}
	void setEdgeList(Edge* newEdgeList) {
		edgeList = newEdgeList;
	}

	void addVertex(Vertex* v) {
		Vertex* vertexPtr = vertexList;

		if (vertexPtr == NULL) {
			vertexList = v;
		}
		else {
			while (vertexPtr != NULL) {
				vertexPtr = vertexPtr->getNext();
			}
			vertexPtr->setNext(v);
		}
	}
	void addEdge(Edge* e) {
		Edge* edgePtr = edgeList;

		if (edgePtr == NULL) {
			edgePtr = e;
		}
		else {
			while (edgePtr != NULL) {
				edgePtr = edgePtr->getNext();
			}
			edgePtr = e;
		}
	}

	void printGraph() {
		Vertex* vertexPtr = vertexList;
		int i = 0;
		while (vertexPtr != NULL) {
			cout << i << ": ";
			cout << vertexPtr->getData_c() << endl;

			vertexPtr = vertexPtr->getNext();

			i++;
		}

	}
};

int main(void) {

	Graph G;

	Vertex* v1 = new Vertex('1');
	Vertex* v2 = new Vertex('2');
	Vertex* v3 = new Vertex('3');
	Vertex* v4 = new Vertex('4');

	G.addVertex(v1);
	G.addVertex(v2);

	G.addVertex(v3);
	G.addVertex(v4);

	G.printGraph();

	return 0;
}