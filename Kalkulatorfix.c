#include <stdio.h>      // Library standar untuk input-output (printf, scanf)
#include <string.h>     // Digunakan untuk fungsi string seperti strlen, strcpy, dll. berfungsi untuk konversi bilangan
#include <ctype.h>      // Digunakan untuk pengecekan karakter seperti isdigit(), toupper()

// ==================================================
// FUNGSI-FUNGSI PERHITUNGAN LISTRIK DC
// ==================================================

void kalkulatorOhm() {      // Fungsi untuk menghitung Tegangan/Arus/Hambatan
    int pilih;              // Variabel untuk menyimpan menu pilihan
    double V, I, R;         // Variabel untuk nilai tegangan, arus, resistansi

    printf("--- Kalkulator Hukum Ohm (V = I * R) ---\n");
    printf("Hitung apa?\n");
    printf("1. Tegangan (V)\n");       // Menu 1
    printf("2. Arus (I)\n");          // Menu 2
    printf("3. Hambatan (R)\n");      // Menu 3
    printf("Pilihan: ");
    scanf("%d", &pilih);              // Baca pilihan user

    if (pilih == 1) {                 // Jika ingin menghitung tegangan
        printf("Masukkan arus (I) dalam Ampere: ");
        scanf("%lf", &I);             // Input arus
        printf("Masukkan hambatan (R) dalam Ohm: ");
        scanf("%lf", &R);             // Input hambatan
        V = I * R;                    // Rumus dasar V = I * R
        printf("Tegangan (V) = %.4lf Volt\n", V);

    } else if (pilih == 2) {          // Jika ingin menghitung arus
        printf("Masukkan tegangan (V) dalam Volt: ");
        scanf("%lf", &V);             // Input tegangan
        printf("Masukkan hambatan (R) dalam Ohm: ");
        scanf("%lf", &R);             // Input hambatan
        I = V / R;                    // Rumus I = V / R
        printf("Arus (I) = %.4lf Ampere\n", I);

    } else if (pilih == 3) {          // Jika ingin menghitung hambatan
        printf("Masukkan tegangan (V) dalam Volt: ");
        scanf("%lf", &V);             // Input tegangan
        printf("Masukkan arus (I) dalam Ampere: ");
        scanf("%lf", &I);             // Input arus
        R = V / I;                    // Rumus R = V / I
        printf("Hambatan (R) = %.4lf Ohm\n", R);

    } else {
        printf("Pilihan tidak valid.\n"); // Jika user salah input
    }
}

void kalkulatorDaya() {              // Fungsi untuk menghitung daya listrik
    double V, I, P;                  // Variabel untuk tegangan, arus, daya

    printf("--- Kalkulator Daya Listrik (P = V * I) ---\n");
    printf("Masukkan Tegangan (V): ");
    scanf("%lf", &V);                // Input tegangan
    printf("Masukkan Arus (I): ");
    scanf("%lf", &I);                // Input arus

    P = V * I;                       // Rumus daya
    printf("Daya (P) = %.4lf Watt\n", P);
}

void resistorSeri() {                // Fungsi menghitung resistor seri
    int n;                           // Jumlah resistor
    double nilai, total = 0;         // nilai: resistor input | total: jumlah seri

    printf("--- Kalkulator Resistor Seri ---\n");
    printf("Masukkan jumlah resistor: ");
    scanf("%d", &n);                 // Input jumlah resistor

    for (int i = 1; i <= n; i++) {   // Loop sebanyak jumlah resistor
        printf("Masukkan nilai Resistor %d (Ohm): ", i);
        scanf("%lf", &nilai);        // Input resistor ke-i
        total += nilai;              // Penjumlahan langsung untuk seri
    }

    printf("Total Hambatan Seri = %.4lf Ohm\n", total);
}

void resistorParalel() {             // Fungsi menghitung resistor paralel
    int n;                           // Jumlah resistor
    double nilai, totalKebalikan = 0; // Tempat menyimpan jumlah 1/R

    printf("--- Kalkulator Resistor Paralel ---\n");
    printf("Masukkan jumlah resistor: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {   // Loop input tiap resistor
        printf("Masukkan nilai Resistor %d (Ohm): ", i);
        scanf("%lf", &nilai);
        totalKebalikan += (1.0 / nilai);   // Rumus paralel: sum(1/R)
    }

    double total = 1.0 / totalKebalikan;   // Invers hasil untuk mendapatkan Rtotal
    printf("Total Hambatan Paralel = %.4lf Ohm\n", total);
}

