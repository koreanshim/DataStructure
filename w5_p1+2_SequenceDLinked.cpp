#include <iostream>
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
		Node* cur; //�ݺ��ڰ� ����Ű�� Node ���� �����ͺ���
		Iterator(Node* u) {
			cur = u;
		}
	public:
		int& operator*() { //Iterator�� ���� ����Ű�� �ִ� Node elem return
			return cur->elem;
		}
		bool operator==(const Iterator& p) const {
			return cur == p.cur;
		} //���� Node�� iterator�� ����Ű�� �ִ� Node p�� ��ġ�ϴ��� Ȯ��
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
		}//���� Node�� operator
		Iterator& operator--() {
			cur = cur->prev;
			return *this;
		}
		Iterator& operator--(int) {
			cur = cur->prev;
			return *this;
		}//���� Node�� operator

		friend class SequenceList; //SequenceList Class�� iterator Class�� ������ �� �ֵ��� friend ����
	};

private:
	int n; //list�� ũ��
	Node* header; //header ��Ƽ�� ���
	Node* trailer; //trailer ��Ƽ�� ���
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
		Iterator p = begin(); //Iterator p->ù���

		for (int j = 0; j < i; j++) {
			p++;
		}

		return p; //position p return
	}
	int indexOf(const Iterator& p) const {
		Iterator q = begin(); //Iterator q->ù���
		int j = 0;

		while (q != p) {
			q++;
			j++;
		}

		return j; //index j return
	}

};

void print(const SequenceList& T) {
	SequenceList::Iterator temp = T.begin();

	if (T.isEmpty()) { cout << "Empty"; }
	else {
		while (true) {
			if (temp == T.end()) { break; }
			else {
				cout << *temp << " ";

				temp++;
			}
		}
	}
	cout << endl;
}

void reversePrint(const SequenceList& T) {
	SequenceList::Iterator temp = T.end();

	if (T.isEmpty()) { cout << "Empty"; }
	else {
		while (true) {
			if (temp == T.begin()) {
				break;
			}
			else {
				temp--;

				cout << *temp << " ";
			}
		}
	}
	cout << endl;
}


int main() {
	SequenceList sl;
	SequenceList::Iterator iter(sl.begin());

	string cmd;
	int T = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> cmd;

		if (cmd == "insert") {
			int e = 0;
			cin >> e;

			if (sl.isEmpty()) {
				sl.insertFront(e);
			}
			else if (iter == sl.end()) {
				sl.insertBack(e);
			}
			else {
				sl.insert(iter, e);
			}
		}

		else if (cmd == "erase") {
			if (sl.isEmpty()) {
				cout << "Empty" << endl;
			}
			else {
				sl.erase(iter);
			}
		}

		else if (cmd == "begin") {
			iter = sl.begin();
		}

		else if (cmd == "end") {
			iter = sl.end();
		}

		else if (cmd == "++") {
			if (iter == sl.end() || sl.isEmpty()) {
				continue;
			}
			else { iter++; }
		}

		else if (cmd == "--") {
			if (iter == sl.begin() || sl.isEmpty()) {
				continue;
			}
			else { iter--; }
		}

		else if (cmd == "size") {
			cout << sl.size() << endl;
		}

		else if (cmd == "print") {
			print(sl);
		}

		else if (cmd == "reversePrint") {
			reversePrint(sl);
		}

	}

	return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;

class ArrVector {
private:
	int cap; //���� vector�� ���� ������ ���� ����
	int n; //���� vector�� �����ϰ� �ִ� ���� ����
	int* A; //vector ������ ���� ���� ����

public:
	ArrVector(int size) { //������
		this->cap = size;
		this->n = 0;
		this->A = new int[size];
	}
	int size() { //vector�� �����ϰ� �ִ� ���� ���� return
		return n;
	}
	bool isEmpty() {
		if (size() == 0) { return true; }
		else { return false; }
	}
	int& operator[](int i) { //operator overloading
		return A[i];
	}
	int at(int i) { //index i�� ����� ���� return
		if (i < 0 || i >= n) {
			return -1;
		}
		else {
			return A[i];
		}
	}
	void erase(int i) { //index i�� ����� ���� ����, �ʿ�� shift
		for (int j = i + 1; j < n; j++) {
			A[j - 1] = A[j];
		}

		n--;
	}
	void insert(int i, const int& e) { //index i�� elem e����, �ʿ�� shift
		if (n >= cap) {
			reserve(max(1, 2 * cap)); //cap==0�� ��츦 ���� max(1, )
		}

		for (int j = n - 1; j >= i; j--) { //shifting
			A[j + 1] = A[j];
		}

		A[i] = e;
		n++;
	}
	void reserve(int N) { //N�� ũ�⸦ ���� ���ͷ� ���Ҵ�
		if (cap >= N) { return; }

		int* B = new int[N];

		for (int j = 0; j < n; j++) {
			B[j] = A[j];
		}

		if (A != NULL) { delete[] A; }

		A = B;
		cap = N;
		delete[] B;
	}

};


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
		Node* cur; //�ݺ��ڰ� ����Ű�� Node ���� �����ͺ���
		Iterator(Node* u) {
			cur = u;
		}
	public:
		int& operator*() { //Iterator�� ���� ����Ű�� �ִ� Node elem return
			return cur->elem;
		}
		bool operator==(const Iterator& p) const {
			return cur == p.cur;
		} //���� Node�� iterator�� ����Ű�� �ִ� Node p�� ��ġ�ϴ��� Ȯ��
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
		}//���� Node�� operator
		Iterator& operator--() {
			cur = cur->prev;
			return *this;
		}
		Iterator& operator--(int) {
			cur = cur->prev;
			return *this;
		}//���� Node�� operator

		friend class SequenceList; //SequenceList Class�� iterator Class�� ������ �� �ֵ��� friend ����
	};

private:
	int n; //list�� ũ��
	Node* header; //header ��Ƽ�� ���
	Node* trailer; //trailer ��Ƽ�� ���
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
		if (n == 0) { return true; }
		else { return false; }
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
	void eraseFront() {
		erase(begin());
	}
	void eraseBack() {
		erase(--end());
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
		Iterator p = begin(); //Iterator p->ù���

		for (int j = 0; j < i; j++) {
			++p;
		}

		return p; //position p return
	}
	int indexOf(const Iterator& p) const {
		Iterator q = begin(); //Iterator q->ù���
		int j = 0;

		while (q != p) {
			++q;
			++j;
		}

		return j; //index j return
	}
};
*/