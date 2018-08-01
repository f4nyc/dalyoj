#include<iostream>
#include <map>
#include <string>
using namespace std;
map<string,long> value;
map<char,long> arry;
bool bug = false;
long get_value(string temp ){
    if(temp.find("[") == string::npos)
        return stol(temp);
    else if(temp.find("[") != temp.rfind("[")){
        string name;
        long index;
        int low = temp.find("[");
        int upper = temp.rfind("]");
        name = temp.substr(0,low);
        index = get_value(temp.substr(low+1,upper-low-1));
        temp = name + "["+ to_string(index) + "]"; 
    }
    if(value.count(temp))
        return value[temp];
    else {
        bug = true;
        return 0;
    }
}
void assign(string temp){
    unsigned int pos = temp.find("="); 
    string left = temp.substr(0,pos);
    string right = temp.substr(pos+1);
    long index = get_value(left.substr(2,left.length()-3));
    long val = 0;
    if(arry[left[0]] <= index)
        bug = true;
    left = left.substr(0,1)+"["+to_string(index)+"]";
    val = get_value(right);
    if(!bug) 
        value[left]=val;
}
int main(){
    string temp;
    getline(cin,temp);
    while(temp != "."){
        int turn = 0;
        bug= false;
        value.clear();
        arry.clear();
        while(temp != "."){
            if(bug){
                getline(cin,temp);
                continue;
            }
            if(temp.find("=") != string::npos){
                assign(temp);
            }
            else{
                arry[temp[0]] = stol(temp.substr(2));
            }
            turn++;
            getline(cin,temp);
        }
        if(!bug)
            turn = 0;
        cout<<turn<<endl;
        getline(cin,temp);
    }
    return 0;
}
