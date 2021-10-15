#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

void userTries(n1, n2, n3, n4, n5, n6, n7, n8){
    char string[8] = "XXXXXXXX";
    int shuffled[8], j;

    shuffled[0] = n1; shuffled[1] = n2; shuffled[2] = n3; shuffled[3] = n4; shuffled[4] = n5; shuffled[5] = n6, shuffled[6] = n7, shuffled[7] = n8; 

    printf("\n  _______     _______     _______     _______     _______     _______     _______     _______  \n |       |   |       |   |       |   |       |   |       |   |       |   |       |   |       |\n |       |   |       |   |       |   |       |   |       |   |       |   |       |   |       |\n |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |\n |       |   |       |   |       |   |       |   |       |   |       |   |       |   |       |\n |_______|   |_______|   |_______|   |_______|   |_______|   |_______|   |_______|   |_______| ", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7]);

    int i, posicao = 0;

    for(i = 0; i < 8; i++){
        int chute, carta = posicao + 1;

        printf("\n\nMe fale o valor da carta %d:   ", carta);
        scanf("%d", &chute);

        if(chute == shuffled[posicao]){
            #ifdef _WIN32
                system("cls");
            #endif
            #ifdef linux
                system("clear");
            #endif

            printf("Voce acertou o numero da carta %d", carta);
            string[posicao] = shuffled[posicao]+'0';
        
            printf("\n  _______     _______     _______     _______     _______     _______     _______     _______  \n |       |   |       |   |       |   |       |   |       |   |       |   |       |   |       |\n |       |   |       |   |       |   |       |   |       |   |       |   |       |   |       |\n |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |   |   %c   |\n |       |   |       |   |       |   |       |   |       |   |       |   |       |   |       |\n |_______|   |_______|   |_______|   |_______|   |_______|   |_______|   |_______|   |_______| ", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7]);

            posicao++;
        }
        else {
            printf("\n\nGAME OVER! \n\n");
            printf("    _______________         \n");
            printf("   /               \\       \n"); 
            printf("  /                 \\      \n");
            printf("//                   \\/\\  \n");
            printf("\\|   XXXX     XXXX   | /   \n");
            printf(" |   XXXX     XXXX   |/     \n");
            printf(" |   XXX       XXX   |      \n");
            printf(" |                   |      \n");
            printf(" \\__      XXX      __/     \n");
            printf("   |\\     XXX     /|       \n");
            printf("   | |           | |        \n");
            printf("   | I I I I I I I |        \n");
            printf("   |  I I I I I I  |        \n");
            printf("   \\_             _/       \n");
            printf("     \\_         _/         \n");
            printf("       \\_______/           \n");

            playAgain();
        }
    }

    printf("\n\n***** PARABENS *****\n Voce chegou ao fim e acertou todos os numeros!\n\n");
    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n");
    playAgain();

}

void runGame(sleepTime){
    int shuffled[10] = {}, j, l, k, i, timing;

    for (i = 0; i < 10; i++){
        j = rand() % 9;
        shuffled[i] = j;
    };

    #ifdef _WIN32
        system("cls");
    #endif
    #ifdef linux
        system("clear");
    #endif

    for(timing = sleepTime; timing > 0; timing--){
        printf("Voce deve memorizar esta sequencia em %d segundos. Boa sorte!\n\n", sleepTime);

        printf("Voce tem %d segundos", timing);
        printf("\n  _______     _______     _______     _______     _______     _______     _______     _______  \n |       |   |       |   |       |   |       |   |       |   |       |   |       |   |       |\n |       |   |       |   |       |   |       |   |       |   |       |   |       |   |       |\n |   %d   |   |   %d   |   |   %d   |   |   %d   |   |   %d   |   |   %d   |   |   %d   |   |   %d   |\n |       |   |       |   |       |   |       |   |       |   |       |   |       |   |       |\n |_______|   |_______|   |_______|   |_______|   |_______|   |_______|   |_______|   |_______| ", shuffled[0], shuffled[1], shuffled[2], shuffled[3], shuffled[4], shuffled[5], shuffled[6], shuffled[7]);
        sleep(1);

        #ifdef _WIN32
            system("cls");
        #endif
        #ifdef linux
            system("clear");
        #endif
    }

    userTries(shuffled[0], shuffled[1], shuffled[2], shuffled[3], shuffled[4], shuffled[5], shuffled[6], shuffled[7]);
}

int main(void){
    int nivel, sleepTime;

    #ifdef _WIN32
        system("cls");
    #endif
    #ifdef linux
        system("clear");
    #endif

    printf("Voce devera decorar os 8 numeros abaixo!\n\n");
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

        #ifdef _WIN32
            system("cls");
        #endif
        #ifdef linux
            system("clear");
        #endif

        return main();
    }

    runGame(sleepTime);
}