// ==================================================
// KONVERSI BILANGAN
// ==================================================

void decimalToOthers() {             // Fungsi untuk mengubah desimal ke basis lain
    long long dec;                   // Bilangan desimal input
    char biner[100], oktal[100], heksa[100]; // Array untuk menyimpan hasil

    printf("--- Konversi Desimal ke Basis Lain ---\n");
    printf("Masukkan bilangan desimal: ");
    scanf("%lld", &dec);             // Input bilangan desimal

    // ---- KONVERSI BINER MANUAL ----
    long long temp = dec;            // Salin desimal ke variabel sementara
    int i = 0;                       // Index array biner
    while (temp > 0) {               // Loop sampai habis
        biner[i++] = (temp % 2) + '0'; // Sisa bagi 2 jadi digit biner
        temp /= 2;                   // Bagi bilangan
    }
    biner[i] = '\0';                 // Akhiri string

    // Membalik string biner agar urut dari kiri ke kanan
    for (int j = 0; j < i/2; j++) {
        char t = biner[j];
        biner[j] = biner[i-j-1];
        biner[i-j-1] = t;
    }

    // --- KONVERSI OKTAL & HEXA MENGGUNAKAN sprintf ---
    sprintf(oktal, "%llo", dec);     // %o = oktal
    sprintf(heksa, "%llX", dec);     // %X = heksadesimal huruf besar

    printf("Hasil Konversi:\n");
    printf("- Biner : %s\n", biner);
    printf("- Oktal : %s\n", oktal);
    printf("- Heksadesimal : %s\n", heksa);
}

long long basisToDecimal(char *angka, int basis) {
    // Fungsi mengubah basis apa pun → desimal
    int len = strlen(angka);          // Panjang string input
    long long hasil = 0;              // Hasil konversi
    long long pangkat = 1;            // Basis^n

    for (int i = len - 1; i >= 0; i--) { // Loop dari belakang (digit terendah)
        int digit;

        if (isdigit(angka[i]))        // Jika karakter angka 0–9
            digit = angka[i] - '0';
        else                          // Jika A–F atau a–f (heksadesimal)
            digit = toupper(angka[i]) - 'A' + 10;

        hasil += digit * pangkat;     // Tambahkan digit * basis^n
        pangkat *= basis;             // Naikkan pangkat
    }
    return hasil;
}

void binerToDec() {                   // Fungsi convert biner ke desimal
    char bin[100];
    printf("--- Konversi Biner ke Desimal ---\n");
    printf("Masukkan bilangan biner: ");
    scanf("%s", bin);                 // Input biner

    printf("Hasil Desimal = %lld\n", basisToDecimal(bin, 2));
}

void oktalToDec() {                   // Fungsi convert oktal ke desimal
    char oct[100];
    printf("--- Konversi Oktal ke Desimal ---\n");
    printf("Masukkan bilangan oktal: ");
    scanf("%s", oct);

    printf("Hasil Desimal = %lld\n", basisToDecimal(oct, 8));
}

void heksaToDec() {                  // Fungsi convert heksa ke desimal
    char hex[100];
    printf("--- Konversi Heksadesimal ke Desimal ---\n");
    printf("Masukkan bilangan heksadesimal: ");
    scanf("%s", hex);

    printf("Hasil Desimal = %lld\n", basisToDecimal(hex, 16));
}

// ==================================================
// FUNGSI PAUSE
// ==================================================

void pause() {                       // Fungsi jeda sebelum kembali ke menu
    printf("\nTekan Enter untuk kembali ke menu...");
    getchar();                       // Menangkap newline sisa input
    getchar();                       // Menunggu user menekan enter
}

// ==================================================
// MAIN MENU
// ==================================================

int main() {
    int pilihan;                    // Variabel untuk menu utama

    do {                            // Loop menu utama
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
        scanf("%d", &pilihan);       // Input pilihan

        switch (pilihan) {           // Jalankan fungsi sesuai menu
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
                return 0;            // Keluar program
            default:
                printf("Pilihan tidak valid.\n");
        }

        pause();                     // Tunggu sebelum kembali ke menu

    } while (pilihan != 9);          // Loop sampai user memilih keluar

    return 0;                         // Akhiri program
}
