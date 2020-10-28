#include<iostream>
#include<string>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char data) {
        this->data = data;
        this->next = NULL;
    }
};

class SLinkedList {
public:
    Node* head;
    Node* tail;

    SLinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }
    void addFront(char data) {
        Node* n_node = new Node(data);
        n_node->next = head;
        head = n_node;
    }
    char removeFront() {
        Node* tmp = head;
        char data = head->data;
        head = head->next;

        delete tmp;
        return data;
    }
    char peek() {
        return head->data;
    }
};

class Linked_Stack {
public:
    SLinkedList* S;
    int n;

    Linked_Stack() {
        this->n = 0;
        this->S = new SLinkedList();
    }

    int size() {
        return n;
    }
    bool empty() {
        return n == 0;
    }
    char top() {
        if (empty())
            return -1;
        return S->peek();
    }
    void push(int x) {
        S->addFront(x);
        n++;
    }
    char pop() {
        if (empty())
            return -1;
        n--;
        return S->removeFront();
    }
    int get_oper(char a) {
        if (a == '*')
            return 3;
        if (a == '+' || a == '-')
            return 2;
        if (a == '(')
            return 1;
        return -1;//$
    }
};

int main() {
    string cmd, ret;
    int n = 0;
    cin >> n;

    while (n--) {
        cin >> cmd;
        cmd += '$';//���þȿ� �����ִ� �����ڵ� �������� �� ret�� ���� ���̱� ����
        ret = "";//���
        Linked_Stack A;

        for (int i = 0; cmd[i]; i++) {
            if ('1' <= cmd[i] && cmd[i] <= '9') {
                ret += cmd[i];
            }

            else if (cmd[i] == '(') {
                A.push(cmd[i]);
            }

            else if (cmd[i] == ')') {
                while (1) {
                    char a = A.pop();
                    if (a == '(')
                        break;
                    ret += a;
                }
            }
            else if (cmd[i] == '*' || cmd[i] == '-' || cmd[i] == '+' || cmd[i] == '$') {// ������ �켱���������� ���þȿ� �ִ� �����ڸ� ret�� ����
                while (!A.empty()
                    && A.get_oper(A.top()) >= A.get_oper(cmd[i]))
                    ret += A.pop();
                A.push(cmd[i]);
            }
        }

        //���þȿ� �����ִ� ������ �ϳ� $ ����
        A.pop();
        cout << ret << "\n";
    }
}