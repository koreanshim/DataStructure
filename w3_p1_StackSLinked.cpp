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

class S_LinkedList {
public:
	Node* head;
	Node* tail;

	S_LinkedList() {
		head = NULL;
		tail = NULL;
	}

	int Empty() {
		if (head == NULL && tail == NULL) {
			return 1;
		}
		else { return 0; }
	}
	int Peek() {
		return tail->data;
	}
	void Append(int data) {
		Node* new_node = new Node(data);

		if (Empty()) {
			head = new_node;
			tail = new_node;
		}
		else {
			tail->next = new_node;
			tail = tail->next;
		}
	}
	int Delete() {
		int removeNum = 0;
		int cnt = 0;
		Node* cur_node;
		Node* pre_node;

		pre_node = cur_node = head;

		while (cur_node->next != NULL) {
			pre_node = cur_node;
			cur_node = cur_node->next;
		}
		removeNum = cur_node->data;
		pre_node->next = cur_node->next;
		tail = pre_node;

		return removeNum;
	}

};

class Linked_Stack {
public:
	int n;
	S_LinkedList* Stack;

	Linked_Stack() {
		this->Stack = new S_LinkedList();
		this->n = 0;
	}
	int size() {
		return n;
	}
	bool empty() {
		return n == 0;
	}
	int top() {
		if (empty()) { return -1; }
		else { return Stack->Peek(); }
	}
	void push(int e) {
		n++;
		Stack->Append(e);
	}
	int pop() {
		if (empty()) { return -1; }
		else {
			n--;
			return Stack->Delete();
		}
	}
};

int main() {
	Linked_Stack S;
	int iter = 0;
	string order;
	int temp = 0;

	cin >> iter;
	for (int i = 0; i < iter; i++) {
		cin >> order;
		
		if (order == "empty") {
			cout << S.empty() << endl;
		}
		else if (order == "top") {
			cout << S.top() << endl;
		}
		else if (order == "pop") {
			cout << S.pop() << endl;
		}
		else if (order == "push") {
			cin >> temp;
			S.push(temp);
		}
		else if (order == "size") {
			cout << S.size() << endl;
		}
	}
	return 0;
}