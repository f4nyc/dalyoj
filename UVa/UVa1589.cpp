#include<iostream>
using namespace std;
int ax,ay,x[10],y[10],b[11][10],d[11][10],n;
char c[10];


void Chariot(int , int);
void General(int , int);
void Cannon(int , int);
void Horse(int ,int);
int iskilled();
int main(){
    cin>>n;
    while(n){
        for(int i = 0;i<11;i++){
            for(int j = 0;j<10;j++){
                b[i][j] = 0;
                d[i][j] = 0;
            }
        }
        cin>>ax>>ay;
        int m = n;
        while(m--){
            cin>>c[m]>>x[m]>>y[m];
            b[x[m]][y[m]] = c[m];
        }
        for(int i = 0;i<n;i++){
            if(c[i] == 'G'){
                General(x[i],y[i]);
            }
            if(c[i] == 'R'){
                Chariot(x[i],y[i]);
            }
            if(c[i] == 'H'){
                Horse(x[i],y[i]);
            }
            if(c[i] == 'C'){
                Cannon(x[i],y[i]);
            }
        }
        if(iskilled())cout<<"YES\n";
        else cout<<"NO\n";
        cin>>n;
    }
    return 0;
}
void General(int x1, int y1){
    int k = 1;
    for(int j = x1-1;j>0;j--)
    if(b[j][y1]){
        k=j;
        break;
    }
    for(int j = x1;j>=k;j--)d[j][y1] = 1;
}

void Chariot(int x1, int y1){
    int p = 1;
    if(d[x1][y1])p = 0;
    int u = 1,down = 10,l = 1,r = 9;
    for(int j = x1-1;j>0;j--)
    if(b[j][y1]>1){
        u = j;
        break;
    }
    for(int j = x1+1;j<11;j++)
    if(b[j][y1]>1){
        down = j;
        break;
    }
    for(int j = y1-1;j>0;j--)
    if(b[x1][j]>1){
        l = j;
        break;
    }
    for(int j = y1+1;j<10;j++)
    if(b[x1][j]>1){
        r = j;
        break;
    }
    for(int j = u;j <= down;j++)d[j][y1] = 1;
    for(int j = l;j <= r;j++)d[x1][j] = 1;
    if(p)d[x1][y1] = 0;
}
void Horse(int x1,int y1){
    int hold[4] = {0};
    if(x1>1  && b[x1-1][y1])hold[0] = 1;
    if(y1<9  && b[x1][y1+1])hold[1] = 1;
    if(x1<10 && b[x1+1][y1])hold[2] = 1;
    if(y1>1  && b[x1][y1-1])hold[3] = 1;
    if(!hold[0] && 0<x1-2){
        d[x1-2][y1-1] = 1;
        d[x1-2][y1+1] = 1;
    }
    if(!hold[1] && y1+2<10){
        d[x1-1][y1+2] = 1;
        d[x1+1][y1+2] = 1;
    }
    if(!hold[2] && x1+2<11){
        d[x1+2][y1-1] = 1;
        d[x1+2][y1+1] = 1;
    }
    if(!hold[3] && 0<y1-2){
        d[x1-1][y1-2] = 1;
        d[x1+1][y1-2] = 1;
    }
}

void Cannon(int x1,int y1){
    int u = 1,down = 11,l = 1,r = 11;
    for(int j = x1-1;j>0;j--)
    if(b[j][y1]){
        u = j;
        break;
    }
    for(int j = x1+1;j<11;j++)
    if(b[j][y1]){
        down = j;
        break;
    }
    for(int j = y1-1;j>0;j--)
    if(b[x1][j]){
        l = j;
        break;
    }
    for(int j = y1+1;j<10;j++)
    if(b[x1][j]){
        r = j;
        break;
    }
    for(int j = u-1;j > 0;j--){
        d[j][y1] = 1;
        if(b[j][y1])break;
    }
    for(int j = down+1;j < 11;j++){
        d[j][y1] = 1;
        if(b[j][y1])break;
    }
    for(int j = l-1;j > 0;j--){
        d[x1][j] = 1;
        if(b[x1][j])break;
    }
    for(int j = r+1;j < 10;j++){
        d[x1][j] = 1;
        if(b[x1][j])break;
    }
}


int iskilled(){
    int killed=1;
    if(ax>1 && !d[ax-1][ay])killed=0;
    if(ax<3 && !d[ax+1][ay])killed=0;
    if(ay>4 && !d[ax][ay-1])killed=0;
    if(ay<6 && !d[ax][ay+1])killed=0;
    return killed;
}
