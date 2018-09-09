#include<iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
using namespace std;
std::map<string,string> Dict;
std::set<string> added,changed;
bool solve(string old, string n3w){
    string key,value;
    for(auto & c:old)
        if(c == '{' || c == '}' || c == ':' || c == ',')
            c=' ';
    for(auto & c:n3w)
        if(c == '{' || c == '}' || c == ':' || c == ',')
            c=' ';
    stringstream ss(old);
    while(ss>>key){
        ss>>value;
        Dict[key] = value;
    }
    ss.clear();
    ss.str("");
    ss<<n3w;
    while(ss>>key){
        ss>>value;
        if(!Dict.count(key))
            added.insert(key);
        else{
            if(Dict[key] != value)
                changed.insert(key);
            Dict.erase(key); 
        }
    }
    return !(Dict.empty() && added.empty() && changed.empty());
}
int main(){
    int turn;
    string old,n3w;
    cin>>turn;
    cin.get();
    while(turn--){
        getline(cin,old);
        getline(cin,n3w);
        if(solve(old,n3w)){
            if(!added.empty()){
                cout<<'+';
                int i = 0;
                for(auto & s : added){
                    if(i++)
                        cout<<',';
                    cout<<s;
                }
                cout<<endl;
            }
            if(!Dict.empty()){
                cout<<'-';
                int i = 0;
                for(auto & s : Dict){
                    if(i++)
                        cout<<',';
                    cout<<s.first;
                }
                cout<<endl;
            }
            if(!changed.empty()){
                cout<<'*';
                int i = 0;
                for(auto & s : changed){
                    if(i++)
                        cout<<',';
                    cout<<s;
                }
                cout<<endl;
            }
        }
        else
            cout<<"No changes\n";
        Dict.clear();
        added.clear();
        changed.clear();
        cout<<endl;
    } 
    return 0;
}
