#include <stdio.h>

#include "../lib/simple.h"
#include "../lib/advanced.h"

int main() {
    Speed startSpeed = 0;
    Speed currentSpeed = 60;
    Time startTime = 0;
    Time currentTime = 3600;
    Acceleration acceleration = 100;

    Distance rectilinear = calcRectilinearDistance(currentSpeed, currentTime, startTime);
    Distance accelerated = calcAcceleratedRectilinearDistance(currentSpeed, startSpeed, acceleration);
    Distance speed = calcAcceleratedRectilinearSpeed(acceleration, currentTime, startTime, startSpeed);

    printf("\ncalcRectilinearDistance(%.2f, %.2f, %.2f) -> %.2f\n", currentSpeed, currentTime, startTime, rectilinear);
    printf("calcAcceleratedRectilinearDistance(%.2f, %.2f, %.2f) -> %.2f\n", currentSpeed, startSpeed, acceleration, accelerated);
    printf("calcAcceleratedRectilinearSpeed(%.2f, %.2f, %.2f, %.2f) -> %.2f\n", acceleration, currentTime, startTime, startSpeed, speed);

    return 0;
}