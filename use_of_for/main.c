#include <stdio.h>
#include <stdlib.h>
// MUAZZEZ NIHAL BAHADIR  


void M(int s)
{
    int i,j;

    for (i=1; i<=s; i++)
    {
        printf("\t\t");
        for (j=s; j>0; j--)//ters caprazi yaparken karistirmamak icin bu sekilde yaptim
        {
            if(s%2==0)
            {

                if(j==1||j==s||j==i&&i<=s/2||i<=s/2&&j==s-i+1)//boyut cift ise orta bulunamadigindan ortaya nokta konmaz
                    printf("*");
                else
                    printf(" ");
            }
            else
            {
                if(j==1||j==s||j==i&&i<=s/2||i<=s/2&&j==s-i+1||i==s/2+1&&j==s/2+1)//tek sayi boyut olarak girildiginde ortaya bi tane daha yildiz koyar
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
    }

}
void U(int s)
{
    int i,j;

    for (i=1; i<=s; i++)
    {
        printf("\t\t");
        for (j=1; j<=s; j++)
        {
            if(j==1||j==s||i==s)//temelleri atildi
                printf("*");
            else
                printf(" ");
        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
    }

}
void A(int s)
{
    int i,j;

    for (i=1; i<=s; i++)
    {
        printf("\t\t");
        for (j=1; j<=s; j++)
        {
            if(j==1||i==j||i==s/2+1&&j<=s-i)//temel sartlar girildi
                printf("*");
             else
                printf(" ");
        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
    }

}
void Z(int s)
{
    int i,j;


    for (i=1; i<=s; i++)
    {
        printf("\t\t");
        for (j=s; j>0; j--)//ortaya ters capraz cizgi cizmem gerektiginden donguyu sondan baslattim
        {
            if(i==1||i==s||j==i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
    }
}
void E(int s)
{
    int i,j;

    for (i=1; i<=s; i++)
    {
        printf("\t\t");
        for (j=1; j<=s; j++)
        {
            if(i==1||i==s/2||j==1||i==s)//ortadan cizgi cekmek icin i==s/2 kullanildi
                printf("*");
            else
                printf(" ");
        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
    }
}
void N(int s)
{
    int i,j;

    for (i=1; i<=s; i++)//satir kontrolü saglandi
    {
        printf("\t\t");
        for (j=1; j<=s; j++)//sutun kontrolu saglandi
        {
            if (j==1||j==s||i==j) //capraz sekil icin i==j kullanildi
                printf("*");
            else
                printf(" ");//komutlar haricine boþluk koyar
        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
    }
}
void I(int s)
{
    int i,j;

    for (i=1; i<=s; i++)
    {
        printf("\t\t");
        for (j=1; j<=s; j++)
        {
            if(j==s/2)//ortaya cizgi koydu
                printf("*");
            if(i==1||i==s)//basa ve sona cizgi koydu
                printf("*");
            else
                printf(" ");
        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
    }

}
void H(int s)
{
    int i,j;

    for (i=1; i<=s; i++)
    {
        printf("\t\t");
        for (j=1; j<=s; j++)
        {
            if(j==1||j==s||i==s/2)//ortadan cizgi cekmek icin i==s/2 kullanildi
            {
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
    }
}
void L(int s)
{
    int i,j;

    for (i=1; i<=s; i++)
    {
        printf("\t\t");
        for (j=1; j<=s; j++)
        {
            if (i==s||j==1)//bir sutun ve bir satirdan oluþmaktadir
            {
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
    }
}
void B(int s)
{
    int i,j;

    for (i=1; i<=s; i++)
    {
        printf("\t\t");
        for (j=1; j<=s; j++)
        {
            if(j==1||i==1||i==s)//temelleri koyuldu
            {
                printf("*");
            }
            else if(i==s/2&& j<s)//bu dizeden sonra yapilan islemler tamamen tek yildizi koymamak icindi
            {
                printf("*");
            }

            else if(i>s/2&&j==s)
                printf("*");
            else if (i<s/2&&j==s)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)

    }
}
void D(int s)
{
    int i,j;

    for (i=1; i<=s/2; i++)//d yi capraz cizgilerle yapmak istedigimden ikiye boldum
    {
        printf("\t\t");
        for (j=1; j<=s; j++)
        {
            if(j==1||j==i+2)
                printf("*");
            else
                printf(" ");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
        }
        printf("\n");
    }
    for (i=1; i<s/2; i++)
    {
        printf("\t\t");
        for (j=s; j>=1; j--)//ters capraz cizgi cizebilmek icin gerekli olanlar
        {
            if(j==s||j==i+(s/2))
                printf("*");
            else
                printf(" ");

        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
    }

}
void R(int s)
{
    int i,j;
    for (i=1; i<=s/2; i++)//yarisinda capraz kullanilacagindan dolayi i ikiye bolundu
    {
        printf("\t\t");
        for (j=1; j<=s; j++)
        {
            if(i==1||j==1||j==s||i==s)//normal bir kare cizildi
                printf("*");
            else
                printf(" ");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)
        }
        printf("\n");
    }
    for (i=1; i<=s/2; i++)//r nin belden altinin duzenlemesi
    {
        printf("\t\t");
        for (j=1; j<=s; j++)
        {
            if(i==1||j==i+3||j==1)//r seklini belirtebilmek icin i degeri uc deger ileriden baslatildi
                printf("*");
            else
                printf(" ");
        }
        printf("\n");//satir ve sutunu ayirmak icin kullanýlýr(j tamamlaninca satir atlatir)

    }
}
void gap(int s)
{
    int i,j;
    for(i=0; i<s; i++)
    {
        printf("\t\t");
        for(j=0; j<s; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}



int main()
{
    int line;
    printf("Please enter which size you want:");
    scanf("%d",&line);

    M(line);
    printf("\n");


    U(line);
    printf("\n");

    A(line);
    printf("\n");

    Z (line);
    printf("\n");

    Z(line);
    printf("\n");

    E (line);
    printf("\n");

    Z(line);
    printf("\n");
    gap(line);

    N (line);
    printf("\n");

    I(line);
    printf("\n");

    H (line);
    printf("\n");

    A(line);
    printf("\n");

    L(line);
    printf("\n");
    gap(line);

    B(line);
    printf("\n");

    A(line);
    printf("\n");

    H(line);
    printf("\n");

    A(line);
    printf("\n");

    D(line);
    printf("\n");

    I(line);
    printf("\n");

    R(line);
    printf("\n");



    return 0;
}
