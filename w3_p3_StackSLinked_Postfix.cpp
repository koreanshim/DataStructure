#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int a) {
        this->data = a;
        this->next = NULL;

    }
};

class SL {
public:
    Node* tail;
    Node* head;
    SL() {
        this->head = NULL;
        this->tail = NULL;
    }


    void add(int a) {
        Node* newNode = new Node(a);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int remove() {
        int removenum;
        Node* prev;
        Node* rep;
        prev = rep = head;
        if (head->next == NULL) {
            return head->data;
        }
        else {
            while (rep->next != NULL) {
                prev = rep;
                rep = rep->next;
            }
            removenum = rep->data;
            prev->next = NULL;
            tail = prev;
            delete rep;
            return removenum;
        }
    }
    int front() {
        return tail->data;
    }
};

class Stack {
private:
    int sizeofstack;
    SL* Sta;

public:

    Stack() {
        this->Sta = new SL();
        this->sizeofstack = 0;
    }
    int pop() {
        sizeofstack--;
        return Sta->remove();
    }
    void push(int a) {
        sizeofstack++;
        Sta->add(a);
    }
    int top() {
        Sta->front();
    }

};


int main() {
    Stack ST;
    int n;
    cin >> n;
    string s;
    int size = s.size();

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s.at(j) != '+' && s.at(j) != '-' && s.at(j) != '*') {
                int a = s.at(j) - '0';
                ST.push(a);
            }
            else {
                int a, b;
                int result;
                a = ST.pop();
                b = ST.pop();
                if (s.at(j) == '+') {
                    result = a + b;
                }

                else if (s.at(j) == '-') {
                    result = b - a;
                }

                else if (s.at(j) == '*') {
                    result = a * b;
                }
                ST.push(result);
            }

        }
        cout << ST.pop() << endl;
    }
}