#include <stdio.h>
#include <stdlib.h>
#include <string.h>

argc,argv[argc]; argv = {"prog1", "foo", "hello","foo"}
void main(){
    if(argc==1){
        printf("No string found");
        return;
    }
    if(argc == 2){
        printf("only 1 string: %s",argv[1]);
    }
    int amount = 0;
    char* str = argv[1];
    for(int i =2;i<argc;i++){
        if(strcmp(str,argv[i])){
            amount++;
        }
    }
    printf("%s%s%d%s",str,"appears ",amount," times");
}