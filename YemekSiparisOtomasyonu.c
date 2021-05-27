#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
//#include <unistd.h>  //!linux isletim sistemi icin gecerlidir.
#define musteriSayisi 1000

// Kullanilan degiskenler..
int fisIslemSayaci = 0;
float karttakiPara[100];
float kasadakiPara;
float toplamTutar = 0.0;
int musteriSirasi = 0;
short satir, kolon;

// Structlarin tanimi
struct musteriBilgileri
{
    char musteriIsmi[25];
    char musteriSoyismi[25];
    char musteriEMail[50];
    char musteriSifre[25];
    int musteriId;

    char sehir[20];
    char ilce[20];
    char semt[20];
    char sokak[45];
    char apartmanIsmi[10];
    char daireNo[10];

    char kartSahibiAdi[20];
    char kartNumarasi[20];
    char gecerlilikTarihi[5]; // tarih ay/yil seklinde
    char guvenlikKodu[3];
};

struct musteriler
{
    struct musteriBilgileri musteri;
};

struct iceceklerBilgi
{
    char adi[20];
    int stokAdedi;
    float fiyati;
};

struct kebaplarBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct donerlerBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct hamburgerlerBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct corbalarBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct evYemekleriBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct pizzalarBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct pidelerBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct baliklarBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct salatalarBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct tatlilarBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct menuBilgi
{
    struct iceceklerBilgi icecekler;
    struct kebaplarBilgi kebap;
    struct donerlerBilgi doner;
    struct hamburgerlerBilgi hamburger;
    struct corbalarBilgi corba;
    struct evYemekleriBilgi evYemekleri;
    struct pizzalarBilgi pizza;
    struct pidelerBilgi pide;
    struct baliklarBilgi balik;
    struct salatalarBilgi salata;
    struct tatlilarBilgi tatli;
};
struct menuBilgi Yemek_Menu;

//Structlar - fonksiyon // Yemek Secimi
void kebapSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n);
void kebapBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac);

void donerSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n);
void donerBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac);

void hamburgerSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n);
void hamburgerBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac);

void corbaSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n);
void corbaBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac);

void evYemekleriSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n);
void evYemekleriBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac);

void pizzaSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n);
void pizzaBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac);

void pideSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n);
void pideBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac);

void balikSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n);
void balikBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac);

void salataSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n);
void salataBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac);

void tatliSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n);
void tatliBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac);

void icecekSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n);
void icecekBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac);

void icecekBilgisiCek(struct menuBilgi *x);
void kebapBilgisiCek(struct menuBilgi *x);
void donerBilgisiCek(struct menuBilgi *x);
void hamburgerBilgisiCek(struct menuBilgi *x);
void corbaBilgisiCek(struct menuBilgi *x);
void evYemekleriBilgisiCek(struct menuBilgi *x);
void pizzaBilgisiCek(struct menuBilgi *x);
void pideBilgisiCek(struct menuBilgi *x);
void balikBilgisiCek(struct menuBilgi *x);
void salataBilgisiCek(struct menuBilgi *x);
void tatliBilgisiCek(struct menuBilgi *x);
void yemekBilgisiCek(struct menuBilgi *x);
void mBilgiCek(struct musteriler *y);
void mGirisiBilgisiCek(struct musteriler *y);
void kredikartiBilgisiCek(struct musteriler *y);

// Ekleme ve guncelleme Fonksiyonlari
void yemek_ekle(int veri, char yemekAdi[25], int miktar, float fiyat);
void fiyat_guncelle();
void musteriBilgileriGoruntule(struct musteriler *y, struct menuBilgi *x);
void onlineOdeme(struct musteriler *y, struct menuBilgi *x, float *fiyatToplam, int *musteriSirasi);
void odemeYontemi(struct musteriler *y, struct menuBilgi *x);
void kapidaOdeme(struct musteriler *y, struct menuBilgi *x, float *fiyatToplam, int *musteriSirasi);
void siparisBilgileriGoruntule();

// islev fonksiyonlari
void siparisDetaylari(float *fiyatToplam, float tekFiyat, char isim[], int fisIslemSayaci);
int kasaBilgiOku();
void kasaBilgiYaz(int toplam);
void yeniMusteriOlustur(struct musteriler *y, struct menuBilgi *x);
void kayitliMusteriKontrol(struct musteriler *y, struct menuBilgi *x);
void kredikartiBilgisiKontrol();
void mGirisiBilgisiCek(struct musteriler *y);


// Menu fonksiyonlari
void yemek_listesi(struct musteriler *y, int n, struct menuBilgi *x);
void admin_menu(struct musteriler *y, struct menuBilgi *x);
void bireyselMusteriGoruntule(struct musteriler *y, struct menuBilgi *x, int siraMusteri);
void kayitliMusteriMenu(struct musteriler *y, struct menuBilgi *x, int *musteriSirasi);
void musteriGirisiMenu(struct musteriler *y, struct menuBilgi *x);
void siparis_menu(int siparis, int miktar, int sip_kodu, struct menuBilgi *x);
void ana_menu(struct musteriler *y, struct menuBilgi *x);
void uygulamayiKapat();
void gecersizGiris();
int secimFonksiyonu();
void hakkimizdaGoruntule(struct musteriler *y, struct menuBilgi *x);

// Yemek fonksiyonlari
void kebap();
void doner();
void corba();
void evYemekleri();
void balik();
void pizza();
void pide();
void hamburger();
void salata();
void tatli();
void icecekler();

// Tasarim fonksiyonlari
void tamEkran();
void cls();
void echo(char print[]);
void satir_bas(int line);
void tab_bas(int tab);
void bosluk_bas(int space);
void cerceve();
void karsilama();
void ilerleme();
void menuRenk();
void zamanGoster();

int main()
{
    tamEkran(); // Konsol ekranini tam ekran seklinde donusturme.
    system("title Marmara Kebap House");
    
    struct musteriBilgileri musteri[musteriSayisi];

    struct menuBilgi *ptrYemek_Menu;
    ptrYemek_Menu = (struct menuBilgi *)malloc(100 * sizeof(struct menuBilgi));
    yemekBilgisiCek(ptrYemek_Menu);

    struct musteriler *ptrMusteriBilgi;
    ptrMusteriBilgi = (struct musteriler *)malloc(100 * sizeof(struct musteriler));
    mGirisiBilgisiCek(ptrMusteriBilgi);
    mBilgiCek(ptrMusteriBilgi);
    kredikartiBilgisiCek(ptrMusteriBilgi);
    
    ilerleme();
    cls();
    karsilama();
    cls();

    ana_menu(ptrMusteriBilgi, ptrYemek_Menu);
}

void ana_menu(struct musteriler *y, struct menuBilgi *x)
{
    cls();
    int i, n = 0;
    char anaMenuListesi[4][20] = {"Musteri Girisi", "Admin Girisi", "Hakkimizda", "Cikis"};
    tab_bas(12);
    echo("     MARMARA KEBAP HOUSE");
    zamanGoster();
    cerceve();
    satir_bas(1);
    tab_bas(13);
    echo("  (Anamenu)");
    satir_bas(12);

    for (i = 0; i < 4; i++)
    {
        satir_bas(2);
        tab_bas(12);
        printf("==>  [%d]. %s\n\n", i + 1, anaMenuListesi[i]);
        Sleep(100);
    }
    satir_bas(2);
    int anaSecim = secimFonksiyonu();
    switch (anaSecim)
    {
    case 1:
        musteriGirisiMenu(y, x);
        break;

    case 2:
        admin_menu(y, x);
        break;

    case 3:
        hakkimizdaGoruntule(y, x);
        break;

    case 4:
        uygulamayiKapat();

    default:
        gecersizGiris(y, x);
        break;
    }
}

void musteriGirisiMenu(struct musteriler *y, struct menuBilgi *x)
{
    int i;
    char musteriMenuListesi[2][25] = {"Yeni Musteri", "Kayitli Musteri"};
    menuRenk();
    tab_bas(12);
    echo("     MARMARA KEBAP HOUSE");
    zamanGoster();
    cerceve();
    satir_bas(1);
    tab_bas(12);
    echo("   (Musteri Giris Ekrani)");
    satir_bas(12);

    for (i = 0; i < 2; i++)
    {
        satir_bas(2);
        tab_bas(12);
        printf("==>  [%d]. %s\n\n", i + 1, musteriMenuListesi[i]);
        Sleep(100);
    }
    satir_bas(2);
    int musteriSecim = secimFonksiyonu();
    switch (musteriSecim)
    {
    case 0:
        ana_menu(y, x);
        break;
    case 1:
        yeniMusteriOlustur(y, x);
        break;

    case 2:
        kayitliMusteriKontrol(y, x);
        break;

    default:
        gecersizGiris(y, x);
        break;
    }
}


