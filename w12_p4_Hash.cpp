#include <iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;

class cell {
public:
	int key;
	int value;
	int flag;

	cell() {
		key = -1;
		value = -1;
		flag = NOITEM;
	}
};

class LinearHashTable {
private:
	cell* hashArr;
	int arrSize;
	int curSize;
public:
	LinearHashTable(int size) {
		this->arrSize = size;
		hashArr = new cell[arrSize];
		curSize = 0;
	}

	int hashFunc(int key) {
		return key % arrSize;
	}

	void find(int key) {
		int probing = 1;
		int initial_idx = hashFunc(key) % arrSize;
		int curIdx = hashFunc(key) % arrSize;
		bool firstOpr = true;

		while (hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE) {
			if (hashArr[curIdx].key == key) {
				cout << "True " << probing << endl;
				return;
			}
			else if (curIdx == initial_idx && !firstOpr) {
				cout << "loop" << endl;
				return;
			}
			probing += 1;
			firstOpr = false;
			curIdx = (hashFunc(key) + probing - 1) % arrSize;
		}
		cout << "False " << probing << endl;
	}

	void put(int key, int value) {
		int probing = 1;
		int initial_idx = hashFunc(key) % arrSize;
		int curIdx = hashFunc(key) % arrSize;
		bool firstOpr = true;

		if (isFull()) {
			cout << "Full" << endl;
		}
		else {
			while (hashArr[curIdx].flag == ISITEM) {
				if (curIdx == initial_idx && !firstOpr) {
					cout << "loop" << endl;
					break;
				}
				probing += 1;
				firstOpr = false;
				curIdx = (hashFunc(key) + probing - 1) % arrSize;
			}
			hashArr[curIdx].key = key;
			hashArr[curIdx].value = value;
			hashArr[curIdx].flag = ISITEM;
		}
		curSize++;
	}

	void erase(int key) {
		int probing = 1;
		int initial_idx = hashFunc(key) % arrSize;
		int curIdx = hashFunc(key) % arrSize;
		bool firstOpr = true;

		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			while (hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE) {
				if (hashArr[curIdx].key == key) {
					hashArr[curIdx].flag = AVAILABLE;
					hashArr[curIdx].key = -1;
					hashArr[curIdx].value = -1;
					break;
				}
				else if (curIdx == initial_idx && !firstOpr) {
					cout << "loop" << endl;
					break;
				}
				probing += 1;
				firstOpr = false;
				curIdx = (hashFunc(key) + probing - 1) % arrSize;
			}
		}
		curSize--;
	}

	bool isFull() {
		return (curSize == arrSize);
	}

	bool isEmpty() {
		return (curSize == 0);
	}

	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << i << " " << hashArr[i].value << endl;
		}
	}
};

int main() {
	int T = 0;
	int P = 0;
	int Q = 0;
	int key = 0;
	int R = 0;
	int r = 0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		
		cin >> P;
		LinearHashTable L(P);

		cin >> Q;
		for (int j = 0; j < Q; j++) {
			cin >> key;
			L.put(key, key);
		}

		cin >> R;
		for (int j = 0; j < R; j++) {
			cin >> r;
			L.find(r);
		}
	}

	return 0;
}