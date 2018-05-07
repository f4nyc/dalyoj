#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
int process(vector<int> & v){
    int flag = 0;
    for (int i = 0; i < v.size() - 1; ++i) 
       flag += v[i] = abs(v[i]-v[i + 1]); 
    v[v.size() - 1] = v[0];
    return flag;
}
int main(){
    ios::sync_with_stdio(0);
    int t, n;
    cin>>t;
    while(t--){
        int t;
        bool iszero =false;
        vector<int> v; 
        cin >> n;
        while(n--){
            cin>>t;
            v.push_back(t);
        }
        v.push_back(v[0]);
        int m = 1000;               // 用啥set，反正一千次
        while(m--){                 // 其实m = 50就能AC,不过....真无聊 
            if(!process(v))
                iszero = true;
        }
        if(iszero)
            cout<<"ZERO\n";
        else
            cout<<"LOOP\n";
    }
    return 0;
}
