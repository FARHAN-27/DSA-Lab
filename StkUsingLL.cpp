#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	int data;
	
    Node* next;
	

	Node(int n)
	{
		data = n;
		next = NULL;
	}
};

class Stack {
	
    Node* top;

public:
	Stack() { 
        top = NULL;
     }

	void push(int data)
	{
    Node* temp = new Node(data);
        if (!temp) {
			cout << "\nStack Overflow";
			exit(1);
		}
        temp->data = data;
		temp->next = top;
		top = temp;
	}

	
	bool isEmpty()
	{
	
		return top == NULL;
	}

	int peek()
	{
		
		if (!isEmpty())
			return top->data;
		else
			exit(1);
	}

		void pop()
	{
		Node* temp;

	
		if (top == NULL) {
			cout << "\nStack Underflow" << endl;
			exit(1);
		}
		else {

				temp = top;

	
			top = top->next;

			
			free(temp);
		}
	}

	
	void display()
	{
		Node* temp;

		
		if (top == NULL) {
			cout << "\nStack Underflow";
			exit(1);
		}
		else {
			temp = top;
			while (temp != NULL) {

				// Print node data
				cout << temp->data<<" ";

				// Assign temp link to temp
				temp = temp->next;
				
			}
		}
	}
};


int main()
{
    Stack s;
    s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);
    s.display();
    cout << "\nTop element is " << s.peek() << endl;
    s.pop();
	s.pop();
    s.display();
    cout << "\nTop element is " << s.peek() << endl;

	return 0;
}
