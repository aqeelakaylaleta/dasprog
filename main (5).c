/* Toolkit Lengkap Asisten Laboratorium - C
   Sesuai spesifikasi "Spec Project" (Dasar Pemrograman).
   Compile: gcc -o toolkit toolkit.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
  #define CLEAR_CMD "cls"
#else
  #define CLEAR_CMD "clear"
#endif

/* --- Deklarasi fungsi --- */
void pressEnterToContinue();
void showMenu();
void calcOhm();
void calcPower();
void calcSeries();
void calcParallel();
void decToOthers();
void binToDec();
void octToDec();
void hexToDec();

/* --- Fungsi utama --- */
int main() {
    int choice;
    do {
        system(CLEAR_CMD);
        showMenu();
        printf("Masukkan pilihan Anda (1-9): ");
        if (scanf("%d", &choice) != 1) {
            // jika input bukan angka, buang input dan ulang
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            choice = 0;
        }

        // buang newline yang tersisa
        int c; while ((c = getchar()) != '\n' && c != EOF) {}

        switch (choice) {
            case 1: calcOhm(); break;
            case 2: calcPower(); break;
            case 3: calcSeries(); break;
            case 4: calcParallel(); break;
            case 5: decToOthers(); break;
            case 6: binToDec(); break;
            case 7: octToDec(); break;
            case 8: hexToDec(); break;
            case 9:
                printf("\nTerima kasih telah menggunakan toolkit ini!\n");
                break;
            default:
                printf("\nPilihan tidak valid. Silakan masukkan angka 1-9.\n");
                pressEnterToContinue();
        }
    } while (choice != 9);

    return 0;
}

/* --- Implementasi fungsi bantu --- */
void showMenu() {
    printf("=================================================\n");
    printf("| TOOLKIT LENGKAP ASISTEN LABORATORIUM ELEKTRO |\n");
    printf("=================================================\n");
    printf("| --- Verifikasi Rangkaian Elektrik ---         |\n");
    printf("| 1. Kalkulator Hukum Ohm (V = I * R)          |\n");
    printf("| 2. Kalkulator Daya Listrik (P = V * I)       |\n");
    printf("| 3. Kalkulator Resistor Seri                   |\n");
    printf("| 4. Kalkulator Resistor Paralel                |\n");
    printf("|                                              |\n");
    printf("| --- Utilitas Sistem Digital ---              |\n");
    printf("| 5. Desimal -> Biner / Oktal / Heksadesimal   |\n");
    printf("| 6. Biner -> Desimal                           |\n");
    printf("| 7. Oktal -> Desimal                           |\n");
    printf("| 8. Heksadesimal -> Desimal                    |\n");
    printf("|                                              |\n");
    printf("| 9. Keluar                                     |\n");
    printf("-------------------------------------------------\n");
}

/* Menunggu Enter untuk kembali */
void pressEnterToContinue() {
    printf("\nTekan Enter untuk kembali ke menu utama ...");
    while (getchar() != '\n') {}
}

/* --- Fungsi nomor 1: Kalkulator Hukum Ohm --- */
void calcOhm() {
    system(CLEAR_CMD);
    printf("--- Kalkulator Hukum Ohm (V = I * R) ---\n");
    printf("Hitung: 1) Tegangan (V)  2) Arus (I)  3) Hambatan (R)\n");
    printf("Pilih (1-3): ");
    int opt;
    if (scanf("%d", &opt) != 1) { while (getchar()!='\n'); opt = 0; }
    double V, I, R;
    switch (opt) {
        case 1:
            printf("Masukkan Arus (I) dalam Ampere: ");
            scanf("%lf", &I);
            printf("Masukkan Hambatan (R) dalam Ohm: ");
            scanf("%lf", &R);
            V = I * R;
            printf("\nHasil: V = I * R = %.6g V\n", V);
            break;
        case 2:
            printf("Masukkan Tegangan (V) dalam Volt: ");
            scanf("%lf", &V);
            printf("Masukkan Hambatan (R) dalam Ohm: ");
            scanf("%lf", &R);
            if (R == 0) {
                printf("\nError: Hambatan R tidak boleh 0 untuk menghitung arus.\n");
            } else {
                I = V / R;
                printf("\nHasil: I = V / R = %.6g A\n", I);
            }
            break;
        case 3:
            printf("Masukkan Tegangan (V) dalam Volt: ");
            scanf("%lf", &V);
            printf("Masukkan Arus (I) dalam Ampere: ");
            scanf("%lf", &I);
            if (I == 0) {
                printf("\nError: Arus I tidak boleh 0 untuk menghitung hambatan.\n");
            } else {
                R = V / I;
                printf("\nHasil: R = V / I = %.6g Ohm\n", R);
            }
            break;
        default:
            printf("\nPilihan tidak valid.\n");
    }
    // buang sisa input
    while (getchar() != '\n') {}
    pressEnterToContinue();
}