void yeniMusteriOlustur(struct musteriler *y, struct menuBilgi *x)
{
    int musteriID = 0, satirSayac = 0; //musteri ID numarası satir sayisi ile esitlenmelidir.
    char c;
    char gAd[20], gSoyad[20], gMail[20], gSifre[20], gSehir[20], gIlce[20], gSemt[20],
        gSokak[20], gDaireno[20], gApartman[20];

    FILE *fpp;
    fpp = fopen("musteriGirisiBilgisi.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    musteriID = satirSayac + 2;

    menuRenk();
    tab_bas(12);
    echo("(Yeni Musteri)\n");
    Sleep(200);
    tab_bas(8);
    cerceve();
    Sleep(200);
    satir_bas(3);
    tab_bas(9);
    printf("E-posta:");
    scanf("%s", gMail);
    satir_bas(1);
    tab_bas(9);
    printf("Sifre:");
    scanf("%s", gSifre);
    satir_bas(1);
    tab_bas(9);

    FILE *Fp = fopen("musteriGirisiBilgisi.txt", "a");
    if (Fp == NULL)
    {
        tab_bas(11);
        puts("!!! musteriGirisiBilgisi.txt Dosya olusturulamadi !!!\n");
        Sleep(500);
        exit(1);
    }
    else
    {
        fprintf(Fp, "\n%s\t%s\t%d", gMail, gSifre, musteriID);
    }
    fclose(Fp);

    echo("- Adiniz:");
    scanf("%s", gAd);
    satir_bas(1);
    tab_bas(9);
    echo("- Soyadiniz:");
    scanf("%s", gSoyad);
    satir_bas(1);
    tab_bas(9);
    echo("- Evinizin bulundugu sehir:");
    scanf("%s", gSehir);
    satir_bas(1);
    tab_bas(9);
    echo("- Ilce: ");
    scanf("%s", gIlce);
    satir_bas(1);
    tab_bas(9);
    echo("- Mahalle: ");
    scanf("%s", gSemt);
    satir_bas(1);
    tab_bas(9);
    echo("- Sokak: ");
    scanf("%s", gSokak);
    satir_bas(1);
    tab_bas(9);
    echo("- Apartman ismi:");
    scanf("%s", gApartman);
    satir_bas(1);
    tab_bas(9);
    echo("- Daire NO: ");
    scanf("%s", gDaireno);
    satir_bas(1);
    tab_bas(10);

    FILE *Fpk = fopen("musteriBilgileri.txt", "a");
    if (Fpk == NULL)
    {
        tab_bas(11);
        puts("!!! musteriBilgileri.txt Dosya olusturulamadi !!!\n");
        Sleep(500);
        exit(1);
    }
    else
    {
        fprintf(Fpk, "\n%s %s %s %s %s %s %s %s", gAd, gSoyad, gSehir, gIlce, gSemt, gSokak, gApartman, gDaireno);
    }
    fclose(Fpk);

    Sleep(300);
    echo("Basariyla kayit olusturulmustur.\n");
    tab_bas(10);
    echo("Tekrar giris yaparak siparis verebilirsiniz.\n");
    satir_bas(1);
    cerceve();
    getch();
    mBilgiCek(y);
    mGirisiBilgisiCek(y);
    ana_menu(y, x);
}

void kayitliMusteriKontrol(struct musteriler *y, struct menuBilgi *x)
{
    cls();
    system("color 3E");

    int i, n = 0, satirSayac = 0, onayla = 0;
    char c;
    char mail[40], sifre[40];

    FILE *fp;

    fp = fopen("musteriGirisiBilgisi.txt", "r");
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fp);

    satir_bas(3);
    tab_bas(10);
    printf("- Lutfen e-posta adresi giriniz:");
    scanf("%s", &mail);
    tab_bas(10);
    printf("- Sifrenizi giriniz:");
    scanf("%s", &sifre);

    for (i = 0; i <= satirSayac; i++)
    {
        if (strcmp((y + i)->musteri.musteriEMail, mail) == 0 && strcmp((y + i)->musteri.musteriSifre, sifre) == 0)
        {
            satir_bas(2);
            tab_bas(10);
            printf("Giris Basarili...");
            Sleep(1500);
            onayla = 1;
            musteriSirasi = i + 1;
            break;
        }
    }
    if (onayla)
    {
        kayitliMusteriMenu(y, x, &musteriSirasi);
    }
    else
    {
        gecersizGiris(y, x);
    }
}

void kredikartiBilgisiKontrol(struct musteriler *z)
{
hataliTuslama:
    cls();
    system("color 3E");

    int i, n = 0, satirSayac = 0, onayla = 0;
    char c, kartNumarasi[16], gecerlilikTarihi[4], kartSahibiAdi[50], guvenlikKodu[3];

    FILE *fp;
    fp = fopen("bankaBilgileriKrediKarti.txt", "r");
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            satirSayac = satirSayac + 1;
    fclose(fp);

    satir_bas(3);
    tab_bas(9);
    echo("- Lutfen Kart Bilgilerini Giriniz:");
    satir_bas(3);
    tab_bas(9);
    echo("- Kredi karti numaraniz:");
    scanf("%s", &kartNumarasi);
    satir_bas(1);
    tab_bas(9);
    echo("- Kredi karti sahibi adi ve soyadi (bitisik yazilmalidir!!): ");
    scanf("%s", &kartSahibiAdi);
    satir_bas(1);
    tab_bas(9);
    echo("- Kredi karti son gecerlilik tarihi (ay ve yil bitisik yazilmalidir!!): ");
    scanf("%s", &gecerlilikTarihi);
    satir_bas(1);
    tab_bas(9);
    echo("- Kredi karti guvenlik numaraniz: ");
    scanf("%s", &guvenlikKodu);
    satir_bas(2);
    tab_bas(9);
    echo("Kart bilgileriniz bankanizla kontrol ediliyor...");
    Sleep(2000);
    satir_bas(2);

    for (i = 0; i <= satirSayac; i++)
    {
        if (strcmp((z + i)->musteri.kartNumarasi, kartNumarasi) == 0 && strcmp((z + i)->musteri.kartSahibiAdi, kartSahibiAdi) == 0 && strcmp((z + i)->musteri.gecerlilikTarihi, gecerlilikTarihi) == 0 && strcmp((z + i)->musteri.guvenlikKodu, guvenlikKodu) == 0)
        {
            satir_bas(2);
            tab_bas(10);
            printf("Giris Basarili...\n");
            Sleep(1500);
            onayla = 1;
            break;
        }
    }
    if (onayla)
    {
        tab_bas(9);
        echo("Bankaniz tarafindan onaylandi...");
        Sleep(1000);
    }
    else
    {
        tab_bas(9);
        echo("Gecersiz kart bilgileri!!! Tekrar giris yapiniz.");
        Sleep(3000);
        goto hataliTuslama;
    }
}

void kayitliMusteriMenu(struct musteriler *y, struct menuBilgi *x, int *musteriSirasi)
{

    int siraMusteri;
    siraMusteri = *musteriSirasi;

    int i, n = 0;
    char kayitliMusteriMenuListesi[2][30] = {"Siparis Ver", "Bilgilerimi Goruntule"};
hataliTuslama:
    menuRenk();

    tab_bas(12);
    echo("     MARMARA KEBAP HOUSE");
    zamanGoster();
    cerceve();
    satir_bas(1);
    tab_bas(12);
    echo("  (Kayitli Musteri Menusu)");
    satir_bas(12);

    for (i = 0; i < 2; i++)
    {
        satir_bas(2);
        tab_bas(12);
        printf("==>  [%d]. %s\n\n", i + 1, kayitliMusteriMenuListesi[i]);
        Sleep(100);
    }
    satir_bas(2);
    int kayitliMusteriSecim = secimFonksiyonu();
    switch (kayitliMusteriSecim)
    {
    case 0:
        ana_menu(y, x);
        break;
    case 1:
        yemek_listesi(y, n, x);
        break;
    case 2:
        bireyselMusteriGoruntule(y, x, siraMusteri);
        break;
    default:
        cls();
        satir_bas(10);
        tab_bas(11);
        echo("   Gecersiz giris yaptiniz !!");
        Sleep(900);
        goto hataliTuslama;
        break;
    }
}

