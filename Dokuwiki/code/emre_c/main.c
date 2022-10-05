#include<stdio.h>
//türkçe harfler için gerekli kütüphane
//#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include"read_f.h"
#include"file_dir.h"

int main(){
    printf("Projeye Hoşgeldiniz \n");
    char *file_name;
    char link_list[50][50];

    //printf("wire the file name : ");
    //fgets(file_name, 100,stdin);
    printf("here");

    char files[50][50];
    int file_count;
    char path[50] = "../";
    find_file(path,files,&file_count); 
    printf("file count : %d\n",file_count);
 
    for(int i= 0 ;i < file_count;i++){
        printf("%d. dosya :",i);
        puts(files[i]);
        printf("sonuç :");
        //read_file(file_name,link_list);
    }

    return 0;
}
