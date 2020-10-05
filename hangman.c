#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define boolean unsigned char 
#define true 1
#define false 0

typedef char infotype;
typedef struct tElmtList *alamat;
typedef struct tElmtList{
	infotype info;
	alamat next;
}ElmtList;

typedef struct{
	alamat First;
}List;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

boolean CekKosong(List L){
	return (First(L)==NULL);
}

void BuatKosong(List *L){
	First(*L)=NULL;
}

alamat Alokasi(infotype X){
	alamat P;

	P=(alamat)malloc(sizeof(ElmtList));
	Info(P)=X;
	Next(P)=NULL;

	return P;
}

void Dealokasi(alamat *Del){
	free(*Del);
}

void TambahSimpulPertama(List *L, infotype X){
	alamat P;

	P=Alokasi(X);
	if(P!=NULL){
		Next(P)=First(*L);
		First(*L)=P;
	}
}

void TambahSimpulSesudah(alamat *prec,infotype X){
	alamat P;

	P=Alokasi(X);
	if(P!=NULL){
		Next(P)=Next(*prec);
		Next(*prec)=P;
	}
}

void TambahSimpulTerakhir(List *L,infotype X){
	alamat P,Last;

	P=Alokasi(X);
	if(P!=NULL){
		if(CekKosong(*L)){
			TambahSimpulPertama(&(*L),X);
		}else{
			Last=First(*L);
			while(Next(Last)!=NULL){
				Last=Next(Last);
			}
			TambahSimpulSesudah(&Last,X);
		}
	}
}

void HapusPertama(List *L, alamat *P){
	if(!CekKosong(*L)){
		*P=First(*L);
		First(*L)=Next(*P);
		Next(*P)=NULL;
		Dealokasi(P);
	}
}

void HapusTerakhir(List *L, alamat *P){
	alamat Last,PrecLast;

	if(!CekKosong(*L)){
		Last=First(*L);
		PrecLast=NULL;
		while(Next(Last)!=NULL){
			PrecLast=Last;
		}
		*P=Last;
		if(PrecLast==NULL){
			HapusPertama(&(*L),&(*P));
		}else{
			Next(PrecLast)=NULL;
		}
		Dealokasi(P);
	}
}

void PrintKataTertebak(List L,List L2, infotype X){
	alamat P,P2;

	P=First(L);
	P2=First(L2);
	while(P!=NULL&&P2!=NULL){
		if(Info(P)==X){
			Info(P2)=X;
		}
		P=Next(P);
		P2=Next(P2);
	}
}

void Tanda(List L){
	alamat P;

	P=First(L);
	while(P!=NULL){
		printf("-");
		P=Next(P);
	}
}

void Jawaban(List L){
	alamat P;

	P=First(L);
	while(P!=NULL){
		printf("%c",Info(P));
		P=Next(P);
	}
	printf("\n");
}

void KataSama(List L2){
	alamat P2;
	
	P2=First(L2);
	while(P2!=NULL){
		printf("%c",Info(P2));
		P2=Next(P2);
	}
	printf("\n");
}


void showHangman(int choice);


