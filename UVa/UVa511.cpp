//虽然题目描述复杂但是实际上测试数据最多就是比较到比例这一步。。。。
//按理说lambda要比Cmp类轻巧，但是太乱了十分受不了
#include<iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
using CoorDat = tuple<float,float,float,float>;
using MapDat = tuple<int,CoorDat,int>;
class Cmp{
public:
    Cmp() = default;
    Cmp(float x, float y):x(x),y(y){};
    bool operator () (const MapDat & a, const MapDat & b){ 
        int level_a = get<0>(a), level_b = get<0>(b);
        if(level_a < level_b)
            return true;
        else if(level_a > level_b)
            return false; 
        float dis_a = center_distance(get<1>(a));
        float dis_b = center_distance(get<1>(b));
        if( dis_a > dis_b)
            return true;
        if( dis_a > dis_b)
            return false;
        float ratio_a = ratio(get<1>(a));
        float ratio_b = ratio(get<1>(b));
        if( ratio_a > ratio_b)
            return true;
        if( ratio_a > ratio_b)
            return false;
        dis_a = corner_distance(get<1>(a));
        dis_b = corner_distance(get<1>(b));
        if( dis_a > dis_b)
            return true;
        if( dis_a > dis_b)
            return false;
        return get<0>(get<1>(a)) > get<0>(get<1>(b));

    }
private:
    float x,y;
    float center_distance(const CoorDat & cd){
        float l = get<0>(cd);
        float r = get<1>(cd);
        float u = get<2>(cd);
        float b = get<3>(cd);
        return powf(2*x-l-r, 2)+powf(2*y-u-b,2);
    }
    float corner_distance(const CoorDat & cd){
        float r = get<1>(cd);
        float b = get<3>(cd);
        return powf(2*x-r, 2)+powf(2*y-b,2);
    }
    float ratio(const CoorDat & cd){
        float l = get<0>(cd);
        float r = get<1>(cd);
        float u = get<2>(cd);
        float b = get<3>(cd);
        return fabsf(0.75 - (r-l)/(u-b));
    }
};
class Location{
    public:
        Location() = default;
        Location(float x,float y):x(x),y(y){};
        void contain_in(int level, const CoorDat & md, int id){
            containers.emplace_back(level,md,id); 
        }
        void sort(){
            std::sort(containers.begin(),containers.end(),Cmp(x,y));
        }
        bool is_located(){
            return containers.size();
        }
        pair<bool,int> get_id(int level){
            int id;
            bool flag = false;
            for(auto & t : containers){
                if(get<0>(t) == level)
                    flag = true;
                if(get<0>(t) > level)
                    break;
                id = get<2>(t);
            }
            return make_pair(flag,id);
        }
        float x,y;
    private:
        vector<MapDat> containers;
};
class Map{
    public:
        Map(float l, float r,float u,float b,string reg):l(l),r(r),u(u),b(b),area((r-l)*(u-b)),region(reg){}
        bool operator < (const Map & that){
            return this->area > that.area;
        }
        bool contain(const Location * loc){
            return loc->x > l && loc->x < r && loc->y < u && loc->y > b;
        }
        CoorDat get_data()const{
            return make_tuple(l,r,u,b);
        }
        float get_area() const{
            return area;
        }
        string region;
    private:
        float l,r,u,b,area;
};
vector<Map> maps;
map<string,Location> locations;
void read_map(){
    string word;
    float r,l,u,b;
    cin>>word>>word;
    while(word != "LOCATIONS"){
        cin>>l>>b>>r>>u;  
        if(l > r)swap(l,r);
        if(b > u)swap(b,u);
        maps.emplace_back(l,r,u,b,word);
        cin>>word;
    }
    sort(maps.begin(), maps.end());
}
void read_location(){
    string word;
    float x,y;
    cin>>word;
    while(word != "REQUESTS"){
        cin>>x>>y;
        locations.emplace(word,Location(x,y));
        cin>>word;
    }
}
void locate_maps(Location * l){
    int id = 0, level = 0;
    float area = 0;
    for(auto & m : maps){
        if(m.contain(l)){
            if(m.get_area() != area){
                level++;
                area = m.get_area();
            }
            l->contain_in(level,m.get_data(),id);
        }
        id++;
    }
    l->sort();
}
void read_requst(){
    string loc;
    int level;
    Location * l = nullptr;
    cin>>loc;
    while( loc != "END"){
        cin>>level;
        cout<<loc<<" at detail level "<<level;
        if(locations.count(loc)){
            l = & locations[loc];
            if(!l->is_located())
                locate_maps(l);
            if(l->is_located()){
                pair<bool,int> res = l->get_id(level);
                if(!res.first)
                    cout<<" no map at that detail level;";
                cout<<" using "<<maps[res.second].region<<endl; 
            }
            else
                cout<<" no map contains that location\n";
        }
        else
            cout<<" unknown location\n";
        cin>>loc;
    }
};
int main(){
    read_map();
    read_location();
    read_requst();
    return 0;
}
