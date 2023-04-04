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

string infixToPostfix(string s) {
    Stack st;
    string res = "";
  
    for (int i = 0; i <s.length(); i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];  

        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.isEmpty() && st.peek() !='('){
                res+=st.peek();
                st.pop();
            }
            if(!st.isEmpty()){
                st.pop();
            }
        }

        else{
            while(!st.isEmpty() && prec(st.peek())>prec(s[i])){
                res+=st.peek();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.isEmpty()){
        res+=st.peek();
        st.pop();
    }


    return res;
    

}

int main() {
    string infix = "(a-b/c)/(a/k-l)";
    string postfix = infixToPostfix(infix);
   
    cout << postfix << endl;
    return 0;
}
