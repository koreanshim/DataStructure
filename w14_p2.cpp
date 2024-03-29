#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define NOT_EXPLORED 0
#define DISCOVERY 1
#define BACK 2

class vertex {
public:
	int data;
	int degree;
	bool visited;
	vector<vertex*> adj_list;
	vertex(int data) {
		this->data = data;
		this->degree = 0;
		this->visited = false;
	}
};

class edge {
public:
	vertex* src;
	vertex* dst;
	int data;
	bool edge_stat;
	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
		this->data = 0;
		this->edge_stat = NOT_EXPLORED;
	}
};

#define vertexRange 1000

class graph {
public:
	edge*** edgeMatrix;
	vector<vertex*> vertex_list;
	vector<edge*> edge_list;
	graph() {
		edgeMatrix = new edge **[vertexRange];
		for (int i = 0; i < vertexRange; i++) {
			edgeMatrix[i] = new edge * [vertexRange];
			for (int j = 0; j < vertexRange; j++) {
				edgeMatrix[i][j] = NULL;
			}
		}
	}

	vertex* findvertex(int data) {
		vertex* v = NULL;
		for (int i = 0; i < vertex_list.size(); i++) {
			if (vertex_list[i]->data == data) {
				v = vertex_list[i];
				break;
			}
		}
		return v;
	}
	edge* findedge(int src, int dst) {
		int _src = NULL, _dst = NULL;
		for (int i = 0; i < vertex_list.size(); i++) {
			if (vertex_list[i]->data == src) {
				_src = i;
			}
			if (vertex_list[i]->data == dst) {
				_dst = i;
			}
		}
		if (edgeMatrix[_src][_dst] == NULL) {
			return NULL;
		}
		else {
			return edgeMatrix[_src][_dst];
		}
	}

	void insert_vertex(int n) {
		if (findvertex(n) != NULL) {
			return;
		}

		else {
			int size = vertex_list.size();

			vertex* newVertex = new vertex(n);
			vertex_list.push_back(newVertex);
		}
	}

	void insert_edge(int source, int destination) {
		vertex* src = findvertex(source);
		vertex* dst = findvertex(destination);
		int _src = NULL, _dst = NULL;
		for (int i = 0; i < vertex_list.size(); i++) {
			if (vertex_list[i]->data == source) {
				_src = i;
			}
			if (vertex_list[i]->data == destination) {
				_dst = i;
			}
		}
		if (findedge(source, destination) == NULL) {
			edge* new_e = new edge(src, dst);
			edge_list.push_back(new_e);
			edgeMatrix[_src][_dst] = new_e;
			edgeMatrix[_dst][_src] = new_e;
			src->adj_list.push_back(dst);
			dst->adj_list.push_back(src);
		}
		else {
			cout << -1 << endl;
			return;
		}
		src->degree++;
		dst->degree++;
	}

	void DFS(vertex* curV) {
		
	}
};

int main() {
	graph G;

	int N, M, A = 0;
	vertex* V;
	int I = 0;
	int S, D = 0;

	cin >> N >> M >> A;

	for (int i = 0; i < N; i++) {
		cin >> I;
		G.insert_vertex(I);
	}
	
	for (int i = 0; i < M; i++) {
		cin >> S >> D;
		G.insert_edge(S, D);
	}

	cin >> A;


	vertex* V = new vertex(A);
	G.DFS(V);


}