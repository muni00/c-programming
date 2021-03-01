#include <stdio.h>
#include <stdlib.h>

// abone ve bilgilerini struct yapýlarý ile tutan c programý
typedef struct fatura
{
    int f_tip;
    double f_borc;
    int alt_abone_no;
}F;
typedef struct abone
{
    int a_no;
    char ad[10];
    char soyad[10];
    char ilce[10];
    double t_borc;
    int ft_sayisi;
    F*f;
}A;

A bilgi_al(int);
void borc_hesapla(A*,int);
void bilgi_goster(A*,int);

int main()
{
    A *a;
    int absay;
    printf("kac abone icin yer ayrýlacak");
    scanf("%d",&absay);

    *a = bilgi_al(absay);
    borc_hesapla(a,absay);
    bilgi_goster(a,absay);

    return 0;
}

A bilgi_al(int abones)
{
    int i,j,fsayisi;
     A*a=(A*)malloc(sizeof(A)*abones);
    for(i=0;i<abones;i++)
    {
        printf("\nabone no:");
        scanf("%d",&(a+i)->a_no);
        printf("\nabone adý ve soyadý");
        scanf("%s %s",(a+i)->ad,(a+i)->soyad);
        printf("\nabone ilce ismi");
        scanf("%s",(a+i)->ilce);
        printf("\nabonenin fatura sayisi:");
        scanf("%d",&(a+i)->ft_sayisi);
        (a+i)->f =(F*)malloc(sizeof(F)*(a+i)->ft_sayisi);
        for(j=0;j<(a+i)->ft_sayisi;j++)
        {
            printf("\nfatura tipi:");
            scanf("%d",&((a+i)->f+j)->f_tip);
            printf("\nfatura borcu:");
            scanf("%d",&((a+i)->f+j)->f_borc);
            printf("\nalt abone no:");
            scanf("%d",&((a+i)->f+j)->alt_abone_no);
        }
    }
    return *a;
}
void borc_hesapla(A*ap,int abones)
{
    int i,j,tborc;
    for(i=0;i<abones;i++)
    {
        tborc=0;
        for(j=0;j<(ap+i)->ft_sayisi;j++)
        {
            tborc +=((ap+i)->f+j)->f_borc;
        }
        (ap+i)->t_borc=tborc;
    }

}
void bilgi_goster(A*a,int abones)
{
    int i,j,aranan;
    printf("\narananin numarasý:");
    scanf("%d",aranan);
    for(i=0;i<abones;i++)
    {
         if(aranan==(a+i)->a_no)
         {
             for(j=0;j<(a+i)->ft_sayisi;j++)
             {
                 printf("\nfatura tipi:%d\nfatura borcu:%D",((a+i)->f+j)->f_tip,((a+i)->f+j)->f_borc);
             }
             printf("\ntoplam borc:%d",(a+i)->t_borc);
         }
    }
}
