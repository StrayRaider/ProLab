#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void main(){
     FILE * testfile;
     int i,no;
     testfile = fopen("/home/ruvanoit/Documents/ProLab/Dokuwiki/file_operations_test/test.md","w");
     if (testfile == NULL)
     {
        printf("dosya bulunamadı.");
     }
    else
    {
        for(i=1;i<=5;i++){
            printf("sayı gir: ");
            scanf("%d",&no);
            fprintf(testfile,"%d\n",no);
        }   
    }
    fclose(testfile);
}