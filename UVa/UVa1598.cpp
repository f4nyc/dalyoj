#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using intPair = pair<int, int>;
int main() {
  int n;
  cin.sync_with_stdio(false);
  bool flag = true;
  while (cin >> n) {
    if (!flag) {
      cout << endl;
    }
    flag = false;
    priority_queue<intPair, vector<intPair>, function<bool(intPair, intPair)>>
        ask([](intPair a, intPair b) {
          return a.first == b.first ? a.second > b.second : a.first > b.first;
        });
    priority_queue<intPair, vector<intPair>, function<bool(intPair, intPair)>>
        bid([](intPair a, intPair b) {
          return a.first == b.first ? a.second > b.second : a.first < b.first;
        });
    map<int, intPair> orders;
    map<int, int> bidQuotes, askQuotes;
    string demand;
    int p, q, i;
    int bidPrice = 0, askPrice = 99999;
    bidQuotes[bidPrice] = 0;
    askQuotes[askPrice] = 0;
    for (int indx = 1; indx <= n; indx++) {
      cin >> demand;
      if (demand == "BUY") {
        cin >> q >> p;
        while (q > 0 && !ask.empty() && p >= ask.top().first) {
          int price = ask.top().first;
          i = ask.top().second;
          int quote = min(q, orders[i].first);
          orders[i].first -= quote;
          askQuotes[price] -= quote;
          q -= quote;
          if (quote > 0) {
            cout << "TRADE " << quote << " " << price << endl;
          }
          if (orders[i].first == 0) {
            ask.pop();
          }
        }
        if (q > 0) {
          bid.push(make_pair(p, indx));
          bidQuotes[p] += q;
          bidPrice = bid.top().first;
          orders[indx] = make_pair(q, p);
        }

      } else if (demand == "SELL") {

        cin >> q >> p;
        while (q > 0 && !bid.empty() && p <= bid.top().first) {
          int price = bid.top().first;
          i = bid.top().second;
          int quote = min(q, orders[i].first);
          orders[i].first -= quote;
          bidQuotes[price] -= quote;
          q -= quote;
          if (quote > 0) {
            cout << "TRADE " << quote << " " << price << endl;
          }
          if (orders[i].first == 0) {
            bid.pop();
          }
        }
        if (q > 0) {
          ask.push(make_pair(p, indx));
          askQuotes[p] += q;
          askPrice = ask.top().first;
          orders[indx] = make_pair(q, p);
        }
      } else {
        cin >> i;
        q = orders[i].first;
        p = orders[i].second;
        orders[i].first = 0;
        if (askQuotes[p] != 0)
          askQuotes[p] -= q;
        if (bidQuotes[p] != 0)
          bidQuotes[p] -= q;
      }
      while (!ask.empty() && orders[ask.top().second].first == 0)
        ask.pop();
      while (!bid.empty() && orders[bid.top().second].first == 0)
        bid.pop();
      bidPrice = bid.empty() ? 0 : bid.top().first;
      askPrice = ask.empty() ? 99999 : ask.top().first;
      cout << "QUOTE " << bidQuotes[bidPrice] << ' ' << bidPrice << " - "
           << askQuotes[askPrice] << ' ' << askPrice << endl;
    }
  }
  return 0;
}
