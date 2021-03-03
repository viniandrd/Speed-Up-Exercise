#include <stdio.h>
#include <time.h>
#include <math.h>
#define EXEC 30

int TestaPrimo(int n) {
    int EhPrimo = 1, d = 2;
    if (n <= 1)
        EhPrimo = 0;

    while (EhPrimo == 1 && d <= n / 2) {
        if (n % d == 0)
            EhPrimo = 0;
        d = d + 1;
    }
    return EhPrimo;
}

int main1(void) {
    int valores[] = {7, 37, 8431, 13033, 524287, 664283, 3531271, 2147483647};
    float tempos[8][EXEC];
    float medias[8];


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < EXEC; j++) {
            clock_t begin = clock();

            int res = TestaPrimo(valores[i]);

            clock_t end = clock();
            float tempo = (float) (end - begin) / CLOCKS_PER_SEC;
            float tempo_total = tempo * 1000;
            printf("Numero %d eh %d demorou %lf ms\n", valores[i], res, tempo_total);
            tempos[i][j] = tempo_total;
        }
    }


    printf("\n");
    /*printf("--------Matriz de tempos--------\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < EXEC; j++) {
            printf("%lf ", tempos[i][j]);
        }
        printf("\n");
    }*/

    for (int i = 0; i < 8; i++) {
        float soma = 0;
        for (int j = 0; j < EXEC; j++) {
            soma += tempos[i][j];
        }
        medias[i] = soma / EXEC;
    }

    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("Media de tempo do numero %d eh %f \n", valores[i], medias[i]);
    }


    double dp[8];

    for (int i = 0; i < 8; i++) {
        float x = pow((tempos[i][EXEC - 1] - medias[i]), 2) + pow((tempos[i][0] - medias[i]), 2);
        double res = sqrt(x);
        dp[i] = res;
    }

    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("Desvio padrao do numero %d eh %lf \n", valores[i], dp[i]);
    }
    return 0;
}