# Karakter Tabanlı Hayatta Kalma Simülatörü (Survival Simulator)

Bu proje, C programlama dili kullanılarak geliştirilmiş, metin tabanlı (console-based) bir hayatta kalma oyunudur. Oyuncu; sağlık, enerji, yemek ve sığınak durumunu yöneterek hayatta kalmaya çalışır.

##  Proje Amacı ve Teknik Detaylar

Bu simülatör, Algoritma ve Programlama dersi kapsamında C dilinin temel yapı taşlarını pratik etmek amacıyla geliştirilmiştir. Projede aşağıdaki teknik yapılar kullanılmıştır:

* **Durum Yönetimi (State Management):** `saglik`, `enerji`, `yemek` ve `siginak` değişkenleri ile oyunun anlık durumu aritmetik operatörler kullanılarak sürekli güncellenir.
* **SWITCH-CASE Yapısı:** Kullanıcıdan alınan 'A', 'S', 'R' gibi komutların yönetimi ve ilgili fonksiyonların çağrılması için kullanılmıştır.
* **DO-WHILE Döngüsü:**
    * **Oyun Döngüsü:** Oyuncu 'X' komutunu verene kadar oyunun sürekli devam etmesini sağlar.
    * **Şifre Kontrolü:** 'P' komutunda oyuncu doğru şifreyi girene kadar döngünün devam etmesi için kullanılmıştır.
* **FOR Döngüsü:** "Tehlike Dalgası" ('F') simülasyonunda, belirli sayıda (3 kez) art arda gelen saldırıların ve hasar hesabının yapılması için kullanılmıştır.
* **Mantıksal Operatörler ve IF-ELSE:**
    * Sığınak inşa ederken enerji kontrolü (`&&`).
    * Dinlenirken yemek stoku kontrolü.
    * Tehlike anında sığınağın rastgele yıkılma ihtimali (Random Event).

##  Oynanış ve Kurallar

Oyuncu aşağıdaki komutları kullanarak hayatta kalmaya çalışır:

| Komut | Açıklama |
| :--- | :--- |
| **[A]vlan** | Enerji harcar. Şansa bağlı olarak yemek kazandırır veya yaralanmaya sebep olur. |
| **[S]ığınak** | Enerji harcayarak sığınak inşa etmenizi sağlar. Tehlike anında koruma sağlar. |
| **[R]Dinlen** | **Yemek tüketerek** sağlık ve enerji yeniler. Sığınak varsa daha fazla iyileşme sağlar. |
| **[E]nvanter** | Mevcut sağlık, enerji, yemek ve sığınak durumunu görüntüler. |
| **[F]Tehlike** | Bölgeye bir tehlike dalgası çağırır (For döngüsü). Sığınağın yıkılma riski vardır. |
| **[P]Şifre** | Şifreli sandığı açmaya çalışırsınız (Do-While). Doğru şifre (1234) ödül kazandırır. |
| **[X]Çıkış** | Simülasyonu sonlandırır. |

##  Kurulum ve Çalıştırma

Proje standart C kütüphanelerini kullanır (`stdio.h`, `stdlib.h`, `time.h`, `ctype.h`). Herhangi bir C derleyicisi ile çalıştırılabilir.

