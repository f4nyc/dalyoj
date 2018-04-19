#include<iostream>
const int N = 1000000;
using namespace std;
struct Student{
    int a,b,c,wake;
}s[10];

int main(){
    std::ios::sync_with_stdio(false);
    int n,m,t,rnd = 0;
    while(cin>>n && n){
        rnd++;
        t = -1;
        m = 0;
        for(int i = 0;i<n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
            s[i].c--;
            if(s[i].c<s[i].a){
                s[i].wake = 1;
                m++;
            }
        }
        for(int i = 1;i<N;i++){
            if(m == n){
                t = i;
                break;
            }
            int p = (m>=n-m);
            m = 0;
            for(int j = 0;j<n;j++){
                s[j].c = (s[j].c+1)%(s[j].a+s[j].b);
                if(s[j].c == s[j].a && p)s[j].c=0;
                if(s[j].c<s[j].a){
                    s[j].wake = 1;
                    m++;
                }
            }
        }
        cout<<"Case "<<rnd<<": "<<t<<endl;
    }
    return 0;
}
