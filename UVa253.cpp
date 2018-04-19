#include <iostream>
using namespace std;
//当六个面中只有一个面为r(g)，显然均相同
//两个面时，分为相邻和相对，可知所有相邻相同，所有相对也相同
//当三个面时，仍然可以有如上结论
//因此，只需要两个正方体存在一一映射即可（每条轴的正反不产生影响）
int main()
{
    char s[13];
    int a,b,c,d,e,f;
    while(cin>>s){
        a = s[0]+s[5];
        b = s[1]+s[4];
        c = s[2]+s[3];
        d = s[6]+s[11];
        e = s[7]+s[10];
        f = s[8]+s[9];
        if((a == d||a == e||a == f)&&
           (b == d||b == e||b == f)&&
           (a == d||c == e||c == f))
        if((d == a||d == b||d == c)&&
           (d == a||e == b||e == c)&&
           (f == a||f == b||f == c))
        cout<<"TRUE"<<endl;
        else cout<<"FALSE"<<endl;
        else cout<<"FALSE"<<endl;
    }
    return 0;
}
