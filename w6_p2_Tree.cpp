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
	~Node() {}

	void setParent(Node* par) {
		this->parent = par;
	}
	void insertChild(Node* chi) {
		this->child.push_back(chi);
	}
	void delChild(Node* chi) {
		for (int i = 0; i < this->child.size(); i++) {
			if (this->child[i] == chi) {
				this->child.erase(this->child.begin() + i);
			}
		}
	}
};

class Tree {
private:
	Node* root;
	vector<Node*> node_list;

public:
	Tree(int e) {
		this->root = NULL;
		this->root = new Node(e);
		node_list.push_back(root);
	}
	~Tree() {}
	int size() {
		return node_list.size();
	}
	void insertNode(int par_data, int data) {
		for (int i = 0; i < size(); i++) {
			if (node_list[i]->data == par_data) {
				Node* node = new Node(data);

				node->setParent(node_list[i]);
				node_list[i]->insertChild(node);
				node_list.push_back(node);

				return;
			}
		}
	}
	void delNode(int e) {
		Node* nownode;
		Node* par;

		for (int i = 0; i < this->node_list.size(); i++) {
			if (this->node_list[i]->data == e) {
				nownode = node_list[i];
				if (nownode == root) { return; }
				par = nownode->parent;
				for (Node*& child : nownode->child) {
					par->insertChild(child);
					child->parent = par;
				}
				par->delChild(nownode);
				this->node_list.erase(this->node_list.begin() + i);
				delete nownode;
			}
		}
		return;
	}
	void printChild(int e) {
		for (int i = 0; i < size(); i++) {
			if (node_list[i]->data == e) {
				if (node_list[i]->child.size() == 0) {
					cout << "0" << endl;
					return;
				}
				for (int j = 0; j < node_list[i]->child.size(); j++) {
					cout << node_list[i]->child[j]->data << " ";
				}
				cout << endl;
				return;
			}
		}
	}
	void printSibling(int e) {
		for (int i = 0; i < size(); i++) {
			if (node_list[i]->data == e) {
				if (node_list[i]->parent == NULL) {
					cout << e << endl;
					return;
				}
				else {
					Node* par_node = node_list[i]->parent;
					for (int j = 0; j < par_node->child.size(); j++) {
						cout << par_node->child[j]->data << " ";
					}
					cout << endl;
					return;
				}
			}
		}
		cout << "0" << endl;
	}
};

int main() {
	Tree t = Tree(1);
	int n = 0;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str == "insert") {
			int par = 0;
			int data = 0;

			cin >> par >> data;
			t.insertNode(par, data);
		}
		else if (str == "delete") {
			int data = 0;
			cin >> data;
			t.delNode(data);
		}
		else if (str == "print") {
			int data = 0;
			cin >> data;
			t.printSibling(data);
		}
	}
}