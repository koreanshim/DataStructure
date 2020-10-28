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
private:
	vector<Node*> node_list;
public:
	Node* root;
	Tree(int data) {
		this->root = NULL;
		this->root = new Node(data);
		node_list.push_back(root);
	}
	~Tree() { }
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
	void deleteNode(int data) {
		Node* nowNode;
		Node* par;
		for (int i = 0; i < this->node_list.size(); i++) {
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
};

int main() {
	int n = 0;
	int m = 0;
	int par = 0;
	int data = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		Tree t = Tree(1);

		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> par >> data;
			t.insertNode(par, data);
		}

		t.postOrder(t.root);
		cout << endl;
	}

	return 0;
}