/*
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	int depth;
	Node* parent;
	vector<Node*> child;

	Node(int data) {
		this->data = data;
		this->parent = NULL;
		this->depth = 0;
	}
	~Node() {}
	void setParent(Node* parent) {
		this->parent = parent;
	}
	void insertChild(Node* child) {
		this->child.push_back(child);
	}
	void setDepth(int d) {
		this->depth = d;
	}
	int getDepth() {
		return depth + 1;
	}
};

class Tree {
private:
	Node* root;
	vector<Node*> node_list;
public:
	Tree(int data) {
		root = NULL;
		root = new Node(data);
		node_list.push_back(root);
	}
	~Tree() {}
	int size() {
		return node_list.size();
	}
	void insertNode(int par_data, int data) {
		for (int i = 0; i < size(); i++) {
			if (node_list[i]->data == par_data) {
				Node* node = new Node(data);

				node->setDepth(node_list[i]->getDepth());
				node->setParent(node_list[i]);

				node_list[i]->insertChild(node);
				node_list.push_back(node);

				return;
			}
		}
	}
	void searchMaxOfDepth(int d) {
		int max = 0;
		for (int i = 0; i < size(); i++) {
			if (node_list[i]->getDepth() == d) {
				if (max < node_list[i]->data) {
					max = node_list[i]->data;
				}
			}
		}
		cout << max << endl;
	}
};

int main() {
	Tree t = Tree(1);
	int n = 0;
	int m = 0;

	cin >> n >> m;



	for (int i = 0; i < n; i++) {
		int par = 0;
		int data = 0;

		cin >> par >> data;

		t.insertNode(par, data);
	}

	for (int i = 0; i < m; i++) {
		int depth = 0;
		cin >> depth;
		t.searchMaxOfDepth(depth);
	}

	return 0;
}
*/
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* par;
    vector<Node*> chi_v;
    int depth;
    Node(int data) {
        this->data = data;
        this->par = NULL;
        this->depth = 0;
    }
    ~Node() {}
    void setParent(Node* parent) {
        this->par = parent;
    }
    void insertChild(Node* child) {
        this->chi_v.push_back(child);
    }
};

class Tree {
public:
    Node* root;
    vector<Node*> node_list;

    Tree(int r) {
        root = NULL;
        root = new Node(r);
        node_list.push_back(root);
    }
    ~Tree(){}
    void insertNode(int par_data, int data) {
        for (int i = 0; i < node_list.size(); i++) {
            if (node_list[i]->data == par_data) {
                Node* newNode = new Node(data);
                newNode->setParent(node_list[i]);
                node_list.push_back(newNode);
                node_list[i]->insertChild(newNode);
                return;
            }
        }
    }

    void preorder(Node* r) {
        if (r) {
            for (Node* c : r->chi_v) {
                c->depth = r->depth + 1;
                preorder(c);
            }
        }
    }

    void depth(int a) {
        for (int i = 0; i < node_list.size(); i++) {
            if (a == node_list[i]->data) {
                cout << node_list[i]->depth << endl;
                return;
            }
        }
    }
    void depthMaxNode(int a) {
        int max = 0;
        for (int i = 0; i < node_list.size(); i++) {
            if (a == node_list[i]->depth) {
                if (max < node_list[i]->data) {
                    max = node_list[i]->data;
                }
            }
        }
        cout << max << endl;
        return;
    }
};

int main() {
    int N;
    int M;
    cin >> N;
    cin >> M;

    Tree t = Tree(1);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        t.insertNode(a, b);
    }
    t.preorder(t.root);
    for (int j = 0; j < M; j++) {
        int a;
        cin >> a;
        t.depthMaxNode(a);
    }
}
