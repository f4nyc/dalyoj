#include<iostream>
#include<string>
using namespace std;
int f(string a ){
    int l=a.length();
    int n=0;
    for(int i=0;i<l;i++){
        for (int j=0;j<l;j++){
            if(a[(i+j)%l]==a[(n+j)%l])continue;
            if(a[(i+j)%l]<a[(n+j)%l]){
                n=i;
                break;
            }
            else break;
        }
    }
    return n;
};
int main(){
    string a;
    int t;
    cin>>t;
    while(t--){
        cin>>a;
        int p=f(a);
        for(int i=0;i<a.length();i++)cout<<a[(i+p)%(a.length())];
        cout<<endl;
    }
}