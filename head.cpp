#include "head.h"

void createListStud(list_stud &S){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    S.first = NULL;
}
void createListDorm(list_dorm &D){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    D.first = NULL;
}

adr_stud allocate_stud(infotype_stud x) {
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    adr_stud P = new elm_stud;
    P -> info = x;
    P -> next = NULL;
    P -> nextDorm = NULL;
    return P;
}
adr_dorm allocate_dorm(infotype_dorm x) {
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    adr_dorm P = new elm_dorm;
    P -> info = x;
    P -> next = NULL;
    return P;
}

void deleteDorm(list_dorm &L, adr_dorm Q){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    adr_dorm P = L.first;
    while (P != NULL && P -> next != Q) {
        P = P -> next;
    };
    P -> next = Q -> next;
    Q -> next = NULL;
}
adr_dorm search_dorm(list_dorm &L, string dorm){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    adr_dorm Q = L.first;
    while (Q != NULL && Q->info.dorm_name != dorm) {
        Q = Q->next;
    };
    if (Q != NULL){
        return Q;
    } else {
        return NULL;
    }
}
adr_stud search_stud(list_stud &L, string sid){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    adr_stud Q = L.first;
    while (Q != NULL && Q->info.sid != sid) {
        Q = Q->next;
    };
    if (Q != NULL){
        return Q;
    } else {
        return NULL;
    }
}
void insertLastStud(list_stud &S, adr_stud P){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    if (S.first == NULL) {
        S.first = P;
    } else {
        adr_stud Q = S.first;
        while (Q->next != NULL) {
            Q = Q -> next;
        }
        Q -> next = P;
    }
}
void insertLastDorm(list_dorm &D, adr_dorm P){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    if (D.first == NULL) {
        D.first = P;
    } else {
        adr_dorm Q = D.first;
        while (Q->next != NULL) {
            Q = Q -> next;
        }
        Q -> next = P;
    }
}
void setDorm(list_stud &L1, list_dorm L2, string sid, string dorm){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    adr_stud P;
    adr_dorm Q;
    P = search_stud(L1,sid);
    Q = search_dorm(L2, dorm);
    if (P != NULL && Q != NULL){
        P->nextDorm = Q;
    }
}
void unsetDorm(list_stud L1, list_dorm L2, string sid, string dorm){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    adr_stud P;
    adr_dorm Q;
    P = search_stud(L1,sid);
    Q = search_dorm(L2, dorm);
    if (P != NULL && Q != NULL){
        P->nextDorm = NULL;
    }
}
void del_dorm(list_stud L1, list_dorm L2, string dorm){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    adr_stud P;
    adr_dorm Q;
    Q = search_dorm(L2, dorm);
    if (Q != NULL) {
        P = L1.first;
        while (P != NULL){
            if (P->nextDorm == Q){
                P->nextDorm = NULL;
            }
            P = P -> next;
        }
        deleteDorm(L2, Q);
    }
}
void printStud(list_stud &S){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    if (S.first == NULL){
        cout << "Empty List" << endl;
    } else {
        adr_stud P = S.first;
        int i = 1;
        cout << "Student List\n";
        while (P != NULL) {
            cout << i << ". Student ID: " << P->info.sid << "\n   Name: " << P->info.name << "\n   Gender: " << P->info.gender<< endl;
            P = P -> next;
            i++;
        }
        cout<<endl;
    }
}
void printDorm(list_dorm &D){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    if (D.first == NULL){
        cout << "Empty List" << endl;
    } else {
        adr_dorm P = D.first;
        int i = 1;
        cout << "Dorm List\n";
        while (P != NULL) {
            cout << i <<". Dorm Name: "<<P -> info.dorm_name << "\n   Helpdesk: " << P->info.helpdesk << "\n   Capacity: "<< P->info.capacity<< endl;
            P = P -> next;
            i++;
        }
        cout<<endl;
    }
}
void printRelation(list_stud S, list_dorm D){
    /*
    Name : Raden Aria Gusti Aji
    SID : 1301180503
*/

    adr_stud P = S.first;
    int i = 1;
    cout << "Relation List\n";
    while (P != NULL) {
        cout << i << ". " <<P->info.name<<", from dorm : ";
        if(P -> nextDorm != NULL){
            cout<<P -> nextDorm -> info.dorm_name<<endl;
        } else {
            cout<<"Not listed in dorm"<<endl;
        }
        i++;
        P = P -> next;
    }
    cout<<endl;
}
