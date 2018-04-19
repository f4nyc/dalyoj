#include<iostream>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    long long n,x,y,k,a,b,ans[2]={0};
    while(cin>>n>>x>>y){
        k = 1LL<<62;
        for( a = 0;a<32;a++)
            for(b = 0;b<32;b++){
                long long temp =(((n-1)*x+((n-1)*x<<a))>>b)+y;
                if(temp>=n*y && temp<k){
                    k = temp;
                    ans[0] = a;
                    ans[1] = b;
                    }
            }
        cout<<k<<' '<<ans[0]<<' '<<ans[1]<<endl;
    }
    return 0;
}
