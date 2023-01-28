// Abdullah Salih Öner 21118080733
// Lab1_Homework3
#include <stdio.h>
#include <string.h>
#include <math.h>

void Odev(int length, double array[]) // odev metodu array ve length input olarak veriliyor, verilen array içerde dolduruluyor
{

    int counter = 0;         // çalıştırabilmek için değişken tanımladık
    while (counter < length) // kullanıcın gönderdiği ödev sayısı kadar döngü çalışıyor
    {

        int a = 1;       // do while yapısnın kontrolünü sağlamak için değişken oluşturduk
        double inputNot; // do-while döngüsü kullanabilmek için bir değişken atadık ayrıca kullanıcadan değer almak için kullandık
        do
        {

            printf("Ogrencinin %d. odev notunu giriniz: ", counter + 1);
            scanf("%lf", &inputNot); // Kullanıcdan ödev notlarını alıyoruz

            if (inputNot < 0 || inputNot > 100)
            {
                printf("Lutfen 0 ve 100 araliginda deger giriniz \n"); // kullanıcının girdiği notun belirli aralıkta olup olmadığını sorguladık
            }
            else
            {
                array[counter] = inputNot; // girilen notu odevler arrayimize atadık
                counter++;
                a = 0;
            }

        } while (a == 1);
    }
}

double Hesapla(int ogrNo, int odvSys) // Hesapla Fonksiyonu oluşturduk
{
    struct ogrenci
    {
        double vizeNot;  // Vize notu atanacak değişken
        double finalNot; // Final notu atancak değişken
        double odevNot;
        double odevOrt;
        double genelOrt;
        double odevler[odvSys];
    } ogr;

    int i = 1; // do-while döngüsü kullanabilmek için bir değişken atadık
    do
    {
        printf("%d numarali ogrenci icin vize notunu giriniz : ", ogrNo);
        scanf("%lf", &ogr.vizeNot); // Kullanıcıdan vize notunu aldık

        printf("%d numarali ogrenci icin final notunu giriniz : ", ogrNo);
        scanf("%lf", &ogr.finalNot); // Kullanıcıdan final notunu aldık
        if (ogr.finalNot < 0 || ogr.finalNot > 100 || ogr.vizeNot < 0 || ogr.vizeNot > 100)
        {
            printf("Lutfen 0 ve 100 araliginda deger giriniz \n"); // kullanıcının girdiği notun belirli aralıkta olup olmadığını sorguladık
        }
        else
        {
            i = 0;
        }

    } while (i == 1);

    Odev(odvSys, ogr.odevler); // Odev metodu burda çağrıldı ve Verilen girdiler ile odevler arrayi dolduruldu

    for (int i = 0; i < odvSys; i++) // Odevlerin ortalamasi hesaplandi
    {
        ogr.odevNot += ogr.odevler[i];
    }

    ogr.odevOrt = ogr.odevNot / odvSys;                     // odevlerin ortalaması hesaplatıyoruz
    printf("Odevler Not Ortalmasi : %.2f \n", ogr.odevOrt); // odevlerin ortalamsını yazdırıyoruz

    if (odvSys == 0) // DERSİN ODEVININ OLUP OLMAMASINA GÖRE FARKLI ORANDAKİ NOT ORTALMA HESAPLAMALRINI YAPTIRDIK
    {
        ogr.genelOrt = (ogr.vizeNot * 40) / 100 + (ogr.finalNot * 60) / 100; // ortalamayı hesapladık
    }
    else
    {
        ogr.genelOrt = (ogr.odevOrt * 30) / 100 + (ogr.vizeNot * 30) / 100 + (ogr.finalNot * 40) / 100; // ortalamayı hesapladık
    }

    return ogr.genelOrt; // Ortalmayı döndürdük
}

