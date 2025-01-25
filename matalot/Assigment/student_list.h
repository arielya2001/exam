#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

// הגדרת טיפוס "handle" - מצביע מופשט למבנה רשימה
typedef struct StudentList* StudentListHandle;

/**
 * @brief יוצר רשימה חדשה ומחזיר Handle לשימוש חיצוני
 * @return StudentListHandle המייצג רשימת סטודנטים חדשה
 */
StudentListHandle createStudentList();

/**
 * @brief משמיד רשימת סטודנטים ומשחרר משאבים
 * @param list ה-Handle של רשימת הסטודנטים
 */
void destroyStudentList(StudentListHandle list);

/**
 * @brief מוסיף סטודנט חדש לרשימה
 * @param list ה-Handle של הרשימה
 * @param name שם הסטודנט
 * @param id מזהה הסטודנט
 */
void addStudent(StudentListHandle list, const char* name, int id);

/**
 * @brief מוחק סטודנט מהרשימה לפי מזהה
 * @param list ה-Handle של הרשימה
 * @param id מזהה הסטודנט
 * @return 1 אם המחיקה הצליחה, 0 אם לא נמצא סטודנט
 */
int removeStudent(StudentListHandle list, int id);

/**
 * @brief מחפש סטודנט ברשימה לפי מזהה
 * @param list ה-Handle של הרשימה
 * @param id מזהה הסטודנט
 * @param outName מחרוזת (תוקצה מבחוץ) שאליה יועתק שם הסטודנט
 * @return 1 אם נמצא סטודנט, 0 אחרת
 */
int findStudent(StudentListHandle list, int id, char* outName);

#endif
