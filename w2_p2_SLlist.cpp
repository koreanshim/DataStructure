#include<iostream>
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

class LinkedList {
public:
	Node* head;
	Node* tail;
	
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	int Empty() {
		if (head == NULL && tail == NULL) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int Print() {
		Node* cur_node = head;

		if (Empty()) {
			return -1;
		}
		else {
			return cur_node->data;
		}
	}
	void addFront(int data) {
		Node* new_node = new Node(data);
		
		new_node->data = data;
		new_node->next = head;

		head = new_node;

		Print();
	}
	int removeFront() {
		int num;

		if (Empty()) {
			return -1;
		}
		else {
			Node* temp = head;

			head = temp->next;
			num = temp->data;

			delete temp;
		}

		return num;
	}
	int front() {
		Node* cur_node = head;

		if (Empty()) {
			return -1;
		}
		else {
			return cur_node->data;
		}
	}
};

int main() {
	LinkedList list;

	int n = 0;
	int value = 0;
	string order;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> order;

		if (order == "addFront") {
			cin >> value;
			list.addFront(value);
		}
		else if (order == "removeFront") {
			cout << list.removeFront() << endl;
		}
		if (order == "front") {
			cout << list.front() << endl;
		}
		if (order == "empty") {
			cout << list.Empty() << endl;
		}
	}

	return 0;
}