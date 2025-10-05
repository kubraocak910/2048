#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> // Konsoldan tuş okumak için getch() gibi fonksiyonlar (Windows'a özgüd
#include <windows.h> // kullacağımız siste komutları cls


// tabloyu çizdik
int tablo [4][4] ={0};
int sifirSayisi;


void oyunBitti() {
    system("cls");
    printf("\n\n=== OYUN BİTTİ ===\n");
    printf("Çıkmak için bir tuşa basın...\n");
    getch();
}

void sifirSay() {
    int sifirSayisi = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (tablo[i][j] == 0)
                sifirSayisi++;
                
}

void up() {
    int hareketVarMi = 0;
    for (int j = 0; j < 4; j++) {
        /// ilk  yukarı 
        for (int tur = 0; tur < 3; tur++) {
            for (int i = 1; i <4 ; i++) {
                if (tablo[i-1][j] == 0 && tablo[i][j] != 0) {
                    tablo[i-1][j] = tablo[i][j];
                    tablo[i][j] = 0;
                    hareketVarMi = 1;}}}
        // birleştir
        for (int i=1; i<4 ; i++) {
            if (tablo[i-1][j] == tablo[i][j] && tablo[i][j] != 0) {
                tablo[i-1][j] *= 2;
                tablo[i][j] = 0;
                hareketVarMi = 1;}}
            // hareket yukarıya doğtu o yüzden birleştirme yaparken i = 1 i-1= 0 konumundan ilerlememiz gerekli 
        // tekrar  yukarı  kaydır
         for (int tur = 0; tur < 3; tur++) {
            for (int i = 1; i < 4; i++) {
                if (tablo[i-1][j] == 0 && tablo[i][j] != 0) {
                    tablo[i-1][j] = tablo[i][j];
                    tablo[i][j] = 0;
                    hareketVarMi = 1;}}}}

   if (!hareketVarMi) {
        sifirSay();
        if (sifirSayisi == 0) {
            oyunBitti();
            exit(0);}}}           

void  down() {
    int hareketVarMi = 0;
    for (int j = 0; j < 4; j++) {
        /// ilk  aşağı 
        for (int tur = 0; tur < 3; tur++) {
            for (int i = 0; i < 3; i++) {
                if (tablo[i+1][j] == 0 && tablo[i][j] != 0) {
                    tablo[i+1][j] = tablo[i][j];
                    tablo[i][j] = 0;
                    hareketVarMi = 1;}}}
        // birleştir
        for (int i=2 ; i >= 0; i--) {
            if (tablo[i+1][j] == tablo[i][j] && tablo[i][j] != 0) {
                tablo[i+1][j] *= 2;
                tablo[i][j] = 0;
                hareketVarMi = 1;}}
           
        // tekrar  yukarı  kaydır
         for (int tur = 0; tur < 3; tur++) {
            for (int i = 0 ; i < 3; i++) {
                if (tablo[i+1][j] == 0 && tablo[i][j] != 0) {
                    tablo[i+1][j] = tablo[i][j];
                    tablo[i][j] = 0;
                    hareketVarMi = 1;}}}}

   if (!hareketVarMi) {
        sifirSay();
        if (sifirSayisi == 0) {
            oyunBitti();
            exit(0);}}}

void  right() {
    int hareketVarMi = 0;
    for (int i= 0; i < 4; i++) {
        /// ilk  sağ 
        for (int tur = 0; tur < 3; tur++) {
            for (int j = 0; j < 3; j++) {
                if (tablo[i][j+1] == 0 && tablo[i][j] != 0) {
                    tablo[i][j+1] = tablo[i][j];
                    tablo[i][j] = 0;
                    hareketVarMi = 1;}}}
        // birleştir
        for (int j=2 ; j >= 0; j--) {
            if (tablo[i][j+1] == tablo[i][j] && tablo[i][j] != 0) {
                tablo[i][j+1] *= 2;
                tablo[i][j] = 0;
                hareketVarMi = 1;}}

        // tekrar  sağ  kaydır
         for (int tur = 0; tur < 3; tur++) {
            for (int j = 0 ; j < 3; j++) {
                if (tablo[i][j+1] == 0 && tablo[i][j] != 0) {
                    tablo[i][j+1] = tablo[i][j];
                    tablo[i][j] = 0;
                    hareketVarMi = 1;}}}}

   if (!hareketVarMi) {
        sifirSay();
        if (sifirSayisi == 0) {
            oyunBitti();
            exit(0);}}}          

 void left() {
    int hareketVarMi = 0;
    for (int i = 0; i < 4; i++) {
        /// ilk  yukarı 
        for (int tur = 0; tur < 3; tur++) {
            for (int j = 1; j <4 ; j++) {
                if (tablo[i][j-1] == 0 && tablo[i][j] != 0) {
                    tablo[i][j-1] = tablo[i][j];
                    tablo[i][j] = 0;
                    hareketVarMi = 1;}}}
        // birleştir
        for (int j=1; j<4 ; j++) {
            if (tablo[i][j-1] == tablo[i][j] && tablo[i][j] != 0) {
                tablo[i][j-1] *= 2;
                tablo[i][j] = 0;
                hareketVarMi = 1;}}
            
        // tekrar  yukarı  kaydır
         for (int tur = 0; tur < 3; tur++) {
            for (int j = 1; j < 4; j++) {
                if (tablo[i][j-1] == 0 && tablo[i][j] != 0) {
                    tablo[i][j-1] = tablo[i][j];
                    tablo[i][j] = 0;
                    hareketVarMi = 1;}}}}

   if (!hareketVarMi) {
        sifirSay();
        if (sifirSayisi == 0) {
            oyunBitti();
            exit(0);}}}

void tabloyazdir() {
     for(int i= 0;i<4;i++){
            for (int j=0;j<4;j++){
                 printf(" ");
                 printf("%d", tablo[i][j]);}
            printf("\n");}
    printf("***********************\n");
}

void sayiekle(){
    int x = rand()%4;
    int y = rand()%4;
    while(tablo[x][y] != 0){
        x = rand()%4;
        y = rand()%4;}
    tablo[x][y] = 2;
    tabloyazdir();}

int main()
{
    char tus;
    srand(time(NULL));  
    tabloyazdir();
    sayiekle();
/// kullanıcodan   yer yön bilgisi alıyoruz 
while(1){
    
    scanf("%c",&tus);

    if (tus =='w' || tus == 'W'){
         up();
         sayiekle();
         tabloyazdir();}
    else if (tus =='s' || tus == 'S'){
         down();
         sayiekle();
         tabloyazdir();}
    else if (tus =='d' || tus == 'D'){
         right();
         sayiekle();
         tabloyazdir();}
    else if (tus =='a' || tus == 'A'){
         left();
         sayiekle();
         tabloyazdir();}
    else if (tus =='e' || tus == 'E'){
         oyunBitti();
         break;}

}

return 0;
}
