#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    char data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char item) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack overflow\n";
            return;
        }
        top++;
        data[top] = item;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return '\0';
        }
        char item = data[top];
        top--;
        return item;
    }

    bool isEmpty() {
        return (top == -1);
    }

    char peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return '\0';
        }
        return data[top];
    }
};



int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else return -1;
}

bool isBalanced(string s){
    Stack st;
    bool ans= true;

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='[' || s[i]=='(' ||s[i]=='{' ){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.isEmpty() && st.peek()=='('){
                st.pop();

            }
            else {
                ans = false;
                break;
            }
        }
        else if(s[i]=='}'){
            if(!st.isEmpty() && st.peek()=='{'){
                st.pop();

            }
            else {
                ans = false;
                break;
            }
        }
        else if(s[i]==']'){
            if(!st.isEmpty() && st.peek()=='['){
                st.pop();

            }
            else {
                ans = false;
                break;
            }
        }
    }

    if(!st.isEmpty()){
        ans= false;
    }

    return ans;
    


}




int main() {
    string ss= "[{()}]";

    if(isBalanced(ss)) cout<<"yo";
    else cout<<"no";
    
        return 0;
}
