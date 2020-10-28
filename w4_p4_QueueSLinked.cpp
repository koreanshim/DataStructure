#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};

class LinkedList {
public:
	Node* head;
	Node* tail;
	LinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}
	void addEnd(int e) {
		Node* newNode = new Node(e);
		
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	void removeFront() {
		if (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	void addGap(int e) {
		if (head != NULL) {
			head->data += e;
		}
	}
	int front() {
		return head->data;
	}
};

class Queue {
public:
	LinkedList* L;
	Queue() {
		this->L = new LinkedList();
	}
	void enqueue(int e) { L->addEnd(e); }
	void dequeue() { L->removeFront(); }
	void addDiffer(int e) { L->addGap(e - 1); }
	int Front() { return L->front(); }
};

int main() {
	Queue P1;
	Queue P2;

	int game = 0;
	
	cin >> game;

	for (int i = 0; i < game; i++) {
		int round = 0;
		int score1 = 0;
		int score2 = 0;

		cin >> round;

		for (int j = 0; j < round; j++) {
			int deck = 0;

			cin >> deck;
			P1.enqueue(deck);
		}
		for (int j = 0; j < round; j++) {
			int deck = 0;

			cin >> deck;
			P2.enqueue(deck);
		}

		for (int j = 0; j < round; j++) {
			int differ = P1.Front() - P2.Front();

			if (differ > 0) {
				P1.dequeue();
				P2.dequeue();
				P2.addDiffer(differ);

				score1++;
			}
			else if (differ < 0) {
				P1.dequeue();
				P2.dequeue();
				P1.addDiffer(-differ);

				score2++;
			}
			else {
				P1.dequeue();
				P2.dequeue();
			}
		} // rounds

		if (score1 > score2) {
			cout << 1 << endl;
		}
		else if (score1 < score2) {
			cout << 2 << endl;
		}
		else {
			cout << 0 << endl;
		} //result

	} //games

	return 0;
}