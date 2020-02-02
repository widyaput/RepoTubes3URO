#include "hilmy.h"

void TampilkanStats(Stats* S){
    printf("\n=== Statistik Hilmy ===\n");
    printf("Health    %d\nHygiene   %d\n", Hlt(*S),Hyg(*S));
    printf("Social    %d\nHappiness %d\n", Soc(*S),Hpy(*S));
    printf("Money     %d\n", Mny(*S));
    printf("Skor sekarang : %d\n",skor(*S));
    printf("=======================\n");
}

void StartStats(Stats* S){
    Hlt(*S) = 100;
    Hpy(*S) = 50;
    Soc(*S) = 50;
    Hyg(*S) = 100;
    Mny(*S) = 0;
    skor(*S) = 0;
}

void TbhSkor(Stats* S, int k){
    skor(*S) += k;
}

void KurangHlt(Stats* S, int W){
    Hlt(*S) -= W;
}

void Makan(Stats* S){
    if (Mny(*S) < 5){
        printf("Uang tidak cukup\n");
        return;
    }
    Hpy(*S) += 5;
    if (Hpy(*S) > 100){
        Hpy(*S) = 100;
    }
    Mny(*S) -= 5;
    KurangHlt(S, 5);
    TbhSkor(S, 3);
}

void Kerja(Stats* S){
    Hpy(*S) -= 10;
    if (Hpy(*S) < 0){
        Hpy(*S) = 0;
    }
    Mny(*S) += 30;
    if (Mny(*S) > 100){
        Mny(*S) = 100;
    }
    KurangHlt(S, 15);
    TbhSkor(S, 5);
}

void Nongkrong(Stats* S){
    if (Mny(*S) < 5) {
        printf("Uang tidak cukup\n");
        return;
    }
    Hpy(*S) += 3;
    if (Hpy(*S) > 100){
        Hpy(*S) = 100;
    }
    Soc(*S) += 3;
    if (Soc(*S) > 100){
        Soc(*S) = 100;
    }
    Mny(*S) -= 5;
    KurangHlt(S,5);
    TbhSkor(S, 3);
}

void MainHP(Stats* S){
    if (Mny(*S) < 5) {
        printf("Uang tidak cukup\n");
        return;
    }
    Soc(*S) -= 15;
    if (Soc(*S) < 0){
        Soc(*S) = 0;
    }
    Hpy(*S) += 7;
    if (Hpy(*S) > 100){
        Hpy(*S) = 100;
    }
    Mny(*S) -= 5;
    KurangHlt(S,10);
    TbhSkor(S, 2);
}

void Mandi(Stats* S){
    if (Mny(*S) < 5) {
        printf("Uang tidak cukup\n");
        return;
    }
    Hyg(*S) += 20;
    if (Hyg(*S) > 100){
        Hyg(*S) = 100;
    }
    Mny(*S) -= 5;
    KurangHlt(S,5);
    TbhSkor(S, 4);
}

void Olahraga(Stats* S){
    if (Mny(*S) < 15){
        printf("Uang tidak cukup\n");
        return;
    }
    Hyg(*S) -= 25;
    if (Hyg(*S) < 0){
        Hyg(*S) = 0;
    }
    Hpy(*S) += 15;
    if (Hpy(*S) > 100){
        Hpy(*S) = 100;
    }
    Mny(*S) -= 15;
    KurangHlt(S,10);
    TbhSkor(S, 4);
}

void Belanja(Stats* S){
    if (Mny(*S) < 30){
        printf("Uang tidak cukup\n");
        return;
    }
    Hpy(*S) += 25;
    if (Hpy(*S) > 100){
        Hpy(*S) = 100;
    }
    Mny(*S) -= 40;
    KurangHlt(S,10);
    TbhSkor(S, 5);
}

void MainBG(Stats* S){
    if (Mny(*S) < 10){
        printf("Uang tidak cukup\n");
        return;
    }
    Soc(*S) += 10;
    if (Soc(*S) > 100){
        Soc(*S) = 100;
    }
    Hpy(*S) += 5;
    if (Hpy(*S) >= 100){
        Hpy(*S) = 100;
    }
    Mny(*S) -= 10;
    KurangHlt(S,5);
    TbhSkor(S, 2);
}

void Nonton(Stats* S){
    if (Mny(*S) < 10){
        printf("Uang tidak cukup\n");
        return;
    }
    Hpy(*S) += 10;
    if (Hpy(*S) > 100){
        Hpy(*S) = 100;
    }
    Mny(*S) -= 10;
    KurangHlt(S, 5);
    TbhSkor(S, 4);
}

void Bersih(Stats* S){
    if (Mny(*S) < 5){
        printf("Uang tidak cukup\n");
        return;
    }
    Hyg(*S) += 10;
    if (Hyg(*S) > 100){
        Hyg(*S) = 100;
    }
    Hpy(*S) += 5;
    if (Hpy(*S) > 100){
        Hpy(*S) = 100;
    }
    Mny(*S) -= 5;
    KurangHlt(S, 5);
    TbhSkor(S, 4);
}
