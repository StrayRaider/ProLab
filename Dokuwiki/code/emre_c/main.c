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

    int folder_count = 0;
    char folders[50][100];
    char path[100] = "../";
    find_folder(path,folders, &folder_count);

    char files[50][200];
    int file_count = 0;
    printf("folder count : %d\n",folder_count);
    for(int i=0;i<=folder_count;i++){
        find_file(folders[i],files,&file_count); 
    }
    //printf("file count : %d\n",file_count);
    int link_count =0;
    for(int i= 0 ;i < file_count;i++){
        printf("%d.dosya : %s \n",i,files[i]);
        read_file(files[i],link_list,&link_count);
        printf("geçti\n");
    }

    printf("\n\n HERE \n\n");
    char n_link_list[20][50];
    int last_w = 0;
    strcpy(n_link_list[0],link_list[0]);
    for(int i =0;i<=link_count;i++){
        printf("%s\n",link_list[i]);
        int is_eq = 0;
        for(int k=0;k <= 50;k++){
            //printf("döndü\n");
            if(!strcmp(n_link_list[k],link_list[i])){
                printf("eşit\n");
                is_eq = 1;
                break;
                }
                }
            printf("%d here\n",is_eq);
            if(!is_eq){
                strcpy(n_link_list[last_w+1],link_list[i]);
                last_w +=1;
                }
            }
        
    for(int i=0;i<last_w;i++){
        printf("etiket : %s\n",n_link_list[i]);
        
    }

    return 0;
}
