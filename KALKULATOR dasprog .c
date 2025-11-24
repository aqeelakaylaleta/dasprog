#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ===============================
// FUNGSI-FUNGSI PERHITUNGAN DC
// ===============================

void kalkulatorOhm() {
    int pilih;
    double V, I, R;

    printf("--- Kalkulator Hukum Ohm (V = I * R) ---\n");
    printf("Hitung apa?\n");
    printf("1. Tegangan (V)\n");
    printf("2. Arus (I)\n");
    printf("3. Hambatan (R)\n");
    printf("Pilihan: ");
    scanf("%d", &pilih);

    if (pilih == 1) {
        printf("Masukkan arus (I) dalam Ampere: ");
        scanf("%lf", &I);
        printf("Masukkan hambatan (R) dalam Ohm: ");
        scanf("%lf", &R);
        V = I * R;
        printf("Tegangan (V) = %.4lf Volt\n", V);

    } else if (pilih == 2) {
        printf("Masukkan tegangan (V) dalam Volt: ");
        scanf("%lf", &V);
        printf("Masukkan hambatan (R) dalam Ohm: ");
        scanf("%lf", &R);
        I = V / R;
        printf("Arus (I) = %.4lf Ampere\n", I);

    } else if (pilih == 3) {
        printf("Masukkan tegangan (V) dalam Volt: ");
        scanf("%lf", &V);
        printf("Masukkan arus (I) dalam Ampere: ");
        scanf("%lf", &I);
        R = V / I;
        printf("Hambatan (R) = %.4lf Ohm\n", R);

    } else {
        printf("Pilihan tidak valid.\n");
    }
}

void kalkulatorDaya() {
    double V, I, P;

    printf("--- Kalkulator Daya Listrik (P = V * I) ---\n");
    printf("Masukkan Tegangan (V): ");
    scanf("%lf", &V);
    printf("Masukkan Arus (I): ");
    scanf("%lf", &I);

    P = V * I;
    printf("Daya (P) = %.4lf Watt\n", P);
}

void resistorSeri() {
    int n;
    double nilai, total = 0;

    printf("--- Kalkulator Resistor Seri ---\n");
    printf("Masukkan jumlah resistor: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Masukkan nilai Resistor %d (Ohm): ", i);
        scanf("%lf", &nilai);
        total += nilai;
    }

    printf("Total Hambatan Seri = %.4lf Ohm\n", total);
}

void resistorParalel() {
    int n;
    double nilai, totalKebalikan = 0;

    printf("--- Kalkulator Resistor Paralel ---\n");
    printf("Masukkan jumlah resistor: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Masukkan nilai Resistor %d (Ohm): ", i);
        scanf("%lf", &nilai);
        totalKebalikan += (1.0 / nilai);
    }

    double total = 1.0 / totalKebalikan;
    printf("Total Hambatan Paralel = %.4lf Ohm\n", total);
}

// ===============================
// KONVERSI BILANGAN
// ===============================

void decimalToOthers() {
    long long dec;
    char biner[100], oktal[100], heksa[100];

    printf("--- Konversi Desimal ke Basis Lain ---\n");
    printf("Masukkan bilangan desimal: ");
    scanf("%lld", &dec);

    // Biner
    long long temp = dec;
    int i = 0;
    while (temp > 0) {
        biner[i++] = (temp % 2) + '0';
        temp /= 2;
    }
    biner[i] = '\0';

    // Balik string
    for (int j = 0; j < i/2; j++) {
        char t = biner[j];
        biner[j] = biner[i-j-1];
        biner[i-j-1] = t;
    }

    // Oktal
    sprintf(oktal, "%llo", dec);

    // Heksadesimal
    sprintf(heksa, "%llX", dec);

    printf("Hasil Konversi:\n");
    printf("- Biner : %s\n", biner);
    printf("- Oktal : %s\n", oktal);
    printf("- Heksadesimal : %s\n", heksa);
}

long long basisToDecimal(char *angka, int basis) {
    int len = strlen(angka);
    long long hasil = 0;
    long long pangkat = 1;

    for (int i = len - 1; i >= 0; i--) {
        int digit;

        if (isdigit(angka[i]))
            digit = angka[i] - '0';
        else
            digit = toupper(angka[i]) - 'A' + 10;

        hasil += digit * pangkat;
        pangkat *= basis;
    }
    return hasil;
}

void binerToDec() {
    char bin[100];
    printf("--- Konversi Biner ke Desimal ---\n");
    printf("Masukkan bilangan biner: ");
    scanf("%s", bin);

    printf("Hasil Desimal = %lld\n", basisToDecimal(bin, 2));
}

void oktalToDec() {
    char oct[100];
    printf("--- Konversi Oktal ke Desimal ---\n");
    printf("Masukkan bilangan oktal: ");
    scanf("%s", oct);

    printf("Hasil Desimal = %lld\n", basisToDecimal(oct, 8));
}

void heksaToDec() {
    char hex[100];
    printf("--- Konversi Heksadesimal ke Desimal ---\n");
    printf("Masukkan bilangan heksadesimal: ");
    scanf("%s", hex);

    printf("Hasil Desimal = %lld\n", basisToDecimal(hex, 16));
}

// ===============================
// MAIN MENU
// ===============================

void pause() {
    printf("\nTekan Enter untuk kembali ke menu...");
    getchar();
    getchar();
}

int main() {
    int pilihan;

    do {
        printf("===============================================\n");
        printf("| TOOLKIT LENGKAP ASISTEN LABORATORIUM ELEKTRO |\n");
        printf("===============================================\n");
        printf("| --- Verifikasi Rangkaian Elektrik ---       |\n");
        printf("| 1. Kalkulator Hukum Ohm                     |\n");
        printf("| 2. Kalkulator Daya Listrik                  |\n");
        printf("| 3. Kalkulator Resistor Seri                 |\n");
        printf("| 4. Kalkulator Resistor Paralel              |\n");
        printf("|                                             |\n");
        printf("| --- Utilitas Sistem Digital ---             |\n");
        printf("| 5. Desimal -> Biner/Oktal/Heksadesimal      |\n");
        printf("| 6. Biner -> Desimal                         |\n");
        printf("| 7. Oktal -> Desimal                         |\n");
        printf("| 8. Heksadesimal -> Desimal                  |\n");
        printf("|                                             |\n");
        printf("| 9. Keluar                                   |\n");
        printf("===============================================\n");

        printf("Masukkan pilihan Anda (1-9): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: kalkulatorOhm(); break;
            case 2: kalkulatorDaya(); break;
            case 3: resistorSeri(); break;
            case 4: resistorParalel(); break;
            case 5: decimalToOthers(); break;
            case 6: binerToDec(); break;
            case 7: oktalToDec(); break;
            case 8: heksaToDec(); break;
            case 9:
                printf("Terima kasih telah menggunakan toolkit ini!\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }

        pause();

    } while (pilihan != 9);

    return 0;
}