/* --- Fungsi nomor 2: Kalkulator Daya Listrik --- */
void calcPower() {
    system(CLEAR_CMD);
    printf("--- Kalkulator Daya Listrik (P = V * I) ---\n");
    double V, I;
    printf("Masukkan Tegangan (V) dalam Volt: ");
    scanf("%lf", &V);
    printf("Masukkan Arus (I) dalam Ampere: ");
    scanf("%lf", &I);
    double P = V * I;
    printf("\nHasil: P = V * I = %.6g Watt\n", P);
    while (getchar() != '\n') {}
    pressEnterToContinue();
}

/* --- Fungsi nomor 3: Resistor Seri --- */
void calcSeries() {
    system(CLEAR_CMD);
    printf("--- Kalkulator Resistor Seri ---\n");
    int n;
    printf("Masukkan jumlah resistor: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("\nInput tidak valid.\n");
        while (getchar() != '\n') {}
        pressEnterToContinue();
        return;
    }
    double total = 0.0;
    for (int i = 1; i <= n; i++) {
        double r;
        printf("Masukkan nilai Resistor %d (Ohm): ", i);
        scanf("%lf", &r);
        total += r;
    }
    printf("\nTotal Hambatan Seri adalah: %.6g Ohm\n", total);
    while (getchar() != '\n') {}
    pressEnterToContinue();
}

/* --- Fungsi nomor 4: Resistor Paralel --- */
void calcParallel() {
    system(CLEAR_CMD);
    printf("--- Kalkulator Resistor Paralel ---\n");
    int n;
    printf("Masukkan jumlah resistor: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("\nInput tidak valid.\n");
        while (getchar() != '\n') {}
        pressEnterToContinue();
        return;
    }
    double inv_total = 0.0;
    for (int i = 1; i <= n; i++) {
        double r;
        printf("Masukkan nilai Resistor %d (Ohm): ", i);
        scanf("%lf", &r);
        if (r == 0) {
            printf("\nError: Resistor tidak boleh bernilai 0 (menyebabkan arus tak hingga).\n");
            while (getchar() != '\n') {}
            pressEnterToContinue();
            return;
        }
        inv_total += 1.0 / r;
    }
    if (inv_total == 0.0) {
        printf("\nError: total kebalikan = 0, hasil tidak terdefinisi.\n");
    } else {
        double r_total = 1.0 / inv_total;
        printf("\nTotal Hambatan Paralel adalah: %.6g Ohm\n", r_total);
    }
    while (getchar() != '\n') {}
    pressEnterToContinue();
}

