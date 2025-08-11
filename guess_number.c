#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int random_number=rand() % 100 + 1;

    printf("guess a number between 1-100:\n");

int guess;
scanf("%d",&guess);

while (guess != random_number) {   

    if (guess < random_number) {
        printf("Smaller than guess!\n");

    }else if (guess > random_number) {
        printf("Bigger than guess!\n");
    }

    printf("Enter your guess:");
    scanf("%d",&guess);

}

    printf("you are right!\n");
    return 0;

}
