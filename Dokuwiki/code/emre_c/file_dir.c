#include <dirent.h> 
#include <string.h>
#include <stdio.h> 

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

void find_file(char* path,char files[50][200], int *file_count){
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
                }
                }
        }
    closedir(main_dir);
    }
}
