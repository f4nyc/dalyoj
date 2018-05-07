#include<iostream>
#include<iomanip>
using namespace std;
int n,k,m,rnd,p1,p2;
int p[25];
void pick(int*);
int main(){
  while(cin>>n>>k>>m && n){
    for(int i = 0;i<n;i++)p[i]=1;
    rnd=n;
    p1=0;
    p2=n-1;
    while(rnd){
      pick(p);
      if(rnd)cout<<',';
    }
    cout<<endl;
  }
 return 0;
}
void pick(int* p){
  for(int i = 0;i<k;p1++)
    if(p[p1=(p1+n)%n])i++;
  for(int j = 0;j<m;p2--)
    if(p[p2=(p2+n)%n])j++;
  cout<<setw(3)<<p1;
  rnd--;
  p[p1-1]=0;
  if((p2+2)%n != p1%n){
    cout<<setw(3)<<p2+2;
    rnd--;
    p[p2+1]=0;
  }
}
