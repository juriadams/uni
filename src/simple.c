#include <stdio.h>

#include "./lib/simple.h"

int main() {
    Distance distance;
    printf("Enter Distance (meters): ");
    scanf("%f",&distance);

    Time time;
    printf("Enter Time (seconds): ");
    scanf("%f",&time);

    Mass mass;
    printf("Enter Mass (kg): ");
    scanf("%f",&mass);

    Speed speed = calcSpeed(distance, time);
    Acceleration acceleration = calcAcceleration(distance, time);
    Impulse impulse = calcImpulse(mass, speed);

    printf("\n> Speed: %.2f m/s\n", speed);
    printf("> Acceleration: %.2f m/s\n", acceleration);
    printf("> Impulse: %.2f\n", impulse);

    return 0;
}