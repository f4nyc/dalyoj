#include<iostream>
#include<cstring>
#include<iomanip>
#define maxed 150000
const double eps = 1e-5;
using namespace std;

struct Student{
    int removed;
    char sid[15];
    int cid;
    char name[15];
    unsigned int score[5];
}s[maxed];
int n;
const char* course_name[] = {"Chinese", "Mathematics", "English", "Programming"};

void menu();
void Add();
void Remove();
void Query();
int  Rank(int );
void Stat();

int main(){
    while(1){
        int choice;
        menu();
        cin>>choice;
        if(choice == 0)break;
        if(choice == 1)Add();
        if(choice == 2)Remove();
        if(choice == 3)Query();
        if(choice == 4)cout<<"Showing the ranklist hurts students' self-esteem. Don't do that.\n";
        if(choice == 5)Stat();
    }
    return 0;
}

void menu(){
    cout<<"Welcome to Student Performance Management System (SPMS).\n"
        <<"\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n";
}

void Add(){
    while(1){
        cout<<"Please enter the SID, CID, name and four scores. Enter 0 to finish.\n";
        cin>>s[n].sid;
        if(!strcmp(s[n].sid,"0"))break;
        int ok=0;
        for(int i = 0;i<n;i++)
            if(!s[i].removed)
            if(!strcmp(s[i].sid,s[n].sid)){
                cout<<"Duplicated SID.\n";
                ok = 1;
                break;
            }
        s[n].removed=0;
        cin>>s[n].cid>>s[n].name>>s[n].score[0]>>s[n].score[1]>>s[n].score[2]>>s[n].score[3];
        s[n].score[4]=s[n].score[0]+s[n].score[1]+s[n].score[2]+s[n].score[3];
        if(!ok)n++;
    }
    return;
}

void  Remove(){
    char id[15];
    while(1){
        cout<<"Please enter SID or name. Enter 0 to finish.\n";
        cin>>id;
        int num=0;
        if(!strcmp(id,"0"))break;
        for(int i = 0;i<n;i++)
            if(!s[i].removed)
            if(!strcmp(s[i].sid,id) || !strcmp(s[i].name,id)){
                s[i].removed = 1;
                num++;
            }
        cout<<num<<" student(s) removed.\n";
    }
}

void Query(){
    char id[15];
    int num=0;
    while(1){
        cout<<"Please enter SID or name. Enter 0 to finish.\n";
        cin>>id;
        if(!strcmp(id,"0"))break;
        for(int i = 0;i<n;i++)
            if(!s[i].removed)
                if(!strcmp(s[i].sid,id) || !strcmp(s[i].name,id)){
                    cout<<Rank(i)<<' '<<s[i].sid<<' '<<s[i].cid<<' '<<s[i].name<<' ';
                    for(int j=0;j<5;j++)cout<<s[i].score[j]<<' ';
                    cout<<setiosflags(ios::fixed)<<setprecision(2)<<s[i].score[4]/4.0+eps<<endl;
                }
    }
}

int  Rank(int i){
    int rank = 1;
    for(int j=0;j<n;j++)
        if(!s[j].removed)
            if(s[j].score[4]>s[i].score[4])rank++;
    return rank;
}

void Stat(){
    int cid,num = 0,passed[4] = {0},oa[5]={0};
    double average[4]={0};
    cout<<"Please enter class ID, 0 for the whole statistics.";
    cin>>cid;
    for(int i = 0;i<n;i++)
        if(!s[i].removed)
            if(s[i].cid == cid || cid == 0){
                num++;
                int k=0;
                for(int j = 0;j<4;j++){
                    average[j] += s[i].score[j];
                    if(s[i].score[j] >= 60){passed[j]++;k++;}
            }
            oa[k]++;
        }
    for(int i = 0;i<4;i++)
        cout<<endl<<course_name[i]<<endl<<"Average Score: "<<setiosflags(ios::fixed)
            <<setprecision(2)<<average[i]/num+eps<<
             "\nNumber of passed students: "<<passed[i]<<"\nNumber of failed students: "<<num-passed[i]<<endl;
    cout<<"\nOverall:\n"<<"Number of students who passed all subjects: "<<oa[4]
        <<"\nNumber of students who passed 3 or more subjects: "<<oa[4]+oa[3]
        <<"\nNumber of students who passed 2 or more subjects: "<<oa[4]+oa[3]+oa[2]
        <<"\nNumber of students who passed 1 or more subjects: "<<oa[4]+oa[3]+oa[2]+oa[1]
        <<"\nNumber of students who failed all subjects: "<<oa[0]<<endl<<endl;
}
