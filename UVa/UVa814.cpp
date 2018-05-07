#include<iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;
using SendList = vector< map<string, vector<string> > >;
void PraseAddress(const string &addr, string & mta){
    int index = addr.find("@");
    mta = addr.substr(index+1);
}
int main(){
    set<string> address;
    string from, mta, mtaSend, user;
    int num;
    while(cin >> from && from !="*"){
        cin>>mta>>num;
        while(num--){
            cin>>user;
            address.insert(user+"@"+mta);
        }
    }
    while(cin >> from && from !="*"){
        string dest;
        vector<string> mtaList;
        map<string,vector<string> > userList;
        set<string> valid;
        PraseAddress(from, mtaSend);
        while(cin >> dest && dest !="*"){
            PraseAddress(dest,mta);
            if(valid.count(dest))
                continue;
            valid.insert(dest);
            if(!userList.count(mta)){
                mtaList.push_back(mta);
                userList.insert(make_pair(mta, vector<string> {dest}));
            }
            else
                userList[mta].push_back(dest);
        }
        cin.get();
        string data = "", temp;
        while(getline(cin, temp) && temp[0] != '*' )
            data += "     " + temp + "\n"; 
        for (const string & mtaRecv : mtaList){
            bool flag = false;
            cout<<"Connection between "<<mtaSend<<" and "<<mtaRecv<<endl
                <<"     HELO "<<mtaSend<<endl
                <<"     250\n"
                <<"     MAIL FROM:<"<<from<<">\n"
                <<"     250\n";
            for (const string & dest : userList[mtaRecv]) {
                cout<<"     RCPT TO:<"<<dest<<">\n";
                if(address.count(dest)){
                    flag =true;
                    cout<<"     250\n";
                }
                else
                        cout<<"     550\n";
            }
            if(flag)
                cout<<"     DATA\n     354\n"
                    <<data
                    <<"     .\n     250\n";
            cout<<"     QUIT\n     221\n";
        }
    }
        return 0;
    }
