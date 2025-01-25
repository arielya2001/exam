#include <stdio.h>
#include "student_list.h"

int main() {
    // יוצרים שתי רשימות שונות
    StudentListHandle listA = createStudentList();
    StudentListHandle listB = createStudentList();

    // מוסיפים סטודנטים לרשימה A
    addStudent(listA, "Alice", 101);
    addStudent(listA, "Bob",   102);
    
    // מוסיפים סטודנטים לרשימה B
    addStudent(listB, "Charlie", 201);
    addStudent(listB, "Diana",   202);

    // הדגמת חיפוש ברשימה A
    char foundName[50];
    int result = findStudent(listA, 102, foundName);
    if (result) {
        printf("נמצא סטודנט (ברשימה A): %s עם מזהה 102\n", foundName);
    } else {
        printf("סטודנט עם מזהה 102 לא נמצא ברשימה A\n");
    }

    // נסיר סטודנט ממזהה 201 ברשימה B
    if (removeStudent(listB, 201)) {
        printf("סטודנט עם מזהה 201 הוסר בהצלחה מרשימה B.\n");
    } else {
        printf("סטודנט עם מזהה 201 לא נמצא ברשימה B.\n");
    }

    // משחררים זיכרון בסוף
    destroyStudentList(listA);
    destroyStudentList(listB);

    return 0;
}
