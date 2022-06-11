#include <stdio.h>
#include <string.h>

struct Ogrenci{
	char ad[15];
	char soyad[15];
	int no;
};

struct Sifre{
	int anahtarSayi;
	char sifrelenecekMetin[30];
	char sifreliMetin[30];
};

int KarakterKontrol(char str[15]){
	int i;
	for(i = 0; i < strlen(str);i++){
		if(!(((str[i] >= 97) && (str[i] <= 122)) || ((str[i] >= 65) && (str[i] <= 90)))){
			printf("\nLutfen Turkce Karakter, Rakam, Sembol ve Bosluk Kullanmayiniz!\n\n");
			return 1; //Hata var
		}
	}
	return 0; //Hata yok
}

void BilgiAlma(struct Ogrenci *ogrPtr){
	int hataVarMi=0;
	while(1){
		printf("Adiniz Nedir? (Iki Isimli Ise Bosluk Birakmayiniz!) : ");
		scanf("%s",&ogrPtr->ad);
		
		if(KarakterKontrol(ogrPtr->ad))
			continue;
		
		printf("Soyadiniz Nedir? : ");
		scanf("%s",&ogrPtr->soyad);
		
		if(KarakterKontrol(ogrPtr->soyad))
			continue;

		printf("Ogrenci  Numaraniz  Nedir? : ");
		scanf("%d",&ogrPtr->no);
		break;
	}
}

void AnahtarSayiBulma(struct Ogrenci *ogrPtr, struct Sifre *sifrePtr){
	int temp = ogrPtr->no, sayi;
	while(1){
		sayi = temp % 10;
		temp /= 10;
		if(sayi != 0)
			break;
	}
	sifrePtr->anahtarSayi = sayi;
}

void MetinBirlestirme(struct Ogrenci *ogrPtr, struct Sifre *sifrePtr){
	strcpy(sifrePtr->sifrelenecekMetin, ogrPtr->ad);
	strcat(sifrePtr->sifrelenecekMetin, ogrPtr->soyad);
}

void Sifreleme(struct Ogrenci *ogrPtr, struct Sifre *sifrePtr){
	AnahtarSayiBulma(ogrPtr, sifrePtr);
	MetinBirlestirme(ogrPtr, sifrePtr);
	
	int i;
	char sifre[20];
	
	for(i=0; i<strlen(sifrePtr->sifrelenecekMetin); i++){
		if((sifrePtr->sifrelenecekMetin[i] >= 97) && (sifrePtr->sifrelenecekMetin[i] <= 122)){
			sifrePtr->sifreliMetin[i] = ((sifrePtr->sifrelenecekMetin[i] + sifrePtr->anahtarSayi) > 122 ? (sifrePtr->sifrelenecekMetin[i] + sifrePtr->anahtarSayi) - 26 : (sifrePtr->sifrelenecekMetin[i] + sifrePtr->anahtarSayi));
		}
		else if((sifrePtr->sifrelenecekMetin[i] >= 65) && (sifrePtr->sifrelenecekMetin[i] <= 90)){
			sifrePtr->sifreliMetin[i] = ((sifrePtr->sifrelenecekMetin[i] + sifrePtr->anahtarSayi) > 90 ? (sifrePtr->sifrelenecekMetin[i] + sifrePtr->anahtarSayi) - 26 : (sifrePtr->sifrelenecekMetin[i] + sifrePtr->anahtarSayi));
		}
	}
	sifrePtr->sifreliMetin[i] = '\0';
}

void SifreOkuma(struct Sifre *sifrePtr){
	int i;

	for(i=0; i<strlen(sifrePtr->sifreliMetin); i++){
		if((sifrePtr->sifreliMetin[i] >= 97) && (sifrePtr->sifreliMetin[i] <= 122)){
			sifrePtr->sifrelenecekMetin[i] = ((sifrePtr->sifreliMetin[i] - sifrePtr->anahtarSayi) < 97 ? (sifrePtr->sifreliMetin[i] - sifrePtr->anahtarSayi) + 26 : (sifrePtr->sifreliMetin[i] - sifrePtr->anahtarSayi));
		}
		else if((sifrePtr->sifreliMetin[i] >= 65) && (sifrePtr->sifreliMetin[i] <= 90)){
			sifrePtr->sifrelenecekMetin[i] = ((sifrePtr->sifreliMetin[i] - sifrePtr->anahtarSayi) < 65 ? (sifrePtr->sifreliMetin[i] - sifrePtr->anahtarSayi) + 26 : (sifrePtr->sifreliMetin[i] - sifrePtr->anahtarSayi));
		}
	}
	sifrePtr->sifrelenecekMetin[i] = '\0';
}

void DosyaYazma(struct Sifre *sifrePtr){
	FILE *dosya;
	if((dosya = fopen("sifrelimetin.txt","w")) == NULL){
		printf("\nDosya Isleminde Bir Hata Meydana Geldi!\n");
		exit(1);
	}
	fprintf(dosya,"%s",sifrePtr->sifreliMetin);
	fclose(dosya);
}

void DosyaOkuma(struct Sifre *sifrePtr){
	FILE *dosya;
	if((dosya = fopen("sifrelimetin.txt","r")) == NULL){
		printf("\nDosya Isleminde Bir Hata Meydana Geldi!\n");
		exit(1);
	}
	fscanf(dosya,"%s",&sifrePtr->sifreliMetin);
	fclose(dosya);
}

int AsalCarpanBulma(struct Ogrenci *ogrPtr){
	int i=1, sayi = ogrPtr->no;
	while((i<sayi) && (sayi-i != 1)){
		if(sayi % (sayi-i) ==0){
			sayi -= i;
			i=1;
			continue;
		}
		i++;
	}
	return sayi;
}

int GirisKontrol(struct Ogrenci *ogrPtr, struct Sifre *sifrePtr){
	int sifre, enBuyukAsalCarpan;
	enBuyukAsalCarpan = AsalCarpanBulma(ogrPtr);
	while(1){
		printf("Ogrenci  Numaranizin  En  Buyuk  Asal Carpani Nedir? : ");
		scanf("%d",&sifre);
		
		if(sifre == enBuyukAsalCarpan){
			DosyaOkuma(sifrePtr);
			printf("\n******************************\n");
			printf("Sifre : %s\n",sifrePtr->sifreliMetin);
			SifreOkuma(sifrePtr);
			printf("Sifrenin Anlami : %s\n",sifrePtr->sifrelenecekMetin);
			printf("Ogrenci No : %d",ogrPtr->no);
			printf("\n******************************\n");
			break;
		}
		else{
			printf("Hatali Giris Lutfen Tekrar Deneyiniz\n");
		}
	}
}

int main(){
	struct Ogrenci ogr;
	struct Sifre sifre;
	
	printf("Merhaba! Sezar Sifreleme Uygulamasina Hosgeldiniz\nLutfen Turkce Karakter Kullanmayiniz!\n\n");
	BilgiAlma(&ogr);
	Sifreleme(&ogr, &sifre);
	DosyaYazma(&sifre);
	GirisKontrol(&ogr,&sifre);
}

