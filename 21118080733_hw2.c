//Abdullah Salih Öner 21118080733
//Lab1_Homework2
#include <stdio.h>
#include <string.h>
#include <math.h>



double Hesapla(int ogrNo)                                               //Hesapla Fonksiyonu oluşturduk
{
    double vizeNot;  // Vize notu atanacak değişken
    double finalNot; // Final notu atancak değişken

    int i = 1;                                                                                // do-while döngüsü kullanabilmek için bir değişken atadık
    do
    {
        printf("%d numarali ogrenci icin vize notunu giriniz : ", ogrNo);
        scanf("%lf", &vizeNot); // Kullanıcıdan vize notunu aldık

        printf("%d numarali ogrenci icin final notunu giriniz : ", ogrNo);
        scanf("%lf", &finalNot); // Kullanıcıdan final notunu aldık
        if (finalNot < 0 || finalNot > 100 || vizeNot < 0 || vizeNot > 100)
        {
            printf("Lutfen 0 ve 100 araliginda deger giriniz \n");                             //kullanıcının girdiği notun belirli aralıkta olup olmadığını sorguladık
        }
        else
        {
            i = 0;
        }

    } while (i == 1);

    double Ort = (vizeNot * 40) / 100 + (finalNot * 60) / 100;                                   //ortalamayı hesapladık
    return Ort;
}

int main(void)
{
    int ogrNo;       // Öğrenci numrası tutan değişkeni long tipinde belirledik
    double notOrt;   // Not ortalmasını atayacağımız değişken

    printf("NOT ORTALAMA HESAPLAMA   \n");
    printf("*************************\n");
    printf("\n");


    int b = 1;
    do                                               // Kullanıcının verdiği cevabına göre devam edip etmemeyi do -while yapısı ile yönettik.
    {
        int a = 1;                                  // while döngüsü kullanabilmek için bir değişken atadık
        while (a == 1)                              // while döngüsü yardımı ile öğrenci numarasının istenen koşullarda olıp olmadığını test ettik
        {
            printf("Lutfen ogrenciye ait 9 haneli ogrenci numrasini giriniz : ");
            scanf("%d", &ogrNo);                                                     // Kullanıcıdan öğrenci numarasını aldık
            int length = floor(log10(abs(ogrNo))) + 1;                        //öğrenci numarasının basamak sayısını hesapladık
            if (length == 9)                                                         //öğrenci numarasının uzunluğunu kontrol ettik
            {
                a = 0;
            }
            else
            {
                a = 1;
                printf("Lutfen 9 haneli!!!!! ogrenci numarasini giriniz \n");
            }
        }

        notOrt = Hesapla(ogrNo);                   // Not ortalamasını sınav yüzdelerine göre hesapladık ve değişkene atadık Hesapla fonksiyonu yardımıyla

        printf("%d numarali ogrencinin not ortalamasi : %.2f\n", ogrNo, notOrt);    // Öğrencinin not ortalamasını yazdırdık virgülden sonra iki basamak yazdırdık
        printf("\n");

        int c = 1;                                                                  // while döngüsü kullanabilmek için bir değişken atadık
        while (c == 1)                                                              //Geçersiz bir karar verilmesi durmunda tekrar soruyu soruyor
        {

            char karar;
            char forNull;       //default olarak boş gelen yapıyı değişkene atadık
            printf("Yeni bir ogrenci notu hesaplamak icin '1' ,cikmak icin '0' tuslayiniz : "); // kullanıcıya devam edip etmek isteyip istemediğni sorduk
            scanf("%c",&forNull); //default olarak boş gelen yapıyı değişkene atadık
            scanf("%c", &karar); 
           

            if (karar == '0')
            {
                b = 0;
                c = 0;
                printf("********************Bizi Tercih Ettiginiz icin tesekkurler************************");
            }
            else if (karar == '1')
            {
                b = 1;
                c = 0;
            }
            else
            {
                printf("Gecersiz sayi \n");
            }
        } 

        

    } while (b == 1);

    return 0;
}

