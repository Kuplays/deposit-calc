#include <stdio.h>

int main(void) {
    int duration;
    float investment;
    
    printf("Enter investment duration: ");
    scanf("%d", &duration);

    if (duration < 0 || duration > 365 ) {
        printf("Invalid duration time, aborting....\n");
        return 1;
    }
    printf("Enter investent amount: ");
    scanf("%f", &investment);

    if (investment < 0.0) {
        printf("Invalid investment amount, aborting....\n");
        return 1;
    }
    printf("%d %f", duration, investment);
    
    return 0;
}
