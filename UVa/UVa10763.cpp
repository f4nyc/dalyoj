#include<iostream>
#include <map>
using namespace std;
int main(){
    int n;
    map <pair<int,int>, int> s;
    while(cin >> n && n){
       int first, secound; 
       pair<int, int> seq,rev;
       while(n--){
           cin>>first>>secound;
           seq.first = first;
           seq.second = secound;
           rev.first = secound;
           rev.second = first;

           if( s.count(rev)){
               int t = --s[rev];
               if(!t)
                   s.erase(rev);
           }
           else
               s[seq]++;
       }
       if(s.empty())
           cout<<"YES\n";
       else
           cout<<"NO\n";
        s.clear();
    }
return 0;
}
