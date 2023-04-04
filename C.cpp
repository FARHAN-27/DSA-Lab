#include<bits/stdc++.h>

using namespace std;

int main(){
    int r,c;

    cin>>r>>c;

    int mat[r][c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>mat[i][j];
        }
        

    }


        for(int i=0;i<r;i++){
            int j=0;
            int k=i;
            int v[100];
            int vvv=0;
            while(j<c){
                if(i>=r)
                break;
               v[vvv]= mat[i][j];
                j++;
                i++;
                vvv++;
            }
              sort(v,v+vvv);

            i=k;
            int jj=0;
            int s=0;
            while(jj<c){
                if(i>=r)
                break;
                mat[i][jj]=v[s];
                i++,jj++,s++;
            }
             i=k;


        }

          
        for(int j=1;j<c;j++){
            int i=0;
            int k=j;
            int v[100];
            int vvv=0;
            while(i<r){
                if(j>=c)
                break;
                v[vvv]=mat[i][j];
                j++;
                i++;
                vvv++;
            }
            j=k;
            sort(v,v+vvv);
           
            int ii=0;
            int s=0;
          
            while(ii<r){
                if(j>=c)
                break;
                mat[ii][j]=v[s];
                j++;
                ii++;
                s++;
            }
            j=k;
            

        
    }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    
}
    

      