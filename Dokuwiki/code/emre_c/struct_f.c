#include<string.h>

struct link{
    char name[50];
    char file[50];
    int start_i;
    int stop_i;
    };

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
