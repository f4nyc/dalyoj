#include<iostream>
#include <algorithm>
using namespace std;
const int MAXN = 105;
int xList[2*MAXN];
class Building{
    int id, x, y, w, h, r;
    public:
    friend istream & operator>>(istream & in, Building & b){
        in>>b.x>>b.y>>b.w>>b.h>>b.h;
        b.r = b.x + b.w;
        return in;
    };
    friend bool operator<(const Building & a, const Building & b){
        return a.x != b.x ? a.x < b.x : a.y < b.y;
    }
    void setid(int id){
        this->id = id;
    };
    int getid() const{
        return id;
    };
    int getx() const{
        return x;
    };
    int getr() const{
        return r;
    };
    bool contain(int m) const{
        return x <= m && r > m;
    };
    bool cover( const Building & b, int m){
        return this->contain(m) && b.contain(m) && this->y < b.y && this->h >= b.h; 
    }
    private:
} buildings[MAXN];

bool visible(int i, int m, int n){
    if(!buildings[i].contain(m))
        return false;
    for (int k = 0; k < n; ++k) 
        if(buildings[k].cover(buildings[i], m))
            return false;
    return true;
}

void solve(int n){
    sort(buildings, buildings + n);
    sort(xList, xList + 2*n);
    int m = unique(xList, xList + 2*n) - xList;
    bool flag =false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m-1; j++){
            int middle = ( xList[j] + xList[j+1] ) / 2;
            if(visible(i, middle, n)){
                if(flag)
                    cout<<' ';
                cout<<buildings[i].getid();
                flag = true;
                break;
            }
        }
};
int main(){
    ios::sync_with_stdio(0);
    int n, city = 0;
    while(cin>>n && n != 0){
        for (int i = 0; i < n; ++i) {
            cin>>buildings[i];
            xList[2*i] = buildings[i].getx();
            xList[2*i+1] = buildings[i].getr();
            buildings[i].setid(i+1);
        }
        if(city++)
            cout<<endl;
        cout<<"For map #"<<city<<", the visible buildings are numbered as follows:\n";
        solve(n);
        cout<<endl;
    }
    return 0;
}
