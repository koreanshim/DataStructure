#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
	Node() {
		this->data = 0;
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->parent = NULL;
	}
	Node(int data) {
		this->data = data;
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->rightChild = NULL;
		this->parent = NULL;
	}
};

class binarySearchTree {
private:
public:
	Node* root;
	binarySearchTree() {
		this->root = NULL;
	}

	void insert(int inputData) {
		Node* newNode = new Node(inputData);
		Node* saveNode = NULL;
		if (root == NULL) {
			root = newNode;
		}
		else {
			Node* curNode = root;
			while (curNode != NULL) {
				saveNode = curNode;
				if (curNode->data == inputData) {
					cout << "Duplication" << endl;
				}
				else if (curNode->data > inputData) {
					curNode = curNode->leftChild;
				}
				else {
					curNode = curNode->rightChild;
				}
			}
			if (saveNode->data > inputData) {
				newNode->parent = saveNode;
				saveNode->leftChild = newNode;
			}
			else {
				newNode->parent = saveNode;
				saveNode->rightChild = newNode;
			}
		}
	}

	Node* find(int inputData) {
		Node* curNode = root;
		while (curNode != NULL) {
			if (curNode->data == inputData) {
				return curNode;
			}
			else if (curNode->data > inputData) {
				curNode = curNode->leftChild;
			}
			else {
				curNode = curNode->rightChild;
			}
		}
		return NULL;
	}

	Node* minFindNode(Node* node) {
		Node* curNode = node;
		Node* saveNode = NULL;
		while (curNode != NULL) {
			saveNode = curNode;
			curNode = curNode->leftChild;
		}
		return saveNode;
	}

	Node* maxFindNode(Node* node) {
		Node* curNode = node;
		Node* saveNode = NULL;
		while (curNode != NULL) {
			saveNode = curNode;
			curNode = curNode->rightChild;
		}
		return saveNode;
	}

	void erase(int data) {
		Node* curNode = find(data);
		int numOfChild = bool(curNode->leftChild) + bool(curNode->rightChild);

		if (numOfChild == 0) {
			if (curNode == root) {
				root = NULL;
			}
			else {
				if (curNode->parent->data > curNode->data) {
					curNode->parent->leftChild = NULL;
				}
				else {
					curNode->parent->rightChild = NULL;
				}
			}
			delete curNode;
		}
		else if (numOfChild == 2) {
			Node* minNode = minFindNode(curNode->rightChild);
			int data = minNode->data;
			erase(minNode->data);
			curNode->data = data;
		}
		else if (numOfChild == 1) {
			if (curNode == root) {
				if (curNode->leftChild != NULL) {
					root = curNode->leftChild;
				}
				else {
					root = curNode->rightChild;
				}
			}
			else {
				Node* curParent = curNode->parent;
				Node* child = (curNode->leftChild) ? curNode->leftChild : curNode->rightChild;
				if (curParent->data > child->data) {
					curParent->leftChild = child;
					child->parent = curParent;
				}
				else {
					curParent->rightChild = child;
					child->parent = curParent;
				}
			}
			delete curNode;
		}
	}

	void preorderPrint(Node* curNode) {
		if (curNode != NULL) {
			cout << curNode->data << " ";
			preorderPrint(curNode->leftChild);
			preorderPrint(curNode->rightChild);
		}
	}
	
	void preorder() {
		preorderPrint(root);
		cout << endl;
	}
};

int main() {
	int t = 0;
	
	cin >> t;
	for(int i = 0 ; i < t; i++) {
		binarySearchTree T;
		int n = 0;
		cin >> n;
		
		for (int j = 0; j < n; j++) {
			int e = 0;
			cin >> e;
			T.insert(e);
		}

		int f = 0;
		cin >> f;

		cout << T.minFindNode(T.find(f))->data << " ";
		cout << T.maxFindNode(T.find(f))->data << endl;
	}
}