#include<iostream>
#include <queue>
using namespace std;
int main(){
    int n;
    queue<int> q;
    while(cin>>n && n){
        cout<<"Discarded cards:"; 
        for (int i = 1; i <= n; ++i)
            q.push(i);
        while(q.size() > 1){
            if(q.front() != 1)
                cout<<',';
            cout<<' '<<q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout<<"\nRemaining card: "<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
