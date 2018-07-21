#include<iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    string temp,title,author;
    vector<pair<string,string>> v;
    multimap<string, int> m;            //处理相同title
    set<int> shelved;
    set<int> unshelved;
    getline(cin,temp);
    while(temp != "END"){
        int index = temp.find("by");
        title = temp.substr(0,index-1);
        author = temp.substr(index+3,temp.length());
        v.push_back(make_pair(author,title));
        getline(cin,temp);
    }
    sort(v.begin(),v.end());
    int index = 0;
    for(auto & s : v){
       m.insert(make_pair(s.second,index)); 
       shelved.insert(index++);
    }
    while(cin>>temp){
        if(temp == "END")
            break;
        if(temp == "BORROW"){
            cin.get();
            getline(cin,temp);
            for( auto  book = m.lower_bound(temp); book != m.upper_bound(temp); book++)
                if(shelved.count(book->second)){
                    shelved.erase(shelved.find(book->second));
                    break;
                }


        }
        else if(temp == "RETURN"){
            cin.get();
            getline(cin,temp);
            for( auto  book = m.lower_bound(temp); book != m.upper_bound(temp); book++)
                if(!shelved.count(book->second) & !unshelved.count(book->second)){
                    unshelved.insert(book->second);
                    break;
                }
        }
        else if(temp == "SHELVE"){
            for(auto book : unshelved){
                auto low = shelved.lower_bound(book);
                cout<<"Put "<<v[book].second;
                if(low == shelved.begin())
                    cout<<" first\n";
                else cout<<" after "<<v[*(--low)].second<<endl;
                shelved.insert(book);
            }
            unshelved.clear();
            cout<<"END\n";
        }
    }

    return 0;
}
