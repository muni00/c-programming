#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//MUAZZEZ NIHAL BAHADIR 
// pointer ile yapýlmýþ bir bulmaca programý
int nStrlen(char *s)
{
    int uzunluk = 0;
    while(*s != '\0')
    {
        s++;
        uzunluk++;
    }
    return uzunluk;
}

int main( )
{

    int satir,sutun,i,j,boyut,k,sayac1,sayac2=0,sayac3;
    char matris[100][100],kelime[30];
    int m, fark='a'- 'A';//A=65,a=97 ascýý deki karsiligidir;
    char *arr = matris,*wr = kelime; //pointere atama islemi gerceklestirildi


    srand(time(NULL));

    printf("Satir sayisini giriniz :");
    scanf("%d",&satir);
    printf("Sutun sayisini giriniz :");
    scanf("%d",&sutun);
    printf("_________________________________________________________\n\n");
    for(i=0; i<satir; i++)
    {
        for(j=0; j<sutun; j++)
        {
            //*(*(arr+i)+j)='A'+rand()%26; pointer tek boyutlu oldugundan cift kirma yapilaadigi icin
            *(arr+i*sutun+j) = 'A'+rand()%26 ; //icin tek boyut mantigi ile yapildi
            printf("%c\t", *(arr+i*sutun+j) ); //yazilirken ayni anda bastirilmasi icin ayni fora yazildi

        }

        printf("\n\n");
    }
    printf("_________________________________________________________\n");

    printf("\n\n");
    printf("aranmasini istediginiz kelimeyi giriniz :\n\n");
    scanf("%s",wr);//yukarida atama islemini gerceklestirdigim pointeri kullandim
    boyut=nStrlen(wr);//fonksiyon seklinde yazildi
    for(m=0; m<boyut; m++)
    {
        if(*(wr+m)>='a'&&*(wr+m)<='z')
            *(wr+m) -= fark;                    //kucuk harf girilse de islem yapabilmesi icin yapildi
        //printf("%c", *(wr+m));
    }
    printf("\n");
    printf("_________________________________________________________\n\n");

    printf("\n");


    printf("soldan saga arama sonucu:\n");

    sayac3=0;
    for(i=0; i<satir; i++)//her elemana teker teker ulasmak icin dongu olusturuldu
    {
        for(j=0; j<sutun; j++)
        {
            if(*(arr+i*sutun+j) == *wr)//ilk harfin esitlik kontrolu yapildi
            {

                sayac1=1; //birinci harf bulundugu icin birden baslatildi
                for(k=1; k<boyut && j+k<sutun ; k++) //ilk harfi bulmus oldugum icin k=1'den baslattim
                {
                    if(*(arr+i*sutun+j+k) != *(wr+k))//esitligin bozulmasi halinde donguden cikma kosulu verildi
                        break;
                    else
                        sayac1++;//boyut karsilastirilmasi icin sayac arttilirdi
                }

                if(sayac1 == boyut) //sayac kelimedeki harf sayisina esit olunca aralik yazilacak
                {
                    printf("\n{%d,%d} - {%d,%d} indisleri arasindadir",i+1,j+1,i+1,j+boyut);
                    sayac2++;//toplamda kac tane bulundugunu soylemede yyardimci sayac
                    sayac3++;//sadece buna ozel toplami soylemede yardici sayac
                }

            }
        }
        printf("\n");
    }
    printf("[ soldan saga toplam = %d]\n\n",sayac3);
    printf("_________________________________________________________\n\n");
    printf("yukaridan asagiya arama sonucu:\n");
    sayac3=0;
    for(j=0; j<sutun; j++)//her elemana teker teker ulasmak icin dongu olusturuldu
    {
        for(i=0; i<satir-boyut+1; i++)//kelimenin boyutundan fazlasýnýgitmesi vakit kaybi oldugundan boyut-1 e kadar gidicek
        {
            if(*(arr+i*sutun+j) == *wr)//ilk harf kontrolu
            {
                sayac1=1;
                for(k=1; k<boyut; k++)
                {
                    if(*(arr+i*sutun+j+k*sutun) != *(wr+k))
                        break;
                    sayac1++;
                }
                if(sayac1 == boyut)
                {
                    printf("\n{%d,%d} - {%d,%d} indisleri arasindadir",i+1,j+1,i+boyut,j+1);//kullanicinin yeri daha iyi saptamasi icin sýfýrlari kaldirmak amaci ile +1 yapildi
                    sayac2++;
                    sayac3++;
                }
            }
        }
        printf("\n");
    }
    printf("[ yukaridan asagiya toplam bulunan = %d]\n\n",sayac3);
    printf("_________________________________________________________\n\n");

    printf("sagdan sola arama sonucu:\n");
    sayac3=0;
    for(i=0; i<satir; i++)//her elemana teker teker ulasmak icin dongu olusturuldu
    {

        for(j=sutun-1 ; j>boyut-2 ; j--)//(sutun-boyut+1) = boyut-2 ikisi de ayni islemi yapar
        {
            if(*(arr+i*sutun+j) == *wr)
            {
                sayac1=1;
                for(k=1; k<boyut; k++)
                {
                    if(*(arr+i*sutun+j-k) != *(wr+k) )
                        break;
                    sayac1++;
                    sayac3++;
                }

                if(sayac1 == boyut)
                {
                    printf("\n{%d,%d} - {%d,%d} indisleri arasindadir",i+1,j+1,i+1,j-boyut+2);
                    sayac2++;
                }

            }
        }
        printf("\n");
    }
    printf("[ sagdan sola toplam bulunan = %d]\n\n",sayac3);
    printf("_________________________________________________________\n\n");

    printf("asagidan yukari arama sonucu\n ");
    sayac3=0;

    for(j=0; j<sutun; j++)//her elemana teker teker ulasmak icin dongu olusturuldu
    {

        for(i=satir-1; i>0; i--)
        {
            if(*(arr+i*sutun+j) == *wr)
            {
                sayac1=1;
                for(k=1; k<boyut; k++)
                {
                    if(*(arr+i*sutun+j-(k*sutun)) !=*(wr+k) )
                        break;
                    sayac1++;
                }
                if(sayac1 == boyut)
                {
                    printf("\n{%d,%d} - {%d,%d} indisleri arasindadir",i+1,j+1,i-boyut+2,j+1);
                    sayac2++;
                    sayac3++;
                }
            }
        }
        printf("\n");
    }
    printf("[ asagidan yukariya toplam bulunan = %d]\n\n",sayac3);
    printf("_________________________________________________________\n\n");
    printf("[ bulmacanin toplaminda bulunan aranan sayisi : %d]\n\n",sayac2);
    printf("_________________________________________________________\n\n");


    return 0;
}
