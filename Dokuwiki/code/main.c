#include<stdio.h>
//türkçe harfler için gerekli kütüphane
#include<locale.h>
#include<stdlib.h>
#include"read_f.h"

int main(){
    printf("Projeye Hoşgeldiniz \n");
    char *file_name;
    char link_list[50][50];
    printf("wire the file name : ");
    fgets(file_name, 100,stdin);
    add_txt(file_name);
    puts(file_name);
    read_file(file_name,link_list);
    return 0;
}
