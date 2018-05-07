#include<iostream>
using namespace std;
int main(){
    char c;
    int i=1;
    while(cin.get(c)){
        if(c=='"'){
            if(i){
                cout<<"``";
            }
            else cout<<"''";
            i=!i;
            continue;
        }
        cout<<c;
    }
    return 0;
}