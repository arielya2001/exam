#include <stdio.h>
void ex1(){
    int grade;
    for(int i =1;i<3;i++){
        printf("enter grade for student: %d\n",i);
        scanf("%d",&grade);
        printf("%d\n",grade);
    }
}
int main(){
    ex1();
    return 0;
}