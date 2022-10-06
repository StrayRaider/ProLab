#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// parantez içerisinde bulunan stringleri gerekliyse parçalar ve yazar
// gerekli değilse direkt yazar
/*void parse_from_space(char* str,char link_list[50][50],int *last_loc){
    const char s[2] = " ";
    char *token;
    token = strtok(str, s);
    for(;token != NULL;*last_loc += 1 ) {
        //printf( "token:%s\n", token );
        strcpy(link_list[*last_loc],token);
        token = strtok(NULL, s);
    }
}*/

void read_file(char *file_name, char link_list[50][50],int *link_count){
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
        //parse_from_space(link,link_list,&last_loc);
        strcpy(link_list[*link_count],link);
        *link_count += 1;
        }
	fclose(file);

    //tüm linkleri ekrana bas
    /*for(int i=0;i<*link_count;i++){
        printf("%s\n",link_list[i]);
        }*/
    }

void add_txt(char* file_name){
    char txt[5] = ".txt";
    file_name[strlen(file_name)-1] = '\0';
    strcat(file_name,txt);
    //printf("%s",file_name);
}

