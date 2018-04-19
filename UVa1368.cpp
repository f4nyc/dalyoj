#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    string s=" ACGT";
    while(t--){
        char a[51][1001]={0};
        int b[1001][5]={0};
        int m,n;
        int sum=0;
        cin>>m>>n;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                b[j][s.find(a[i][j])]++;
            }
        for(int j=0;j<n;j++){
            int t,k;
            for(int i=0;i<5;i++){
                t=b[j][1],k=1;
                if(t<b[j][2]){t=b[j][2];k=2;}
                if(t<b[j][3]){t=b[j][3];k=3;}
                if(t<b[j][4])k=4;
            }
            b[j][0]=k;
            sum+=(b[j][1]+b[j][2]+b[j][3]+b[j][4]-b[j][k]);
        }
        for(int i=0;i<n;i++){
            cout<<s[b[i][0]];
        }
        cout<<endl<<sum;
//        if(t)
	cout<<endl;
    }
    return 0;
}
