/*
 * 暴力模拟
 * 优化：
 *      1.优先级低于给定任务的不用考虑
 *      2.若同优先级仅有给定任务，计算高优先级数量即可
 *      不过数据量不大优化好像没啥用2333333
 */      
#include<iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

int priority[10] = {0};
int solve(queue<pair<int,int>> &q,int job,int m){
    int sum = 0;
    stack<int> max_prio;
    for(int i = job+1; i < 10; i++){
        for(int j = 0; j <priority[i]; j++)
            max_prio.push(i);
        sum += priority[i];
    }
    if(priority[job] == 1){
        return sum+1;
    }
    while(!max_prio.empty()){
        if(q.front().first >= job && q.front().first < max_prio.top())
            q.push(q.front());
        if(q.front().first == max_prio.top())
            max_prio.pop();
        q.pop();
    }
    for(;;){
        pair<int,int> j = q.front();
        if(j.second == m)
            return sum+1;
        if(j.first == job)
            sum++; 
        q.pop();
    }
}
int main(){
    int turn,n,m,job;
    ios::sync_with_stdio(false);
    queue<pair<int,int>> q;
    queue<int> max;
    cin>>turn;
    while(turn--){
        bzero(priority,sizeof(int)*10);
        cin>>n>>m;
        for(int i = 0; i <n; i++){
            int temp;
            cin>>temp;
            priority[temp]++;
            q.push(make_pair(temp,i));
            if(m == i)
                job = temp;
        }
        cout<<solve(q,job,m)<<endl;
        while(!q.empty())
            q.pop();
    }
    return 0;
}
