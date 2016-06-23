/*
** C Program to find a number between any range which is armstrong as well as palindrome number (i.e. palindromic armstrong number).
** Author: Monjit Nunisa, Software Engineer at www.freshersworld.com
*/
#include <stdio.h>

int main() {
    int fnum=0, lnum=0, i=0, j=0, armNum=0, revArmNum=0, tempNum=0, someTempNum=0, anotherSomeTempNum=0;
    printf("Enter first number: ");
    scanf("%d", &fnum);
    printf("Enter second number: ");
    scanf("%d", &lnum);

    int tensPow(int t){
        if(t==0 || t==1) return 1;
        return 10*tensPow(t-1);
    }

    int countDigits(int d){
        int numOfDigits=0;
        while(d>0){
            numOfDigits++;
            d=d/10;
        }
        return numOfDigits;
    }

    j=fnum;
    while(j<=lnum){
        someTempNum=j;
        while(someTempNum>0){
            tempNum=someTempNum%10;
            armNum+=tempNum*tempNum*tempNum;
            someTempNum=someTempNum/10;
        }
        i=countDigits(armNum);
        if(j==armNum){
            anotherSomeTempNum=armNum;
            while(anotherSomeTempNum>0){
                tempNum=anotherSomeTempNum%10;
                revArmNum+=tempNum*(tensPow(i));
                anotherSomeTempNum=anotherSomeTempNum/10;
                i--;
            }
            
            if((revArmNum==armNum) && (revArmNum==j)) printf("%d is a palindromic armstrong number...Yahoo!\n", j);
            else printf("%d is an armstrong number!\n", j);
        }
        armNum=0;
        revArmNum=0;
        i=0;
        j++;
    }

    return 0;
}
