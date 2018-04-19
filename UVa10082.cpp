#include<iostream>
using namespace std;
int main(){
	string s="1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c;
	while(cin.get(c)){
		if(s.find(c)!=-1)cout<<s[s.find(c)-1];
		else cout<<c;
	}
	return 0;
}
