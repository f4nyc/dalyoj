#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;
int main(){
    double A[20][40]={0};
    long long B[20][40]={0};
    for(int i=0;i<10;i++){
        for(int j=1;j<31;j++){
            double m=1-pow(2,-1-i),e=pow(2,j)-1;
            double t=log10(m)+e*log10(2);
            B[i][j]=t;
            A[i][j]=pow(10,t-B[i][j]);
        }
    }
    /*
      一开始以为要暴力计算最大值，然后打表=。=
      但是一来输入格式AeB转换起来麻烦，二来浮点数误差。
      通过取log得到关系式，近似的A，以此打表。
    */
    string str;
    while(cin>>str){
        if(str=="0e0")break;
        int p=str.find('e');
        str[p]=' ';
        double a;long long b;
        istringstream sin(str);
        sin>>a>>b;
        while(a<1){a*=10;b-=1;}
        for(int i=0;i<10;i++){
            for(int j=1;j<31;j++){
                if(b==B[i][j] && fabs(a-A[i][j])<10e-4){
                    cout<<i<<' '<<j<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}