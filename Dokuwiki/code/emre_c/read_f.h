#include"struct_f.h"
struct link;

// .txt formatında dosyayı okur verilen file_cont değişkenine yazar
char ** read_file(char* file_name,struct link link_struct[50] ,int *link_count);

//dosya adına .txt uzantısı ekler
void add_txt(char*file_name);
