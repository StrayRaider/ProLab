#include<stdio.h>
//türkçe harfler için gerekli kütüphane
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//------------------------
struct link{
    char name[100];
    char file[100];
    char path[100];
    char linked_f[100];
    int start_i;
    int stop_i;
    int ent_c;
    int orphan; //yetim mi sorgusu
    int count;
    };


void set_linked_file(struct link *r_link,char linked_f[100]){
    strcpy(r_link->linked_f, linked_f);
    }

void set_path(struct link *r_link,char path[100]){
    strcpy(r_link->path, path);
    }

void set_file(struct link *r_link,char file[100]){
    strcpy(r_link->file, file);
    }

void set_name(struct link *r_link,char name[100]){
    strcpy(r_link->name, name);
    }

void set_ind(struct link *r_link, int start_i, int stop_i){
    (*r_link).start_i = start_i;
    (*r_link).stop_i = stop_i;
    }

void set_ent(struct link *r_link, int enter_c){
    (*r_link).ent_c = enter_c;
    }


void f_to_path(char *file, char path[100]){
    int k = 0;
    strcpy(path,file);
    for(k = strlen(path); k>0; k-=1){
        if(path[k] == '/'){
            path[k+1] = '\0';
            break;
        }
    }
}

//---------------------read file-----------

