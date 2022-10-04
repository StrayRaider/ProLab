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
                printf("dosya:%s\n", dir->d_name);
                strcpy(files[*file_count], dir->d_name);
                *file_count += 1;
                }
            else
                if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ) // if it is a directory
      {
                    char d_path[255];
                    printf("klasör: %s/%s\n", path, dir->d_name);
                    //find_file()
      }
        }
    closedir(main_dir);

    }

}
