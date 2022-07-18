#include <stdio.h>
#include <string.h>

#include "./lib/types.h"

Car garage[20];

int exists(Car car)
{
    if (!car.engine.hp)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int calcValue(Car car)
{
    if (exists(car) == 0)
    {
        printf("This car does not exist.\n");
        return 0;
    }

    int value = 0;

    if (car.hasAbs == 1)
    {
        value += 3000;
    }

    for (int i = 0; i < sizeof(car.options); i++)
    {
        if (car.options[i])
        {
            value += 5000;
        }
    }

    value = value + car.topSpeed * 50 * car.doors;

    if (strcmp(car.make, "Porsche"))
    {
        value = value * 2;
    }

    return value;
}

void printCar(Car car)
{
    if (exists(car) == 0)
    {
        printf("This car does not exist.\n");
        return;
    }

    printf("%-17s %s\n", "Make", car.make);
    printf("%-17s %d\n", "Top Speed", car.topSpeed);
    printf("%-17s %d\n", "Doors", car.doors);
    printf("%-17s %s\n", "Has ABS", car.hasAbs == 1 ? "Yes" : "No");
    printf("Options\n");
    for (int i = 0; i < sizeof(car.options) / sizeof(car.options[0]); i++)
    {
        if (strlen(car.options[i]) > 0)
            printf("    %-13d %s\n", i + 1, car.options[i]);
    }
    printf("Engine\n");
    printf("    %-13s %d\n", "Horse Power", car.engine.hp);
    printf("    %-13s %d\n", "Cylinders", car.engine.cylinders);
    printf("    %-13s %d\n", "Displacement", car.engine.displacement);
}

void addToGarage(Car car)
{
    int free = -1;
    for (int i = 0; i < 20; i++)
    {
        if (exists(garage[i]) == 0)
            free = i;
        break;
    }

    printf("\nFREE: %d\n", free);

    if (free == -1)
    {
        printf("The Garage seems to be full.\n");
    }
    else
    {
        garage[free] = car;
    }
}

void removeFromGarage(Car car)
{
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(garage[i].make, car.make) == 0)
        {
            for (int j = i; j < 20 - 1; j++)
            {
                garage[j] = garage[j - 1];
            }
        }
        break;
    }
}

void printGarage(void)
{
    if (exists(garage[0]) == FALSE)
    {
        printf("The Garage seems to be empty.\n");
        return;
    }

    for (int i = 0; i < 20; i++)
    {

        if (garage[i].engine.hp != 0)
        {
            printCar(garage[i]);
        }
    }
}
