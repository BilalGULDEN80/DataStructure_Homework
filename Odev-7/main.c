#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define KAPASITE 5
void silDeger(int [],int);
int main(int argc, char *argv[]) {
	
	int boyut=0;
	int deger;
	int sirano;
	printf("\n 5 Elemanli Olarak Tanimli");
	int dizi[KAPASITE];	
	
	while(boyut<5)
	{
		printf("Deger Girin\n");
		scanf("%d",&dizi[boyut] );    
    	boyut++;
    }    
    printf("\n Silme Yapmak Icin index girin");   
	 scanf("%d",&sirano);
    if(sirano<5)
    {
    	sildeger(dizi,deger);
	}
	else
	{
		printf("\n 5 den kucuk olmali");
	}
    getchar(); 
	return 0;
}
void silDeger(int dizi[], int deger)
{
    int index = -1;
int sayac = 0;
    for (sayac = 0; sayac < 5; sayac++)
    {
        if (dizi[sayac] == deger)
        {
            index = sayac;
            break;
        }
    }
    if (index == -1)
    {
        printf("Deger bulunamadi.\n");
        return;
    }
	int i;
    for (i = index; i < 5; i++)
        dizi[i] = dizi[i + 1];

    boyut--;
}
