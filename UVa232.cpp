#include<iostream>
#include<string>
using namespace std;
int main(){
    int r,c,t=0;
     char p[10][10]={0};
    cin>>r>>c;
    while(r){
        if(t){cin>>c;cout<<endl;}
        cout<<"puzzle #"<<++t<<":\n";
        int a[11][11]={0},k=1;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                cin>>p[i][j];
                if(p[i][j]=='*'){
                    a[i][j]=-1;
                    continue;
                }
                if(i==0||j==0||a[i-1][j]==-1||a[i][j-1]==-1){
                    a[i][j]=1;
                }
            }
        cout<<"Across";
        int f=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==1){
                    if(j==0||a[i][j-1]==-1){
                        cout<<"\n";
                        if(k<10)cout<<' ';
                        if(k<100)cout<<' ';
                        cout<<k++<<'.';
                    }
                    else k++;
                    f=1;
                }
                if(a[i][j]==-1)f=0;
                if(f)cout<<p[i][j];
            }
        }
        k=1;
        cout<<"\nDown";
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==1){
                    if(i==0||a[i-1][j]==-1){
                        cout<<"\n";
                        if(k<10)cout<<' ';
                        if(k<100)cout<<' ';
                        cout<<k++<<'.';
                        int l=0;
                        while(a[i+l][j]!=-1 && i+l<r){
                            cout<<p[i+l][j];
                            l++;
                        }
                    }
                    else k++;
                }
            }
        }
        cout<<endl;
        cin>>r;
    }
    return 0;
}