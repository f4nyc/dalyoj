#include<iostream>
#include<algorithm>
using namespace std;
struct re{int l,w;}r[6];
bool f1( re &a,re &b){
    if(a.l<a.w)swap(a.l,a.w);
    if(b.l<b.w)swap(b.l,b.w);
    return a.l>b.l||(a.l==b.l&&a.w>b.w);
        }
int main(){
    while(cin>>r[0].l>>r[0].w){
        for(int i=1;i<6;i++){
            cin>>r[i].l>>r[i].w;
        }
        sort(r,r+6,f1);
        int ok=1;
        for(int i=0;i<6;i+=2){
            if(r[i].l!=r[i+1].l || r[i].w!=r[i+1].w){
                ok=0;
                break;
            }
        }
        if(r[0].l!=r[2].l || r[0].w!=r[4].l || r[2].w!=r[4].w)ok=0;
        if(ok)cout<<"POSSIBLE\n";
        else cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
