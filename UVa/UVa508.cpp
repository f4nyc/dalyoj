#include<iostream>
#include<map>
#include<string>
using namespace std;
map<char,string>code;
map<string,string>word;
void match(string );
int main(){
    string s;
    char ch;
    while(cin>>ch && ch != '*'){
        cin>>code[ch];
    }
    while(cin>>s && s != "*")
        for(char i :s)
            word[s] +=code[i];
    while(cin>>s && s != "*"){
        match(s);
    }
    return 0;
}
void match(string s){
    int ok = 0,l=0x7fffffff;
    string ans="";
    for(const auto &p : word){
         if(p.second == s){
             if(ok){
                 ans += "!";
                 cout<<ans<<endl;
                 return;
             }
             ans = p.first;
             ok = 1;
         }
         if(!ok){
             if(p.second.size()<s.size())
                 if(p.second == s.substr(0,p.second.size())){
                    int d=s.size()-p.second.size();
                    if(d<l){
                        l = d;
                        ans = p.first;
                    }
             }
           if(p.second.size()>s.size())
               if(s == p.second.substr(0,s.size())){
                    int d=p.second.size()-s.size();
                    if(d<l){
                        l = d;
                        ans = p.first;
                    }
           }
         }
    }
    cout<<ans;
    if(!ok)cout<<'?';
    cout<<endl;

}
