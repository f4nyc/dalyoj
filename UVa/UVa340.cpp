#include<iostream>
using namespace std;
int main(){
    int n=1;
    int p=1;
    int a[1010],b[1010];
    while( cin>>n&&n){
        cout<<"Game "<<p++<<":\n";
        int i;
        for( i=0;i<n;i++){
            cin>>a[i];
        }
        while(1){
            int A=0,B=0;
            for(i=0;i<n;i++){
                cin>>b[i];
                if(a[i]==b[i])A++;
            }
            for(i=0;i<n;i++){
                if(b[i]!=0){break;}
            }
            if(i==n)break;
            for(i=0;i<10;i++){
                int c1=0,c2=0;
                for(int j=0;j<n;j++){
                    if(a[j]==i)c1++;
                    if(b[j]==i)c2++;
                }
                if(c1<c2)B+=c1;
                else B+=c2;
            }
            cout<<"    ("<<A<<','<<B-A<<")\n";
        }
    }
    return 0;
}