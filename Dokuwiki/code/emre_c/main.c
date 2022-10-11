#include<stdio.h>
//türkçe harfler için gerekli kütüphane
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include"read_f.h"
#include"file_dir.h"
#include"write.h"
#include"struct_f.h"

struct link{
    char name[50];
    char file[50];
    int start_i;
    int stop_i;
    };

int main(){
    printf("Projeye Hoşgeldiniz \n");
    //Menüden kullanıcı arama yapabilmeli,
    //etiketi ve o etikete ait txt dosyasının adını güncelleyebilmeli
    //ve dosyaya yazma işlemi yapabilmelidir.
    int run = 1;
    while (run){
        printf("Yapacağınız işlemle eşleştirilimiş harf kodunu seçiniz\n");
        printf("-----------------------------\n");
        printf("||-|| Arama Yap         :  1 |\n");
        printf("||-|| Etiketi Güncelle  :  2 |\n");
        printf("||-|| Dosyaya Yaz       :  3 |\n");
        printf("||-|| Çıkış             :  4 |\n");
        printf("-----------------------------\n\n");
        int inp;
        printf("||-|| ");
        scanf("%d",&inp);

        if (inp == 1){
            printf("Arama Yapılıyor..\n");
        }
        if (inp == 2){
            printf("||-|| Etiket Güncelleme işlemi..\n");
            printf("||-|| değiştirmek istediğiniz etiketi seçiniz");
            char *user_link;
            scanf("%s",user_link);
            //etiketin olduğu dosyalar mı gezilecek ?
            change_index("deneme.txt",4,10,"burayı ben yazdım");
        }
        if (inp == 3){
            printf("||-|| Dosyaya Yazılıyor..\n");
        }
        if (inp == 4){
            printf("||-|| çıkılıyor ..\n");
            break;
        }
    }

    struct link link_struct[50];

    char *file_name;
    char link_list[50][50];
    //folderları bulur
    int folder_count = 0;
    char folders[50][100];
    char path[100] = "../";
    find_folder(path,folders, &folder_count);
    //folder içerisindeki .txt leri bulur
    char files[50][200];
    int file_count = 0;
    printf("folder count : %d\n",folder_count);
    for(int i=0;i<=folder_count;i++){
        find_file(folders[i],files,&file_count); 
    }
    //printf("file count : %d\n",file_count);
    //her dosyayı okuyup tüm linkleri link liste atar
    int link_count =0;
    for(int i= 0 ;i < file_count;i++){
        printf("%d.dosya : %s \n",i,files[i]);
        read_file(files[i],link_struct,&link_count);
    }
    // struct atamaları
    for(int k = 0;k<link_count;k++){
        //printf("%s\n",link_list[k]);
        //printf("%s : done!\n", link_list[k]);
        set_file(&link_struct[k], files[k]);
        set_name(&link_struct[k], link_list[k]);
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
        //printf("etiket : %s\n",n_link_list[i]);
    }

    return 0;
}
