#include<iostream>
#include<iomanip>
using namespace std;
char b[9][9];
const char p[2]={'B','W'};
int n;
int check(int ,int,int,bool);//检查位置是否合法
void eat(int, int, int ,int);
int main(){
    std::ios::sync_with_stdio(false);
    cin>>n;
    int rnd = 0;
    while(n--){
        if(rnd++)cout<<endl;
        char color;
        for(int i = 1;i<9;i++)
            for(int j = 1;j<9;j++)cin>>b[i][j];
        int player;
        cin>>color;
        if(color == p[1])player = 1;
        else player = 0;
        while(1){
            char cmd;
            cin>>cmd;
            int ex = 1;
            if(cmd == 'L'){
                for(int i = 1;i<9;i++)
                    for(int j = 1;j<9;j++)
                        if(b[i][j] == '-')
                            if(check(i,j,player,0)){
                                if(!ex)cout<<' ';
                                cout<<'('<<i<<','<<j<<")";
                                ex = 0;
                                }
                if(ex)cout<<"No legal move.";
                cout<<endl;
                }
            if(cmd == 'M'){
                int cnt[2]={0};
                char x,y;
                cin>>x>>y;
                if(!check(x-'0',y-'0',player,1))check(x-'0',y-'0',player = !player,1);
                player = !player;
                for(int i = 0;i<9;i++)
                    for(int j = 0;j<9;j++){
                        if(b[i][j] == p[0])cnt[0]++;
                        if(b[i][j] == p[1])cnt[1]++;
                    }
                cout<<"Black -"<<setw(3)<<cnt[0]<<" White -"<<setw(3)<<cnt[1]<<endl;
                }
            if(cmd == 'Q'){
                for(int i = 1;i<9;i++){
                    for(int j = 1;j<9;j++)cout<<b[i][j];
                    cout<<endl;
                }
                break;
                }
            }
    }
    return 0;
}
int check(int x,int y,int ch,bool d){
    int ok = 0,r[8],c[8];
    if(b[x+1][y] == p[!ch] && x+1<9)
        for(int i = x+2;i<9;i++){
            if(b[i][y] == '-')break;
            if(b[i][y] == p[ch]){
                r[ok] = i;
                c[ok++] = y;
                break;
            }
        }
    if(b[x-1][y] == p[!ch] && x-1>0)
        for(int i = x-2;i>0;i--){
            if(b[i][y] == '-')break;
            if(b[i][y] == p[ch]){
                r[ok] = i;
                c[ok++] = y;
                break;
            }
        }
    if(b[x][y+1] == p[!ch] && y+1<9)
        for(int i = y+2;i<9;i++){
            if(b[x][i] == '-')break;
            if(b[x][i] == p[ch]){
                r[ok] = x;
                c[ok++] = i;
                break;
            }
        }
    if(b[x][y-1] == p[!ch] && y-1>0)
        for(int i = y-2;i>0;i--){
            if(b[x][i] == '-')break;
            if(b[x][i] == p[ch]){
                r[ok] = x;
                c[ok++] = i;
                break;
            }
        }
    if(b[x+1][y+1] == p[!ch] && x+1<9 && y+1<9)
        for(int i = 2;i<9-x && i<9-y;i++){
            if(b[x+i][y+i] == '-')break;
            if(b[x+i][y+i] == p[ch]){
                r[ok] = x+i;
                c[ok++] = y+i;
                break;
            }
        }
    if(b[x+1][y-1] == p[!ch] && x+1<9 && y-1>0)
        for(int i = 2;i<9-x && i<y;i++){
            if(b[x+i][y-i] == '-')break;
            if(b[x+i][y-i] == p[ch]){
                r[ok] = x+i;
                c[ok++] = y-i;
                break;
            }
        }
    if(b[x-1][y+1] == p[!ch] && x-1>0 && y+1<9)
        for(int i = 2;i<x && i<9-y;i++){
            if(b[x-i][y+i] == '-')break;
            if(b[x-i][y+i] == p[ch]){
                r[ok] = x-i;
                c[ok++] = y+i;
                break;
            }
        }
    if(b[x-1][y-1] == p[!ch] && x-1>0 && y-1>0)
        for(int i = 2;i<x && i<y;i++){
            if(b[x-i][y-i] == '-')break;
            if(b[x-i][y-i] == p[ch]){
                r[ok] = x-i;
                c[ok++] = y-i;
                break;
            }
        }
    if(d){
        if(ok)b[x][y] = p[ch];
        for(int i = 0;i<ok;i++)eat(x,y,r[i],c[i]);
    }
    return ok;
}
void eat(int x,int y,int r,int c){
    if(r>x){
        if(c<y)
            for(int i = 1;i<=r-x && i<=y-c;i++)b[x+i][y-i] = b[x][y];
        if(c == y)
            for(int i = x+1;i<r;i++)b[i][y] = b[x][y];
        if(c>y)
            for(int i = 1;i<=r-x && i<=c-y;i++)b[x+i][y+i] = b[x][y];
    }
    if(r == x){
        if(c>y)
            for(int i = y+1;i<c;i++)b[x][i] = b[x][y];
        if(c<y)
            for(int i = y-1;i>c;i--)b[x][i] = b[x][y];
    }
    if(r<x){
        if(c<y)
            for(int i = 1;i<=x-r && i<=y-c;i++)b[x-i][y-i] = b[x][y];
        if(c == y)
            for(int i = x-1;i>r;i--)b[i][y] = b[x][y];
        if(c>y)
            for(int i = 1;i<=x-r && i<=c-y;i++)b[x-i][y+i] = b[x][y];
    }
}
