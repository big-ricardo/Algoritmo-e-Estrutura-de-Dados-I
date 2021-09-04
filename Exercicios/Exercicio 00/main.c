#include <stdio.h>
#define N 30

//gcc -pedantic-errors -Wall main.c -o main.exe && ./main.exe

int main(void) {
    void strcat(char s1[N], char s2[N], char sres[N * 2]);
    char s1[N], s2[N], sres[N * 2];

    scanf("%s", s1);
    scanf("%s", s2);
    strcat(s1, s2, sres);

    printf("%s\n", sres);

    return 0;
}

//Primeira forma possivel
// void strcat(char s1[N], char s2[N], char sres[N * 2]) {

//     int tam1 = 0, tam2 = 0;

//     while (s1[tam1] != '\0') {
//         tam1++;
//     }

//     while (s2[tam2] != '\0') {
//         tam2++;
//     }

//     // printf("%d %d\n", tam1, tam2);

//     for (int i = 0; i <= tam1 + tam2; i++) {
//         if (i < tam1) {
//             sres[i] = s1[i];
//         }
//         else {
//             sres[i] = s2[i - tam1];
//         }
//     }
// }

//Segunda forma possivel
void strcat(char s1[N], char s2[N], char sres[N * 2]) {

    int tam1 = 0, tam2 =0;

    while (s1[tam1] != '\0') {
        sres[tam1] = s1[tam1];
        tam1++;
    }

    while (s2[tam2] != '\0') {
        sres[tam1 + tam2] = s2[tam2];
        tam2++;
    }

    sres[tam1 + tam2] = '\0';

    // printf("%d %d\n", tam1, tam2);
}
