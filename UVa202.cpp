#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    int a,b,x=0;
    ostringstream sout;
    while(cin>>a>>b){
        //if(x++)cout<<endl;
        cout<<a<<'/'<<b<<" = "<<a/b;
        string s;
        int t[3010]={0};
        sout<<'.';
        int k=0;
        while(++k){
            a=a%b;
            if(t[a])break;
            t[a]=k;
            a*=10;
            sout<<a/b;
        }
        s=sout.str();
        s.insert(t[a],1,'(');
        if(k>51){
            s.insert(52,3,'.');
            s.erase(55);
        }
        s.append(1,')');
        cout<<s<<"\n   "<<k-t[a]<<" = number of digits in repeating cycle\n\n";
        sout.str("");
    }
    return 0;
}
