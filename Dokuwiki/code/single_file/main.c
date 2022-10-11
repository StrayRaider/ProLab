#include<stdio.h>
//türkçe harfler için gerekli kütüphane
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include <dirent.h> 

//------------------------
struct link{
    char name[50];
    char file[50];
    char link_file[50];
    int start_i;
    int stop_i;
    int ent_c;
    //yetim mi sorgusu
    int orphan;
    int count;
    };

void set_link_file(struct link *r_link,char link_file[50]){
    strcpy(r_link->link_file, link_file);
    }
void set_file(struct link *r_link,char file[50]){
    strcpy(r_link->file, file);
    }
void set_name(struct link *r_link,char name[50]){
    strcpy(r_link->name, name);
    }
void set_ind(struct link *r_link, int start_i, int stop_i){
    (*r_link).start_i = start_i;
    (*r_link).stop_i = stop_i;
    }
void set_ent(struct link *r_link, int enter_c){
    (*r_link).ent_c = enter_c;
    }


//---------------------read file-----------

void read_file(char *file_name, struct link link_struct[50],int *link_count){
    printf("%s\n",file_name);
    FILE *file = fopen(file_name, "r");
    char c;
    char k;
    int index[50][2];
    int act_l = 0;

    if (file == NULL)
        printf("Dosya açılamadı !");
        //exit(1);
    int start_i = 0;
    int stop_i = 0;
    while ((c = fgetc(file)) != EOF)
    {
    //indexleri listeye yazmadan öce kullanılacak yeçiyi yer tutucular
    start_i = 0;
    stop_i = 0;
        //parantez açmaları bul indeksleri kaydet
        if (c == '['){
            k = fgetc(file);
            if(k == EOF)
                break;
            else if(k == '['){
                start_i = ftell(file);
                index[act_l][0]  = start_i;
            }
        }
        //parantez kapamaları bul indeksleri kaydet
        else if (c == ']'){
            k = fgetc(file);
            if(k == EOF)
                break;
            else if(k == ']'){
                stop_i = ftell(file);
                index[act_l][1]  = stop_i-2;
                if(index[act_l][0] != 0)
                    act_l +=1;
            }
            else{
            index[act_l][0] = 0;
            index[act_l][1] = 0;
            }
        }
    }
    for(int a = 0;a<act_l;a++){
        char c;
        size_t l_count =0;
        char link[50] = "";
        printf("\n link indexi :-%d,%d-\n",index[a][0],index[a][1]);
        for(int x=index[a][0];x<index[a][1];x++){
            fseek(file,x,SEEK_SET);
            c = fgetc(file);
            link[l_count++] = c;
            }

        fseek(file,0,SEEK_SET);
        char chr;
        int n = 1;
        while ((chr = fgetc(file)) != EOF && ftell(file) < index[a][0]){
            if (chr == '\n'){
                n++;
            }
        }
        printf("/n sayısı : %d \n",n);
        set_ent(&link_struct[*link_count],n);

        //struct'a ata
        set_name(&link_struct[*link_count],link);
        set_file(&link_struct[*link_count],file_name);
        set_ind(&link_struct[*link_count],index[a][0],index[a][1]);
        //strcpy(link_list[*link_count],link);
        *link_count += 1;
        }

	fclose(file);
    }

void add_txt(char* file_name){
    char txt[5] = ".txt";
    file_name[strlen(file_name)-1] = '\0';
    strcat(file_name,txt);
    //printf("%s",file_name);
}

//-----------------folder

void find_folder(char* path,char folders[50][100], int *folder_count){
    DIR *main_dir;
    main_dir = opendir(path);
    struct dirent *dir;
    if(main_dir){
         while ((dir = readdir(main_dir)) != NULL) {
                if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 &&     strcmp(dir->d_name,"..")!=0 ) // if it is a directory
      {
                    *folder_count += 1;
                    char d_path[255];
                    strcpy(d_path,"");
                    strcpy(d_path,path);
                    strcat(d_path,dir->d_name);
                    strcat(d_path,"/");
                    //printf("%s\n",d_path);
                    strcpy(folders[*folder_count],d_path);
                    find_folder(d_path,folders, folder_count);
                    }  
                }
            }
        }

void find_file(char* path,char file_names[50][100], char files[50][200], int *file_count){
    DIR *main_dir;
    main_dir = opendir(path);
    struct dirent *dir;
    if(main_dir){
        while ((dir = readdir(main_dir)) != NULL) {
            if(dir-> d_type != DT_DIR){
                char *file_name = dir->d_name;
                int len = strlen(file_name);
                const char *extent = &file_name[len-4];
               


                if (!strcmp(extent,".txt")){
                    char name[50] = "";
                    strcpy(name,path);
                    strcat(name,file_name);
                    strcpy(files[*file_count], name);
                    //printf("%d. ye yazılan şey : %s\n",*file_count,files[*file_count]);
                    *file_count += 1;
                    int k = 0;
                    k = strlen(file_name) - 4;
                    file_name[k] = '\0';
                    printf("txt : %s\n",file_name);
                    strcpy(file_names[*file_count], file_name);
                }
                }
        }
    closedir(main_dir);
    }
}

//-------------------------

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

//----main

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
            //scanf("%s",user_link);
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

    //char *file_name;
    char link_list[50][50];
    //folderları bulur
    int folder_count = 0;
    char folders[50][100];
    char path[100] = "../";
    find_folder(path,folders, &folder_count);
    //folder içerisindeki .txt leri bulur
    char files[50][200];
    char file_names[50][100];
    int file_count = 0;
    printf("folder count : %d\n",folder_count);

    for(int i=0;i<=folder_count;i++){
        find_file(folders[i],file_names,files,&file_count); 
    }

    printf("file count : %d\n",file_count);
    //her dosyayı okuyup tüm linkleri link liste atar
    int link_count =0;
    for(int i= 0 ;i < file_count;i++){
        //printf("%d.dosya : %s \n",i,files[i]);
        read_file(files[i],link_struct,&link_count);
    }

    // struct atamaları
    for(int k = 0;k<link_count;k++){

        //her bir link için
        link_struct[k].orphan = 1;
        for(int i =0;i<file_count;i++){
            if (!strcmp(link_struct[k].name,file_names[i])){
                printf("equal!! \n");
                link_struct[k].orphan = 0;
            //printf("str : %s\n",link_struct[k].name);
            }
        }
        printf("\n\n HERE \n\n");
        int last_w = 0;
        int is_eq = 0;
        for(int l = 0;l<link_count;l++){
            if(!strcmp(link_struct[l].name,link_struct[k].name)){
                is_eq += 1;
                }
            }
            printf("%d here\n",is_eq);
            if(!is_eq){
                last_w +=1;
                }
                
        

        printf("name    : %s\n", link_struct[k].name);
	    printf("file    : %s\n", link_struct[k].file);
	    printf("start_i : %d\n", link_struct[k].start_i);
	    printf("stop_i  : %d\n", link_struct[k].stop_i);
        printf("ent_c  : %d\n", link_struct[k].ent_c);
        printf("yetim mi   : %d\n", link_struct[k].orphan);
	    printf("\n");


    }   
    //for(int i=0;i<last_w;i++){
    //    printf("etiket : %s\n",n_link_list[i]);
    //}
    return 0;
}

