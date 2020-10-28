#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* parent;
	vector<Node*> child;

	Node(int data) {
		this->data = data;
		this->parent = NULL;	
	}
	~Node(){}
	void setParent(Node* parent) {
		this->parent = parent;
	}
	void insertChild(Node* child) {
		this->child.push_back(child);
	}
	void deleteChild(Node* child) {
		for (int i = 0; i < this->child.size(); i++) {
			if (this->child[i] == child) {
				this->child.erase(this->child.begin() + i);
			}
		}
	}
};

class Tree {
public:
	int count = 0;
	Node* root;
	vector<Node*> node_list;

	Tree(int data) {
		this->root = NULL;
		this->root = new Node(data);
		node_list.push_back(root);
	}
	~Tree(){}
	int Size() {
		return node_list.size();
	}
	void insertNode(int parData, int data) {
		for (int i = 0; i < Size(); i++) {
			if (node_list[i]->data == parData) {
				Node* node = new Node(data);
				node->setParent(node_list[i]);
				node_list[i]->insertChild(node);
				node_list.push_back(node);
				return;
			}
		}
	}
	void deleteNode(int data) {
		Node* nowNode;
		Node* par;
		
		for (int i = 0; i < Size(); i++) {
			if (this->node_list[i]->data == data) {
				nowNode = node_list[i];
				if (nowNode == root) { return; }
				par = nowNode->parent;
				for (Node*& child : nowNode->child) {
					par->insertChild(child);
					child->parent = par;
				}
				par->deleteChild(nowNode);
				this->node_list.erase(this->node_list.begin() + i);
				delete nowNode;
			}
		}
		return;
	}
	void preOrder(Node* node) {
		if (!node) { return; }
		cout << node->data << " ";
		for (int i = 0; i < node->child.size(); i++) {
			preOrder(node->child[i]);
		}
	}
	void postOrder(Node* node) {
		if (!node) { return; }
		for (int i = 0; i < node->child.size(); i++) {
			postOrder(node->child[i]);
		}
		cout << node->data << " ";
	}
	void preOrderCount(Node* node) {
		if (!node) { return; }

		count++;
		
		if (node->child.size() == 0) {
			cout << count << " ";
			count = 0;
		}

		for (int i = 0; i < node->child.size(); i++) {
			preOrderCount(node->child[i]);
		}
	}
	void preOrderCnt(Node* node) { //ÇõÀÌ´ä
		if (!node) { return; }
	
		count++;
		if (node->child.size() == 0) {
			cout << count << " ";
			count = 0;
		}
		for (int i = 0; i < node->child.size(); i++) {
			preOrderCnt(node->child[i]);
		}
	
	}
};

int main() {
	int n, m = 0;
	int par, data = 0;

	cin >> n;
	while (n--) {
		Tree T = Tree(1);
		cin >> m;
		while (m--) {
			cin >> par >> data;
			T.insertNode(par, data);
		}
		T.preOrderCount(T.root);
		cout << " ";
	}
}