# C İle Sezar Sifreleme
Bu proje Algoritma ve Programlama II dersinin yıl sonu ödevidir.

---

## Proje Hakkında Temel Açıklama
Proje temel olarak C dili ile öğrenci isimini ve soyismini "Sezar Şifreleme" yöntemiyle şifreleyen ve sonrasında şifreli metni TXT dosyasına kaydeden daha sonrasında parola sistemiyle ile şifreli metni gösteren konsol uygulamasıdır. Projenin detayları [Algoritma ve Programlama II - Proje.pdf](https://github.com/CeylinC/Sezar-Sifreleme-C/blob/main/Algoritma%20ve%20Programlama%20II%20-%20Proje.pdf)'inde yer almaktadır.

### Sezar Sifreleme Yöntemi Nedir?
Şifrelenecek metinin belirtilen anahtar sayısı kadar alfabede ilerletilmesidir. Okuma işleminde ise şifreli metin belirtilen anahtar sayısı kadar geriye döndürülür.
Bu projede anahtar sayısı öğrenci numarasının son rakamadır(0 ise solundaki ele alınır).

### Parola Sistemi Nasıl?
Uygulama **öğrenci numaranın en büyük asal sayısını** hesaplar, sifre gösterilmeden önce kullanıcıya sorar. Kullanıcı parolayı doğru girdiğinde şifreli metni, şifreli metnin çözülmüş halini ve öğrenci numarasını ekrana bastırır. Parola yanlış girildiğinde ise kullanıcıya tekrar sorulur.
