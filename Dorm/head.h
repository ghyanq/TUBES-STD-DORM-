#include <iostream>
#include <string>

using namespace std;

struct infotype_stud {
    string sid;
    string name;
    string gender;
};
struct infotype_dorm {
    string dorm_name;
    string helpdesk;
    int capacity;
};
typedef struct elm_stud*adr_stud;
typedef struct elm_dorm*adr_dorm;

struct elm_stud {
    infotype_stud info;
    adr_stud next;
    adr_dorm nextDorm;
};
struct elm_dorm {
    infotype_dorm info;
    adr_dorm next;
};

struct list_stud {
    adr_stud first;
};
struct list_dorm {
    adr_dorm first;
};

void createListStud(list_stud &S);
void createListDorm(list_dorm &D);

adr_stud allocate_stud(infotype_stud x);
adr_dorm allocate_dorm(infotype_dorm x);

void deleteDorm(list_dorm &L, adr_dorm Q);
adr_dorm search_dorm(list_dorm &L, string dorm);

void insertLastStud(list_stud &S, adr_stud P);
void insertLastDorm(list_dorm &D, adr_dorm P);

void setDorm(list_stud &L1, list_dorm L2, string sid, string dorm);
void unsetDorm(list_stud L1, list_dorm L2, string sid, string dorm);
void del_dorm(list_stud L1, list_dorm L2, string dorm);

void printStud(list_stud &S);
void printDorm(list_dorm &D);
void printRelation(list_stud S, list_dorm D);
