#include<iostream>
#include <string>
#include <vector>
//move 表示a堆需要归位操作
//onto 表示b堆需要归位操作 
//不要忘记resize
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
const int Maxnum = 25;
int num;
const string op[5] = {"move","pile","onto","over","quit"};
vector<int> pile[Maxnum];
void find(int n, int &p, int & h){
    for(int i = 0; i < num; i++)
        for(int j = 0; j < pile[i].size(); j++)
            if(pile[i][j] == n){
                p = i;
                h = j;
            }
}
void clear(int i,int j){
    for(int k = j+1; k < pile[i].size(); k++){
        int index = pile[i][k];
        pile[index].push_back(index);
    }
    pile[i].resize(j+1);
}
void pileon(int i1,int j, int i2){
    for(int i = j; i < pile[i1].size(); i++)
        pile[i2].push_back(pile[i1][i]);
    pile[i1].resize(j);
}
int main(){
    string sou,des;
    int from,to;
    cin>>num;
    from = num;
    while(from--)
        pile[from].push_back(from);
    while(cin>>sou){
        if(sou == op[4])break;
        cin>>from>>des>>to;
        int i,j,k,l;
        find(from,i,j);
        find(to,k,l);
        if(i == k)continue;
        if(sou == op[0])clear(i,j);       
        if(des == op[2])clear(k,l);
        pileon(i,j,k);
    }
    for(int i = 0; i < num; i++){
       cout<<i<<':';
      for(int j = 0; j < pile[i].size(); j++)
         cout<<" "<<pile[i][j];
      cout<<endl;
    }
return 0;
}