void read_file(char *file_name, struct link link_struct[50],int *link_count){
    //printf("%s\n",file_name);
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
        char link[100] = "";
        //printf("\n link indexi :-%d,%d-\n",index[a][0],index[a][1]);
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
        //printf("/n sayısı : %d \n",n);
        set_ent(&link_struct[*link_count],n);
        //struct'a ata
        set_name(&link_struct[*link_count],link);
        set_file(&link_struct[*link_count],file_name);
        char path[100];
        f_to_path(file_name, path);
        set_path(&link_struct[*link_count],path);
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


void del_txt(char *file_name){
    int k = 0;
    k = strlen(file_name) - 4;
    file_name[k] = '\0';
    printf("txt : %s\n",file_name);
}

int is_txt(char *file_name){
    int len = strlen(file_name);
    const char *extent = &file_name[len-4];
    if (!strcmp(extent,".txt"))
        return 1;
    return 0;
}

void find_f(char* path,char folders[50][100],char files[50][200] ,char file_names[50][100] , int *folder_count, int *file_count){
    DIR *dir;
    struct dirent *dent;
    dir = opendir(path);   
    if(dir!=NULL)//dir varsa
    {
    while((dent=readdir(dir))!=NULL){
        if((strcmp(dent->d_name,".")==0 || strcmp(dent->d_name,"..")==0 || (*dent->d_name) == '.' ))
            {
            }
        else
            {
            char d_path[255];
            strcpy(d_path,path);
            strcat(d_path,dent->d_name);
            DIR *dir_n;
            dir_n = opendir(d_path);   
            strcat(d_path,"/");
            char *file_name = dent->d_name;
            if(dir_n == NULL){//is file
                //File
                char f_path[255];
                strcpy(f_path,path);
                strcat(f_path,dent->d_name);
                if(is_txt(file_name)){
                    printf("path : %s\n",path);
                    printf("yazılan fn: %s\n",file_name);
                    printf("yazılan f: %s\n",f_path);
                    strcpy(files[*file_count],f_path);
                    printf("path : %s\n",d_path);
                    del_txt(file_name);
                    strcpy(file_names[*file_count], file_name);
                    *file_count+=1;
                    }
                }
            else{//is folder
                //Folder
                strcpy(folders[*folder_count],d_path);
                *folder_count +=1;
                find_f(d_path,folders,files,file_names,folder_count,file_count);
                }
            }
        }
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

void print_links(struct link link_struct[50], int *link_count){
    char writed[50][100];
    printf("Etiket Listesi- Tekrar Sayısı\n");
    printf("%s \t\t-\t\t %d\n",link_struct[0].name,link_struct[0].count);
    strcpy(writed[0],link_struct[0].name);
    for(int i = 0; i < *link_count;i+=1){
        for(int k =0; k < *link_count;k+=1){
            if(!strcmp(writed[k],link_struct[i].name)){
                break;
                }
            if(k == link_struct[i].count){
                printf("%-50s \t-\t %d\n",link_struct[i].name,link_struct[i].count);
                strcpy(writed[k],link_struct[i].name);
                }
            }
        }
    }

void fprint_out(struct link link_struct[50], int *link_count){
    char writed[50][100];
    char orp_list[50][100];//yazılacak yetim etiket isimlerini tutar
    FILE *file = fopen("output.txt", "w");
    fprintf(file,"Etiket Listesi- Tekrar Sayısı\n");
    fprintf(file,"%s \t\t-\t\t %d\n",link_struct[0].name,link_struct[0].count);
    strcpy(writed[0],link_struct[0].name);
    int orp_c = 0;
    //printf("lc : %d",*link_count);
    for(int i = 0; i < *link_count;i+=1){
        for(int k =0; k < *link_count;k+=1){
            if(!strcmp(writed[k],link_struct[i].name)){
                printf("burası : %d",i);
                break;
                }
            else if(k == link_struct[i].count){
                if(link_struct[i].orphan == 1){
                    strcpy(orp_list[orp_c],link_struct[i].name);
                    orp_c += 1;
                    }
                fprintf(file,"%-70s \t-\t %d\n",link_struct[i].name,link_struct[i].count);
                strcpy(writed[k],link_struct[i].name);
                }
            }
        }
    
    fprintf(file,"\n\nYetim Etiketler :\n\n\n");
    for(int o = 0; o < orp_c;o+=1){
        fprintf(file,"%s\n",orp_list[o]);
        }

    fclose(file);
    }

void print_struct(struct link *link_struct,int k){
    printf("name               : %s\n", link_struct[k].name);
	printf("path               : %s\n", link_struct[k].path);
	printf("file               : %s\n", link_struct[k].file);
	printf("connected file     : %s\n", link_struct[k].linked_f);
	printf("start_i            : %d\n", link_struct[k].start_i);
    printf("stop_i             : %d\n", link_struct[k].stop_i);
    printf("ent_c              : %d\n", link_struct[k].ent_c);
    if(link_struct[k].orphan == 1){
        printf("yetim_e\n");
    }
    else{
        printf("yetim olmayan etiket \n");
    }
    //printf("yetim mi           : %d\n", link_struct[k].orphan);
    printf("link aded sayısı   : %d\n", link_struct[k].count);
    printf("\n");

}

void change_space(char file_name[100]){
    for(int i=0;i < strlen(file_name);i++){
        if(file_name[i] == ' '){
            file_name[i] = '_';
            }
        }
    printf("%s",file_name);
}


//----main


int main(){
    setlocale(LC_ALL,"Turkish");
    struct link link_struct[50];

    //folderları bulur
    int folder_count = 0;
    char folders[50][100];
    char path[100] = "../";
    char files[50][200];
    char file_names[50][100];
    int file_count = 0;
    find_f(path ,folders ,files ,file_names ,&folder_count ,&file_count);
    //folder içerisindeki .txt leri bulur
    printf("folder count : %d\n",folder_count);
    printf("file count : %d\n",file_count);
    //her dosyayı okuyup tüm linkleri link liste atar
    int link_count =0;
    for(int i= 0 ;i < file_count;i++){
        printf("%d.dosya : %s \n",i,files[i]);
        read_file(files[i],link_struct,&link_count);
    }
    //yetim mi sorgusu
    // struct atamaları
    for(int k = 0;k<link_count;k++){
        //her bir link için
        link_struct[k].orphan = 1;
        for(int i =0;i<file_count;i++){
            if (!strcmp(link_struct[k].name,file_names[i])){
                printf("\nFile_names i %s    %s\n\n",files[i],file_names[i]);
                link_struct[k].orphan = 0;
                set_linked_file(&link_struct[k], files[i]);
                break;
            //printf("str : %s\n",link_struct[k].name);
                }
            else{
                char tmp[100] = " ";
                set_linked_file(&link_struct[k], tmp);
                }
        }
        int last_w = 0;
        int is_eq = 0;
        for(int l = 0;l<link_count;l++){
            if(!strcmp(link_struct[l].name,link_struct[k].name)){
                is_eq += 1;
                }
            }
            //printf("%d here\n",is_eq);
            link_struct[k].count = is_eq;
            if(!is_eq){
                last_w +=1;
                }
        print_struct(link_struct,k);
    }

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
        char ln;
        printf("||-|| ");
        scanf("%d",&inp);
        scanf("%c",&ln);
        printf("girilenn :%d\n",inp);

        if (inp == 1){
            printf("Arama Yapılıyor..\n");
            printf("Arama Yapmak istediğiniz Kelimeyi giriniz : ");
            char search_w[100];
            fscanf(stdin,"%s",search_w);
            printf("girilen : %s\n",search_w);
            //linkler arasında ara
            for(int i=0; i<link_count ;i += 1){
                if(!strcmp(search_w,link_struct[i].name)){
                    printf("Bulundu ! ;\n");
                    print_struct(link_struct,i);
                }
            //str str ile dosya içerisinde kelime ara

            }

        }
         else if (inp == 2){
            printf("||-|| Etiket Güncelleme işlemi..\n");
            //etiket isimlerinin listelenmesi
            printf("Linklerin Listesi : \n");
            print_links(link_struct,&link_count);
            printf("||-|| değiştirmek istediğiniz etiketin adını giriniz :");
            char search_w[100];
            //fscanf(stdin,"%s",search_w);
            fgets(search_w,100,stdin);
            search_w[strcspn(search_w, "\n")] = '\0';
            printf("girilen : %s\n",search_w);
            //yazılan listede var mı?
            int ind_l[10];
            int counter =0;
            for(int i=0;i<link_count;i+=1){
                if(!strcmp(search_w, link_struct[i].name)){
                    printf("listede var\n");
                    ind_l[counter] = i;
                    counter += 1;
                }
            }
            //listede var ise
            if(counter > 0){
                //linkin adını değiştir
                char new_link_name[100];
                printf("linke vermek istediğiniz yeni ismi giriniz :");
                fgets(new_link_name,100,stdin);
                new_link_name[strcspn(new_link_name, "\n")] = '\0';
                //fscanf(stdin,"%s",new_link_name);
                for(int i=0;i < counter;i+=1){
                    //link struct adını değiştir
                    set_name(&link_struct[ind_l[i]], new_link_name);
                    //dosyada yazanı değiştir
                    printf("döndü %s \n",link_struct[ind_l[i]].file);
                    change_index(link_struct[ind_l[i]].file,link_struct[ind_l[i]].start_i,link_struct[ind_l[i]].stop_i,new_link_name);
                    //link yetim değil ise dosya adını değiştir 
                    if(link_struct[ind_l[i]].orphan != 1){
                        printf("first new link :%s\n",new_link_name);
                        //add_txt(new_link_name);
                        printf("file name :%s\n",new_link_name);
                        //structdaki dosya adını değiştir
                        set_file(&link_struct[ind_l[i]],new_link_name);
                        printf("file a yazılan :%s\n",link_struct[ind_l[i]].name);
                        //dosya adını değiştir
                        char new_file_name[100];
                        change_space(new_link_name);
                        char l_f_path[100];
                        f_to_path(link_struct[ind_l[i]].linked_f, l_f_path);
                        strcpy(new_file_name, l_f_path);
                        strcat(new_file_name, new_link_name);
                        strcat(new_file_name, ".txt");
                        rename(link_struct[ind_l[i]].linked_f,new_file_name);
                        printf("yeni file ismi :%s\n",new_file_name);
                        }
                    }
                }
                else{
                printf("listede yok !\n");
                }
            //etiketin olduğu dosyalar mı gezilecek ?
        }
        else if (inp == 3){
            printf("||-|| Dosyaya Yazılıyor..\n");
            fprint_out(link_struct, &link_count);
        }
        else if (inp == 4){
            printf("||-|| çıkılıyor ..\n");
            break;
        }
        else if (inp != 1 || inp != 2 || inp != 3|| inp != 4){ 
            printf("hata\n"); // Kullanici menude string girerse program loop'a dusuyordu.
            break;
        }
    }




    //for(int i=0;i<last_w;i++){
    //    printf("etiket : %s\n",n_link_list[i]);
    //}
    return 0;
}


