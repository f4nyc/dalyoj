#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <sstream>
using namespace std;
class doc{
    public:
        void print() const{
            for(auto & s : raw)
                cout<<s<<endl;
        }
        void print(int line_num) const{
            cout<<raw[line_num]<<endl;
        }
        void add(string & line){
            string temp;
            raw.push_back(line);
            for_each(line.begin(),line.end(),[](char & c){
                    if(isalpha(c))c = tolower(c);
                    else c = ' ';
                    });
            stringstream ss(line);
            while(ss>>temp)
                Index[temp].push_back(line_num);
            line_num++; 
        }
        bool find(const string & item, set<int> & result){
            if(count(item))
                for(int line: Index[item])
                    result.insert(line);
            return count(item);
        };
        bool count(const string &item) const {
            return Index.count(item);
        };
        void clear(){
            Index.clear();
            line_num = 0;
            raw.clear();
            raw.shrink_to_fit();
        }
    private:
        int line_num = 0;
        map<string,vector<int>> Index;
        vector<string> raw;
};
int main(){
    int m,n;
    std::string input;
    doc temp;
    vector<doc> docs; 
    cin>>n;
    cin.get();
    while(n){
        getline(cin,input);
        if(input == "**********"){
            n--;
            docs.push_back(temp);
            temp.clear();
            continue;
        }
        temp.add(input);
    }
    cin>>m;
    cin.get();
    while(m--){
        getline(cin,input);
        string item1,item2;
        bool flag= false;
        set<int> res;
        if(input.find(" AND ") != string::npos){
            int index = input.find(" AND");
            item1 = input.substr(0,index); 
            item2 = input.substr(index+5); 
            for(auto & d : docs)
                if(d.count(item1) && d.count(item2)){
                    d.find(item1,res);
                    d.find(item2,res);
                    if(flag)cout<<"----------\n";
                    for(int line: res)
                        d.print(line);
                    flag = true;
                    res.clear();
                }
        }
        else if(input.find(" OR ") != string::npos){
            int index = input.find(" OR");
            item1 = input.substr(0,index); 
            item2 = input.substr(index+4); 
            for(auto & d : docs)
                if(d.count(item1) || d.count(item2)){  //请注意，判断条件不要有副作用
                    d.find(item1,res);
                    d.find(item2,res);
                    if(flag)cout<<"----------\n";
                    for(int line: res)
                        d.print(line);
                    flag = true;
                    res.clear();
                }
        }
        else if(input.find("NOT") != string::npos){
            int index = input.find("NOT");
            item1 = input.substr(index+4); 
            for(auto & d : docs)
                if(!d.count(item1)){
                    if(flag)cout<<"----------\n";
                    d.print();
                    flag = true;
                }
        }
        else
            for(auto & d : docs)
                if(d.find(input,res)){
                    if(flag)cout<<"----------\n";
                    for(int line: res)
                        d.print(line);
                    res.clear();
                    flag = true;
                }
        if(!flag)
            cout<<"Sorry, I found nothing.\n";
        cout<<"==========\n";
    }
    return 0;
}
