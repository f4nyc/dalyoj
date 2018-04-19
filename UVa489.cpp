#include<iostream>
#include<cstring>
using namespace std;
char a[100],a1[100];
bool win,lose;
int lefted,chance;
void judge(char* a,char* a1);
int main(){
  int rnd;
  while(cin>>rnd&&rnd != -1){
    cin>>a>>a1;
    win = 0;
    lose = 0;
    lefted = strlen(a);
    chance = 7;
    judge(a,a1);
    cout<<"Round "<<rnd<<endl;
    if(win){
      cout<<"You win.\n";
      continue;
    }
    if(lose){
      cout<<"You lose.\n";
      continue;
    }
    cout<<"You chickened out.\n";
  }
  return 0;
}
void judge(char *a,char *a1){
  for(int i = 0;i<strlen(a1);i++){
    int ok=1;
    for(int j = 0;j<strlen(a);j++){
      if(a1[i] == a[j]){
        lefted--;
        a[j] = ' ';
        ok = 0;
      }
    }
    if(ok)chance--;
    if(!lefted)win = 1;
    if(!chance)lose = 1;
    if(win || lose)break;
  }
};