void MultyPlayer (){
char z[40];
char hangmanWord[100], tempWord[100];       /**untuk membandingkan masukan dan tebakan**/
    char hangmanOutput[100];
    int wrongTry = 4 , matchFound = 0;
        int counter = 0 , position = 0, winner, length , i;
    char alphabetFromUser;
    system ("cls");
        printf("+-----------------------------------------------------------------------------+\n");
    printf("|             _   _    _    _   _  ____ __  __    _    _   _                  |\n");
    printf("|            | | | |  / \\  | \\ | |/ ___|  \\/  |  / \\  | \\ | |                 |\n");
    printf("|            | |_| | / _ \\ |  \\| | |  _| |\\/| | / _ \\ |  \\| |                 |\n");
    printf("|            |  _  |/ ___ \\| |\\  | |_| | |  | |/ ___ \\| |\\  |                 |\n");
    printf("|            |_| |_/_/   \\_|_| \\_|\\____|_|  |_/_/   \\_|_| \\_|                 |\n");
    printf("|            ------------------------------------------------                 |\n");
    printf("|                            MULTI PLAYER                                    |\n");
    printf("|                                                                             |\n");
    printf("+-----------------------------------------------------------------------------+\n");

printf("Masukankata Hint : ");
scanf("%s",z);
printf("Masukan jawaban : ");
scanf("%s",hangmanWord);


//clean soal dan jawaban
    printf("\n\n Silahkan Berikan Komputer keteman anda untuk menebak");
    printf("\n\n\tTekan >>ENTER<<");
getchar();

length = strlen(hangmanWord);  // mendapatkan kata panjang

system("cls");

    printf("\n\n !!!!!!!!!!!!!!!!!!!Selamat Datang Di Game Hangman!!!!!!!!!!!!!!!!!\n\n\n");   /**Penjelasan singkat**/
    printf("\n\n Anda Mendapat 4 kesempatan untuk menebak kata");
    printf("\n\n Silahkan menebak dengan tekan Enter!!!!");

    getchar();
    
    
    system("cls");

        printf("\n\t||===== ");                 /**Menampilkan Kesempatan**/
		printf("\n\t||    | ");
        printf("\n\t||    O  ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
	printf("\n Anda harus menebak kata-kata dari %s", z);
    printf("\n\n     Banyak huruf ada %d dalam kata itu \n\n",length);
    
    for( i = 0; i < length ; i++)
    {
        hangmanOutput[i] = '_';
        hangmanOutput[length] = '\0';
    }

    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",hangmanOutput[i]);        /**Menunjukan kata dengan banyak n, berupa (_)**/

    }
    while(wrongTry != 0)                        /**while loop for untuk keluar dari program**/
    {
        matchFound = 0;
        printf("\n\n   masukan huruf apapun dari a sampai z, mohon gunakan huruf kecil!!");
        printf("\n\n\t Masukan disini ==> ");

	    fflush(stdin);

	    scanf("%c",&alphabetFromUser);            /**Mendapatkan huruf dari pengguna**/
    if(alphabetFromUser < 'a' || alphabetFromUser > 'z') /**jika pemain memasukan huruf selain aa sampai z , maka console akan di pertanyakan lagi**/
    {
        system("cls");
        printf("\n\n\t Masukan anda salah, silahkan masukan ulang ");
        matchFound = 2;
    }
    fflush(stdin);
    if (matchFound != 2)
    {
        for(counter=0;counter<length;counter++)    /**untuk mengecek apakah ada huruf masukan pengguna atau tidak dalam kata**/
	    {
		    if(alphabetFromUser==hangmanWord[counter])
		     {
		       matchFound = 1;
                     }
            }

	   if(matchFound == 0)                      /**Dalam kasus salah tebak**/
	    {
     	      printf("\n\t :( Masukan anda salah, Kesempatan anda berkurang satu ",--wrongTry);
	          getchar();
              showHangman(wrongTry);
              getchar();
	    }

	   else
	   {
	     for(counter = 0; counter < length; counter++)
             {
     	         matchFound = 0;
                 if(alphabetFromUser == hangmanWord[counter])
	          {
     		     position = counter ;
     		     matchFound = 1;
	          }
    	      if(matchFound == 1)
	          {
                 for(i = 0 ; i < length ; i++)
                 {
                      if( i == position)
                  	  {
                          hangmanOutput[i] = alphabetFromUser; /**Meletakkan huruf pada posisinya**/
                      }
                      else if( hangmanOutput[i] >= 'a' && hangmanOutput[i] <= 'z' ) /** jika posisi huruf sudah di tempati maka tidak perlu di isi lagi **/
                      {
                          continue;
                  	  }

                      else
                      {
                          hangmanOutput[i] = '_';            /** Letakkan kosong pada posisi alphabet yang tidak bisa ditebak **/
                      }
                }
                tempWord[position] = alphabetFromUser;      /**letakkan huruf di array char lain untuk memeriksa kata aslinya**/
                tempWord[length] = '\0';                    /**Letakkan karakter NULL di akhir temp string**/
                winner = strcmp(tempWord,hangmanWord);      /**Pada perbandingan Benar itu akan kembali 0**/

                if(winner == 0)                             /**Jika pemain menebak seluruh kata itu maka dia adalah PEMENANG**/
                {
                    printf("\n\n\t \t YEEE Kamu Adalah Pemenang!!!!");
                    printf("\n\n\t The Word was %s ",hangmanWord);
                    printf("\n\n\n\n\t\tMudah Kan??\n\n");
                    getchar();
                }
	       }
	    }
      }
     }
    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",hangmanOutput[i]);                /**Tampilkan kata asli dengan huruf kosong dan kanan Masukan Huruf**/
      }

    getchar();
    }//end of while loop

      if(wrongTry <= 0)                                 /**Jika pemain tidak bisa menebak dalam 4 kali kesempatan**/
      {
          printf("\n\n\t Kata yang benar %s ",hangmanWord);
          printf("\n\n\t Kesempatan Habis!!! Anda Kurang Cermat!!!");
	      printf("\n\n\t Semoga Beruntung Selanjutnya");

      }
