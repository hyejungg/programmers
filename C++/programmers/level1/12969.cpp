#include <stdio.h>

int main(void) {
    int a; //n 가로
    int b; //m 세로
    scanf("%d %d", &a, &b);
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}