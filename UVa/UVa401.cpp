#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
	string s[4]{" -- is not a palindrome."," -- is a regular palindrome."," -- is a mirrored string."," -- is a mirrored palindrome."};
	string ch="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
	string rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	string a="";
	while(getline(cin,a)){
		int k=a.length();
		int p=3;
		for(int i=0;i<k;i++){
			if(a[i]!=a[k-1-i]){
				p=2;
				break;
			}
		}
		for(int j=0;j<k;j++){
			if(a[j]!=rev[ch.find(a[k-1-j])]){
				if(p==3)p=1;
				else p=0;
				break;
			}
		}
		if(a!="")cout<<a<<s[p]<<endl<<endl;
	}
    return 0;
}


