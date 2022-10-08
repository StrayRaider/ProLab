#include<stdio.h>
//türkçe harfler için gerekli kütüphane
//#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include"read_f.h"
#include"file_dir.h"
#include"write.h"

struct link{
	char *name;
	char *file;
	int count;
	};

void set(struct link *r_link,char *name,char*file,int count){
	strcpy((*r_link).name,name);
	strcpy((*r_link).file,file);
    (*r_link).count = count;
	}


int main(){
    printf("Projeye Hoşgeldiniz \n");


    //Menüden kullanıcı arama yapabilmeli,
    //etiketi ve o etikete ait txt dosyasının adını güncelleyebilmeli
    //ve dosyaya yazma işlemi yapabilmelidir.
    int run = 1;
    while (run){
        printf("Yapacağınız işlemle eşleştirilimiş harf kodunu seçiniz\n");
        printf("------------------------------------------------------\n");
        printf("||-|| Arama Yap         :  1 \n");
        printf("||-|| Etiketi Güncelle  :  2 \n");
        printf("||-|| Dosyaya Yaz       :  3 \n\n");
        int inp;
        scanf("%d",&inp);

        printf("girilen : %d\n",inp);
        if (inp == 1){
            printf("Arama Yapılıyor..\n");
        }
        if (inp == 2){
            printf("Etiket Güncelleme işlemi..\n");
            //etiketin olduğu dosyalar mı gezilecek ?
            change_index("deneme.txt",3,8,"burayı ben yazdım");
        }
        if (inp == 3){
            printf("Dosyaya Yazılıyor..\n");
        }
    break;
    }


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
    for(int k = 0;k<link_count;k++){
        printf("%s",link_list[k]);
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
