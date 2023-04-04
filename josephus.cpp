#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;
public:
    Queue() {
        front = rear = -1;
    }

    bool isFull() {
        if ((front == 0 && rear == MAX_SIZE - 1) || front == rear + 1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        return false;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow\n";
        }
        else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = val;
        }
    }

    int dequeue() {
        int val;
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        else {
            val = arr[front];
            if (front == rear) {
                front = rear = -1;
            }
            else {
                front = (front + 1) % MAX_SIZE;
            }
            return val;
        }
    }
};

int josephus(int n, int k) {
    Queue q;
    for (int i = 1; i <= n; i++) {
        q.enqueue(i);
    }
    while (q.isEmpty() == false) {
        for (int i = 1; i < k; i++) {
            q.enqueue(q.dequeue());
        }
        int eliminated = q.dequeue();
        if (q.isEmpty()) {
            return eliminated;
        }
    }
    
    return -1;
}


int main() {
    int n = 40;
    int k = 7;
    int survivor = josephus(n, k);
    cout << "The survivor is " << survivor << endl;
    return 0;
}
