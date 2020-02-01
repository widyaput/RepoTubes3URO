#include <stdio.h>
#include <string.h>
#include "hilmy.h"

int main() {
    Stats Robot;
    Stats *S;
    S = &Robot;
    int round = 0;
    int choice;
    
    StartStats(S);
    
    printf(
        "1. Makan\n"
        "2. Kerja\n"
        "3. Nongkrong\n"
        "4. MainHP\n"
        "5. Mandi\n"
        "6. Olahraga\n"
        "7. Belanja\n"
        "8. MainBG\n"
        "9. Nonton\n"
        "10. Bersih\n"
    );
    do {
        round += 1;
        printf("============RONDE %d============\n", round);
        printf("Health    %d\nHygiene   %d\n", Hlt(Robot),Hyg(Robot));
        printf("Social    %d\nHappiness %d\n", Soc(Robot),Hpy(Robot));
        printf("Money     %d\n", Mny(Robot));
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
    } while (Hlt(Robot)> 0 && Hpy(Robot)> 0);

    if(Hlt(Robot) <= 0) {
    	printf("Health    %d\nHygiene   %d\n", Hlt(Robot),Hyg(Robot));
        printf("Social    %d\nHappiness %d\n", Soc(Robot),Hpy(Robot));
        printf("Money     %d\n", Mny(Robot));
        printf("Nyawa Hilmy sudah habis.");
    } else if(Hpy(Robot) <= 0) {
    	printf("Health    %d\nHygiene   %d\n", Hlt(Robot),Hyg(Robot));
        printf("Social    %d\nHappiness %d\n", Soc(Robot),Hpy(Robot));
        printf("Money     %d\n", Mny(Robot));
        printf("Hilmy tidak bahagia. Dia meninggal karena depresi.");
    }

    return 0;
}
