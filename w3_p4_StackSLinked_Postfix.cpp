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
        cmd += '$';//스택안에 남아있는 연산자들 마지막에 다 ret에 갖다 붙이기 위해
        ret = "";//출력
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
            else if (cmd[i] == '*' || cmd[i] == '-' || cmd[i] == '+' || cmd[i] == '$') {// 연산자 우선순위에따라 스택안에 있는 연산자를 ret에 붙임
                while (!A.empty()
                    && A.get_oper(A.top()) >= A.get_oper(cmd[i]))
                    ret += A.pop();
                A.push(cmd[i]);
            }
        }

        //스택안에 남아있는 마지막 하나 $ 방출
        A.pop();
        cout << ret << "\n";
    }
}