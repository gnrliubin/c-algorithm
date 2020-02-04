#include <stdio.h>
#include <math.h>

//常规判断,除以从2到本身-1的每一个数，有余数为0的则不是素数，返回0
int isPrime1(int x);

//先把除2以外的偶数剔除，然后除以从3开始到本身-1的每一个基数，有余数为0的则不是素数，返回0
int isPrime2(int x);

//在isPrime2的基础上改进，除以3到本身平方根的每一个基数
int isPrime3(int x);

//组织一张素数表
int isPrime4(int x,int primeArr[],int knownPrimes);

int main () {

    //方法1 判断是否被除1和自身外其他数整除
    const int range = 100;
    for (int i =1;i<range;i++){
        if (isPrime1(i)){
            printf("%d\t",i);
        }
    }
    printf("\n------------\n");

    //方法2 先剔除偶数，在除以3开始到本身-1的数，判断是否能整除
    for (int i =1;i<range;i++){
        if (isPrime2(i)){
            printf("%d\t",i);
        }
    }
    printf("\n------------\n");

    //方法3 先剔除偶数，在除以3开始到本身的平方根，判断是否能整除
    for (int i =1;i<range;i++){
        if (isPrime3(i)){
            printf("%d\t",i);
        }
    }
    printf("\n------------\n");
    printf("use array and append every prime");
    printf("\n------------\n");

    //方法4 建立素数表，判断是否能被比本身小的素数整除
    int primeArr[range]={2};
    int i=3;
    int current = 1;
    while (i<range){
        if(isPrime4(i,primeArr,current)){
            primeArr[current++] = i;
        }
        i++;
    }
    for (int i=0;i<current;i++){
        printf("%d\t",primeArr[i]);
    }
    printf("\n------------\n");
    printf("check array index ,if isPrime make value =1 else make set value =0");
    printf("\n------------\n");


    //方法5 下标作为样本，从2开始，将下标是其倍数的项置0。最终值为1的项下标都是素数
    int primeIndexArr[range];
    //初始化所有元素为1
    for (int i=0; i<range; i++) {
        primeIndexArr[i] = i;
    }
    for (int i = 2; i<range ;i++){
        if(primeIndexArr[i]){
            for (int j=i; j*i<range;j++){
                primeIndexArr[j*i]=0;
            }
        }
    }

    for (int i=2;i<range;i++){
        if(primeIndexArr[i]){
            printf("%d\t",primeIndexArr[i]);
        }
    }


    

    return 0;
}


int isPrime1 (int x ){
    int res = 1;
    if (x==1) res=0;
    for (int i=2; i<x; i++) {
        if (x%i==0){
            res = 0;
            break;
        }
    }
    return res;
}

int isPrime2 (int x) {
    int res = 1;
    if (x==1 || (x%2==0 && x!=2)) res=0;
    for (int i=3; i<x;i+=2) {
        if (x%i==0){
            res = 0;
            break;
        }
    }
    return res;
}


int isPrime3 (int x) {
    int res = 1;
    if (x==1 || (x%2==0 && x!=2)) res=0;
    //这里的条件<=平方根，如果只用<那么9，25，49之类的数是进不了循环的，因此都会被判断为素数。
    for (int i=3; i<=sqrt(x);i+=2) {
        if (x%i==0){
            res = 0;
            break;
        }
    }
    return res;
}

int isPrime4(int x,int primeArr[],int knownPrimes) {
    int res = 1;
    for (int i = 0; i<knownPrimes; i++) {
        if (x%primeArr[i]==0){
            res =0;
            break;
        }
    }
    return res;
}







