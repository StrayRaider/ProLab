#include<stdio.h>
#include <dirent.h>
#include<string.h>



void search_f(char *path)
    {
    DIR *dir;
    struct dirent *dent;
    dir = opendir(path);   

    if(dir!=NULL)//is dir
    {
    while((dent=readdir(dir))!=NULL){
        if((strcmp(dent->d_name,".")==0 || strcmp(dent->d_name,"..")==0 || (*dent->d_name) == '.' ))
            {
            }
        else
            {
            char d_path[255];
            strcpy(d_path,path);
            strcat(d_path,dent->d_name);
            //printf("%s\n",d_path);
            printf(dent->d_name);
            printf("\n");
            DIR *dir_n;
            dir_n = opendir(d_path);   
            strcat(d_path,"/");
            if(dir_n == NULL)//is file
                printf("file\n");
            else
                search_f(d_path);
            }
        }
        }
       //close(dir);
     }




void main(){
    char *path = "../";
    search_f(path);
}


