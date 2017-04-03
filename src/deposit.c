#include <stdio.h>
#include "deposit.h"

void getInput(int* dur, float* amount) {
    if (*dur < 0 || *dur > 365 || *amount < 0.0) {
        getInput(dur, amount);
    }
}

void perform(int* dur, float* amount) {
    if (*dur >= 0 && *dur <= 30) {
        *amount *= 0.9;
    }
    
    if (*amount < 100000) {
        if (*dur >= 31 && *dur <= 120) {
            *amount *= 1.02;
        }

        if (*dur >= 121 && *dur <= 240) {
            *amount *= 1.06;
        }
        
        if (*dur >= 241 && *dur <= 365) {
            *amount *= 1.12;
        }
    }
    
    if (*amount > 100000) {
        if (*dur >= 31 && *dur <= 120) {
            *amount *= 1.03;
        }

        if (*dur >= 121 && *dur <= 240) {
            *amount *= 1.08;
        }
        
        if (*dur >= 241 && *dur <= 365) {
            *amount *= 1.15;
        }
    }
}
