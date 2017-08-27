//#include <cs50.h>
#include <stdio.h>
//#include <math.h>

int GetNumber();
int GetCent();
int getCoins(int nominal, int* pay);

int main(void){
    printf("%d\n", GetCent());
    getch();
    return 0;
}

int GetNumber(){
    float n = 0;
    do{
        printf("O hai! How much change is owed?\n");
        scanf("%f", &n);
    } while(n < 0);
    n = n * 100 + 0.5; // 0.5 для корректного округления
    return (int)n;
}

int getCoins(int nominal, int* pay) {
    int coins = 0;
    coins = *pay / nominal;
    *pay = *pay % nominal;
    return coins;
}

int GetCent(){
    int quarters = 25;
    int dimes = 10;
    int nikels = 5;
    int pennies = 1;
    int pay = GetNumber();
    int coin = 0;

    coin += getCoins(quarters, &pay);
    coin += getCoins(dimes, &pay);
    coin += getCoins(nikels, &pay);
    coin += getCoins(pennies, &pay); // Хотя тут можно просто pay прибавить, номинал 1 к 1

    return coin;
}