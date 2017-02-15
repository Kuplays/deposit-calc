#include <stdio.h>

int main(void) {
    int duration;
    float investment;
    
    printf("Enter investment duration: ");
    scanf("%d", &duration);
    printf("Enter investent amount: ");
    scanf("%f", &investment);
    printf("%d %f", duration, investment);
}
