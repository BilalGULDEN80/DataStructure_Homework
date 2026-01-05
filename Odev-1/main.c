#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int _xiKullaniciSecim;
    printf("Kendin Deger Girerek mi Olusturacaksan 1, hazir matrix kullanacaksan 2 Gir: ");
    scanf("%d", &_xiKullaniciSecim);	
	/* yapay zeka deðil El Emeðidir Hocam */
    int satir, sutun;
    int sparseMatrix[100][100]; 
    int i, j;

    if (_xiKullaniciSecim == 1) {
        printf("Satir Sayisini Girin: ");
        scanf("%d", &satir);
        printf("Sutun Sayisini Girin: ");
        scanf("%d", &sutun);

        printf("Matris elemanlarini girin (%dx%d):\n", satir, sutun);
        for (i = 0; i < satir; i++) {
            for (j = 0; j < sutun; j++) {
                printf("matris[%d][%d] = ", i, j);
                scanf("%d", &sparseMatrix[i][j]);
            }
        }
    }
    else if (_xiKullaniciSecim == 2) 
	{
        //Kaynak Olarak Paylaþtýðýnýz Book1.psf'deki hazýr örnek matris
        satir = 4;
        sutun = 5;
        int temp[4][5] = {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}
        };       
        for (i = 0; i < satir; i++) {
            for (j = 0; j < sutun; j++) {
                sparseMatrix[i][j] = temp[i][j];
            }
        }
    }
    else {
        printf("Gecersiz secim!\n");
        return 1;
    }    
    printf("\nOrijinal Matris (%dx%d):\n", satir, sutun);
    for (i = 0; i < satir; i++) {
        for (j = 0; j < sutun; j++) {
            printf("%4d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }    
    int sifirOlmayanSayisi = 0;
    for (i = 0; i < satir; i++) {
        for (j = 0; j < sutun; j++) {
            if (sparseMatrix[i][j] != 0) {
                sifirOlmayanSayisi++;
            }
        }
    }   
    int compressed[sifirOlmayanSayisi + 1][3];

    compressed[0][0] = satir;
    compressed[0][1] = sutun;
    compressed[0][2] = sifirOlmayanSayisi;

    int k = 1; 
    for (i = 0; i < satir; i++) {
        for (j = 0; j < sutun; j++) {
            if (sparseMatrix[i][j] != 0) {
                compressed[k][0] = i;      // satýr 
                compressed[k][1] = j;      // sütun 
                compressed[k][2] = sparseMatrix[i][j];
                k++;
            }
        }
    }   
    printf("\nSikistirilmis Sparse Matris:\n");
    printf("Satir\tSutun\tDeger\n");
    for (i = 0; i <= sifirOlmayanSayisi; i++) {
        printf("%d\t%d\t%d\n", compressed[i][0], compressed[i][1], compressed[i][2]);
    }

    return 0;
}
