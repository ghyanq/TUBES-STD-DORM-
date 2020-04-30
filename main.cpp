#include "head.h"

using namespace std;

int main(){
    list_stud studList;
    list_dorm dormList;
    createListStud(studList);
    createListDorm(dormList);

    /** Student List */
    infotype_stud stud;
    /** insert Ali */
    stud.sid = "1301171234";
    stud.name = "Ali";
    stud.gender = "Male";
    insertLastStud(studList,allocate_stud(stud));
    /** insert Shinta */
    stud.sid = "1301164321";
    stud.name = "Shinta";
    stud.gender = "Female";
    insertLastStud(studList,allocate_stud(stud));
    /** insert Bagas */
    stud.sid = "1301186789";
    stud.name = "Bagas";
    stud.gender = "Male";
    insertLastStud(studList,allocate_stud(stud));

    /** Dorm List */
    infotype_dorm dorm;
    /** insert Liki */
    dorm.dorm_name = "Liki";
    dorm.helpdesk = "Pak Bambang";
    dorm.capacity = 100;
    insertLastDorm(dormList,allocate_dorm(dorm));
    /** insert Leti */
    dorm.dorm_name = "Leti";
    dorm.helpdesk = "Bu Endang";
    dorm.capacity = 120;
    insertLastDorm(dormList,allocate_dorm(dorm));


    cout << "Current List:" << endl;
    printDorm(dormList);
    printStud(studList);
    printRelation(studList,dormList);
    cout << endl;

    cout << "Connected the student with dorm!"<<endl;
    setDorm(studList,dormList,"1301171234","Liki");
    setDorm(studList,dormList,"1301164321","Leti");
    setDorm(studList,dormList,"1301186789","Liki");

    cout << "\nAfter connected the student with dorm!"<<endl;
    printRelation(studList,dormList);

    cout << "\nDisconnected the student with dorm!"<<endl;
    unsetDorm(studList,dormList,"1301171234","Liki");
    cout << "\nAfter disconnected the student with dorm!"<<endl;
    printRelation(studList,dormList);

    cout << "\nDelete the dorm!"<<endl;
    del_dorm(studList,dormList,"Leti");

    cout << "\nAfter Delete the dorm!"<<endl;
    printDorm(dormList);

    printRelation(studList,dormList);

    return 0;
};
