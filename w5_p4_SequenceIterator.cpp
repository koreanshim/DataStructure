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
		Node* cur; //반복자가 가리키는 Node 저장 포인터변수
		Iterator(Node* u) {
			cur = u;
		}
	public:
		int& operator*() { //Iterator가 현재 가리키고 있는 Node elem return
			return cur->elem;
		}
		bool operator==(const Iterator& p) const {
			return cur == p.cur;
		} //현재 Node와 iterator가 가리키고 있는 Node p와 일치하는지 확인
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
		}//다음 Node로 operator
		Iterator& operator--() {
			cur = cur->prev;
			return *this;
		}
		Iterator& operator--(int) {
			cur = cur->prev;
			return *this;
		}//이전 Node로 operator

		friend class SequenceList; //SequenceList Class가 iterator Class에 접근할 수 있도록 friend 선언
	};

private:
	int n; //list의 크기
	Node* header; //header 센티널 노드
	Node* trailer; //trailer 센티널 노드
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
	void insertFront(const int& e) {
		insert(begin(), e);
	}
	void insertBack(const int& e) {
		insert(end(), e);
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
	void erase(const Iterator& p) {
		Node* v = p.cur;
		Node* w = v->next;
		Node* u = v->prev;

		u->next = w; w->prev = u;

		delete v;
		this->n--;
	}
	Iterator atIndex(int i) const {
		Iterator p = begin(); //Iterator p->첫노드

		for (int j = 0; j < i; j++) {
			p++;
		}

		return p; //position p return
	}
	int indexOf(const Iterator& p) const {
		Iterator q = begin(); //Iterator q->첫노드
		int j = 0;

		while (q != p) {
			q++;
			j++;
		}

		return j; //index j return
	}

};

void printAvg(const SequenceList& T) {
	SequenceList::Iterator temp = T.begin();
	int sum = 0;
	int avg = 0;
	if (!T.isEmpty()) {
		while (true) {
			if (temp == T.end()) { break; }
			else {
				sum += *temp;

				temp++;
			}
		}
	}
	avg = sum / T.size();
	cout << floor(avg) << " ";
}

void printMin(const SequenceList& T) {
	SequenceList::Iterator temp = T.begin();
	int Min = *T.begin();
	if (!T.isEmpty()) {
		while (true) {
			temp++;
			if (temp == T.end()) { break; }
			else {
				Min = min(Min, *temp);
			}
		}
	}
	cout << Min << endl;
}

int main() {
	string cmd;
	int T = 0;
	int N = 0;
	int p = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		SequenceList S;
		SequenceList::Iterator iter(S.begin());
		
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> p;
			S.insertBack(p);
		}
		printAvg(S);
		printMin(S);
	}
}