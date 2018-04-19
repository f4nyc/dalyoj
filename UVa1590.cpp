#include<iostream>
using namespace std;
//我觉得csapp还是没白看，位运算啊位运算，注意有符号和无符号的坑
unsigned int ad[1500][5],n;
int main(){
    int m;
    while(cin>>m){
        unsigned int mask = 0xffffffff;
        n = m;
        while(m--){
            cin>>ad[m][1];
            for(int i = 2;i<5;i++){cin.get();cin>>ad[m][i];}
            ad[m][0] = (ad[m][1]<<24)+(ad[m][2]<<16)+(ad[m][3]<<8)+ad[m][4];
        }
        while(1){
            int flag = 1;
            for(int i = 0;i<n;i++)
                if((ad[i][0]&mask) != (ad[0][0]&mask)){
                    flag = 0;
                    break;
                }
            if(flag)break;
            mask <<= 1;
        }
        for(int i = 0;i<3;i++)
            cout<<(((ad[0][0]&mask)<<i*8)>>24)<<'.';
        cout<<(ad[0][0] & mask & 0xff)<<endl;
        for(int i = 0;i<3;i++)
            cout<<((mask<<i*8)>>24)<<'.';
        cout<<(mask & 0xff)<<endl;
    }
    return 0;
}
