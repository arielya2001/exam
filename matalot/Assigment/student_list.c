#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_list.h"

// נגדיר מבנה פנימי לרשימת הסטודנטים.
// מבנה זה אינו גלוי בקובץ .h, וכך המשתמש לא רואה אותו.
typedef struct Student {
    char name[50];
    int id;
    struct Student* next;
} Student;

struct StudentList {
    Student* head;
};

// יוצר רשימה חדשה
StudentListHandle createStudentList() {
    StudentListHandle list = (StudentListHandle)malloc(sizeof(*list));
    if (list) {
        list->head = NULL;
    }
    return list;
}

// משמיד רשימה קיימת
void destroyStudentList(StudentListHandle list) {
    if (!list) return;
    
    Student* current = list->head;
    while (current) {
        Student* toDelete = current;
        current = current->next;
        free(toDelete);
    }
    free(list);
}

// מוסיף סטודנט חדש לרשימה
void addStudent(StudentListHandle list, const char* name, int id) {
    if (!list) return;

    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) return; // במצב אמת ניתן לבדוק טיפול שגיאות
    
    strncpy(newStudent->name, name, sizeof(newStudent->name));
    newStudent->name[sizeof(newStudent->name) - 1] = '\0'; // הבטחת סיום מחרוזת
    newStudent->id = id;
    newStudent->next = list->head;
    list->head = newStudent;
}

// מוחק סטודנט מהרשימה לפי מזהה
int removeStudent(StudentListHandle list, int id) {
    if (!list) return 0;
    
    Student* current = list->head;
    Student* prev = NULL;

    while (current) {
        if (current->id == id) {
            // מצאנו את הסטודנט להסרה
            if (prev) {
                prev->next = current->next;
            } else {
                list->head = current->next;
            }
            free(current);
            return 1; // הצלחה
        }
        prev = current;
        current = current->next;
    }
    return 0; // לא נמצא
}

// מחפש סטודנט לפי מזהה
int findStudent(StudentListHandle list, int id, char* outName) {
    if (!list) return 0;
    
    Student* current = list->head;
    while (current) {
        if (current->id == id) {
            // מעתיקים את השם למשתנה שהתקבל
            strcpy(outName, current->name);
            return 1; // נמצא
        }
        current = current->next;
    }
    return 0; // לא נמצא
}
