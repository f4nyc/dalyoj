#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;
const int RANK = 71;
const int LAST = 69;
const int MAXNUM = 145;

double money[RANK];
class Player{
    public:
        string name = "", place = "";
        int rd[4] = {}, cnt = 0, total = 0, rank = 0;
        bool pro = true, dq = false, havemoney = false;
        double won = 0;
        bool equal( const Player & that){
            return ( this->rd[0] + this->rd[1] ) == ( that.rd[0] + that.rd[1] );
        }
        friend bool operator < (const Player &a, const Player &b){
            if(a.cnt != b.cnt)
                return a.cnt > b.cnt;
            return a.total != b.total ? a.total < b.total : a.name < b.name;
        }
        friend istream &  operator >> ( istream& in, Player & p){
            string temp;
            getline(in, temp);
            p.name = temp.substr(0,20);
            if( p.name.find("*") < p.name.length())
                p.pro = false;
            for (int i = 0; i < 4; ++i) {
                if(temp.substr(20+i*3,3) == " DQ"){
                    p.dq = true;
                    break;
                }
                p.cnt = i+1;
                p.rd[i] = stoi(temp.substr(20 + i*3,3));
                p.total += p.rd[i];
            }
            return in;
        }
        friend ostream & operator << (ostream & out, Player & p){
            out<<p.name<<' '<<setw(10)<<left<<p.place;
            for ( int i = 0; i < p.cnt; ++i) 
                out<<setw(5)<<left<<p.rd[i]; 
            for( int i = p.cnt; i <4; i++)
                out<<setw(5)<<left<<" "; 
            if(p.dq)
                out<<"DQ";
            else if( p.havemoney)
                out<<left<<setw(10)<<p.total<<"$"<<fixed<<setprecision(2)<<setw(9)<<right<<p.won/100;
            else 
                out<<p.total;
            out<<endl;
            return out;
        }
        friend bool operator == ( const Player &a, const Player &b){
            return ( a.cnt == b.cnt ) && ( a.total == b.total );
        }
};
bool PlayerCMP(const Player & a, const Player & b){
    if( a.cnt < 2)
        return false;
    if( b.cnt < 2)
        return true;
    return (a.rd[0]+a.rd[1]) < (b.rd[0]+b.rd[1]);
}


void print( Player * group, int num ){

    cout<<"Player Name          Place     RD1  RD2";
    cout<<"  RD3  RD4  TOTAL     Money Won\n";
    cout<<"---------------------------------------";
    cout<<"--------------------------------\n";
    int index = 1; 
    int i = 0;
    while(i < num){
        if(group[i].dq){
            cout<<group[i++];
            continue;
        }
        int j = i, count = 0;
        while(group[j] == group[i] && j < num){
            group[j].place = to_string(i+1);
            if( group[j++].pro)
                count++;
        }
        for (int j = 1; j < count; ++j) {
            money[index] += money[j + index]; 
        }
        if(count)
            money[index] /= count; 
        for(;i < j; i++){
            if(group[i].pro)
                if(index <=70 && !group[i].dq){
                    group[i].havemoney = true;
                    group[i].won = money[0]*money[index];
                    if(count > 1)
                        group[i].place += "T";
                }
            cout<<group[i];
        }
        index += count;

    } 
}
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0); 
    int turn,num; 
    cin>>turn;
    while(turn--){
        Player group[MAXNUM];
        for(int i = 0; i < RANK; i++)
            cin>>money[i];
        cin>>num;
        cin.get();
        for (int i = 0; i < num; ++i) 
            cin>>group[i];
        sort( group,group + num,PlayerCMP );
        int index = LAST;
        while( group[++index].equal(group[LAST]) );
        sort( group, group + index );
        print(group,index);
        if(turn)cout<<endl;
    }
    return 0;
}
