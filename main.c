#include <stdio.h>
#include <string.h>
#include "hilmy.h"

int main() {
	int skortertinggi=0;
	char namaskortertinggi[100]="Anonim";
	int maingame;
	do{
		printf("Selamat Datang di Permainan Hilmy's Life !\n");
		printf("Skor Tertinggi Saat Ini : %s - %d\n",namaskortertinggi,skortertinggi);
		printf("Siapa Namamu ?\n");
		char nama[100];
		scanf(" %[^\n]", &nama);
		printf("Selamat bermain Hilmy's Life %s !\n",nama);
		Stats Robot;
		Stats *S;
		S = &Robot;
		int round = 0;
		int choice;
		bool berhasil;
		
		StartStats(S);
		
		printf(
			"Berikut adalah kegiatan yang dapat dilakukan oleh hilmy\n"
			"1. Makan (skor +3)\n"
			"2. Kerja (skor +5)\n"
			"3. Nongkrong (skor +3)\n"
			"4. MainHP (skor +2)\n"
			"5. Mandi (skor +4)\n"
			"6. Olahraga (skor +4)\n"
			"7. Belanja (skor +5)\n"
			"8. MainBG (skor +2)\n"
			"9. Nonton (skor +4)\n"
			"10. Bersih (skor +4)\n"
		);
		do {
			round += 1;
			int moneyf, hygienef, happinessf, socialf;
			berhasil=false;
			printf("\n============RONDE %d============\n", round);
			printf("Skormu akan bertambah %d jika berhasil melewati ronde ini\n", (round*5));
			TampilkanStats(S);
			if(round<=3){
				moneyf=round*5+5;
				printf("============Goals Ronde %d============\nMoney	%d\n", round,moneyf);
			} else if(4<=round<=6){
				moneyf=round*5;
				socialf=round*5+20;
				printf("============Goals Ronde %d============\nMoney	%d\nSocial	%d\n", round,moneyf,socialf);
			} else if(7<=round<=10){
				moneyf=round*5;
				socialf=30;
				hygienef=round*5-15;
				printf("============Goals Ronde %d============\n Money	%d\n Social	%d\n Hygiene	%d\n", round,moneyf,socialf,hygienef);	
			} else {
				moneyf=round*5;
				if (moneyf>=80){
					moneyf=80;
				}
				socialf=40;
				hygienef=40;
			}
			do {
				if(Hlt(Robot)<=10){
					printf("PERINGATAN ! Kesehatan Hilmy berada dalam bahaya. Pilihlah kegiatan yang ingin dilakukan dengan tepat.\n");
				} if(Hpy(Robot)<=10){
					printf("PERINGATAN ! Hilmy tidak bahagia !. Pilihlah kegiatan yang tepat sebelum hilmy depresi.\n");
				}
				printf("Apa yang harus Hilmy lakukan?\n");
				scanf("%d", &choice);
				if (choice == 1) {
					Makan(S);
				} else if (choice == 2) {
					Kerja(S); 
				} else if (choice == 3) {
					Nongkrong(S);
				} else if (choice == 4) {
					MainHP(S);
				} else if (choice == 5) {
					Mandi(S);
				} else if (choice == 6) {
					Olahraga(S);
				} else if (choice == 7) {
					Belanja(S);
				} else if (choice == 8) {
					MainBG(S);
				} else if (choice == 9) {
					Nonton(S);
				} else if (choice == 10) {
					Bersih(S);
				} else {
					round -= 1;
				}
				if ((round<=3) && (Mny(Robot)>=moneyf)){
					berhasil=true;
				} else if ((4<=round<=6)&&(Mny(Robot)>=moneyf)&&(Soc(Robot)>=socialf)){
					berhasil=true;
				} else if ((7<=round<=10)&&(Mny(Robot)>=moneyf)&&(Soc(Robot)>=socialf)&&(Hyg(Robot)>=hygienef)){
					berhasil=true;
				} else if ((11<=round)&&(Mny(Robot)>=moneyf)&&(Soc(Robot)>=socialf)&&(Hyg(Robot)>=hygienef)){
					berhasil=true;
				} TampilkanStats(S);
				} while (Hlt(Robot)> 0 && Hpy(Robot)>0 && berhasil==false);
				if (berhasil==true && Hlt(Robot)> 0 && Hpy(Robot)> 0){
					TbhSkor(S, (round*5));
				}
			}while (Hlt(Robot)> 0 && Hpy(Robot)> 0 && berhasil==true);
		if(Hlt(Robot) <= 0) {
			printf("Nyawa Hilmy sudah habis.\n");
		} else if(Hpy(Robot) <= 0) {
			printf("Hilmy tidak bahagia. Dia meninggal karena depresi.\n");		
		}
		printf("=== GAME OVER ===\nSkor akhirmu adalah %d\n",skor(Robot));
		if(skor(Robot)>skortertinggi){
			printf("Selamat %s !, Kamu telah mencetak skor tertinggi baru.\n",nama);
			skortertinggi=skor(Robot);
			strcpy(namaskortertinggi, nama);
		} 
		printf("Apakah kamu ingin bermain lagi ?\nKetik 1 untuk ya\nKetik 0 untuk tidak\n");
		scanf("%d",&maingame);
	} while (maingame==1);
    return 0;
}
