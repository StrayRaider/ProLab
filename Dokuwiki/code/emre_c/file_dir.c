#include <dirent.h> 
#include <string.h>
#include <stdio.h> 

void find_file(char* path,char files[50][50], int *file_count){
    DIR *main_dir;
    main_dir = opendir(path);
    struct dirent *dir;
    if(main_dir){
        while ((dir = readdir(main_dir)) != NULL) {
            if(dir-> d_type != DT_DIR){
                char *file_name = dir->d_name;
                //printf("dosya:%s\n", dir->d_name);
                int len = strlen(file_name);
                const char *extent = &file_name[len-4];
                //printf("uzantı : %s\n",extent);
                if (!strcmp(extent,".txt")){
                    //printf("pathı : %s\n",path);
                    strcpy(files[*file_count], path);
                    strcat(files[*file_count], file_name);
                    printf("%s is a txt file \n",file_name);
                    *file_count += 1;
                }
                }
            else
                if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ) // if it is a directory
      {
                    char d_path[255];
                    strcpy(d_path,path);
                    strcat(d_path,dir->d_name);
                    strcat(d_path,"/");
                    printf("klasör = %s\n",d_path);
                    //printf("klasör: %s/%s\n", path, dir->d_name);
                    find_file(d_path,files,file_count);
      }
        }
    printf("arama bitmiştir !\n");
    closedir(main_dir);

    }

}
