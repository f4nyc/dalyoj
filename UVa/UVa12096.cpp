#include<iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
typedef std::set<int> Set;
int main(){
    int round,n;
    string op;
    cin>>round;
    while(round--){
        std::stack<Set> s;
        std::map<Set, int> ID;
        int maxID = 0;
        cin>>n;
        while(n--){
            cin>>op; 
            if(op[0] == 'P')
                s.push(Set());
            else if(op[0] == 'D')
                s.push(s.top());
            else {
                Set s1 = s.top();
                s.pop();
                Set s2 = s.top();
                s.pop();
                if(op[0] == 'U'){
                    Set t = Set();
                    std::set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),std::inserter(t,t.begin())) ;
                    s.push(t);
                }
                if(op[0] == 'I'){
                    Set t = Set();
                    std::set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),std::inserter(t,t.begin())) ;
                    s.push(t);
                }
                if(op[0] == 'A'){
                    int id;
                    if(!ID.count(s1))
                        ID[s1] = maxID++;
                    id = ID[s1];
                    s2.insert(id);
                    s.push(s2);
                }
            }
            cout<<s.top().size()<<endl;
        }
        cout<<"***\n";
    }
    return 0;
}
