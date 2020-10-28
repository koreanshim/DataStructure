#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class SlinkedStack {
public:
	Node* head;
	int size;
	SlinkedStack() {
		this->size = 0;
		this->head = NULL;
	}
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void Size() {
		cout << size << endl;
	}
	void top() {
		if (isEmpty()) {
			cout << -1 << endl;
		}
		else {
			cout << head->data << endl;
		}
	}
	void push(int data) {
		Node* node = new Node(data);
		if (isEmpty()) {
			head = node;
		}
		else {
			node->next = head;
			head = node;
		}
		size++;
	}
	void pop() {
		if (isEmpty()) {
			cout << -1 << endl;
		}
		else {
			Node* node = head;
			head = head->next;
			node->next = NULL;
			cout << node->data << endl;
			size--;
		}
	}
};

int main() {
	SlinkedStack S;
	int n;
	string order;
	int temp;

	cin >> n;
	while (n--) {
		cin >> order;

		if (order == "empty") {
			cout << S.isEmpty() << endl;
		}
		else if (order == "top") {
			S.top();
		}
		else if (order == "push") {
			cin >> temp;
			S.push(temp);
		}
		else if (order == "pop") {
			S.pop();
		}
		else if (order == "size") {
			S.Size();
		}
	}
}