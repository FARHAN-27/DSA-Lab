#include<bits/stdc++.h>
using namespace std;

#define n 100


class Sttack{
   
    private:
    
    string arr[n];
    int top;
   
    public:
    
    Sttack(){
        top=-1;
    }


    void push(string x){

        if(top==n-1){
            cout<<"stact is full"<<endl;
        }
        top++;
        arr[top]=x;

    }

    void pop(){
        if(top==-1){
            cout<<"<stack is empty"<<endl;
        }
        top--;


    }

    string Top(){
        if(top==-1){
            cout<<"stk is empty"<<endl;
        }


        return arr[top] ;
          }
    bool empty(){
        return top==-1;
    }



};

void ReverseStringUsingStack(string ss){
    Sttack st;
    string word;
    for (int i = 0; i < ss.length(); i++)
    {
        string word;
        while (ss[i]!=' ' && i<ss.length())
        {
            word =word +  ss[i];
            i++;
        }
        st.push(word);


        
    }
    while(!st.empty()){
        cout<<st.Top()<<" ";
        st.pop();
        
    }

   //./ cout<<st.top()<<" "
    
}

int PrefixEvloution(string s){


    stack<int>st;
    for (int i = s.length()-1; i >= 0; i--)
    {
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');

        }

        else{
            int op1 = st.top();
            st.pop();

            int op2  = st.top();
            st.pop();
            switch (s[i])
            {
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '+':
                st.push(op1+op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            
           
            }

        }
    }

    return st.top();
    

}
int PostfixEvloution(string s){


    stack<int>st;
    for (int i = 0; i <= s.length()-1; i++)
    {
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');

        }

        else{
            int op2 = st.top();
            st.pop();

            int op1  = st.top();
            st.pop();
            switch (s[i])
            {
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '+':
                st.push(op1+op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            
           
            }

        }
    }

    return st.top();
    

}




int main(){
 //   stack st;
    //  Sttack s;
    //  s.push(1);
    //  s.push(3);
    //   s.push(43);
    //    s.push(545);
    //     s.push(65);
        
    //     cout<<s.Top()<<endl;
    //     s.pop();
    //     s.pop();
    //     s.pop();
    //     s.pop();
    //     s.pop();
    //     //s.pop();
    //     cout<<s.empty()<<endl;

    string s= "hey, I am Road to breakUp";
    ReverseStringUsingStack(s);

    cout<<PrefixEvloution("-+7*45+20")<<endl;
    cout<<PostfixEvloution("46+2/5*7+")<<endl;




    
}