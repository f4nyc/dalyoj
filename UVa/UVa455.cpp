#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        string a;
        cin>>a;
        int ans=0;
        int l=a.length();
        for(int i=1;i<=l;i++){
            if(l%i==0){
                int p=1;
                for(int j=i;j<l;j++){
                    if(a[j]!=a[j%i]){
                        p=0;
                        break;
                    }
                }
                if(p){
                    cout<<i<<endl;
                    if(n)cout<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}