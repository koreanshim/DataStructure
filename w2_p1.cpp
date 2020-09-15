#include <iostream>
using namespace std;

int arr[10000] = { 0, };

void At(int idx) {
	cout << arr[idx] << endl;
}

void Set(int idx, int x) {
	if (arr[idx] == 0) {
		cout << 0 << endl;
	}
	else {
		arr[idx] = x;
	}
}

void Add(int idx, int x) {
	if (arr[idx] == 0) {
		for (int i = 0; i < idx; i++) {
			if (arr[i] == 0) {
				arr[i] = x;

				return; //if¹®¿¡¼­ Å»Ãâ
			}
		}
	}
	else {
		for (int iter = 9999; iter > idx; iter--) {
			arr[iter] = arr[iter - 1];
		}

		arr[idx] = x;
	}
}

int main() {
	string order;
	int n, idx, x;

	cin >> n; //iteration

	for (int iter = 0; iter < n; iter++) {
		cin >> order;

		if (order == "at") {
			cin >> idx;

			At(idx);
		}

		else if (order == "set") {
			cin >> idx >> x;

			Set(idx, x);
		}

		else if (order == "add") {
			cin >> idx >> x;

			Add(idx, x);
		}
	}

	return 0;
}