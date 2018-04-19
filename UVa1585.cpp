#include<iostream>
using namespace std;
int main(){
    string str;
    int n;
    cin>>n;
    while(n--){
        cin>>str;
        int s=0,x=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='O')x+=1;
            if(str[i]=='X')x=0;
            s+=x;
        }
         cout<<s<<endl;
    }
    return 0;
}