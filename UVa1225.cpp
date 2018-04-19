#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int t,c[10]={0};
        cin>>t;
        for(int i=1;i<t+1;i++){
            int k=i;
            while(k>0){
                c[k%10]+=1;
                k/=10;
            }
        }
        for(int i=0;i<10;i++){
            if(i)cout<<' ';
            cout<<c[i];
        }
        cout<<endl;
    }
}