/* --- Fungsi nomor 5: Desimal -> Biner/Oktal/Heksadesimal --- */
void decToOthers() {
    system(CLEAR_CMD);
    printf("--- Konversi dari Desimal ---\n");
    unsigned long long n;
    printf("Masukkan bilangan desimal (>=0): ");
    if (scanf("%llu", &n) != 1) {
        printf("\nInput tidak valid.\n");
        while (getchar() != '\n') {}
        pressEnterToContinue();
        return;
    }

    // Biner
    if (n == 0) {
        printf("\nHasil Konversi:\n- Biner : 0\n- Oktal : 0\n- Heksadesimal : 0\n");
        while (getchar() != '\n') {}
        pressEnterToContinue();
        return;
    }

    char bin[512] = {0}, oct[256] = {0}, hexs[256] = {0};
    int ib = 0, io = 0, ih = 0;
    unsigned long long temp = n;

    // biner
    while (temp > 0) {
        bin[ib++] = (temp % 2) + '0';
        temp /= 2;
    }
    // reverse
    for (int i = 0; i < ib/2; i++) {
        char t = bin[i]; bin[i] = bin[ib-1-i]; bin[ib-1-i] = t;
    }
    bin[ib] = '\0';

    // oktal
    temp = n;
    while (temp > 0) {
        oct[io++] = (temp % 8) + '0';
        temp /= 8;
    }
    for (int i = 0; i < io/2; i++) {
        char t = oct[i]; oct[i] = oct[io-1-i]; oct[io-1-i] = t;
    }
    oct[io] = '\0';

    // heksadesimal
    temp = n;
    while (temp > 0) {
        int rem = temp % 16;
        if (rem < 10) hexs[ih++] = '0' + rem;
        else hexs[ih++] = 'A' + (rem - 10);
        temp /= 16;
    }
    for (int i = 0; i < ih/2; i++) {
        char t = hexs[i]; hexs[i] = hexs[ih-1-i]; hexs[ih-1-i] = t;
    }
    hexs[ih] = '\0';

    printf("\nHasil Konversi:\n- Biner : %s\n- Oktal : %s\n- Heksadesimal : %s\n",
           bin, oct, hexs);

    while (getchar() != '\n') {}
    pressEnterToContinue();
}

/* --- Fungsi nomor 6: Biner -> Desimal --- */
void binToDec() {
    system(CLEAR_CMD);
    printf("--- Konversi Biner ke Desimal ---\n");
    char s[1024];
    printf("Masukkan bilangan biner (mis: 1101): ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("\nInput error.\n");
        pressEnterToContinue();
        return;
    }
    // buang newline
    s[strcspn(s, "\r\n")] = 0;
    // validasi
    int len = strlen(s);
    if (len == 0) {
        printf("\nInput kosong.\n");
        pressEnterToContinue();
        return;
    }
    unsigned long long result = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] != '0' && s[i] != '1') {
            printf("\nInput bukan bilangan biner yang valid.\n");
            pressEnterToContinue();
            return;
        }
        result = result * 2 + (s[i] - '0');
    }
    printf("\nHasil Desimal: %llu\n", result);
    pressEnterToContinue();
}

/* --- Fungsi nomor 7: Oktal -> Desimal --- */
void octToDec() {
    system(CLEAR_CMD);
    printf("--- Konversi Oktal ke Desimal ---\n");
    char s[1024];
    printf("Masukkan bilangan oktal (mis: 307): ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("\nInput error.\n");
        pressEnterToContinue();
        return;
    }
    s[strcspn(s, "\r\n")] = 0;
    int len = strlen(s);
    if (len == 0) {
        printf("\nInput kosong.\n");
        pressEnterToContinue();
        return;
    }
    unsigned long long result = 0;
    for (int i = 0; i < len; i++) {
        if (!isdigit((unsigned char)s[i]) || s[i] < '0' || s[i] > '7') {
            printf("\nInput bukan bilangan oktal yang valid.\n");
            pressEnterToContinue();
            return;
        }
        result = result * 8 + (s[i] - '0');
    }
    printf("\nHasil Desimal: %llu\n", result);
    pressEnterToContinue();
}

/* --- Fungsi nomor 8: Heksadesimal -> Desimal --- */
void hexToDec() {
    system(CLEAR_CMD);
    printf("--- Konversi Heksadesimal ke Desimal ---\n");
    char s[1024];
    printf("Masukkan bilangan heksadesimal (mis: C7): ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("\nInput error.\n");
        pressEnterToContinue();
        return;
    }
    s[strcspn(s, "\r\n")] = 0;
    int len = strlen(s);
    if (len == 0) {
        printf("\nInput kosong.\n");
        pressEnterToContinue();
        return;
    }
    unsigned long long result = 0;
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        int val;
        if (ch >= '0' && ch <= '9') val = ch - '0';
        else if (ch >= 'A' && ch <= 'F') val = 10 + (ch - 'A');
        else if (ch >= 'a' && ch <= 'f') val = 10 + (ch - 'a');
        else {
            printf("\nInput bukan bilangan heksadesimal yang valid.\n");
            pressEnterToContinue();
            return;
        }
        result = result * 16 + val;
    }
    printf("\nHasil Desimal: %llu\n", result);
    pressEnterToContinue();
}
