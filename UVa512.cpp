#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
//暴力操作法
//int row[55][55],col[55][55],r,c;
//void readcom();
//void readque();
//
//int main(){
//    int rnd=1;
//    while(cin>>r>>c && r != 0 && c != 0){
//        if(rnd !=1)cout<<endl;
//        cout<<"Spreadsheet #"<<rnd++<<endl;
//        for(int i = 1;i <= r;i++)
//            for(int j=1;j <= c;j++)row[i][j]=i;
//        for(int i = 1;i <= r;i++)
//            for(int j=1;j <= c;j++)col[i][j]=j;
//        int n,q;
//        cin>>n;
//        while(n--)readcom();
//        cin>>q;
//        while(q--)readque();
//    }
//    return 0;
//}
//
//
//void readcom(){
//    int  p[15];
//    char com[3];
//    cin>>com;
//    if(!strcmp(com,"EX")){
//        int r1,c1,r2,c2;
//        cin>>r1>>c1>>r2>>c2;
//        int r3=0,c3=0,r4=0,c4=0;
//        for(int i=1;i<=r;i++)
//            for(int j=1;j<=c;j++){
//                if(row[i][j] == r1 && col[i][j] == c1 && !r3){
//                    r3=i;c3=j;
//                }
//                if(row[i][j] == r2 && col[i][j]==c2 && !r4){
//                    r4=i;c4=j;
//                }
//            }
//        if(r3 && c3){
//            row[r3][c3]=r2;
//            col[r3][c3]=c2;
//        }
//        if(r4 && c4){
//            row[r4][c4]=r1;
//            col[r4][c4]=c1;
//        }
//        return;
//    }
//    int num;
//    cin>>num;
//    for(int i=0;i<num;i++)cin>>p[i];
//    sort(p,p+num);
//    while(num--){
//        if(!strcmp(com,"DC"))
//            for(int i = 1;i <= r;i++)
//                for(int j = 1;j <= c;j++){
//                    if(col[i][j] == p[num])col[i][j]=0;
//                    if(col[i][j]>p[num])col[i][j]--;
//                }
//        if(!strcmp(com,"DR"))
//            for(int i = 1;i <= r;i++)
//                for(int j = 1;j <= c;j++){
//                    if(row[i][j] == p[num])row[i][j]=0;
//                    if(row[i][j]>p[num])row[i][j]--;
//                }
//        if(!strcmp(com,"IC"))
//            for(int i = 1;i <= r;i++)
//                for(int j = 1;j <= c;j++)
//                    if(col[i][j]>=p[num])col[i][j]++;
//        if(!strcmp(com,"IR"))
//            for(int i = 1;i <= r;i++)
//                for(int j = 1;j <= c;j++)
//                    if(row[i][j]>=p[num])row[i][j]++;
//    }
//    return;
//}
//
//
//void readque(){
//    int r,c;
//    cin>>r>>c;
//    if(row[r][c] && col[r][c])
//        cout<<"Cell data in ("<<r<<','<<c<<") moved to ("
//            <<row[r][c]<<','<<col[r][c]<<")\n";
//    else  cout<<"Cell data in ("<<r<<','<<c<<") GONE\n";
//    return;
//}
//
struct Command{
    char c[5];
    int r1,c1,r2,c2;
    int a,x[20];
}cmd[10000];
int r,c,n;

void query();
int main(){
    int r0, c0, q, rnd = 0;
    while(cin>>r>>c>>n && r){
        for(int i = 0;i<n;i++){
            cin>>cmd[i].c;
            if(cmd[i].c[0] == 'E')cin>>cmd[i].r1>>cmd[i].c1>>cmd[i].r2>>cmd[i].c2;
            else {
                cin>>cmd[i].a;
                for(int j = 0;j<cmd[i].a;j++)cin>>cmd[i].x[j];
            }
        }
        if(rnd++)cout<<endl;
        cout<<"Spreadsheet #"<<rnd<<endl;
        cin>>q;
        while(q--)query();
    }
    return 0;
}
void query(){
    int r0,c0;
    cin>>r0>>c0;
    cout<<"Cell data in ("<<r0<<','<<c0<<")";
    for(int i = 0;i<n;i++){
        if(cmd[i].c[0] == 'E'){
            if(r0 == cmd[i].r1 && c0 == cmd[i].c1){r0 = cmd[i].r2; c0 = cmd[i].c2;}
            else if(r0 == cmd[i].r2 && c0 == cmd[i].c2){r0 = cmd[i].r1; c0 = cmd[i].c1;}
        } else{
            int num = cmd[i].a;
            int dr=0,dc=0;
            for(int j = 0;j<num;j++){
                int x =cmd[i].x[j];
                if(cmd[i].c[0] == 'I'){
                    if(cmd[i].c[1] == 'R' && x<=r0 )dr++;
                    if(cmd[i].c[1] == 'C' && x<=c0 )dc++;
                } 
                else{
                    if(cmd[i].c[1] == 'R' && x==r0 ){
                        cout<<" GONE\n";
                        return;
                    } 
                    if(cmd[i].c[1] == 'R' && x<r0)dr--;
                    if(cmd[i].c[1] == 'C' && x==c0 ){
                        cout<<" GONE\n";
                        return;
                    } 
                    if(cmd[i].c[1] == 'C' && x<c0)dc--;
                }
            }
            r0 += dr;
            c0 += dc;
        }
    }
    cout<<" moved to ("<<r0<<','<<c0<<")\n";
    return;
}
