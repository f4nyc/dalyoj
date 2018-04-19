#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int d,s,b,m;
string str[6];
char mode;
int recover();
void print_ans();
int main(){
    std::ios::sync_with_stdio(false);
    cout.setf(ios::uppercase);
    int rnd = 0;
    while(cin>>d && d != 0){
        cin>>s>>b>>mode;
        rnd++;
        if(mode == 'E')m = 0;
        else m = 1;
        for(int i = 0;i<d;i++)
        cin>>str[i];
        if(recover()){
            cout<<"Disk set "<<rnd<<" is valid, contents are: ";
            print_ans();
        }
        else cout<<"Disk set "<<rnd<<" is invalid.\n";
    }
    return 0;
}
int recover(){
    for(int i = 0;i<s*b;i++){
        int num = 0,cover = 0,ind = 0;
        for(int j = 0;j<d;j++){
            if(str[j][i] == 'x'){
                cover++;
                ind = j;
            }
            if(str[j][i] == '1')num++;
        }
        num = num%2;
        if(cover > 1)return 0;
        if(num == m)
        if(cover)str[ind][i]='0';
        if(num != m){
            if(cover)str[ind][i]='1';
            else return 0;
        }
    }
    return 1;
}
void print_ans(){
    int h = 0,t = 0;
    for(int i = 0;i<s*b;i+=s)
    for(int j = 0;j<d;j++){
        if((i/s)%d == j)continue;
        for(int k = 0;k<s;k++){
            h = h<<1;
            h+= (str[j][i+k]-'0');
            if(!(++t%4)){
                cout<<hex<<h<<dec;
                h = 0;
            }
        }
    }
    if(t%4){
        h = h<<(4-t%4);
        cout<<hex<<h<<dec;
    }
    cout<<endl;
}
