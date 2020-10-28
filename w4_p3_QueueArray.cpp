#include <iostream>
using namespace std;

class arrQueue {
public:
	int* Q;
	int f;
	int r;
	arrQueue(int size) {
		this->Q = new int[size];
		this->f = 0;
		this->r = -1;
		for (int i = 0; i < size; i++) {
			Q[i] = 0;
		}
	}
	int front() {
		return Q[f];
	}
	void enqueue(int data) {
		r += 1;
		Q[r] = data;
	}
	void dequeue() {
		Q[f] = 0;
		f = f + 1;
	}
	void addDiffer(int e) {
		Q[f] += (e - 1);
	}
};

int main() {
	int game = 0;
	int round = 0;

	cin >> game;

	while (game--) {
		cin >> round;

		arrQueue P1(round+1);
		arrQueue P2(round+1);
		int score1 = 0;
		int score2 = 0;

		for (int i = 0; i < round; i++) {
			int deck = 0;
			cin >> deck;
			P1.enqueue(deck);
		} //Player1 Enqueue
		for (int i = 0; i < round; i++) {
			int deck = 0;
			cin >> deck;
			P2.enqueue(deck);
		} //Player2 Enqueue

		for (int i = 0; i < round; i++) {
			int differ = P1.front() - P2.front();

			if (differ > 0) {
				P1.dequeue();
				P2.dequeue();
				P1.addDiffer(differ);

				score1++;
			}
			else if (differ < 0) {
				P1.dequeue();
				P2.dequeue();
				P2.addDiffer(-differ);

				score2++;
			}
			else {
				P1.dequeue();
				P2.dequeue();
			}
		} //for¹®
		//result Ãâ·Â
		if (score1 > score2) {
			cout << 1 << endl;
		}
		else if (score1 < score2) {
			cout << 2 << endl;
		}
		else {
			cout << 0 << endl;
		}

	} //while

	return 0;
}