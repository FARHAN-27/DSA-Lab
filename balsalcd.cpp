#include <iostream>
#include <string>

using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
     for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }

    string res;
      for (int i = 0; i < s.length(); i++) {
        if (i == 0 || s[i] != s[i-1]) {
            res += s[i];
        }
    }

    if(res=="meow") cout<<"YES"<<endl;
    

    else  cout<<"NO"<<endl;



}

int main() {
  int x;
cin>>x;

while (x--)
{
    solve();
}


    return 0;
}
