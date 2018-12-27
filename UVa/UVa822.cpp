#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
struct Topic {
  public:
    Topic() = default;
    Topic(int tid, int num, int next, int service, int interval)
        : tid(tid), num(num), next(next), service(service),
          interval(interval){};
    int update(int time) {
        num--;
        int ret = max(next, time) + service;
        next += interval;
        return ret;
    }
    bool avaliable(int time) { return num > 0 && next <= time; }

    int tid, num, next, service, interval;
};
struct Personnel {
  public:
    Personnel() = default;
    Personnel(int pid, int num, vector<int> topics)
        : pid(pid), num(num), topics(std::move(topics)), avaliable(0),
          last(0){};
    int pid, num, avaliable, last;
    std::vector<int> topics;
};
int solve(unordered_map<int, Topic> topic, vector<Personnel> person) {
    int time = 0;
    priority_queue<int, vector<int>, std::greater<int>> pq;
    for (auto t : topic)
        for (int i = 0; i < t.second.num; ++i)
            pq.push(t.second.next + i * t.second.interval);

    while (!pq.empty()) {
        time = pq.top();
        while (pq.top() == time && !pq.empty())
            pq.pop();
        sort(person.begin(), person.end(), [](Personnel a, Personnel b) {
            return a.last == b.last ? a.pid < b.pid : a.last < b.last;
        });
        for (auto &p : person)
            if (p.avaliable <= time)
                for (auto t : p.topics)
                    if (topic[t].avaliable(time)) {
                        p.last = max(p.avaliable, topic[t].next);
                        p.avaliable = topic[t].update(p.avaliable);
                        pq.push(p.avaliable);
                        break;
                    }
    }
    return time;
}
int main() {
    int req, per, turn = 1;
    cin >> req;
    vector<Personnel> person;
    unordered_map<int, Topic> topic;
    while (req) {
        for (int i = 0; i < req; ++i) {
            int tid, num, first, service, interval;
            cin >> tid >> num >> first >> service >> interval;
            topic.insert({tid, {tid, num, first, service, interval}});
        }
        cin >> per;
        for (int i = 0; i < per; ++i) {
            int pid, num, topic;
            cin >> pid >> num;
            vector<int> set;
            for (int i = 0; i < num; ++i) {
                cin >> topic;
                set.push_back(topic);
            }
            person.emplace_back(pid, num, std::move(set));
        }
        cout << "Scenario " << turn++ << ": All requests are serviced within "
             << solve(std::move(topic), std::move(person)) << " minutes.\n";
        cin >> req;
    }
    return 0;
}