void bireyselMusteriGoruntule(struct musteriler *y, struct menuBilgi *x, int siraMusteri)
{
    int i, satirSayac = 0;
    char c;

    menuRenk();
    tab_bas(11);
    echo("* * * * * Bilgileriniz * * * * *\n");
    cerceve();
    satir_bas(3);
    tab_bas(9);

    printf("Adiniz: %s       Soyadiniz: %s", (y + (siraMusteri - 1))->musteri.musteriIsmi, (y + (siraMusteri - 1))->musteri.musteriSoyismi);
    satir_bas(3);
    tab_bas(9);
    printf("Adres Bilginiz:\n");
    tab_bas(9);
    printf("Sehir:   %s   Ilce:   %s   Semt/Mahalle:   %s\n", (y + (siraMusteri - 1))->musteri.sehir, (y + (siraMusteri - 1))->musteri.ilce, (y + (siraMusteri - 1))->musteri.semt);
    tab_bas(9);
    printf("Sokak:   %s   Apartman Ismi:   %s   Daire No:   %s\n\n", (y + (siraMusteri - 1))->musteri.sokak, (y + (siraMusteri - 1))->musteri.apartmanIsmi, (y + (siraMusteri - 1))->musteri.daireNo);

    satir_bas(3);
    tab_bas(9);

    echo("Herhangi bir tusa basarak kendi sayfaniza donebilirsiniz.");
    satir_bas(3);
    cerceve();
    getch();
    kayitliMusteriMenu(y, x, &musteriSirasi);
}

void admin_menu(struct musteriler *y, struct menuBilgi *x)
{
    menuRenk();
    echo("\n\nSifrenizi girin: ");
    int adminSecim = secimFonksiyonu();

    if (adminSecim == 0)
    {
        ana_menu(y, x);
    }

    else if (adminSecim != 12345)
    {
        cls();
        bosluk_bas(5);
        tab_bas(9);
        echo("Giris yaparken hatali tuslama yaptiniz...\n\n");
        Sleep(1000);
        ana_menu(y, x);
    }

    else if (adminSecim == 12345)
    {
        cls();
        satir_bas(10);
        tab_bas(12);
        echo("Basariyla Giris Yaptiniz...");
        Sleep(1000);

    admin:
        cls();

        int i;
        char adminMenuListesi[5][40] = {"Ana Menuye Don", "Gunluk Butce", "Musteri Bilgileri", "Siparis Bilgileri", "Yemekleri Guncelle"};
        satir_bas(2);
        tab_bas(12);
        echo("      (Admin Menu)");
        cerceve();
        satir_bas(7);
        for (i = 0; i < 5; i++)
        {
            satir_bas(2);
            tab_bas(12);
            printf("==>  [%d]. %s\n\n", i, adminMenuListesi[i]);
            Sleep(100);
        }

        int adminSecim = secimFonksiyonu();
        switch (adminSecim)
        {
        case 0:
            ana_menu(y, x);
            break;

        case 1:
            kasadakiPara = kasaBilgiOku();
            cls();
            satir_bas(10);
            cerceve();
            satir_bas(2);
            tab_bas(11);
            printf("Kasaya giren toplam para : %.2f ", kasadakiPara);
            satir_bas(3);
            cerceve();
            getchar();
            Sleep(3000);
            goto admin;
            break;

        case 2:
            cls();
            musteriBilgileriGoruntule(y, x);
            goto admin;
            break;

        case 3:
            cls();
            siparisBilgileriGoruntule(y, x);
            goto admin;
            break;

        case 4:
            cls();
            int n;
            yemek_listesi(y, n, x);
            getchar();
            Sleep(3000);
            goto admin;
            break;

        default:
            cls();
            satir_bas(1);
            tab_bas(11);
            puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
            goto admin;
            break;
        }
    }
}

void yemek_listesi(struct musteriler *y, int n, struct menuBilgi *x)
{
    int i;
    char yemekListesi[11][15] = {"Kebaplar", "Donerler", "Hamburgerler", "Corbalar", "Ev Yemekleri",
                                 "Pizzalar", "Pideler", "Baliklar", "Salatalar", "Tatlilar", "Icecekler"};
    menuRenk();

    tab_bas(12);
    echo("   (Yemek Listesi)");
    cerceve();
    satir_bas(8);
    for (i = 0; i < 11; i++)
    {
        bosluk_bas(1);
        tab_bas(12);
        Sleep(100);
        printf("==>  [%d]. %s\n\n", i + 1, yemekListesi[i]);
    }
    Sleep(100);

    int listeSecim = secimFonksiyonu();

    switch (listeSecim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        kebap(y, n, x);
        break;

    case 2:
        doner(y, n, x);
        break;

    case 3:
        hamburger(y, n, x);
        break;

    case 4:
        corba(y, n, x);
        break;

    case 5:
        evYemekleri(y, n, x);
        break;

    case 6:
        pizza(y, n, x);
        break;

    case 7:
        pide(y, n, x);
        break;

    case 8:
        balik(y, n, x);
        break;

    case 9:
        salata(y, n, x);
        break;

    case 10:
        tatli(y, n, x);
        break;

    case 11:
        icecekler(y, n, x);
        break;

    default:
        gecersizGiris(y, x);
        break;
    }
}

void icecekler(struct musteriler *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("icecekler.tsv", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Icecek Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i) 
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("===========================>   [%d].%14s: %7.2f%25s   ", i + 1, (x + i)->icecekler.adi, (x + i)->icecekler.fiyati, "    <==========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        icecekBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        icecekSecimVeFiyatlandirma(y, x, n);
    }
}

void icecekSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n)
{
    FILE *Fp = fopen("kasadakiPara.txt", "a");
    if (Fp == NULL)
    {
        tab_bas(8);
        puts(" kasadakiPara.txt Dosya olusturulamadi.\n");
        Sleep(300);
        exit(1);
    }
    fclose(Fp);
    echo("\n");
    fisIslemSayaci = 3;
    int icecek_secim = secimFonksiyonu();
    switch (icecek_secim)
    {
    case 0:
        tab_bas(8);
        echo("Icecek istemediginizden emin misiniz? Evet 1 / Hayir 0 \n");
        int tercih = secimFonksiyonu();
        if (tercih)
        {
            tab_bas(8);
            printf("Aldiklariniz %.2f TL tutmustur.\n", toplamTutar);
            tab_bas(8);
            echo("Siparisiniz hazirlaniyor. Odeme Ekranina yonlendiriliyorsunuz...");
            Sleep(1100);
            kasadakiPara = kasaBilgiOku(); //kasadakiPara dosyadan okunuyor son yazan bakiye kasadakiPara degiskenine atiliyor.
            kasadakiPara += toplamTutar;   //islem gerceklesti.
            kasaBilgiYaz(kasadakiPara);    //kasadakiPara degiskenindeki deger dosyaya yaziliyor.
            odemeYontemi(y, x);
        }
        else
        {
            icecekler(y, n, x);
        }
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->icecekler.fiyati, (x + 0)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku(); //kasadakiPara dosyadan okunuyor son yazan bakiye kasadakiPara degiskenine atiliyor.
        kasadakiPara += toplamTutar;   //islem gerceklesti.
        kasaBilgiYaz(kasadakiPara);    //kasadakiPara degiskenindeki deger dosyaya yaziliyor.
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->icecekler.fiyati, (x + 1)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->icecekler.fiyati, (x + 2)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->icecekler.fiyati, (x + 3)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->icecekler.fiyati, (x + 4)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->icecekler.fiyati, (x + 5)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->icecekler.fiyati, (x + 6)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        break;
    default:
        cls();
        icecekler(y, n, x);
        break;
    }
    Sleep(1000);
    fisIslemSayaci = 0;
    odemeYontemi(y, x);
}

void icecekBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac)
{
    int icecekGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    icecekGuncelleme = secimFonksiyonu();
    satir_bas(3);
    switch (icecekGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[0].icecekler.adi);
        scanf("%f", &x[0].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[0].icecekler.fiyati);
        break;
    case 2:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[1].icecekler.adi);
        scanf("%f", &x[1].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[1].icecekler.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[2].icecekler.adi);
        scanf("%f", &x[2].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[2].icecekler.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[3].icecekler.adi);
        scanf("%f", &x[3].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[3].icecekler.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[4].icecekler.adi);
        scanf("%f", &x[4].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[4].icecekler.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[5].icecekler.adi);
        scanf("%f", &x[5].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[5].icecekler.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[6].icecekler.adi);
        scanf("%f", &x[6].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[6].icecekler.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    // Degistirilen bilgilerin tekrar yeni bir dosya acilarak yazdirilmasi

    int i;
    FILE *fpp;
    fpp = fopen("icecekler.tsv", "w");
    for (i = 0; i < satirSayac; i++)
    {
        fprintf(fpp, "\n%s\t%d\t%f", (x + i)->icecekler.adi, (x + i)->icecekler.stokAdedi, (x + i)->icecekler.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void kebap(struct musteriler *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("kebaplar.tsv", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);

    echo("Kebap Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>     [%d].%14s: %7.2f%25s  ", i + 1, (x + i)->kebap.adi, (x + i)->kebap.fiyati, "     <=========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        kebapBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        kebapSecimVeFiyatlandirma(y, x, n);
    }
}

void kebapBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac)
{
    int kebapGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    kebapGuncelleme = secimFonksiyonu();

    switch (kebapGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].kebap.adi);
        scanf("%f", &x[0].kebap.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].kebap.fiyati);
        break;

    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].kebap.adi);
        scanf("%f", &x[1].kebap.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].kebap.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].kebap.adi);
        scanf("%f", &x[2].kebap.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].kebap.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("kebaplar.tsv", "w");

    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s\t%d\t%f", (x + i)->kebap.adi, (x + i)->kebap.malzemeAdedi, (x + i)->kebap.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void kebapSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int kebap_secim = secimFonksiyonu();

    switch (kebap_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->kebap.fiyati, (x + 0)->kebap.adi, fisIslemSayaci); // 0
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->kebap.fiyati, (x + 1)->kebap.adi, fisIslemSayaci); // 0
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->kebap.fiyati, (x + 2)->kebap.adi, fisIslemSayaci); // 0
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    default:
        cls();
        gecersizGiris(y, x);
        break;
    }
}

void doner(struct musteriler *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("donerler.tsv", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Doner Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>     [%d].%14s: %7.2f%25s  ", i + 1, (x + i)->doner.adi, (x + i)->doner.fiyati, "     <=========================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        donerBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        donerSecimVeFiyatlandirma(y, x, n);
    }
}

void donerSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int doner_secim = secimFonksiyonu();

    switch (doner_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->doner.fiyati, (x + 0)->doner.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->doner.fiyati, (x + 1)->doner.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->doner.fiyati, (x + 2)->doner.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void donerBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac)
{
    int donerGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    donerGuncelleme = secimFonksiyonu();

    switch (donerGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].doner.adi);
        scanf("%f", &x[0].doner.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].doner.fiyati);
        break;

    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].doner.adi);
        scanf("%f", &x[1].doner.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].doner.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].doner.adi);
        scanf("%f", &x[2].doner.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].doner.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("donerler.tsv", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s\t%d\t%f", (x + i)->doner.adi, (x + i)->doner.malzemeAdedi, (x + i)->doner.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void hamburger(struct musteriler *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("hamburgerler.tsv", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(12);
    echo("    Hamburger Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>   [%d].%18s: %7.2f%25s  ", i + 1, (x + i)->hamburger.adi, (x + i)->hamburger.fiyati, "   <========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        hamburgerBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        hamburgerSecimVeFiyatlandirma(y, x, n);
    }
}

void hamburgerSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int hamburger_secim = secimFonksiyonu();

    switch (hamburger_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->hamburger.fiyati, (x + 0)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->hamburger.fiyati, (x + 1)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->hamburger.fiyati, (x + 2)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->hamburger.fiyati, (x + 3)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->hamburger.fiyati, (x + 4)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->hamburger.fiyati, (x + 5)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->hamburger.fiyati, (x + 6)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 8:
        siparisDetaylari(&toplamTutar, (x + 7)->hamburger.fiyati, (x + 7)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 9:
        siparisDetaylari(&toplamTutar, (x + 8)->hamburger.fiyati, (x + 8)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 10:
        siparisDetaylari(&toplamTutar, (x + 9)->hamburger.fiyati, (x + 9)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void hamburgerBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac)
{
    int hamburgerGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    hamburgerGuncelleme = secimFonksiyonu();

    switch (hamburgerGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].hamburger.adi);
        scanf("%f", &x[0].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].hamburger.fiyati);
        break;

    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].hamburger.adi);
        scanf("%f", &x[1].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].hamburger.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].hamburger.adi);
        scanf("%f", &x[2].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].hamburger.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].hamburger.adi);
        scanf("%f", &x[3].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].hamburger.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[4].hamburger.adi);
        scanf("%f", &x[4].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[4].hamburger.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[5].hamburger.adi);
        scanf("%f", &x[5].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[5].hamburger.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[6].hamburger.adi);
        scanf("%f", &x[6].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[6].hamburger.fiyati);
        break;
    case 8:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[7].hamburger.adi);
        scanf("%f", &x[7].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[7].hamburger.fiyati);
        break;
    case 9:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[8].hamburger.adi);
        scanf("%f", &x[8].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[8].hamburger.fiyati);
        break;
    case 10:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[9].hamburger.adi);
        scanf("%f", &x[9].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[9].hamburger.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("hamburgerler.tsv", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s\t%d\t%f", (x + i)->hamburger.adi, (x + i)->hamburger.malzemeAdedi, (x + i)->hamburger.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void corba(struct musteriler *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("corbalar.tsv", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Corba Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>    [%d].%14s: %7.2f%25s  ", i + 1, (x + i)->corba.adi, (x + i)->corba.fiyati, "    <=========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        corbaBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        corbaSecimVeFiyatlandirma(y, x, n);
    }
}

void corbaSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int corba_secim = secimFonksiyonu();

    switch (corba_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->corba.fiyati, (x + 0)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->corba.fiyati, (x + 1)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->corba.fiyati, (x + 2)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->corba.fiyati, (x + 3)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->corba.fiyati, (x + 4)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->corba.fiyati, (x + 5)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->corba.fiyati, (x + 6)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 8:
        siparisDetaylari(&toplamTutar, (x + 7)->corba.fiyati, (x + 7)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 9:
        siparisDetaylari(&toplamTutar, (x + 8)->corba.fiyati, (x + 8)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 10:
        siparisDetaylari(&toplamTutar, (x + 9)->corba.fiyati, (x + 9)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void corbaBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac)
{
    int corbaGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    corbaGuncelleme = secimFonksiyonu();

    switch (corbaGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].corba.adi);
        scanf("%f", &x[0].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].corba.fiyati);
        break;

    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].corba.adi);
        scanf("%f", &x[1].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].corba.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].corba.adi);
        scanf("%f", &x[2].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].corba.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].corba.adi);
        scanf("%f", &x[3].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].corba.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[4].corba.adi);
        scanf("%f", &x[4].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[4].corba.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[5].corba.adi);
        scanf("%f", &x[5].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[5].corba.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[6].corba.adi);
        scanf("%f", &x[6].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[6].corba.fiyati);
        break;
    case 8:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[7].corba.adi);
        scanf("%f", &x[7].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[7].corba.fiyati);
        break;
    case 9:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[8].corba.adi);
        scanf("%f", &x[8].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[8].corba.fiyati);
        break;
    case 10:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[9].corba.adi);
        scanf("%f", &x[9].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[9].corba.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("corbalar.tsv", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s\t%d\t%f", (x + i)->corba.adi, (x + i)->corba.malzemeAdedi, (x + i)->corba.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void evYemekleri(struct musteriler *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("evyemekleri.tsv", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(12);
    echo("   Ev Yemekleri Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================> [%d].%20s: %7.2f%25s  ", i + 1, (x + i)->evYemekleri.adi, (x + i)->evYemekleri.fiyati, "  <=========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        evYemekleriBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        evYemekleriSecimVeFiyatlandirma(y, x, n);
    }
}

void evYemekleriSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int evYemekleri_secim = secimFonksiyonu();

    switch (evYemekleri_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->evYemekleri.fiyati, (x + 0)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->evYemekleri.fiyati, (x + 1)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->evYemekleri.fiyati, (x + 2)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->evYemekleri.fiyati, (x + 3)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->evYemekleri.fiyati, (x + 4)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->evYemekleri.fiyati, (x + 5)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->evYemekleri.fiyati, (x + 6)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 8:
        siparisDetaylari(&toplamTutar, (x + 7)->evYemekleri.fiyati, (x + 7)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 9:
        siparisDetaylari(&toplamTutar, (x + 8)->evYemekleri.fiyati, (x + 8)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 10:
        siparisDetaylari(&toplamTutar, (x + 9)->evYemekleri.fiyati, (x + 9)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 11:
        siparisDetaylari(&toplamTutar, (x + 10)->evYemekleri.fiyati, (x + 10)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void evYemekleriBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac)
{

    int evYemekleriGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    evYemekleriGuncelleme = secimFonksiyonu();

    switch (evYemekleriGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].evYemekleri.adi);
        scanf("%f", &x[0].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].evYemekleri.fiyati);
        break;
    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].evYemekleri.adi);
        scanf("%f", &x[1].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].evYemekleri.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].evYemekleri.adi);
        scanf("%f", &x[2].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].evYemekleri.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].evYemekleri.adi);
        scanf("%f", &x[3].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].evYemekleri.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[4].evYemekleri.adi);
        scanf("%f", &x[4].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[4].evYemekleri.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[5].evYemekleri.adi);
        scanf("%f", &x[5].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[5].evYemekleri.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[6].evYemekleri.adi);
        scanf("%f", &x[6].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[6].evYemekleri.fiyati);
        break;
    case 8:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[7].evYemekleri.adi);
        scanf("%f", &x[7].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[7].evYemekleri.fiyati);
        break;
    case 9:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[8].evYemekleri.adi);
        scanf("%f", &x[8].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[8].evYemekleri.fiyati);
        break;
    case 10:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[9].evYemekleri.adi);
        scanf("%f", &x[9].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[9].evYemekleri.fiyati);
        break;
    case 11:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[10].evYemekleri.adi);
        scanf("%f", &x[10].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[10].evYemekleri.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("evYemekleri.tsv", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s\t%d\t%f", (x + i)->evYemekleri.adi, (x + i)->evYemekleri.malzemeAdedi, (x + i)->evYemekleri.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void pizza(struct musteriler *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("pizzalar.tsv", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Pizza Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>   [%d].%18s: %7.2f%25s  ", i + 1, (x + i)->pizza.adi, (x + i)->pizza.fiyati, "   <=========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        pizzaBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        pizzaSecimVeFiyatlandirma(y, x, n);
    }
}

void pizzaSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int pizza_secim = secimFonksiyonu();

    switch (pizza_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->pizza.fiyati, (x + 0)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->pizza.fiyati, (x + 1)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->pizza.fiyati, (x + 2)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->pizza.fiyati, (x + 3)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->pizza.fiyati, (x + 4)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->pizza.fiyati, (x + 5)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->pizza.fiyati, (x + 6)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void pizzaBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac)
{

    int pizzaGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    pizzaGuncelleme = secimFonksiyonu();

    switch (pizzaGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].pizza.adi);
        scanf("%f", &x[0].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].pizza.fiyati);
        break;
    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].pizza.adi);
        scanf("%f", &x[1].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].pizza.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].pizza.adi);
        scanf("%f", &x[2].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].pizza.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].pizza.adi);
        scanf("%f", &x[3].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].pizza.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[4].pizza.adi);
        scanf("%f", &x[4].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[4].pizza.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[5].pizza.adi);
        scanf("%f", &x[5].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[5].pizza.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[6].pizza.adi);
        scanf("%f", &x[6].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[6].pizza.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("pizzalar.tsv", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s\t%d\t%f", (x + i)->pizza.adi, (x + i)->pizza.malzemeAdedi, (x + i)->pizza.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void pide(struct musteriler *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("pideler.tsv", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Pide Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=======================>   [%d].%22s: %6.2f%25s  ", i + 1, (x + i)->pide.adi, (x + i)->pide.fiyati, "   <=======================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        pideBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        pideSecimVeFiyatlandirma(y, x, n);
    }
}

void pideSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int pide_secim = secimFonksiyonu();

    switch (pide_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->pide.fiyati, (x + 0)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->pide.fiyati, (x + 1)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->pide.fiyati, (x + 2)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->pide.fiyati, (x + 3)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->pide.fiyati, (x + 4)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->pide.fiyati, (x + 5)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->pide.fiyati, (x + 6)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void pideBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac)
{

    int pideGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    pideGuncelleme = secimFonksiyonu();

    switch (pideGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].pide.adi);
        scanf("%f", &x[0].pide.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].pide.fiyati);
        break;
    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].pide.adi);
        scanf("%f", &x[1].pide.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].pide.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].pide.adi);
        scanf("%f", &x[2].pide.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].pide.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].pide.adi);
        scanf("%f", &x[3].pide.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].pide.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[4].pide.adi);
        scanf("%f", &x[4].pide.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[4].pide.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[5].pide.adi);
        scanf("%f", &x[5].pide.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[5].pide.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[6].pide.adi);
        scanf("%f", &x[6].pide.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[6].pide.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("pideler.tsv", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s\t%d\t%f", (x + i)->pide.adi, (x + i)->pide.malzemeAdedi, (x + i)->pide.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void balik(struct musteriler *y, int n, struct menuBilgi *x)
{

    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("baliklar.tsv", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Balik Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>    [%d].%14s: %8.2f%25s  ", i + 1, (x + i)->balik.adi, (x + i)->balik.fiyati, "     <=========================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        balikBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        balikSecimVeFiyatlandirma(y, x, n);
    }
}

void balikSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n)
{
    echo("\n");

    int balik_secim = secimFonksiyonu();
    switch (balik_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->balik.fiyati, (x + 0)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->balik.fiyati, (x + 1)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->balik.fiyati, (x + 2)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->balik.fiyati, (x + 3)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->balik.fiyati, (x + 4)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->balik.fiyati, (x + 5)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->balik.fiyati, (x + 6)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void balikBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac)
{
    int balikGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    balikGuncelleme = secimFonksiyonu();

    switch (balikGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].balik.adi);
        scanf("%f", &x[0].balik.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].balik.fiyati);
        break;
    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].balik.adi);
        scanf("%f", &x[1].balik.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].balik.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].balik.adi);
        scanf("%f", &x[2].balik.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].balik.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].balik.adi);
        scanf("%f", &x[3].balik.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].balik.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[4].balik.adi);
        scanf("%f", &x[4].balik.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[4].balik.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[5].balik.adi);
        scanf("%f", &x[5].balik.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[5].balik.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[6].balik.adi);
        scanf("%f", &x[6].balik.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[6].balik.fiyati);
        break;
    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("baliklar.tsv", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s\t%d\t%f", (x + i)->balik.adi, (x + i)->balik.malzemeAdedi, (x + i)->balik.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void salata(struct musteriler *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("salatalar.tsv", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Salata Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>     [%d].%12s: %7.2f%25s  ", i + 1, (x + i)->salata.adi, (x + i)->salata.fiyati, "       <=========================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        salataBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        salataSecimVeFiyatlandirma(y, x, n);
    }
}

void salataSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n)
{
hataliTuslama:
    echo("\n");

    int salata_secim = secimFonksiyonu();
    switch (salata_secim)
    {
    case 0:
        tab_bas(8);
        echo("Salata tercih etmediniz\n");
        tab_bas(8);
        echo("Tatli sayfasina yonlendiriliyorsunuz...");
        Sleep(800);
        tatli(y, n, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->salata.fiyati, (x + 0)->salata.adi, fisIslemSayaci);
        fisIslemSayaci++; //2
        tatli(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->salata.fiyati, (x + 1)->salata.adi, fisIslemSayaci);
        fisIslemSayaci++;
        tatli(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->salata.fiyati, (x + 2)->salata.adi, fisIslemSayaci);
        fisIslemSayaci++;
        tatli(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->salata.fiyati, (x + 3)->salata.adi, fisIslemSayaci);
        fisIslemSayaci++;
        tatli(y, n, x);
        break;
    default:
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }
}

void salataBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac)
{
    int salataGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    salataGuncelleme = secimFonksiyonu();

    switch (salataGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].salata.adi);
        scanf("%f", &x[0].salata.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].salata.fiyati);
        break;
    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].salata.adi);
        scanf("%f", &x[1].salata.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].salata.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].salata.adi);
        scanf("%f", &x[2].salata.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].salata.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].salata.adi);
        scanf("%f", &x[3].salata.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].salata.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz.");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("salatalar.tsv", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s\t%d\t%f", (x + i)->salata.adi, (x + i)->salata.malzemeAdedi, (x + i)->salata.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void tatli(struct musteriler *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("tatlilar.tsv", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Tatli Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>    [%d].%16s: %7.2f%25s  ", i + 1, (x + i)->tatli.adi, (x + i)->tatli.fiyati, "    <=========================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        tatliBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        tatliSecimVeFiyatlandirma(y, x, n);
    }
}

