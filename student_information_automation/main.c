#include <stdio.h>
#include <stdlib.h>
//MUAZZEZ NIHAL BAHADIR 
typedef struct ders
{
    char ders_adi[20];
    int vize_notu;
    int final_notu;
} dr;

typedef struct ogrenci
{
    int num;
    char ad[10];
    char soyad[10];
    int ders_sayisi;
    dr *d;
} og;

void listele(og*,int );
void ogrenci_ara(og*,int);
void durum_goster(og*,int);
int my_strcmp(char*, char *);



int main()
{
    og*o;//ogrenci struct'ýnda dolanabilmek amaciyla pointer atamasi yapildi
    int ogr_sayisi,i,n=1,j;
    char secenek;

        printf("\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t\tOGRENCI DURUM KONTROL PROGRAMINA HOSGELDINIZ\n");
        printf("\n\t\t---------------------------------------------------------------------------\n");

    printf("\n\t\tKAC OGRENCI ICIN KULLANACAGINIZI GIRINIZ:");
    scanf("%d",&ogr_sayisi);//ogrenci sayisi bellek tahsisi icin alindi

    o = (og*) malloc (ogr_sayisi*sizeof(og));//ogrenci icin  bellek tahsisi yapildi

    for(i=0; i<ogr_sayisi; i++)//ogrenci bilgilerinin alindigi bölüm
    {
        printf("\n\t\t%d. OGRENCININ NUMARASINI GIRINIZ:",i+1);
        scanf("%d",&(o+i)->num);

        printf("\n\t\t%d. OGRENCININ ADINI GIRINIZ:",i+1);
        scanf("%s",(o+i)->ad);

        printf("\n\t\t%d. OGRENCININ SOYADINI GIRINIZ:",i+1);
        scanf("%s",(o+i)->soyad);

        printf("\n\t\t%d. OGRENCININ DERS SAYISINI GIRINIZ:",i+1);
        scanf("%d",&(o+i)->ders_sayisi);

        (o+i) -> d = (dr*) malloc ((o+i)->ders_sayisi*sizeof(dr));//her ogrenci icin her dersi icin yer tahsisi yapýldi

        for(j=0; j<(o+i)->ders_sayisi; j++)
        {
            printf("\n\n\t\t%d. OGRENCININ %d. DERSININ ADINI GIRINIZ:",i+1,j+1);
            scanf("%s",((o+i)->d+j)->ders_adi);

            printf("\n\t\t%d. OGRENCININ %d. DERSININ VIZE NOTUNU GIRINIZ:",i+1,j+1);
            scanf("%d",&((o+i)->d+j)->vize_notu);

            printf("\n\t\t%d. OGRENCININ %d. DERSININ FINAL NOTUNU GIRINIZ:",i+1,j+1);
            scanf("%d",&((o+i)->d+j)->final_notu);

        }
        printf("\t\t---------------------------------------------------------------------------\n");

    }
    getch();
    system("cls");

    while(n==1)
    {

        printf("\t\t---------------------------------------------------------------------------\n");
        printf("\n\n");
        printf("\t\t[A]---> OGRENCI ARA\n");
        printf("\t\t[B]---> DURUM GOSTER\n");
        printf("\t\t[C]---> LISTELE\n");
        printf("\t\t[D]---> CIKIS\n\n");
        printf("\t\t---------------------------------------------------------------------------\n");
        scanf("c",&secenek);
        secenek=getch();
        switch(secenek)
        {
        case 'A':
            ogrenci_ara(o,ogr_sayisi);
            getch();
            system("cls");
            break;
        case 'B':
            durum_goster(o,ogr_sayisi);
            getch();
            system("cls");
            break;
        case 'C':
            listele(o,ogr_sayisi);
            getch();
            system("cls");
            break;
        case 'D':
            n=0;
            system("cls");
            break;
        default:
            printf("\n\t\tYANLIS TERCIH YAPTINIZ , LUTFEN TEKRAR DENEYIN !!\n");
            getch();
            system("cls");
        }
    }
    return 0;
}
void listele(og*o,int ogr_sy)//bilgilerin hepsini listeler
{
    int i,j;
    double toplam=0.0;
    for(i=0; i<ogr_sy; i++)
    {

        printf(" \n\t\tNUMARASI:%d\n\t\tADI VE SOYADI:%s %s\n\t\tALDIGI DERS SAYISI:%d",(o+i)->num,(o+i)->ad,(o+i)->soyad,(o+i)->ders_sayisi);
        for(j=0; j<(o+i)->ders_sayisi; j++)
        {
            printf("\n\n\t\tDERS ADI:%s\n\t\tVIZE NOTU:%d\n\t\tFINAL NOTU:%d",((o+i)->d+j)->ders_adi,((o+i)->d+j)->vize_notu,((o+i)->d+j)->final_notu);
            toplam=0.0;
            toplam += ((((o+i)->d+j)->vize_notu) * (0.4));
            toplam += ((((o+i)->d+j)->final_notu) * (0.6));
            if(toplam >= 60)
                printf("\n\t\tDERSTEN GECTI");
            else
                printf("\n\t\tDERSTEN KALDI");

        }
        printf("\n\t\t---------------------------------------------------------------------------\n");
    }
}
void ogrenci_ara(og*o,int ogr_sy)//aranan ogrencinin bilgilerini listeler
{
    char arn_ad[10],*p;
    int i,j;
    printf("\n\t\tARADIGINIZ OGRENCININ ADINI GIRINIZ:");
    scanf("%s",arn_ad);
    p=arn_ad;
    for(i=0; i<ogr_sy; i++)
    {
        if(my_strcmp((o+i)->ad,p)==0)
        {
            printf(" \n\t\tNUMARASI:%d\n\t\tADI VE SOYADI:%s %s\n\t\tALDIGI DERS SAYISI:%d",(o+i)->num,(o+i)->ad,(o+i)->soyad,(o+i)->ders_sayisi);

            for(j=0; j<(o+i)->ders_sayisi; j++)
            {
                printf("\n\n\t\tDERS ADI:%s\n\t\tVIZE NOTU:%d\n\t\tFINAL NOTU:%d",((o+i)->d+j)->ders_adi,((o+i)->d+j)->vize_notu,((o+i)->d+j)->final_notu);

            }
        }
    }

}

void durum_goster(og*o,int ogr_sy)//ogrencilerin gecme kalma durumunu gosterir
{
    int i,j;
    double toplam=0.0;
    for(i=0; i<ogr_sy; i++)
    {
        printf("\n\t\t%s %s",(o+i)->ad,(o+i)->soyad);
        for(j=0; j<(o+i)->ders_sayisi; j++)
        {
            printf("\n\n\t\t%s",((o+i)->d+j)->ders_adi);

            toplam=0.0;
            toplam += (((o+i)->d+j)->vize_notu) * (0.4);
            toplam += (((o+i)->d+j)->final_notu) * (0.6);

            if(toplam >= 60)
                printf("\n\t\tDERSTEN GECTI");
            else
                printf("\n\t\tDERSTEN KALDI");

        }
        printf("\n\t\t---------------------------------------------------------------------------\n");
    }
}

int my_strcmp(char *s1, char *s2)//isimlerin karsilastirilabilmesi icin strcmp fonkunun icerigi
{
    int i=0;
    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        i++;
    }
    return (s1[i] - s2[i]);
}
