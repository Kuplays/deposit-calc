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
    
    if (duration >= 0 && duration <= 30) {
        investment *= 0.9;
    }

    if (investment < 100000) {
        if (duration >= 31 && duration <= 120) {
            investment *= 1.02;
        }

        if (duration >= 121 && duration <= 240) {
            investment *= 1.06;
        }
        if (duration >= 241 && duration <= 365) {
            investment *= 1.12;
        }
    }

    if (investment > 100000) {
        if (duration >= 31 && duration <= 120) {
            investment *= 1.03;
        }

        if (duration >= 121 && duration <= 240) {
            investment *= 1.08;
        }
        if (duration >= 241 && duration <= 365) {
            investment *= 1.15;
        }
    }

    printf("Duration: %d \nInvestment: %f", duration, investment);
    printf("\n");
    
    return 0;
}
