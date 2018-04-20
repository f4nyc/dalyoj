#include<iostream>
#include <iomanip>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
const int Maxwidth = 60;
const int Maxnum = 100;
std::string filename[Maxnum];
int main(){
    std::ios::sync_with_stdio(false);
    int num;
    while(cin>>num){
        int i = 0;
        int maxlength = 0;
        while(i < num){
            cin>>filename[i];
            if(filename[i].length() >  maxlength)
                maxlength = filename[i].length();
            i++;
        }
        std::sort(filename,filename + num);
        int cols = (Maxwidth - maxlength) / (maxlength + 2) + 1;
        int rows = (num - 1) / cols + 1;
        i = 60;
        while(i--)
            cout<<'-';
        cout<<endl;
        cout.setf(std::ios::left);
        for(int i = 0; i < rows; i++){
            int j;
            for(j = 0; j < cols-1; j++)
                cout<<std::setw(maxlength + 2)<<filename[i + j*rows];;
            if(num > i + j*rows)
                cout<<std::setw(maxlength)<<filename[i + j*rows];;
            cout<<endl;
        }
    }
    return 0;
}
