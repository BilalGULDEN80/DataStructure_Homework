#include <stdio.h>
#include <stdlib.h>

void Algo1();   
// Algo7 hesaplayamadým Hocam 2.(k+1) her adýmda 
int main()
{
	Algo1();
   printf("Test calisiyor!\n");
    system("PAUSE");
    return 0;
}

void Algo1()//n kez döndüðü için Zaman Karmaþýklýðý O(n)
{
    int i, n;

    printf("Kaç kez yazdýrmak istiyorsunuz? n = ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Merhaba Data Structure\n");
    }
}
void Algo2()// iki tane for döngüsü mevcut,iç içe olduðu için zaman karmaþýklýðý O(n²)
{
	int n;
	 printf("Kaç kez yazdýrmak istiyorsunuz? n = ");
    scanf("%d", &n);
	int i, j;
	for (i = 1;i<n;i++)
	{
    	for (j = 1;j<n;j++) 
    	{
        	print("Merhaba, Bilal kurtul veri yapýlarýndan");
    	}
	}
}
void Algo3()// i deðeri her iþlemde 2 kat katlanarak büyüyor, lineer deðil, 2^k=n kadar çalýþýr. burada k=log2(n) kez çalýþýr. O(log2 n)
{
	int i;
	int n;
	 printf("Kaç kez yazdýrmak istiyorsunuz? n = ");
    scanf("%d", &n);
	for(i=1;i<n;i=i*2)
	{
		print("Zamaný karýþtýrma,yýllar eriyecek!");
	}
}
void Algo4()// koddan gidecek olursak bu kod satýrý aslýnda calýþmaz, ama i'nin baþka bir deðer aldýðýný var sayarsak O(log5 n)
{
	int i;
		int n;
	 printf("Kaç kez yazdýrmak istiyorsunuz? n = ");
    scanf("%d", &n);
	for(i=1;i<n;i=i/5)
	{
		print("Merhaba Bilal");
	}
}
void Algo5()//Hocam Her bir aþamada i deðeri 5 kat artýþ deðeri kaydettiðinden logarikmik olarak log5 tabanýnda n³ olarak hesaplanýr O(log5n³) olarak hesaplanýr 
{
	int i;
		int n;
	 printf("Kaç kez yazdýrmak istiyorsunuz? n = ");
    scanf("%d", &n);
	for(i=0;i<n*n*n;i=i*5)
	{
		print("Merhaba Data Structure");
	}
}
void Algo6()// i*i <=n matematiksel olarak i=karekök n olarak hesaplanýr, 
{
	int i;
		int n;
	 printf("N degeri?  = ");
    scanf("%d", &n);
	for(i=0;i*i<=n;i++)
	{
		print("Karekök n zaman karmaþýklýðý vardýr.");
	}
}
void Algo7()
{
	int i=1;int k=1;
		int n;
	 printf("N degeri?  = ");
    scanf("%d", &n);
	while(k>=n)
	{
		i++;
		k=k+i;
		print(" zaman karmaþýklýðýný hesaplayamadým.");
	}
}


