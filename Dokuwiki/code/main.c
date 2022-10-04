#include<stdio.h>
//türkçe harfler için gerekli kütüphane
#include<locale.h>
#include<stdlib.h>
#include"read_f.h"
#include"file_dir.h"

int main(){
    printf("Projeye Hoşgeldiniz \n");
    char *file_name;
    char link_list[50][50];
    printf("wire the file name : ");
    fgets(file_name, 100,stdin);
    add_txt(file_name);
    puts(file_name);
    read_file(file_name,link_list);
    char files[50][50];
    int file_count;
    char * path = ".";
    find_file(path,files,&file_count); 
    printf("fc : %d",file_count);
    int counter = 0;
    while(counter<10){
        printf("ok");
        counter += 1;
    }
    return 0;
}