getchar();

}
void SingelPlayer(){
	system("cls");
	char Kata1[16];
	char Kata2[16];
	List L;
	List L2;
	infotype x;
	int hasil=1;
	alamat P,P2;
	BuatKosong(&L);
	BuatKosong(&L2);
	int i;
	
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|             _   _    _    _   _  ____ __  __    _    _   _                  |\n");
    printf("|            | | | |  / \\  | \\ | |/ ___|  \\/  |  / \\  | \\ | |                 |\n");
    printf("|            | |_| | / _ \\ |  \\| | |  _| |\\/| | / _ \\ |  \\| |                 |\n");
    printf("|            |  _  |/ ___ \\| |\\  | |_| | |  | |/ ___ \\| |\\  |                 |\n");
    printf("|            |_| |_/_/   \\_|_| \\_|\\____|_|  |_/_/   \\_|_| \\_|                 |\n");
    printf("|            ------------------------------------------------                 |\n");
    printf("|                            SINGEL PLAYER                                    |\n");
    printf("|                                                                             |\n");
    printf("+-----------------------------------------------------------------------------+\n");
	printf ("Nama Buah  \n");
	printf ("\n");
	
	char Kata1tebak[][16]={"semangka","salak","rambutan","markisa","melon","durian"};

	int acak= rand() % 6;
	
	int PanjangKata=strlen(Kata1tebak[acak]);

	for(i=0;i<PanjangKata;i++){
		TambahSimpulTerakhir(&L,Kata1tebak[acak][i]);
		TambahSimpulTerakhir(&L2,'-');
		Kata1[i]=Kata1tebak[acak][i];
	}
	
	printf("Tebak Huruf : ");
	Tanda(L);
	printf(" Panjang 6 Tanda\n");

	int kesempatan = 4;
	while(kesempatan>1){
		printf("Jumlah Kesempatan Menebak : %d\n",kesempatan);
		fflush(stdin);scanf("%c",&x);
		PrintKataTertebak(L,L2,x);
		KataSama(L2);
		kesempatan--;
	}
	printf("Masukkan Kata Tebakan Secara Utuh : \n");
	scanf("%s",&Kata2);
	for(i=0;i<PanjangKata;i++){
		if(Kata2[i]!=Kata1[i]){
			hasil=0;
		}
		printf("\n");
	}
	if(hasil==1){
		printf("Selamat Jawaban Anda Benar\n");
	}else{
		printf("Jawaban anda salah\n");
		printf("\n");
		printf("Jawaban yang Benar adalah : ");
		Jawaban(L);
	}
}
void MenuUtama(){
	int a;
	printf("+-----------------------------------------------------------------------------+\n");
    printf("|             _   _    _    _   _  ____ __  __    _    _   _                  |\n");
    printf("|            | | | |  / \\  | \\ | |/ ___|  \\/  |  / \\  | \\ | |                 |\n");
    printf("|            | |_| | / _ \\ |  \\| | |  _| |\\/| | / _ \\ |  \\| |                 |\n");
    printf("|            |  _  |/ ___ \\| |\\  | |_| | |  | |/ ___ \\| |\\  |                 |\n");
    printf("|            |_| |_/_/   \\_|_| \\_|\\____|_|  |_/_/   \\_|_| \\_|                 |\n");
    printf("|            ------------------------------------------------                 |\n");
    printf("|                                                                             |\n");
    printf("|                1. Singel Player                                             |\n");
    printf("|                2. Multy Player                                              |\n");
    printf("+-----------------------------------------------------------------------------+\n");
    
    printf("Pilih Mode Player : ");
    scanf("%d",&a);
    switch(a){
		case 1:
			SingelPlayer();
			break;
		case 2:
			MultyPlayer();
			break;
    }
}

int main(){
	MenuUtama();
	return 0;
}
void showHangman(int choice)                            /**Fungsi ini menunjukkan hangman setelah setiap salah mencoba**/
 {

     switch(choice)
     {

     case 0:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	break;
     case 1:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	break;
     case 2:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 3:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
      }
      return;
 }

