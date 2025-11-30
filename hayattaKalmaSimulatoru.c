#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // toupper fonksiyonu için

int main() {
    // Rastgele sayı üretimi için seed (tohum) oluşturma
    srand(time(NULL));

    // Durum Değişkenleri [cite: 22]
    int saglik = 100;
    int enerji = 100;
    int yemek = 0;
    int siginak = 0; // 0: Yok, 1: Var [cite: 26]
    char komut;

    printf("--- HAYATTA KALMA SIMULATORU BASLATILDI ---\n");
    printf("Komutlar: [A]Avlan, [S]Siginak, [E]Envanter, [R]Dinlen, [F]Tehlike, [P]Sifre, [X]Cikis\n");

    // Ana Oyun Döngüsü (Do-While) 
    do {
        printf("\nBir komut giriniz > ");
        scanf(" %c", &komut); // Boşluk karakteri önceki enter tuşunu yutmak için
        komut = toupper(komut); // Küçük harf girilse bile büyüt

        // Komut Sistemi (Switch-Case) 
        switch (komut) {
            case 'A': // AVLANMA
                printf("Avlanmaya ciktiniz...\n");
                // Aritmetik ve Mantıksal İşlemler [cite: 13]
                enerji -= 15; // Enerji harcanır
                
                // Rastgele bir ihtimal hesabı (0-9 arası sayı)
                int sans = rand() % 10; 

                // Avlanma başarısı (Mantıksal operatör kullanımı)
                if (sans > 3 && enerji > 0) { 
                    printf("Basarili! Bir yemek buldunuz.\n");
                    yemek++; 
                } else {
                    printf("Basarisiz oldunuz ve yaralandiniz.\n");
                    saglik -= 10;
                }
                break;

            case 'S': // SIĞINAK ARAMA
                // Mantıksal operatörlerle kontrol [cite: 14]
                if (siginak == 0 && enerji >= 20) {
                    printf("Guvenli bir alan buldunuz ve siginak insa ettiniz!\n");
                    enerji -= 20;
                    siginak = 1;
                } else if (siginak == 1) {
                    printf("Zaten bir siginaginiz var.\n");
                } else {
                    printf("Siginak aramak icin yeterli enerjiniz yok! (Gereken: 20)\n");
                }
                break;

            case 'E': // ENVANTER GÖRÜNTÜLEME
                printf("\n--- DURUM RAPORU ---\n");
                printf("Saglik : %d\n", saglik);
                printf("Enerji : %d\n", enerji);
                printf("Yemek  : %d\n", yemek);
                printf("Siginak: %s\n", siginak ? "VAR" : "YOK");
                break;

           case 'R': // DİNLENME
                if (yemek > 0) { //  Yiyecek kontrolü
                    yemek--; //  Yemek azalıyor
                    printf("Bir porsiyon yemek yiyip dinlendiniz. (Kalan Yemek: %d)\n", yemek);

                    // Aritmetik işlemlerle artış (Mevcut mantık)
                    if (siginak == 1) {
                        printf("Siginakta guvenle dinlendiniz. Saglik ve Enerji yenilendi.\n");
                        enerji += 20;
                        saglik += 10;
                    } else {
                        printf("Disarida dinlenmek tehlikeli ama biraz enerji topladiniz.\n");
                        enerji += 10;
                    }
                    
                    // 100 sınırını aşmaması için kontrol
                    if (enerji > 100) enerji = 100;
                    if (saglik > 100) saglik = 100;

                } else {
                    // EKLENDİ: Yemek yoksa uyarı
                    printf("Dinlenmek icin yiyeceginiz yok! Enerji toplamak icin once [A]vlanmalisiniz.\n");
                }
                break;

            case 'F': // TEHLİKE DALGASI (FOR DÖNGÜSÜ)
                printf("DIKKAT! Bolgeye bir tehlike dalgasi yaklasiyor...\n");
                // For döngüsü ile seri olay simülasyonu 
                for (int i = 1; i <= 3; i++) {
                    int hasar = rand() % 10 + 5;
                    printf("%d. Dalga vurdu! %d hasar aldiniz.\n", i, hasar);
                    saglik -= hasar;
                    
                    if (saglik <= 0) {
                        printf("OluMCul hasar aldiniz!\n");
                        break; // Döngüden erken çıkış
                    }
                }
                break;

            case 'P': // ŞİFRELİ İLERLEME (DO-WHILE)
                printf("Kilitli bir sandik buldunuz.\n");
                int girilenSifre;
                int dogruSifre = 1234;
                // Şifre doğrulama döngüsü 
                do {
                    printf("Sifreyi giriniz (4 hane): ");
                    scanf("%d", &girilenSifre);
                    
                    if (girilenSifre != dogruSifre) {
                        printf("Hatali sifre! Tekrar deneyin.\n");
                    }
                } while (girilenSifre != dogruSifre);
                
                printf("Sifre dogru! Sandiktan 2 yemek ve enerji iksiri cikti.\n");
                yemek += 2;
                enerji += 30;
                if (enerji > 100) enerji = 100;
                break;

            case 'X': // ÇIKIŞ
                printf("Simulasyondan cikiliyor...\n");
                break;

            default:
                printf("Gecersiz komut! Lutfen listedeki komutlari kullanin.\n");
        }

        // Oyun Bitiş Kontrolü (Sağlık 0 ise)
        if (saglik <= 0) {
            printf("\nSAGLIK TUKENDI. OYUN BITTI.\n");
            komut = 'X'; // Döngüyü sonlandırmak için
        }

    } while (komut != 'X'); // Çıkış komutu verilmedikçe devam eder 

    printf("Oyun sonlandirildi.\n");
    return 0;
}
