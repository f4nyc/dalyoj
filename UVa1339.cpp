#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s;
	while(cin>>s){
		int cnt1[26]={0},cnt2[26]={0};
	    for(int i=0;i<s.length();i++)
			cnt1[(s[i]-'A')]++;
		cin>>s;
		for(int i=0;i<s.length();i++)
            cnt2[(s[i]-'A')]++;
        sort(cnt1,cnt1+26);
        sort(cnt2,cnt2+26);
        int ok=1;
        for(int i=0;i<26;i++){
            if(cnt1[i]!=cnt2[i])ok=0;
        }
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}