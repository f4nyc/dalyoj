#include<iostream>
using namespace std;
const int n=100005;
int a[n]={0};
int main(){
    int t,m;
    for(int i=0;i<n;i++){
        int k=i,j=i;
        while(k>0){j+=k%10;k/=10;}
        if(a[j]==0||i<a[j])a[j]=i;
    }
    cin>>t;//出于某种原因，这段输入会导致RE，严重怀疑是iostream的天然劣势
    while(t--){//毕竟我直接在例题代码上进行改造依然RE
        cin>>m;
        cout<<a[m]<<endl;
        }
    return 0;
}