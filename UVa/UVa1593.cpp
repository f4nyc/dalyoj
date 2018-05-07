#include<iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
const int MAXR = 1000;
const int MAXC = 180;
string s[MAXR][MAXC];
int maxlen[MAXC];
int len[MAXR]; 
int main(){
    string temp;
    stringstream sin;
    int r = 0, c = -1;
    while(getline(cin, temp)){
        sin.clear();
        sin.str(temp);
        while(sin>>s[r][++c])
            if(s[r][c].length() > maxlen[c])
                maxlen[c] = s[r][c].length();       
        len[r] = c;
        r++;
        c = -1;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < len[i] - 1; ++j)
            cout<<left<<setw(maxlen[j]+1)<<s[i][j];
        cout<<s[i][len[i]-1]<<endl;
    }
    return 0;
}
