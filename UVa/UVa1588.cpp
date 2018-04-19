#include<iostream>
#include<string>
using namespace std;
string s,t;
int kick(string s,string t);
int main(){
    while(cin>>s>>t){
        s.append(100,'0');
        t.append(100,'0');
        cout<<kick(s,t)-100<<endl;
    }
    return 0;
}
int kick(string s,string t){
    int l=s.length(),m=t.length(),k=0;
    string a=s,b=t;
    for(int i=0;i<l+k;i++){
        if((a[i]+b[i]-'0')>'3'){a.insert(0,1,'0');i=k++;}
    }
    l=a.length();
    l=l<m?m:l;
    a=s;b=t;k=0;
    for(int i=0;i<m+k;i++){
        if((a[i]+b[i]-'0')>'3'){b.insert(0,1,'0');i=k++;}
    }
    m=b.length();
    m=m<a.length()?a.length():m;
    return m>l?l:m;
}