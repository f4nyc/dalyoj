#include<iostream>
int v[10][10],h[10][10],n;
using namespace std;
int check(int, int, int);
int main(){
    std::ios::sync_with_stdio(false);
    int rnd = 0;
    while(cin>>n){
        int status = 1;
        if(rnd)cout<<"\n**********************************\n\n";
        cout<<"Problem #"<<++rnd<<endl<<endl;
        for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++){
            v[i][j] = 0;
            h[i][j] = 0;
        }
        int  m = 0;
        cin>>m;
        while(m--){
            char c = 0;
            int x = 0, y = 0;
            cin>>c>>x>>y;
            if(c == 'H')h[x-1][y-1] = 1;
            else v[y-1][x-1] = 1;
        }
        for(int k =1;k<n;k++){
            int num = 0;
            for(int i = 0;i<n-k;i++)
            for(int j = 0;j<n-k;j++)
            num += check(i,j,k);
            if(num){
                status = 0;
                cout<<num<<" square (s) of size "<<k<<endl;
            }
        }
        if(status)cout<<"No completed squares can be found.\n";
    }
    return 0;
}
    int check(int a ,int b,int c){
        int ok = 1;
        for(int i = a;i<a+c;i++)
        if(!v[i][b] || !v[i][b+c])ok = 0;
        for(int i = b;i<b+c;i++)
        if(!h[a][i] || !h[a+c][i])ok = 0;
        return ok;
    }
