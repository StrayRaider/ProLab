#include<stdio.h>
#include<string.h>

void read_file(char *file_name, char* file_cont){
    char * all_file;
    FILE *file = fopen(file_name, "r");
    char currentline[100];
    if(file != NULL){
        while(fgets(currentline,sizeof(currentline),file)!= NULL){
            //puts(currentline);
            strcat(file_cont,currentline);
            printf("done");
            //file_cont a yaz!
        }
    }
    puts("read done!");
}

void add_txt(char* file_name){
    char txt[5] = ".txt";
    file_name[strlen(file_name)-1] = '\0';
    strcat(file_name,txt);
    //printf("%s",file_name);
}
