#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void playAgain(){
    int retry;
    printf("\n\nQuer jogar de novo?\n [1] Sim\n [2] Nao\n  ");
    scanf("%d", &retry);
    if(retry == 1){
        return main();
    }
    else if(retry == 2){
        return 0;
    }
}

void userTries(n1, n2, n3, n4, n5, n6){
    char string[6] = "XXXXXX";
    int shuffled[6], j;

    shuffled[0] = n1; shuffled[1] = n2; shuffled[2] = n3; shuffled[3] = n4; shuffled[4] = n5; shuffled[5] = n6; 

    printf("\n\n\n  _______     _______     _______     _______     _______     _______  \n |       |   |       |   |       |   |       |   |       |   |       |\n |       |   |       |   |       |   |       |   |       |   |       |\n |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |\n |       |   |       |   |       |   |       |   |       |   |       |\n |_______|   |_______|   |_______|   |_______|   |_______|   |_______| ", string[0], string[1], string[2], string[3], string[4], string[5]);

    int i;

    for(i = 0; i < 6; i++){
        int chute, carta, posicao;

        printf("\n\nMe fale a posicao da carta e seu valor [posicao valor]:   ");
        scanf("%d %d", &carta, &chute);

        posicao = carta - 1;

        if(chute == shuffled[posicao]){
            system("cls");

            printf("Voce acertou o numero da carta %d", carta);
            string[posicao] = shuffled[posicao]+'0';
            printf("\n\n\n  _______     _______     _______     _______     _______     _______  \n |       |   |       |   |       |   |       |   |       |   |       |\n |       |   |       |   |       |   |       |   |       |   |       |\n |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |\n |       |   |       |   |       |   |       |   |       |   |       |\n |_______|   |_______|   |_______|   |_______|   |_______|   |_______| ", string[0], string[1], string[2], string[3], string[4], string[5]);

        }
        else {
            printf("\n\nGAME OVER! ");
            playAgain();
        }
    }

    printf("\n\n***** PARABENS *****\n Voce chegou ao fim e acertou todos os numeros!");
    playAgain();

}

void runGame(sleepTime){
    int shuffled[10] = {}, j, l, k, i, timing;

    for (i = 0; i < 10; i++){
        j = rand() % 9;
        shuffled[i] = j;
    };

    system("cls");

    for(timing = sleepTime; timing > 0; timing--){
        printf("Voce deve memorizar esta sequencia em %d segundos. Boa sorte!\n\n", sleepTime);

        printf("Voce tem %d segundos", timing);
        printf("\n  _______     _______     _______     _______     _______     _______  \n |       |   |       |   |       |   |       |   |       |   |       |\n |       |   |       |   |       |   |       |   |       |   |       |\n |   %d   |   |   %d   |   |   %d   |   |   %d   |   |   %d   |   |   %d   |\n |       |   |       |   |       |   |       |   |       |   |       |\n |_______|   |_______|   |_______|   |_______|   |_______|   |_______| ", shuffled[0], shuffled[1], shuffled[2], shuffled[3], shuffled[4], shuffled[5]);
        sleep(1);
        system("cls");
    }

    userTries(shuffled[0], shuffled[1], shuffled[2], shuffled[3], shuffled[4], shuffled[5]);
}

int main(void){
    int nivel, sleepTime;

    system("cls");

    printf("Voce devera decorar os numeros abaixos!\n\n");
    printf("Escolha o nivel:\n  [1] 20seg\n  [2] 10seg\n  [3] 5seg\n"); 
    scanf("%d", &nivel);

    if(nivel == 1){
        sleepTime = 20;
    }
    else if(nivel == 2){
        sleepTime = 10;
    }
    else if(nivel == 3){
        sleepTime = 5;
    }
    else{
        printf("Você digitou um valor invalido, retornar ao começo!");
        sleep(3);
        system("cls");
        return main();
    }

    runGame(sleepTime);
}