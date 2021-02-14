#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//MUAZZEZ NIHAL BAHADIR 
int main()
{
    char development,pro_sel;//karakter olarakkullanilacaklari icin char olarak yazildi
    double dresult;//islemlerde hata oranini azaltmak icin kullanildi
    float fresult;
    int num1,num2,result;
    int i=1;//ilk atama yapildi

    while (i==1)
    {
        int a=2;//dongulede tekrari saglamak amaci ile ilk deger atama islemi burada yapildi
        printf("\n\n\t\t---------------------------------------------------------\n");
        printf("\t\t|\t\tWELCOME TO CALCULATOR\t\t\t|\n");
        printf("\t\t---------------------------------------------------------\n");
        printf("\n\n");
        printf("\t\t[A]---> SIMPLE LEVEL\n");  //basit düzey
        printf("\t\t[B]---> ADVANCED LEVEL\n"); //gelismis düzey
        printf("\t\t[C]---> OUT\n\n");//cıkıs
        printf("\t\t---------------------------------------------------------\n\n");
        printf("\t\t= ");//secimi gosterirken duzenin bozulmamasi icin
        development = getche();//onay almadan isleme gecmemesi icin getch ile beklettim scanf ile de alınabilirdi
        if(development=='A')
        {
            while(a==2)
            {
                printf("\n\t\t(+).... ADDITION\n");//toplama
                printf("\t\t(-).... SUBTRACTION\n");//çikarma
                printf("\t\t(*).... MULTIPLICATION\n");//çarpma
                printf("\t\t(/).... DIVISION\n");//bölme
                printf("\t\t(!).... RETURN TO MAIN MENU\n\n");//ana menüye dönmek için bi girildi
                printf("\t\t---------------------------------------------------------\n\n");
                printf("\t\t= ");
                pro_sel = getche();
                switch(pro_sel)
                {
                case '+' :
                    printf("\n\t\tENTER A NUMBER :"); //birinci sayi alindi
                    scanf("%d",&num1);
                    printf("\n"); //sayilarin dizaynini korumak icin koyuldu,kolayini bulursan hallet!!
                    printf("\t\tENTER ANOTHER NUMBER :"); //ikinci sayi alindi
                    scanf("%d",&num2);
                    printf("\n");
                    result=num1+num2;//islem gerçeklestirildi
                    printf("\t\t%d + %d = %d\n\n",num1,num2,result); //islem ekrana basildi
                    printf("\t\t---------------------------------------------------------\n\n");
                    getch();
                    break;
                case '-' :
                    printf("\n\t\tENTER A NUMBER :");
                    scanf("%d",&num1);
                    printf("\n");
                    printf("\t\tENTER ANOTHER NUMBER :");
                    scanf("%d",&num2);
                    printf("\n");
                    result=num1-num2;
                    printf("\t\t%d - %d = %d\n\n",num1,num2,result);
                    printf("\t\t---------------------------------------------------------\n\n");
                    getch();
                    break;
                case '*' :

                    printf("\n\t\tENTER A NUMBER :");
                    scanf("%d",&num1);
                    printf("\n");
                    printf("\t\tENTER ANOTHER NUMBER :");
                    scanf("%d",&num2);
                    printf("\n");
                    result=num1*num2;
                    printf("\t\t%d * %d = %d\n\n",num1,num2,result);
                    printf("\t\t---------------------------------------------------------\n\n");
                    getch();
                    break;
                case '/' :

                    printf("\n\t\tENTER A NUMBER :");
                    scanf("%d",&num1);
                    printf("\n");
                    printf("\t\tENTER ANOTHER NUMBER :");
                    scanf("%d",&num2);
                    printf("\n");
                    if (num2==0) //0 a bolunme belirsizliðini ortadan kaldirmak için
                    {
                        printf("\t\tTHE PROCESS IS UNDEFINED\n\n");
                        printf("\t\t---------------------------------------------------------\n\n");
                        getch();
                        break;//menuye donmek icin gereken sonlanma
                    }

                    else
                    {
                        fresult=(float)num1/num2;
                        printf("\t\t %d / %d = %.3f \n",num1,num2,fresult);//genelde yuvarlama islemi icin kayan uc basmak dikkate alindigi icin .3 yapildi
                        printf("\t\t---------------------------------------------------------\n\n");
                    }
                    getch();
                    break;
                case '!' :
                    a=3;
                    system("cls");//gerksiz geride kalmis islemleri yoketmek için

                    break;

                default:
                    printf("\t\tYOU ENTERED THE WRONG OPTION\n\n");
                    printf("\t\t---------------------------------------------------------\n\n");
                }
            }

        }
        else if(development=='B')
        {

            while(a==2)
            {
                printf("\n\t\t(1).... MODE IMPORT OPERATION \n");//mod alma
                printf("\t\t(2).... SQUARE ROOT IMPORT OPERATION\n");//karekök alma
                printf("\t\t(3).... EXPONENT RETRIVAL PROCESS\n");//us alma
                printf("\t\t(4).... E LOGARITHM AT BASE\n");//e tabaninda logaritma alma
                printf("\t\t(5).... LOGARITHM AT BASE 10\n");//10 tabaninda logaritma
                printf("\t\t(!).... RETURN TO MAIN MENU\n\n");//ana menüye dönmek için cikis
                printf("\t\t---------------------------------------------------------\n\n");
                printf("\t\t= ");
                pro_sel = getche();
                switch(pro_sel)
                {
                case '1':

                    printf("\n\t\tENTER A NUMBER :");
                    scanf("%d",&num1);
                    printf("\n");
                    printf("\t\tENTER ANOTHER NUMBER :");
                    scanf("%d",&num2);
                    printf("\n");
                    if (num2>0)//sayinin negatif olup olmamasi kontrol edildi
                    {
                        result=num1%num2;
                        printf("\t\t %d % (%d) = %d\n\n",num1,num2,result);
                        // printf("\t\t---------------------------------------------------------\n\n");
                    }

                    else
                        printf("\t\tPLEASE ENTER A POSITIVE NUMBER !!\n\n");//pozitif sayi girilmesi icicn uyarildi
                    printf("\t\t---------------------------------------------------------\n\n");
                    getch();
                    break;

                case '2':

                    printf("\n\t\tENTER THE NUMBER TO GET THE SQUARE ROOT: ");
                    scanf("%d",&num1);
                    printf("\n");
                    if (num1<0)
                    {
                        printf("\t\tNOT NEGATIVE IN ROOT !!\n\n");//kok icinin negatif olmamasi icin kontrol yapildi
                        printf("\t\t---------------------------------------------------------\n\n");

                        break;
                    }
                    else
                        fresult=(float)sqrt(num1);
                    printf("\t\t SQUARE ROOT : %.3f\n\n ",fresult);
                    printf("\t\t---------------------------------------------------------\n\n");

                    break;

                case '3':

                    printf("\n\t\tENTER A NUMBER :");
                    scanf("%d",&num1);
                    printf("\n");
                    printf("\t\tENTER ANOTHER NUMBER :");
                    scanf("%d",&num2);
                    printf("\n");
                    fresult=(float) pow(num1,num2);
                    printf("\t\tRESULT = %.2f\n\n",fresult);
                    printf("\t\t---------------------------------------------------------\n\n");

                    break;
                case '4':

                    printf("\n\t\tENTER A NUMBER :");
                    scanf("%d",&num1);
                    printf("\n");
                    if (num1<=0)//logaritma isleminde negatif ve sifir olma belirsizligini kontrol ettim
                    {
                        printf("\t\tGIVES NEGATIVE NUMBERS AND ZERO UNDEFINED RESULTS WHEN TAKING LOGARITHMS ON BASE E !! \n\n");
                        printf("\t\t---------------------------------------------------------\n\n");

                        break;
                    }
                    else
                        dresult=(double)log (num1);
                    printf("\t\tLOGARITHM %d = %.2lf\n\n ",num1,dresult);
                    printf("\t\t---------------------------------------------------------\n\n");

                    break;

                case '5':

                    printf("\n\t\tENTER A NUMBER :");
                    scanf("%d",&num1);
                    printf("\n");
                    if (num1<=0)
                    {
                        printf("\t\tGIVES NEGATIVE NUMBERS AND ZERO UNDEFINED RESULTS WHEN TAKING LOGARITHMS ON BASE 10 !! \n\n");
                        printf("\t\t---------------------------------------------------------\n\n");

                        break;
                    }
                    else
                        dresult=(double)log10(num1);
                    printf("\t\tLOGARITHM %d = %.2lf\n\n",num1,dresult);
                    printf("\t\t---------------------------------------------------------\n\n");


                    break;

                case '!':

                    a=3;
                    system("cls");//gereksiz islemlerden kurtulmak icin sayfa temizlenir
                    break;
                default:
                    printf("\n\t\tYOU ENTERED THE WRONG OPTION\n\n");//yanlis secenek girildiginin mesaji verildi
                    printf("\t\t---------------------------------------------------------\n\n");
                    getch();
                }
            }
        }

        else
        {
            printf("\n\t\tSEE YOU LATTER\n\n");
            printf("\t\t---------------------------------------------------------\n\n");

            i=2;
        }

    }
    return 0;
}
