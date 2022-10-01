# Dosya işlemlerinde kullanılabilecek önemli C fonksiyonları
---
## 1. `fopen()`
- Yeni bir dosya oluşturmak ya da var olan dosyayı açmak için kullanılır. Farklı modlarla komut verilir.


| Mod | Anlamı                                                                                                                          |
| --- | ------------------------------------------------------------------------------------------------------------------------------- |
| w   | Text dosyasını yazma modunda oluşturur. Aynı isimli dosya varsa siler ve boş bir dosya açar. Konum göstergeci dosya başındadır. |
| r   | Text dosyayı okuma modunda açar. Göstergeç dosya başındadır.                                                                    |
| a   | Text dosyayı ekleme modunda açar. Dosya konum göstergeci dosya sonundadır. Dosya yoksa oluşturur.                               |
| w+  | Text dosyayı yazma modunda açar, okuma da yapılabilir.                                                                          |
| r+  | Text dosyayı yazma modunda açar, okuma da yapılabilir.                                                                          |
| a+  | Text dosyayı yazma modunda açar, okuma da yapılabilir.                                                                          |
| wb  | Binary dosyayı yazma modunda açar.                                                                                              |
| rb  | Binary dosyayı okuma modunda açar.                                                                                              |
| ab  | Binary dosyayı ekleme modunda açar.                                                                                             |
| w+b | Binary Binary dosyayı yazma modunda açar, okuma da yapılabilir                                                                  |
| r+b | Binary dosyayı okuma modunda açar, yazma da yapılabilir.                                                                        |
| a+b |Binary dosyayı ekleme modunda açar, okuma da yapılabilir|


#### - kullanımı:
  `FILE *fopen( const char * filename, const char * mode );`
```c
#include <stdio.h>
void main(){
    FILE * dosya;// pointer her zaman tanımlanır ve gereklidir.
    dosya = fopen("dosya konumu","kullanılacak mod");
    fclose(dosya);// her zaman işlem sonrası dosya kapatılır.
}
```
## 2. `fclose()`
-   Yapılan işlemler sonrası dosyayı **kapatmak** için kullanılır.
- örnekler: [[https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm]]

## 3. `fprintf()`
- Dosyaya formatlı bir şekilde veri yazmak için kullanılır.
- kullanımı: 
`fprintf(FILE *stream, const char *format, ...)`

## 4. `remove()`
- dosyayı diskten siler.
## 5. `fputs()`
- Dosyaya **string** yazar
## 6. ` `