void tatliSecimVeFiyatlandirma(struct musteriler *y, struct menuBilgi *x, int n)
{
hataliTuslama:
    echo("\n\n");

    int tatli_secim = secimFonksiyonu();
    switch (tatli_secim)
    {
    case 0:
        tab_bas(8);
        echo("Tatli tercih etmediniz\n");
        tab_bas(8);
        echo("Icecek sayfasina yonlendiriliyorsunuz...");
        Sleep(800);
        icecekler(y, n, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->tatli.fiyati, (x + 0)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++; //3
        icecekler(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->tatli.fiyati, (x + 1)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->tatli.fiyati, (x + 2)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->tatli.fiyati, (x + 3)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->tatli.fiyati, (x + 4)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->tatli.fiyati, (x + 5)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->tatli.fiyati, (x + 6)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 8:
        siparisDetaylari(&toplamTutar, (x + 7)->tatli.fiyati, (x + 7)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 9:
        siparisDetaylari(&toplamTutar, (x + 8)->tatli.fiyati, (x + 8)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    default:
        cls();
        satir_bas(1);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }
}

void tatliBilgisiGuncelleme(struct musteriler *y, struct menuBilgi *x, int satirSayac)
{

    int tatliGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    tatliGuncelleme = secimFonksiyonu();

    switch (tatliGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].tatli.adi);
        scanf("%f", &x[0].tatli.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].tatli.fiyati);
        break;
    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].tatli.adi);
        scanf("%f", &x[1].tatli.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].tatli.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].tatli.adi);
        scanf("%f", &x[2].tatli.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].tatli.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].tatli.adi);
        scanf("%f", &x[3].tatli.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].tatli.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[4].tatli.adi);
        scanf("%f", &x[4].tatli.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[4].tatli.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[5].tatli.adi);
        scanf("%f", &x[5].tatli.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[5].tatli.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[6].tatli.adi);
        scanf("%f", &x[6].tatli.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[6].tatli.fiyati);
        break;
    case 8:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[7].tatli.adi);
        scanf("%f", &x[7].tatli.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[7].tatli.fiyati);
        break;
    case 9:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[8].tatli.adi);
        scanf("%f", &x[8].tatli.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[8].tatli.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("tatlilar.tsv", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s\t%d\t%f", (x + i)->tatli.adi, (x + i)->tatli.malzemeAdedi, (x + i)->tatli.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void siparisDetaylari(float *fiyatToplam, float tekFiyat, char isim[], int fisIslemSayaci)
{
    int i;
    char cizgiBastir[67] = "----------------------------------------------------------------\n";

    tab_bas(8);
    printf("%s sectiniz. \n", isim);
    float istenenSayi = 0;
    float toplamFiyat = 0;
    tab_bas(8);
    echo("Kac tane/porsiyon istersiniz?\n");
    tab_bas(8);
    echo("==> ");
    scanf("%f", &istenenSayi);
    *fiyatToplam += istenenSayi * tekFiyat;

    time_t t; //fisin yazdirilmaya baslandigi zaman bilgisi.
    time(&t);
    struct tm *zaman;
    zaman = localtime(&t);

    if (fisIslemSayaci == 0) // 0 bilgisi yani ilk siparis verilince yeni dosya acilacak fis tasarimi baslayacak //cerceve vs.
    {
        FILE *fSiparisFis = fopen("siparisFis.txt", "a");
        if (fSiparisFis == NULL)
        {
            puts("Dosya olusturulamadi.\n");
            Sleep(300);
            exit(1);
        }
        else
        {
            for (i = 0; i < 65; i++)
            {
                fputc(cizgiBastir[i], fSiparisFis);
            }

            fprintf(fSiparisFis, "\t\t\tMarmara Kebap Salonu\n");
            fprintf(fSiparisFis, "\t\t\t   %d/%d/%d  %d:%d\n", zaman->tm_mday, zaman->tm_mon + 1, zaman->tm_year + 1900, zaman->tm_hour, zaman->tm_min);
        }
        fclose(fSiparisFis);
    }

    if (fisIslemSayaci <= 3)
    {
        //Dosyaya yazilacak bilgiler kismi.
        satir_bas(2);
        tab_bas(8);
        printf(" %s : \t\t %.2f * %.2f \n", isim, tekFiyat, istenenSayi);

        FILE *fSiparisFis = fopen("siparisFis.txt", "a");
        if (fSiparisFis == NULL)
        {
            puts("Dosya olusturulamadi.\n");
            Sleep(300);
            exit(1);
        }
        else
        {

            fprintf(fSiparisFis, " \n%s: \t \t %.2f * %.2f\n", isim, tekFiyat, istenenSayi);
        }
        fclose(fSiparisFis);

        Sleep(1000);
        satir_bas(1);
        tab_bas(8);
        printf("Aldiklariniz %.2f TL tutmustur.\n", *fiyatToplam);
        satir_bas(3);
        tab_bas(8);
        echo("Siparisiniz hazirlaniyor. Diger sayfaya yonlendiriliyorsunuz...\n");
        Sleep(800);
    }

    Sleep(1000);
}

void odemeYontemi(struct musteriler *y, struct menuBilgi *x)
{
    int i;
    char odeme[2][30] = {"Online Odeme", "Kapida Odeme"};

hataliTuslama:

    system("color 3E");
    printf("\n\t\t");
    system("color 3E");
    bosluk_bas(1);
    tab_bas(4);
    cls();

    satir_bas(10);
    for (i = 0; i < 2; i++)
    {
        satir_bas(2);
        tab_bas(12);
        printf("==>  [%d]. %s\n\n", i + 1, odeme[i]);
        Sleep(100);
    }
    satir_bas(1);

    int anaSecim = secimFonksiyonu();
    switch (anaSecim)
    {
    case 1:
        onlineOdeme(y, x, &toplamTutar, &musteriSirasi);
        break;

    case 2:
        kapidaOdeme(y, x, &toplamTutar, &musteriSirasi);
        break;

    default:
        cls();
        satir_bas(10);
        tab_bas(11);
        echo("   Gecersiz giris yaptiniz !!");
        Sleep(900);
        goto hataliTuslama;
        break;
    }
}

void kapidaOdeme(struct musteriler *y, struct menuBilgi *x, float *fiyatToplam, int *musteriSirasi)
{
    int i, siraMusteri;
    char cizgiBastir[67] = "----------------------------------------------------------------\n";
    siraMusteri = *musteriSirasi;

    cls();
    system("color 2E");
    satir_bas(3);
    tab_bas(11);
    echo("Ucret Kapida Odeme Olarak tahsil edilecek..\n");
    Sleep(100);
    cerceve();
    Sleep(100);
    satir_bas(4);
    tab_bas(9);
    printf("Adiniz: %s       Soyadiniz: %s", (y + (siraMusteri - 1))->musteri.musteriIsmi, (y + (siraMusteri - 1))->musteri.musteriSoyismi);
    Sleep(100);
    satir_bas(2);
    tab_bas(9);
    printf("Adres Bilginiz:\n");
    tab_bas(9);
    Sleep(100);
    printf("Sehir:   %s   Ilce:   %s   Semt/Mahalle:   %s\n", (y + (siraMusteri - 1))->musteri.sehir, (y + (siraMusteri - 1))->musteri.ilce, (y + (siraMusteri - 1))->musteri.semt);
    tab_bas(9);
    Sleep(100);
    printf("Sokak:   %s   Apartman Ismi:   %s   Daire No:   %s\n\n", (y + (siraMusteri - 1))->musteri.sokak, (y + (siraMusteri - 1))->musteri.apartmanIsmi, (y + (siraMusteri - 1))->musteri.daireNo);
    satir_bas(3);
    tab_bas(9);
    cerceve();

    FILE *fSiparisFis = fopen("siparisFis.txt", "a"); //Fis kismina son olarak siparisin tutari ve musterinin bilgileri bastiriliyor.
    if (fSiparisFis == NULL)
    {
        puts("Dosya olusturulamadi.\n");
        Sleep(300);
        exit(1);
    }
    else
    {
        fprintf(fSiparisFis, "\nToplam tutar:\t \t %.2f\n\n", toplamTutar);
        fprintf(fSiparisFis, "     Ucret Kapida Odeme Olarak tahsil edilecek...\n");

        fprintf(fSiparisFis, "Adiniz: %s       Soyadiniz: %s\n", (y + (siraMusteri - 1))->musteri.musteriIsmi, (y + (siraMusteri - 1))->musteri.musteriSoyismi);
        fprintf(fSiparisFis, "Adres Bilginiz:\n");
        fprintf(fSiparisFis, "Sehir:   %s   Ilce:   %s   Semt/Mahalle:   %s\n", (y + (siraMusteri - 1))->musteri.sehir, (y + (siraMusteri - 1))->musteri.ilce, (y + (siraMusteri - 1))->musteri.semt);
        fprintf(fSiparisFis, "Sokak:   %s   Apartman Ismi:   %s   Daire No:   %s\n\n", (y + (siraMusteri - 1))->musteri.sokak, (y + (siraMusteri - 1))->musteri.apartmanIsmi, (y + (siraMusteri - 1))->musteri.daireNo);

        for (i = 0; i < 65; i++)
        {
            fputc(cizgiBastir[i], fSiparisFis);
        }
    }
    fclose(fSiparisFis);
    toplamTutar = 0;

    Sleep(200);
    satir_bas(3);
    tab_bas(6);
    echo("  Siparis bilgileri basariyla alinmis ve Siparisiniz yukaridaki adrese ulastirilmak uzere hazirlanmaya baslanmistir.\n\n");
    Sleep(1000);
    tab_bas(9);
    echo("   Bizleri tercih ettiginiz icin tesekkur ederiz. Afiyet olsun...");
    getch();
    ana_menu(y, x);
}

void onlineOdeme(struct musteriler *y, struct menuBilgi *x, float *fiyatToplam, int *musteriSirasi)
{
    int i, siraMusteri;
    siraMusteri = *musteriSirasi;
    char cizgiBastir[67] = "----------------------------------------------------------------\n";
    char kartNumarasi[16];
    char gecerlilikTarihi[4]; // tarih ay/yil seklinde
    char kartSahibiAdi[50];
    char guvenlikKodu[3];

    cls();
    system("color 2E");
    satir_bas(3);
    tab_bas(11);
    echo("* * Online Odeme Ekrani * *\n");
    Sleep(100);
    cerceve();
    Sleep(2000);

    //* Banka kredikarti kontrol islemleri
    kredikartiBilgisiKontrol(y);
    //*

    satir_bas(3);
    tab_bas(9);
    printf("Adiniz: %s       Soyadiniz: %s", (y + (siraMusteri - 1))->musteri.musteriIsmi, (y + (siraMusteri - 1))->musteri.musteriSoyismi);
    Sleep(100);
    satir_bas(2);
    tab_bas(9);
    printf("Adres Bilginiz:\n");
    tab_bas(9);
    Sleep(100);
    printf("Sehir:   %s   Ilce:   %s   Semt/Mahalle:   %s\n", (y + (siraMusteri - 1))->musteri.sehir, (y + (siraMusteri - 1))->musteri.ilce, (y + (siraMusteri - 1))->musteri.semt);
    tab_bas(9);
    Sleep(100);
    printf("Sokak:   %s   Apartman Ismi:   %s   Daire No:   %s\n\n", (y + (siraMusteri - 1))->musteri.sokak, (y + (siraMusteri - 1))->musteri.apartmanIsmi, (y + (siraMusteri - 1))->musteri.daireNo);
    satir_bas(3);
    tab_bas(9);
    cerceve();

    FILE *fSiparisFis = fopen("siparisFis.txt", "a"); //Fis kismina son olarak siparisin tutari ve musterinin bilgileri bastiriliyor.
    if (fSiparisFis == NULL)
    {
        puts("Dosya olusturulamadi.\n");
        Sleep(300);
        exit(1);
    }
    else
    {
        fprintf(fSiparisFis, "\nToplam tutar:\t \t %.2f\n\n", toplamTutar);
        fprintf(fSiparisFis, "     Ucret Online Odeme ile tahsil edildi...\n");

        fprintf(fSiparisFis, "Adiniz: %s       Soyadiniz: %s\n", (y + (siraMusteri - 1))->musteri.musteriIsmi, (y + (siraMusteri - 1))->musteri.musteriSoyismi);
        fprintf(fSiparisFis, "Adres Bilginiz:\n");
        fprintf(fSiparisFis, "Sehir:   %s   Ilce:   %s   Semt/Mahalle:   %s\n", (y + (siraMusteri - 1))->musteri.sehir, (y + (siraMusteri - 1))->musteri.ilce, (y + (siraMusteri - 1))->musteri.semt);
        fprintf(fSiparisFis, "Sokak:   %s   Apartman Ismi:   %s   Daire No:   %s\n\n", (y + (siraMusteri - 1))->musteri.sokak, (y + (siraMusteri - 1))->musteri.apartmanIsmi, (y + (siraMusteri - 1))->musteri.daireNo);

        for (i = 0; i < 65; i++)
        {
            fputc(cizgiBastir[i], fSiparisFis);
        }
    }
    fclose(fSiparisFis);
    toplamTutar = 0;

    Sleep(200);
    satir_bas(3);
    tab_bas(6);
    echo("  Siparis bilgileri basariyla alinmis ve Siparisiniz yukaridaki adrese ulastirilmak uzere hazirlanmaya baslanmistir.\n\n");
    Sleep(1000);
    tab_bas(9);
    echo("   Bizleri tercih ettiginiz icin tesekkur ederiz. Afiyet olsun...");
    getch();
    ana_menu(y, x);
}

void musteriBilgileriGoruntule(struct musteriler *y, struct menuBilgi *x)
{
    menuRenk();
    int i, satirSayac = 0;
    char c;

    tab_bas(10);
    printf("    * * * * * * MUSTERI VERILERI * * * * *\n\n");

    FILE *fpp;
    fpp = fopen("musteriBilgileri.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(9);

        printf("[%d]. %s %s\n", i + 1, (y + i)->musteri.musteriIsmi, (y + i)->musteri.musteriSoyismi);
        tab_bas(9);
        printf("Adres Bilgisi:\n");
        tab_bas(9);
        printf("%s ili %s ilcesi %s semti ", (y + i)->musteri.sehir, (y + i)->musteri.ilce, (y + i)->musteri.semt);
        printf("%s sokak %s apartmani %s daire no\n\n", (y + i)->musteri.sokak, (y + i)->musteri.apartmanIsmi, (y + i)->musteri.daireNo);

        Sleep(100);
    }

    satirSayac = 0;
    FILE *fpk;
    fpk = fopen("musteriGirisiBilgisi.txt", "r");

    for (c = getc(fpk); c != EOF; c = getc(fpk))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpk);

    satir_bas(2);
    tab_bas(10);
    printf("    * * * * * * MUSTERI GIRIS VERILERI * * * * *\n\n");
    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(9);
        printf("[%d]. %s %s %d\n", i + 1, (y + i)->musteri.musteriEMail, (y + i)->musteri.musteriSifre, (y + i)->musteri.musteriId);
        Sleep(100);
    }

    satir_bas(1);
    tab_bas(10);
    printf("Kayit olan tum kullanicilar goruntulenmektedir..\n\n\n");
    tab_bas(10);
    printf("Admin menuye donmek icin herhangi bir tusa basiniz...\n\n");
    getch();
}

