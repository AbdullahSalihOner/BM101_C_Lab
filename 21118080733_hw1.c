//Abdullah Salih Öner 21118080733
//Lab1_Homework1
#include <stdio.h>

int main(void)
{
    int ogrSayi; //Girilen Öğrenci sayısını tutan değişken
    long long ogrNo; // Öğrenci numrası tutan değişkeni long tipinde belirledik
    double vizeNot; // Vize notu atanacak değişken
    double finalNot; // Final notu atancak değişken
    double notOrt; // Not ortalmasını atayacağımız değişken

    printf("NOT ORTALAMA HESAPLAMA   \n");
    printf("*************************\n");
    printf("\n");

    printf("Lutfen Ogrenci Sayisi Giriniz :");
    scanf("%i" , &ogrSayi); //Kullanıcıdan öğrenci sayısını aldık
    printf("\n");

    for(int i = 1 ; i <= ogrSayi; i++)// for döngüsü sayesinde her öğrenci için aynı işlemleri yaptırdık .
    {
        printf("Lutfen %d.ogrenciye ait ogrenci numrasini giriniz : ",i); // Her seferinde kaçıncı öğrenci olduğunu yazdırdık
        scanf("%lld" , &ogrNo); // Kullanıcıdan öğrenci numarasını aldık

        printf("%lld numarali ogrenci için vize notunu giriniz : " ,ogrNo);
        scanf("%lf" , &vizeNot); // Kullanıcıdan vize notunu aldık

        printf("%lld numarali ogrenci icin final notunu giriniz : ",ogrNo);
        scanf("%lf" , &finalNot); // Kullanıcıdan final notunu aldık

        notOrt = (vizeNot*40)/100 + (finalNot*60)/100 ;  // Not ortalamasını sınav yüzdelerine göre hesapladık ve değişkene atadık

        printf("%lld numarali ogrencinin not ortalamasi : %f\n", ogrNo ,notOrt); // Öğrencinin not ortalamasını yazdırdık
        printf("\n");

    } //For döngüsü sonu
}