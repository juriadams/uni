#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "garage.c"

void start(void);

void construct(void)
{
    printf("=== create a new car\n");

    // Body props
    char make[20];
    int topSpeed;
    int doors;
    int hasAbs;
    char options[10][100];

    // Engine props
    int hp;
    int cylinders;
    int displacement;

    printf("\nMake: ");
    scanf("%s", *&make); // `
    printf("Top Speed: ");
    scanf("%d", &topSpeed);
    printf("Doors: ");
    scanf("%d", &doors);
    printf("ABS (1 for \"yes\", 0 for \"no\"): ");
    scanf("%d", &hasAbs);

    printf("Options (max. 10):");

    for (int i = 0; i < 10; i++)
    {
        printf("Part name (\"exit\" to abort): ");

        char name[100];
        scanf("%99s", *&name);

        if (strcmp(name, "exit") == 0)
        {
            break;
        }

        strcpy(options[i], name);
    };

    printf("Horse Power: ");
    scanf("%d", &hp);
    printf("Cylinders: ");
    scanf("%d", &cylinders);
    printf("Displacement: ");
    scanf("%d", &displacement);

    Engine engine;
    engine.hp = hp;
    engine.cylinders = cylinders;
    engine.displacement = displacement;

    Car car;
    strcpy(car.make, make);
    car.topSpeed = topSpeed;
    car.doors = doors;
    car.hasAbs = hasAbs == 1 ? TRUE : FALSE;

    char *aids[10] = {};
    car.options = aids;
    for (int i = 0; i < sizeof(options); i++)
    {
        // Not executing for whatever fucking reason
        strcpy(car.options[i], options[i]);
    }

    car.engine = engine;

    addToGarage(car);
}

void removeCarFromParkinglot(void)
{
    // printf("Input the index of the Car you want to remove\n");
    // int index;
    // scanf("%d", &index);
    // removeFromGarage(parkinglot[index]);
}

void estimateCarValue(void){
    // printf("Input the index of the Car you want the Value from\n");
    // int index;
    // scanf("%d", &index);
    // printf("%d", calcValue(parkinglot[index]));
};

void printCarInformation(void)
{
    // printf("Input the index of the Car you want the Information from\n");
    // int index;
    // scanf("%d", &index);
    // printCar(parkinglot[index]);
}

void printAllCars(void)
{
    printGarage();
    start();
}

void start(void)
{
    printf("=== manual\n");
    printf("%d to add a new car to the garage\n", 1);
    printf("%d to remove a car from the garage\n", 2);
    printf("%d to calculate the value of a car\n", 3);
    printf("%d to show the details of a car\n", 4);
    printf("%d to show the details of all cars\n", 5);
    printf("%d to exit the program\n", 6);

    int input = -1;
    scanf("%d", &input);

    switch (input)
    {
    case 1:
        construct();
        start();
        break;

    case 2:
        removeCarFromParkinglot();
        start();
        break;

    case 3:
        estimateCarValue();
        start();
        break;

    case 4:
        printCarInformation();
        start();
        break;

    case 5:
        printAllCars();
        start();

    case 6:
        exit(0);
        break;
    }
}

int main()
{
    start();
    return 0;
}