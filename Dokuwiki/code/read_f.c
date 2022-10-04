#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void read_file(char *file_name, char* file_cont){
    char * all_file;
    FILE *file = fopen(file_name, "r");

    char *code;
    size_t n = 0;
    int c;
    char k;
    char link_list[20][100];
    int index[20][2];
    int act_l = 0;

    if (file == NULL)
        printf("error");
    code = malloc(1000);

    int start_i = 0;
    int stop_i = 0;

    while ((c = fgetc(file)) != EOF)
    {
    start_i = 0;
    stop_i = 0;
        //parantez açmaları bul indeksleri kaydet
        if (c == '['){
            k = fgetc(file);
            code[n++] = k;
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
            code[n++] = k;
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
        code[n++] = (char) c;
    }
    for(int a = 0;a<act_l;a++){
        char c;
        size_t l_count =0;
        printf("\n link indexleri : -%d,%d- \n ",index[a][0],index[a][1]);
        for(int x=index[a][0];x<index[a][1];x++){
            fseek(file,x,SEEK_SET);
            c = fgetc(file);
            link_list[a][l_count++] = c;
            }
        }
    code[n] = '\0';        
    puts(code);
	fclose(file);

    for(int i=0;i<act_l;i++){
        printf("%d. link burada : %s\n",i ,link_list[i]);
    }
}

void add_txt(char* file_name){
    char txt[5] = ".txt";
    file_name[strlen(file_name)-1] = '\0';
    strcat(file_name,txt);
    //printf("%s",file_name);
}
