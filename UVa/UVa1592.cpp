#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::cin;
using std::endl;
std::map< std::string , int> id;
typedef std::pair<int,int> comb;
int ID(const std::string & s){
    static int cnt = 0;
    if(!id.count(s))
        id[s] = cnt++;
    return id[s];
}
void process(int row, int col, int data[][10]){
    for( int i = 0; i < col; i++)
        for( int j = 0; j < i; j++){
            std::map<comb,int > m;
            for(int k = 0; k < row; k++){
                comb temp = std::make_pair(data[k][j],data[k][i]); 
                if(m.count(temp)){
                    cout<<"NO\n";
                    cout<<m[temp] + 1<<' '<<k + 1<<endl;
                    cout<<j + 1<<' '<<i + 1<<endl;
                    return;
                }
                m[temp] = k;
            }
        }
    cout<<"YES\n";
};
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int row,col;
    while(cin>>row>>col){
        id.clear();
        cin.get();
        int data[10000][10];
        std::string s;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(j == col-1)
                    std::getline(cin,s);
                else
                    std::getline(cin,s,',');
                data[i][j] = ID(s);
            }
        }
        process(row,col,data);
    }
    return 0;
}
