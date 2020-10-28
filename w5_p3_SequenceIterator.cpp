#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class SequenceList {
private:
	struct Node {
		int elem;
		Node* prev;
		Node* next;
	};
public:
	class Iterator {
	private:
		Node* cur;
		Iterator(Node* u) {
			cur = u;
		}
	public:
		int& operator*() {
			return cur->elem;
		}
		bool operator==(const Iterator& p) const {
			return cur == p.cur;
		}
		bool operator!=(const Iterator& p) const {
			return cur != p.cur;
		}
		Iterator& operator++() {
			cur = cur->next;
			return *this;
		}
		Iterator& operator++(int) {
			cur = cur->next;
			return *this;
		}
		Iterator& operator--() {
			cur = cur->prev;
			return *this;
		}
		Iterator& operator--(int) {
			cur = cur->prev;
			return *this;
		}

		friend class SequenceList;
	};

private:
	int n;
	Node* header;
	Node* trailer;
public:
	SequenceList() {
		n = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	int size() const {
		return n;
	}
	bool isEmpty() const {
		return n == 0;
	}
	Iterator begin() const {
		return Iterator(header->next);
	}
	Iterator end() const {
		return Iterator(trailer);
	}
	void insert(const Iterator& p, const int& e) {
		Node* w = p.cur;
		Node* u = w->prev;
		Node* v = new Node;

		v->elem = e;
		v->next = w; w->prev = v;
		v->prev = u; u->next = v;

		this->n++;
	}
	void insertFront(const int& e) {
		insert(begin(), e);
	}
	void insertBack(const int& e) {
		insert(end(), e);
	}
	void erase(const Iterator& p) {
		Node* w = p.cur;
		Node* u = w->prev;
		Node* v = w->next;

		u->next = v; v->prev = u;
		delete w;
		this->n--;
	}
	Iterator atIndex(int i)const {
		Iterator p = begin();
		for (int j = 0; j < i; j++) {
			p++;
		}
		return p;
	}
	int indexOf(const Iterator& p) const {
		Iterator q = begin();
		int j = 0;
		while (q != p) {
			q++;
			j++;
		}
		return j;
	}
};

void printAverage(const SequenceList& T) {
	SequenceList::Iterator temp = T.begin();
	int sum = 0;
	int avg = 0;
	while (!T.isEmpty()) {
		if (temp == T.end()) { break; }
		else {
			sum += *temp;
			temp++;
		}
	}
	avg = sum / T.size();
	cout << floor(avg) << " ";
}

void printMax(const SequenceList& T) {
	SequenceList::Iterator temp = T.begin();
	int Max = *temp;
	while (!T.isEmpty()) {
		temp++;
		if (temp == T.end()) { break; }
		else {
			Max = max(Max, *temp);
		}
	}
	cout << Max << endl;
}

int main() {
	int T = 0;
	int N = 0;
	int p = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		SequenceList sl;
		SequenceList::Iterator iter(sl.begin()); 
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> p;
			sl.insertBack(p);
		}
		printAverage(sl);
		printMax(sl);
	}
}