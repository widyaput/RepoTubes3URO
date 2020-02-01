#ifndef _Hilmy_h_
#define _Hilmy_h_

#include <stdio.h>
#include <stdlib.h>

//Struct Stats
typedef struct{
    /* data */
    int Hlt;
    int Hpy;
    int Soc;
    int Hyg;
    int Mny;
    int skor;
}   Stats;

// Selektor
#define Hlt(S) (S).Hlt
#define Hpy(S) (S).Hpy
#define Soc(S) (S).Soc
#define Hyg(S) (S).Hyg
#define Mny(S) (S).Mny
#define skor(S) (S).skor

//Konstruktor
void TampilkanStats(Stats* S);
//Menampilkan stats hilmy

void StartStats(Stats* S);
//Inisiasi status awal

void Makan(Stats* S);
//fungsi kegiatan makan

void Kerja(Stats* S);
//fungsi kegiatan kerja

void Nongkrong(Stats* S);
//fungsi kegiatan nongkrong

void MainHP(Stats* S);
//fungsi kegiatan main hp

void Mandi(Stats* S);
//fungsi kegiatan mandi

void Olahraga(Stats* S);
//fungsi kegiatan olahraga

void Belanja(Stats* S);
//fungsi kegiatan belanja

void MainBG(Stats* S);
//fungsi kegiatan main board game

void Nonton(Stats* S);
//fungsi kegiatan nonton film

void Bersih(Stats* S);
//fungsi kegiatan bersih-bersih rumah

void KurangHlt(Stats* S, int W);
//fungsi untuk mengurangi health tiap ronde

void TbhSkor(Stats* S, int k);
//Fungsi untuk menambah skor player
#endif