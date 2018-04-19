#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main(){
    string a="CHON";
    float b[4]={12.01,1.008,16.00,14.01};
    int n;
    cin>>n;
    while(n--){
        string s;
        float m=0;
        cin>>s;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                int j=i,k=0;
                while(isdigit(s[++j])){
                    k*=10;
                    k+=s[j]-'0';
                }
                if(k)m+=k*b[a.find(s[i])];
                else m+=b[a.find(s[i])];
			}
		}
        cout.precision(3);
        cout<<fixed<<m<<endl;
	}
	return 0;
}
