#include<bits/stdc++.h>
using namespace std;

#define n 100


class Sttack{
   
    private:
    
    int arr[n];
    int top;
   
    public:
    
    Sttack(){
        top=-1;
    }


    void push(int x){

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

    int Top(){
        if(top==-1){
            cout<<"stk is empty"<<endl;
        }


        return arr[top] ;
          }
    bool empty(){
        return top==-1;
    }
    int size(){
        return top+1;
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
       // st.push(word);


        
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

void nearest_greater_to_right(int arr[],int sz){
    Sttack s;
    vector<int>v;
    
    for (int i = sz-1; i >=0 ; i--)
    {
        if(s.size()==0){
            v.push_back(-1);
        }

        else if(s.size()>0 && s.Top()>arr[i]){
            v.push_back(s.Top());
        }

         else if(s.size()>0 && s.Top()<=arr[i]){

            while(s.size()>0 && s.Top() <=arr[i]){
                s.pop();
            }
            if(s.size()==0) v.push_back(-1);

            else v.push_back(s.Top());
            
        }


    
    s.push(arr[i]);
   
    }

    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }



}
void nearest_greater_to_right_for_temp(int arr[],int sz){
    stack<pair<int,int>> s;
    vector<int>v;
    
    for (int i = sz-1; i >=0 ; i--)
    {
        if(s.size()==0){
            v.push_back(i);
        }

        else if(s.size()>0 && s.top().first>arr[i]){
            v.push_back(s.top().second);
        }

         else if(s.size()>0 && s.top().first<=arr[i]){

            while(s.size()>0 && s.top().first <=arr[i]){
                s.pop();
            }
            if(s.size()==0) v.push_back(i);

            else v.push_back(s.top().second);
            
        }


    
    s.push(make_pair(arr[i], i));

   
    }

    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        v[i]=v[i]-i;
        cout << v[i] << " ";
    }



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

    // string s= "hey, I am Road to breakUp";
    // ReverseStringUsingStack(s);

    // cout<<PrefixEvloution("-+7*45+20")<<endl;
    // cout<<PostfixEvloution("46+2/5*7+")<<endl;

    int siz = 8;
    int a[siz]={73,74,75,71,69,72,76,73};

    nearest_greater_to_right_for_temp(a,siz);






    
}