#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
const  float eps = 1e-5;
int V[1000];
int main(){
    std::ios::sync_with_stdio(false);
    int m,n,num,water,rnd = 0;
    float h,p;
    while(cin>>m>>n && m){
        num = m*n;
    for(int i = 0;i<num;i++)
        cin>>V[i];
    cin>>water;
    sort(V,V+num);
    int j;
    for(j = 1;j<num;j++){
        int t = (V[j]-V[j-1])*j*100;
        if(water<=t)break;
        water -= t;
    }
    h = (float)water/(j*100)+V[j-1]+eps;
    p = 100*(float)j/num;
    cout<<"Region "<<++rnd<<"\nWater level is "<<setiosflags(ios::fixed)<<setprecision(2)<<h<<" meters.\n"
        <<p<<" percent of the region is under water.\n\n";
    }
    return 0;
}
