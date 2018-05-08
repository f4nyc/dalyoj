#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
   int t,n;
   cin>>t; 
   while(t--){
       set<pair<int,int> > v;
       cin>>n;
       int first,second, max = 0x1 << ( sizeof(int) * 8 - 1),min = 0x1 << (sizeof(int) * 8 - 2);
       bool flag = true;
       while(n--){
           cin>>first>>second;
           v.insert(make_pair( 2*first,second));
            if(first < min)
                min = first;
            if(first > max)
                max = first;
       }
       int m = max + min;
       for(auto & p : v)
           if(!v.count(make_pair(2*m - p.first, p.second))){
               flag = 0;
               break;
           }
        cout<<( flag ? "YES\n" : "NO\n");
   }
   return 0;
}