void siparisBilgileriGoruntule(struct musteriler *y, struct menuBilgi *x)
{
    system("color 3E");
    printf("\n\t\t");
    system("color 1E");
    bosluk_bas(1);
    tab_bas(5);
    cls();

    int i = 0;
    char *karakter, satir[300];

    FILE *siparisBilgileri = fopen("siparisFis.txt", "r");

    tab_bas(11);
    printf("==> [0].Ana Menu\n");
    tab_bas(11);
    printf("==>[1].Fis Bilgilerini Goruntule\n");

    int musteriEklemeSecim = secimFonksiyonu();
    if (musteriEklemeSecim == 0)
    {
        ana_menu(y, x);
    }

    if (siparisBilgileri == NULL)
    {
        fprintf(stderr, "Dosyalari okurken bir hata meydana geldi...");
    }

    tab_bas(10);
    printf("      * * * * * *   SIPARISLER   * * * * *\n\n");

    do
    {
        tab_bas(10);
        karakter = fgets(satir, 300, siparisBilgileri); //satir satir bilgi okundu...

        if (karakter != NULL)
        {
            printf("%s", satir);
        }

    } while (karakter != NULL);
    i++;

    satir_bas(1);
    tab_bas(10);
    printf("Verilen tum siparisler goruntulenmektedir..\n\n\n");
    fclose(siparisBilgileri);
    tab_bas(10);
    printf("Admin menuye donmek icin herhangi bir tusa basiniz...");
    getch();
}

void uygulamayiKapat()
{
    cls();
    satir_bas(10);
    cerceve();
    satir_bas(2);
    tab_bas(12);
    puts("Yine bekleriz!!\n\n");
    Sleep(200);
    tab_bas(12);
    puts("Program kapatiliyor...");
    cerceve();
    Sleep(800);
    exit(1);
}
void gecersizGiris(struct musteriler *y, struct menuBilgi *x)
{
    cls();
    satir_bas(8);
    tab_bas(10);
    puts("Gecersiz Giris Yaptiniz. Lutfen Tekrar Deneyiniz !!! ");
    Sleep(1300);
    ana_menu(y, x);
}

//Gerekli if yerlerinde kullanilmak uzere secim icin fonksiyon
int secimFonksiyonu()
{
    int secim;
    echo("===> ");
    scanf("%d", &secim);
    return secim;
}

