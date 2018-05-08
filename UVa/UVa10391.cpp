#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    string s;
    unordered_set<string> dic;          //牺牲空间以换取常数时间查找
    vector<string> v;                   //反正输入是有序的
    set<int> len;
    while(cin>>s){
        dic.insert(s); 
        v.push_back(s);
        len.insert(s.length());
    } 
    for(auto & s : v)
        for(auto & l : len){
            if(l >= s.length())
                break;
            if( dic.count(s.substr(0,l)) && dic.count(s.substr(l))){
                cout<<s<<endl;
                break;
            }
        }
    return 0;
}