int main(void)
{
    int ogrNo;     // Öğrenci numrası tutan değişkeni tipinde belirledik
    double notOrt; // Not ortalmasını atayacağımız değişken
    int odvSys;    // Odev saysı değişkeni
    double ogrlerNotOrt[100], max, min;
    double sinifOrt;

    for (int i = 0; i < 100; i++)
    {
        ogrlerNotOrt[i] = -1;
    }

    printf("NOT ORTALAMA HESAPLAMA   \n");
    printf("*************************\n");
    printf("\n");

    int a = 1;
    while (a == 1)
    {
        printf("Lutfen Dersin Odev sayisini giriniz : ");

        if (scanf("%d", &odvSys) == 1) // if else bloğu ile rakam harici karakter girilip girilmediği kontrol ediliyor ve hata veriliyor.
        {
            if (odvSys <= 10 && odvSys >= 0)
            {
                a=0;
            }
            else
            {
                printf("Gecersiz odev sayisi, Odev sayisi 1- 10 araliginda olmalidir !!!\n ");
                a=1;

            }
            
        }
        else
        {
            fflush(stdin); /// fflush() fonksiyonu programın tüm açık fazla çıktılarını temizler.Bu sayede loop a girmez program
            printf("gecersiz karakter girisi ; lutfen sayi girisi yapiniz \n");
            a = 1;
        }
    }

    int counter = 0; // Programın kaç kere çalıştığını takip etmek için oluştrduk ilerde metodlarda kullanacağız

    int b = 1;
    do // Kullanıcının verdiği cevabına göre devam edip etmemeyi do -while yapısı ile yönettik.
    {

        int a = 1;     // while döngüsü kullanabilmek için bir değişken atadık
        while (a == 1) // while döngüsü yardımı ile öğrenci numarasının istenen koşullarda olıp olmadığını test ettik
        {
            printf("Lutfen ogrenciye ait 9 haneli ogrenci numrasini giriniz : ");

            if (scanf("%d", &ogrNo) == 1) // if else bloğu ile rakam harici karakter girilip girilmediği kontrol ediliyor ve hata veriliyor.
            {
                int length = floor(log10(abs(ogrNo))) + 1; // öğrenci numarasının basamak sayısını hesapladık
                if (length == 9)                           // öğrenci numarasının uzunluğunu kontrol ettik
                {
                    a = 0;
                }
                else
                {
                    a = 1;
                    printf("Lutfen 9 haneli!!!!! ogrenci numarasini giriniz \n");
                }
            }
            else
            {
                fflush(stdin); /// fflush() fonksiyonu programın tüm açık fazla çıktılarını temizler.Bu sayede loop a girmez program
                printf("gecersiz karakter girisi ; lutfen sayi girisi yapiniz \n");
                a = 1;
            }

            // scanf("%d", &ogrNo); // Kullanıcıdan öğrenci numarasını aldık
        }

        notOrt = Hesapla(ogrNo, odvSys); // Not ortalamasını sınav yüzdelerine göre hesapladık ve değişkene atadık Hesapla fonksiyonu yardımıyla

        ogrlerNotOrt[counter] = notOrt; // gelen norOrtalamasını diziye atadık
        counter++;                      // Birdaha işlem yapma ihtimalimiz için counter bir artırdık bu sayede array e ortalamaları sırayla ekliycek

        printf("%d numarali ogrencinin not ortalamasi : %.2f\n", ogrNo, notOrt); // Öğrencinin not ortalamasını yazdırdık virgülden sonra iki basamak yazdırdık
        printf("\n");

        int c = 1; // while döngüsü kullanabilmek için bir değişken atadık

        while (c == 1) // Geçersiz bir karar verilmesi durmunda tekrar soruyu soruyor
        {

            char karar[50];
            char forNull;                                                                       // default olarak boş gelen yapıyı değişkene atadık
            printf("Yeni bir ogrenci notu hesaplamak icin '1' ,cikmak icin '0' tuslayiniz : "); // kullanıcıya devam edip etmek isteyip istemediğni sorduk
            scanf("%c", &forNull);                                                              // default olarak boş gelen yapıyı değişkene atadık
            scanf("%s", karar);

            while (1)
            {
                int counter =0;
                for (size_t i = 0; karar[i] != '\0'; i++)
                {
                    counter++;
                }
                if (counter>1)
                {
                    printf("Geçersiz giriş ; \n");
                    printf("Yeni bir ogrenci notu hesaplamak icin '1' ,cikmak icin '0' tuslayiniz");
                    scanf("%s", karar);
                    continue;                    
                }
                break;
                
                
            }
            
            

            if (karar[0]=='0')
            {
                b = 0;
                c = 0;

                for (int i = 0; i < counter; i++)
                {
                    sinifOrt += ogrlerNotOrt[i];
                }

                // max min not belirleme
                max = ogrlerNotOrt[0];
                min = ogrlerNotOrt[0];

                for (int i = 0; i < counter; i++)
                {

                    if (ogrlerNotOrt[i] == -1)
                    {
                        continue;
                    }

                    if (max < ogrlerNotOrt[i])
                    {
                        max = ogrlerNotOrt[i];
                    } // Eğer dizinin herhangi bir elemanı max'tan büyükse yeni max o olacak.

                    if (min > ogrlerNotOrt[i])
                    {
                        min = ogrlerNotOrt[i];
                    } // Aynı şekilde min'den küçük bir eleman var ise yeni min o olacak.
                }

                /////Burada Not ortalması bilgilerini yazdır
                printf("Dersi alan %d ogrenci icin en buyuk not : %.2f \n", counter, max);
                printf("Dersi alan %d ogrenci icin en kucuk not : %.2f\n", counter, min);
                printf("Dersi alan %d ogrenci icin nor ortalamasi : %.2f\n", counter, sinifOrt / counter);

                printf("********************Bizi Tercih Ettiginiz icin tesekkurler************************");
            }
            else if (karar[0]== '1')
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