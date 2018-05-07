#include<iostream>
using namespace std;
char p[512];
int readint(int );
int main(){
  while(cin.getline(p,256)){
    while(1){
      int len = readint(3);
      if(len == 0)break;
      while(1){
        int t = readint(len);
        if(t == (1<<len)-1)break;
        cout<<p[(1<<len)+t-1-len];
      }
    }
    cout<<endl;
    cin.get();
  }
  return 0;
}
int readint(int n){
  int r=0;
  char t=0;
  while(n--){
    cin>>t;
    if(t == '\n' || t == '\r')continue;
    r*=2;
    r+=t-'0';
  }
  return r;
}