//Anlik zaman bilgisi yazdirir.
void zamanGoster()
{
    time_t t;
    time(&t);
    struct tm *zaman;
    zaman = localtime(&t);
    tab_bas(6);
    printf("             %d/%d/%d  %d:%d", zaman->tm_mday, zaman->tm_mon + 1, zaman->tm_year + 1900, zaman->tm_hour, zaman->tm_min);
}

// Console tam ekran yapiliyor.
void tamEkran()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOWMAXIMIZED);
}

int kasaBilgiOku()
{
    int top;
    FILE *Fp = fopen("kasadakiPara.txt", "r");
    if (Fp == NULL)
    {
        tab_bas(11);
        puts("!!! kasadakiPara.txt Dosya okunamadi !!!\n");
        Sleep(500);
        exit(1);
    }
    else
    {
        while (fscanf(Fp, "%d", &top) != EOF)
        {
        }
    }
    fclose(Fp);
    return top;
}

void kasaBilgiYaz(int toplam)
{
    FILE *Fp = fopen("kasadakiPara.txt", "a");
    if (Fp == NULL)
    {
        tab_bas(11);
        puts("!!! kasadakiPara.txt Dosya olusturulamadi !!!\n");
        Sleep(500);
        exit(1);
    }
    else
    {
        fprintf(Fp, "%d\n", toplam);
    }
    fclose(Fp);
}

void icecekBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("icecekler.tsv", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s\t%d\t%f", &(x + i)->icecekler.adi, &(x + i)->icecekler.stokAdedi, &(x + i)->icecekler.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! icecekler.tsv Dosya Bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void kebapBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("kebaplar.tsv", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s\t%d\t%f", &(x + i)->kebap.adi, &(x + i)->kebap.malzemeAdedi, &(x + i)->kebap.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! kebaplar.tsv Dosya Bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void donerBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("donerler.tsv", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s\t%d\t%f", &(x + i)->doner.adi, &(x + i)->doner.malzemeAdedi, &(x + i)->doner.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! donerler.tsv Dosya Bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void hamburgerBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("hamburgerler.tsv", "r")) != NULL)
    {

        while (!feof(fpp))
        {

            fscanf(fpp, "%s\t%d\t%f", &(x + i)->hamburger.adi, &(x + i)->hamburger.malzemeAdedi, &(x + i)->hamburger.fiyati);

            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! hamburgerler.tsv Dosya Bulunamadi !!!");
        Sleep(1000);
    }

    fclose(fpp);
}

void corbaBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("corbalar.tsv", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s\t%d\t%f", &(x + i)->corba.adi, &(x + i)->corba.malzemeAdedi, &(x + i)->corba.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! corbalar.tsv Dosya Bulunamadi !!!");
        Sleep(1000);
    }

    fclose(fpp);
}

void evYemekleriBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("evyemekleri.tsv", "r")) != NULL)
    {
        while (!feof(fpp))
        {
            fscanf(fpp, "%s\t%d\t%f", &(x + i)->evYemekleri.adi, &(x + i)->evYemekleri.malzemeAdedi, &(x + i)->evYemekleri.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! evyemekleri.tsv Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void pizzaBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("pizzalar.tsv", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s\t%d\t%f", &(x + i)->pizza.adi, &(x + i)->pizza.malzemeAdedi, &(x + i)->pizza.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! pizzalar.tsv Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void pideBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("pideler.tsv", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %d %f", &(x + i)->pide.adi, &(x + i)->pide.malzemeAdedi, &(x + i)->pide.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! pideler.tsv Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void balikBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("baliklar.tsv", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s\t%d\t%f", &(x + i)->balik.adi, &(x + i)->balik.malzemeAdedi, &(x + i)->balik.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! baliklar.tsv Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void salataBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("salatalar.tsv", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s\t%d\t%f", &(x + i)->salata.adi, &(x + i)->salata.malzemeAdedi, &(x + i)->salata.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! salatalar.tsv Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void tatliBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("tatlilar.tsv", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s\t%d\t%f", &(x + i)->tatli.adi, &(x + i)->tatli.malzemeAdedi, &(x + i)->tatli.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! tatlilar.tsv Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void yemekBilgisiCek(struct menuBilgi *x)
{
    icecekBilgisiCek(x);
    kebapBilgisiCek(x);
    donerBilgisiCek(x);
    hamburgerBilgisiCek(x);
    corbaBilgisiCek(x);
    evYemekleriBilgisiCek(x);
    pizzaBilgisiCek(x);
    pideBilgisiCek(x);
    balikBilgisiCek(x);
    salataBilgisiCek(x);
    tatliBilgisiCek(x);
}

void mGirisiBilgisiCek(struct musteriler *y)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("musteriGirisiBilgisi.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %s %d", &(y + i)->musteri.musteriEMail, &(y + i)->musteri.musteriSifre, &(y + i)->musteri.musteriId);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!!  musteriGirisiBilgisi.txt Bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void mBilgiCek(struct musteriler *y)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("musteriBilgileri.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %s %s %s %s %s %s %s", &(y + i)->musteri.musteriIsmi, &(y + i)->musteri.musteriSoyismi, &(y + i)->musteri.sehir, &(y + i)->musteri.ilce, &(y + i)->musteri.semt, &(y + i)->musteri.sokak, &(y + i)->musteri.apartmanIsmi, &(y + i)->musteri.daireNo);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! musteriBilgileri.txt Bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void kredikartiBilgisiCek(struct musteriler *z)
{
    int k = 0, i;

    FILE *fpp;
    if ((fpp = fopen("bankaBilgileriKrediKarti.txt", "r")) != NULL)
    {
        while (!feof(fpp))
        {
            fscanf(fpp, "%s %s %s %s", &(z + k)->musteri.kartSahibiAdi, &(z + k)->musteri.kartNumarasi, &(z + k)->musteri.gecerlilikTarihi, &(z + k)->musteri.guvenlikKodu);
            k++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! bankaBilgileriKrediKarti.txt Bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void cls()
{
    system("cls");
}

void echo(char print[])
{
    printf("%s", print);
}

void satir_bas(int satir)
{
    int i;
    for (i = 0; i < satir; i++)
    {
        putchar('\n');
    }
}

void tab_bas(int tab)
{
    int i;
    for (i = 0; i < tab; i++)
    {
        putchar('\t');
    }
}

void bosluk_bas(int bosluk)
{
    int i;
    for (i = 0; i < bosluk; i++)
    {
        putchar(' ');
    }
}

void cerceve()
{
    satir_bas(1);
    tab_bas(8);
    int i;
    for (i = 0; i < 89; i++)
    {
        putchar('=');
    }
}

void karsilama()
{
    system("color 2E");
    int i;
    char hosgeldin[50] = "MARMARA KEBAP SALONUNA HOS GELDINIZ";
    satir_bas(16);
    tab_bas(8);

    for (i = 0; i < strlen(hosgeldin); i++)
    {
        system("color 2E");

        printf(" %c", hosgeldin[i]);
        Sleep(25);
    }

    system("color 2E");
    printf("\n\n\t\t\t\t ");
    Sleep(2000);
}

void ilerleme(void)
{
    int i;
    for (i = 15; i <= 100; i += 20)
    {
        cls();
        system("color 3E");
        satir_bas(15);
        tab_bas(13);

        printf("%d Yukleniyor... %%", i);

        satir_bas(2);
        tab_bas(10);

        printf("");
        int j;
        for (j = 0; j < i; j += 2)
        {
            printf("\xdb");
            system("color 3E");
        }
        Sleep(10);

        if (i == 90 || i == 50 || i == 96 || i == 35)
        {
            Sleep(25);
        }
    }
}

void menuRenk()
{
    system("color 3E");
    printf("\n\t\t");
    system("color 3E");
    cls();
    bosluk_bas(1);
    tab_bas(4);
    printf("\n\t\t");
    echo("==>  [0]. Ust Menu\n\n");
    bosluk_bas(2);
    Sleep(35);
}

void hakkimizdaGoruntule(struct musteriler *y, struct menuBilgi *x)
{
    int k;
    char yazilimcilar[4][50] = {"Melih Afsar", "Kenan Baylan", "Aziz Eren Saganda", "Serif Yilmaz"};
    menuRenk();
    satir_bas(10);
    tab_bas(12);
    echo("   Maramara Kebap Hause");
    cerceve();
    satir_bas(1);
    tab_bas(13);
    echo("since 1883");
    satir_bas(1);
    tab_bas(12);
    echo("Basibuyuk/Maltepe/Istanbul\n");
    satir_bas(5);
    tab_bas(12);
    echo("Yazilimda Emegi Gecenler\n");
    for (k = 0; k < 4; ++k)
    {
        tab_bas(12);
        printf("    %s", yazilimcilar[k]);
        satir_bas(1);
    }
    cerceve();
    getch();
    ana_menu(y, x);
}
