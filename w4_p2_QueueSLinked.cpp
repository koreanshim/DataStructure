#include <iostream>
using namespace std;

class Node {
public:
	Node(int data);
	int data;
	Node* next;
};
Node::Node(int data) {
	this->data = data;
	this->next = NULL;
}

class LinkedList {
public:
	Node* f;
	Node* r;
	
	LinkedList();

	int front();
	int end();
	void addEnd(int data);
	int removeFront();
};
LinkedList::LinkedList() {
	this->f = NULL;
	this->r = NULL;
}
int LinkedList::front() {
	return f->data;
}
int LinkedList::end() {
	return r->data;
}
void LinkedList::addEnd(int data) {
	Node* newNode = new Node(data);

	if (f == NULL) {
		f = newNode;
		r = newNode;
	}
	else {
		r->next = newNode;
		r = newNode;
	}
}
int LinkedList::removeFront() {
	if (f != NULL) {
		Node* tmp = f;

		cout << f->data << endl;

		int tmp_int = f->data;

		f = f->next;
		delete tmp;

		return tmp_int;
	}
	
	return -1;
}

class LinkedQueue {
public:
	LinkedList* L;
	int f;
	int r;
	int cap;
	LinkedQueue() {}
	LinkedQueue(int size);
	int size();
	int isEmpty();
	void front();
	void rear();
	void enqueue(int e);
	void dequeue();
};
LinkedQueue::LinkedQueue(int size) {
	this->L = new LinkedList();
	this->cap = size;
	this->f = 0;
	this->r = -1;
}
int LinkedQueue::size() {
	return (r - f + 1 +cap) % cap;
}
int LinkedQueue::isEmpty() {
	if ((r + 1) % cap == f) { return 1; }
	else { return 0; }
}
void LinkedQueue::front() {
	if (isEmpty() == 1) { cout << "Empty" << endl; }
	else { cout << L->front() << endl; }
}
void LinkedQueue::rear() {
	if (isEmpty() == 1) { cout << "Empty" << endl; }
	else { cout << L->end() << endl; }
}
void LinkedQueue::enqueue(int e) {
	if (size() == cap - 1) { cout << "Full" << endl; }
	else {
		r = (r + 1) % cap;

		L->addEnd(e);
	}
}
void LinkedQueue::dequeue() {
	if (isEmpty() == 1) { cout << "Empty" << endl; }
	else {
		L->removeFront();
		
		f = (f + 1) % cap;
	}
}

int main() {
	int n;
	int qSize;

	cin >> qSize;

	LinkedQueue Q(qSize + 1);

	cin >> n;

	while (n--) {
		string cmd;
		int input;

		cin >> cmd;

		if (cmd == "enqueue") {
			cin >> input;

			Q.enqueue(input);
		}
		else if (cmd == "dequeue") {
			Q.dequeue();
		}
		else if (cmd == "size") {
			cout << Q.size() << endl;
		}
		else if (cmd == "isEmpty") {
			cout << Q.isEmpty() << endl;
		}
		else if (cmd == "front") {
			Q.front();
		}
		else if (cmd == "rear") {
			Q.rear();
		}
	}

	return 0;
}