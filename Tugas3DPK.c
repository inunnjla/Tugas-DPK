#include <stdio.h>
#include <stdlib.h>
 
char c[3][3];
 
void resetPapan() {  // mengisi papan dengan angka '1' sampai '9' sebagai nomor kotak, dipanggil setiap game baru dimulai
    char angka = '1';
    for(int baris=0;baris<3;baris++)
    {
        for(int kolom=0;kolom<3;kolom++)
            c[baris][kolom] = angka++;
    }
}
 
void tampilkanPapan() {  // menggambar papan permainan ke layar
    printf("\n");
    for(int baris=0;baris<3;baris++)
    {
        printf(" ");
        for(int kolom=0;kolom<3;kolom++)
        {
            printf("%c",c[baris][kolom]);
            if(kolom<2) printf(" | ");
        }
        printf("\n");
        if(baris<2) printf("---+---+---\n");
    }
    printf("\n");
}
 
int cekMenang(char p) {  // mengecek apakah pemain 'p' sudah menang
    // cek baris dan kolom
    for(int i=0;i<3;i++)
    {
        if(c[i][0]==p && c[i][1]==p && c[i][2]==p) return 1;
        if(c[0][i]==p && c[1][i]==p && c[2][i]==p) return 1;
    }
    // cek diagonal
    if(c[0][0]==p && c[1][1]==p && c[2][2]==p) return 1;
    if(c[0][2]==p && c[1][1]==p && c[2][0]==p) return 1;
    return 0;
}
 
int papanPenuh() {  // mengecek apakah semua kotak sudah terisi (untuk seri)
    for(int baris=0;baris<3;baris++)
    {
        for(int kolom=0;kolom<3;kolom++)
        {
            if(c[baris][kolom]!='x' && c[baris][kolom]!='o')
                return 0;
        }
    }
    return 1;
}
 
int main(int argc, char * argv[]) {
 
    char pemain = 'x';
    char ulang;
 
    do {  // dipakai agar game selalu main dulu, lalu ditanya mau main lagi atau tidak
        resetPapan();  // kosongkan papan jadi angka 1-9
        pemain = 'x';  // game baru, 'x' selalu mulai duluan
        int selesai = 0;
 
        while(!selesai)
        {
            tampilkanPapan();
 
            int pilihan;
            printf("Giliran pemain %c, pilih kotak (1-9): ", pemain);
            if(scanf("%d",&pilihan)!=1)
            {
                while(getchar()!='\n');   // buang input yang salah
                printf("Input harus berupa angka!\n");
                continue;
            }
 
            if(pilihan<1 || pilihan>9)
            {
                printf("Pilihan harus antara 1 sampai 9!\n");
                continue;
            }
 
            int baris = (pilihan-1)/3;
            int kolom = (pilihan-1)%3;
 
            if(c[baris][kolom]=='x' || c[baris][kolom]=='o')
            {
                printf("Kotak sudah terisi, pilih kotak lain!\n");
                continue;
            }
 
            c[baris][kolom] = pemain;
 
            if(cekMenang(pemain))
            {
                tampilkanPapan();
                printf("Selamat! Pemain %c menang!\n", pemain);
                selesai = 1;
            }
            else if(papanPenuh())
            {
                tampilkanPapan();
                printf("Permainan seri!\n");
                selesai = 1;
            }
            else
            {
                pemain = (pemain=='x') ? 'o' : 'x';
            }
        }
 
        printf("\nMain lagi? (y/n): ");
        scanf(" %c",&ulang);
 
    } while(ulang=='y' || ulang=='Y');
 
    printf("Terima kasih sudah bermain!\n");
    return 0;
}
