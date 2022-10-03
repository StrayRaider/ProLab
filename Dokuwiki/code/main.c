#include<stdio.h>
//türkçe harfler için gerekli kütüphane
#include<locale.h>
#include<stdlib.h>
#include"read_f.h"

int main(){
    printf("Projeye Hoşgeldiniz \n");
    char *file_name;
    printf("wire the file name : ");
    fgets(file_name, 100,stdin);
    add_txt(file_name);
    puts(file_name);
    char* file_cont;
    read_file(file_name,file_cont);
    puts(file_cont);
    return 0;
}
