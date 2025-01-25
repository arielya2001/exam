

#include <stdio.h>
#include <string.h>
#include "strList.h"

#define TRUE 1
#define FALSE 0
/********************************************************************************
 *
 * A StrList library.
 *
 * This library provides a StrList of STRINGS data structure.
 *
 * This library will fail in unpredictable ways when the system memory runs
 * out.
 *
 ********************************************************************************/

/*
 * StrList represents a StrList data structure.
 */
typedef struct _node {
    char *_data;
    struct _node *_next;
} Node;
typedef struct _StrList {
    Node *_head;
    size_t _size;
} StrList;


Node *Node_alloc(const char *data,
                 Node *next) {
    if (data == NULL) return NULL;
    Node *p = (Node *) malloc(sizeof(Node));
    if (p == NULL) return NULL;
    char* newData = (char*)malloc(sizeof(char)*(strlen(data)+1));
    if (newData == NULL) return NULL;
    strcpy(newData, data);
    p->_data = newData;
    p->_next = next;
    return p;
}

void Node_free(Node *node) {
    free(node->_data);
    free(node);
}

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList *StrList_alloc() {
    StrList *p = (StrList *) malloc(sizeof(StrList));
    if (p == NULL) return NULL;
    p->_head = NULL;
    p->_size = 0;
    return p;
}

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList *StrList) {
    if (StrList == NULL) return;
    Node *p1 = StrList->_head;
    Node *p2;
    while (p1) {
        p2 = p1;
        p1 = p1->_next;
        Node_free(p2);
    }
    free(StrList);

}

/*
 * Returns the number of elements in the StrList.
 */
size_t StrList_size(const StrList *StrList) {
    if (StrList == NULL) { return 0; }
    return StrList->_size;
}

/*
 * Inserts an element in the end of the StrList.
 */
void StrList_insertLast(StrList *StrList,
                        const char *data) {
    Node *newNode = Node_alloc(data, NULL);
    if (newNode == NULL) { printf("Node alloc failed"); return; }
    Node *p = StrList->_head;
    if (p == NULL) {
        StrList->_head = newNode;
        StrList->_size++;
        return;
    }
    while (p->_next) {
        p = p->_next;
    }
    p->_next = newNode;
    StrList->_size++;
}

/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList *StrList,
                      const char *data, int index) {

    if (index < 0 || index > StrList->_size) return;
    if (index == 0) {
        Node *newNode = Node_alloc(data, StrList->_head);
        StrList->_head = newNode;
        StrList->_size++;
    } 
    else if (index == StrList->_size) {
        StrList_insertLast(StrList, data);
    }
    else {
        Node *p = StrList->_head;
        for (int i = 0; i < index - 1; i++) {
            p = p->_next;
        }
        Node *newNode = Node_alloc(data, p->_next);
        p->_next = newNode;
        StrList->_size++;
    }
}

/*
 * Returns the StrList first data.
 */
char *StrList_firstData(const StrList *StrList) {
    if (StrList->_head == NULL) { return NULL; }
    return StrList->_head->_data;
}

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList *StrList) {
    if (StrList->_head == NULL) { printf("\n"); return; }
    Node *p = StrList->_head;
    printf("%s", p->_data);
    p = p->_next;
    while (p) {
        printf(" %s", p->_data);
        p = p->_next;
    }
    printf("\n");
}

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList *Strlist, int index) {
    if (index < 0 || index >= Strlist->_size) return;
    Node *p = Strlist->_head;
    for (int i = 0; i < index; i++) {
        p = p->_next;
    }
    printf("%s\n", p->_data);
}

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList *Strlist) {
    int len = 0;
    Node *p = Strlist->_head;
    while (p) {
        len += strlen(p->_data);
        //printf("len: %lu\n",strlen(p->_data));
        //for (int i = 0; i < strlen(p->_data); i++) { printf("%d\n",p->_data[i]);}
        p = p->_next;
    }
    return len;
}

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList *StrList, const char *data) {
    int count = 0;
    Node *p = StrList->_head;
    while (p) {
        if (strcmp(p->_data, data) == 0) {
            count++;
        }
        p = p->_next;
    }
    return count;
}

/*
	Given a string and a list, remove all the appearances of this string in the list.
*/
void StrList_remove(StrList *StrList, const char *data) {
    Node *newHead;
    while (StrList->_head != NULL && strcmp(StrList->_head->_data, data) == 0) {
        newHead = StrList->_head->_next;
        Node_free(StrList->_head);
        StrList->_head = newHead;
        StrList->_size--;
    }

    Node *pre = StrList->_head;
    while (pre) {
        Node *p = pre->_next;
        while (p != NULL && strcmp(p->_data, data) == 0) {
            pre->_next = p->_next;
            Node_free(p);
            p = pre->_next;
            StrList->_size--;
        }
        pre = pre->_next;
    }
}

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList *StrList, int index) {
    if (index < 0 || index >= StrList->_size) return;
    if (index == 0) {
        Node *p = StrList->_head;
        StrList->_head = p->_next;
        Node_free(p);
        StrList->_size--;
    } else {
        Node *p = StrList->_head;
        for (int i = 0; i < index - 1; i++) {
            p = p->_next;
        }
        Node *next = p->_next;
        p->_next = next->_next;
        Node_free(next);
        StrList->_size--;
    }
}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList *StrList1, const StrList *StrList2) {
    const Node *p1 = StrList1->_head;
    const Node *p2 = StrList2->_head;
    while (p1) {
        if (p2 == NULL || strcmp(p1->_data, p2->_data) != 0) return FALSE;
        p1 = p1->_next;
        p2 = p2->_next;
    }
    if (p2 != NULL) return FALSE;
    return TRUE;


}

/*
 * Clones the given StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList *StrList_clone(const StrList *StrList) {
    struct _StrList *newList = StrList_alloc();
    if (newList == NULL) return NULL; //should check what they want us to do in this case
    Node *p = StrList->_head;
    while (p) {
        char *data = (char *) malloc(strlen(p->_data) + 1);
        if (data == NULL) { return NULL; }
        strcpy(data, p->_data);
        StrList_insertLast(newList, data);
        p = p->_next;
        free(data);
    }
    return newList;
}

/*
 * Reverses the given StrList.
 */
void StrList_reverse(StrList *StrList) {
    Node *current = StrList->_head;
    Node *pre = NULL;
    Node *next = NULL;
    while (current) {
        next = current->_next;
        current->_next = pre;

        pre = current;
        current = next;
    }
    StrList->_head = pre;
}

/*
 * Sort the given list in lexicographical order
 */
void StrList_sort(StrList *StrList) {
    int changes = 1;
    while (changes) {
        changes = 0;
        Node *curr = StrList->_head;
        while (curr->_next) {
            if (strcmp(curr->_data, curr->_next->_data) > 0) {
                changes = 1;
                char *temp = (char *) malloc(sizeof(char) * (strlen(curr->_data) + 1));
                strcpy(temp, curr->_data);
                curr->_data = realloc(curr->_data,sizeof(char) * (strlen(curr->_next->_data) + 1));
                strcpy(curr->_data, curr->_next->_data);
                curr->_next->_data = realloc(curr->_next->_data,sizeof(char) * (strlen(temp) + 1));
                strcpy(curr->_next->_data, temp);
                free(temp);
            }

            curr = curr->_next;
        }
    }
}

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList *StrList) {
    Node *p = StrList->_head;
    if (p == NULL) { return TRUE; }
    while (p->_next) {
        if (strcmp(p->_data, p->_next->_data) > 0) {
            return FALSE;
        }
        p = p->_next;
    }
    return TRUE;
}

