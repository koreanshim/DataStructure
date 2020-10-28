#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	int depth;
	Node* parent;
	vector<Node*> child;

	Node(int data) {
		this->data = data;
		this->parent = NULL;
		this->depth = 0;
	}
	~Node() {}
	void setParent(Node* parent) {
		this->parent = parent;
	}
	void insertChild(Node* child) {
		this->child.push_back(child);
	}
	void setDepth(int depth) {
		this->depth = depth + 1;
	}
	int getDepth() {
		return depth;
	}
};

class Tree {
private:
	Node* root;
	vector<Node*> node_list;
public:
	Tree(int data) {
		root = NULL;
		root = new Node(data);
		node_list.push_back(root);
	}
	~Tree() {}
	int size() {
		return node_list.size();
	}
	void insertNode(int par_data, int data) {
		for (int i = 0; i < size(); i++) {
			if ((node_list[i]->data == par_data)) {
				Node* node = new Node(data);
				node->setDepth(node_list[i]->getDepth());
				node->setParent(node_list[i]);
				node_list[i]->insertChild(node);
				node_list.push_back(node);

				return;
			}
		}
	}
	void searchDepth(int d) {
		for (int i = 0; i < size(); i++) {
			if (node_list[i]->data == d) {
				cout << node_list[i]->getDepth() << endl;
				return;
			}
		}
	}
};

int main() {
	Tree t = Tree(1);
	int m = 0;
	int n = 0;

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		int par = 0;
		int data = 0;
		cin >> par >> data;

		t.insertNode(par, data);
	}
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		t.searchDepth(temp);
	}
}