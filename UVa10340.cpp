#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,t;
    while(cin>>s>>t){
        int l=s.length();
        int m=t.length();
        int k=0;
        for(int i=0;i<m;i++){
            if(t[i]==s[k])k++;
            }
        if(k==l)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}