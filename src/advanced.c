#include <stdio.h>

#include "./lib/advanced.h"

int main() {
    Speed startSpeed;
    printf("Enter start Speed (m/s): ");
    scanf("%f",&startSpeed);

    Speed currentSpeed;
    printf("Enter current Speed (m/s): ");
    scanf("%f",&currentSpeed);

    Time startTime;
    printf("Enter start Time (seconds): ");
    scanf("%f",&startTime);

    Time currentTime;
    printf("Enter current Time (seconds): ");
    scanf("%f",&currentTime);

    Acceleration acceleration;
    printf("Enter acceleration (m/s): ");
    scanf("%f",&acceleration);

    Distance rectilinear = calcRectilinearDistance(currentSpeed, currentTime, startTime);
    Distance accelerated = calcAcceleratedRectilinearDistance(currentSpeed, startSpeed, acceleration);
    Distance speed = calcAcceleratedRectilinearSpeed(acceleration, currentTime, startTime, startSpeed);

    printf("\n> Uniform rectilinear distance: %.2f m\n", rectilinear);
    printf("> Uniformly accelerated rectilinear distance: %.2f m\n", accelerated);
    printf("> Uniformly accelerated rectilinear speed: %.2f m/s\n", speed);

    return 0;
}