#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void change_index(char* file_name,int start_i, int stop_i ,char *new_word){
    //dosyayı aç
    FILE *file = fopen(file_name, "r+");
    FILE *tmp = fopen("tmp.txt","w+");
    //index'e git
    char c;
    fseek(file,0,SEEK_SET);
    while (ftell(file)<start_i){
        c = fgetc(file);
        fputc(c,tmp);
        printf("%c",c);

    }

    //yenisini yaz
    fputs(new_word,tmp);

    fseek(file,stop_i,SEEK_SET);
    while (1){
        c = fgetc(file);
        if(c == EOF)
            break;
        fputc(c,tmp);
        printf("%c",c);
    }
    printf("tmp done\n");
    fclose(file);
    fclose(tmp);

    FILE *last_file = fopen(file_name, "w");
    FILE *r_tmp = fopen("tmp.txt","r");
    char l;
    while ((l = fgetc(r_tmp)) != EOF){
        fputc(l,last_file);
    }
    //arasını sil ve ya bir şekilde değiştir
    //yenisini yaz
    fclose(last_file);
    fclose(r_tmp);
    //kapat

    }
