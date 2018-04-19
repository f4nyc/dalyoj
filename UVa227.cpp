#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    int n=0;
    string a[5];
    while(1){
        int x=0,y=0;
        string t;
        getline(cin,a[0]);
        if(a[0][0]=='Z')break;//之前愚蠢的看错大小写.....
        for(int i=1;i<5;i++)
        getline(cin,a[i]);
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(a[i][j]==' '){
                    x=i;y=j;
                }
            }
        }
        int f=0;
        getline(cin,t,'0').get();//干掉‘0’后的\n
        for(int i=0;i<t.length();i++){
            char te;
            if(t[i]=='0')break;
            if(t[i]=='A'&& x>0){te=a[x-1][y];a[x-1][y]=a[x][y];a[x--][y]=te;continue;}
            if(t[i]=='B'&& x<4){te=a[x+1][y];a[x+1][y]=a[x][y];a[x++][y]=te;continue;}
            if(t[i]=='L'&& y>0){te=a[x][y-1];a[x][y-1]=a[x][y];a[x][y--]=te;continue;}
            if(t[i]=='R'&& y<4){te=a[x][y+1];a[x][y+1]=a[x][y];a[x][y++]=te;continue;}
            if(t[i]==' '||t[i]=='\n'||t[i]=='\t')continue;
            f=1;
            break;
        }
        if(n++)
            cout<<endl;
        cout<<"Puzzle #"<<n<<":"<<endl;
        if(f)
            cout<<"This puzzle has no final configuration."<<endl;
        else
        {
            for(int i=0; i<5;i++)
            {
                for(int j=0; j<5; j++)
                {
                    if(j) cout<<" ";
                    cout<<a[i][j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}