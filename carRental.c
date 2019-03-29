//Name:         Bryan Powell
//FileName:     carRental.c
//Description:  Program that implements car rental IS. Keeps track of cars
//              and rental information.
//
//  Additional comments:
//  instead of using variable "int size", I am using "int inv_size" where
//  inv_size is equal to the number of cars in inventory. Instead of using
//  "int size" for size of the list of rentals, I am using "int rental_size"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Global structure declaration
struct CarT
{
    int car_Id;      //unique ID of a car
    char car_make[20];  //make of the car
    char car_model[20]; //model of the car
    int num_doors;   //2 or 4 door cars
    float rate;    //the rental rate of the car
};

struct RentalT
{
    char renter_name[20];    //name of renter
    int days_renting;        //days renting the car
    int car_ID;              //ID of the car rented
};

//Function signatures (listed at top of program out of habit
int CreateInventory (struct CarT *all_cars);
int OpsMenu (void);
int AddNewCar (struct CarT *all_cars, int total_cars, int inv_size);
int AddNewRental (struct CarT *all_cars, int total_cars, struct RentalT *all_rentals, int total_rentals, int rental_size);
int FindCarIDByName (struct CarT *all_cars, int total_cars, char *search_car_make);
int FindReservation (struct RentalT *all_rentals, int total_rentals, char *search_name);
int FindCarByID (struct CarT *all_cars, int total_cars, int car_ID);
void PrintAllRentals (struct RentalT *all_rentals, int total_rentals, struct CarT *all_cars, int total_cars);
void PrintCarInfo (struct CarT *all_cars, int total_cars, int car_ID);
float GetAverageRentalDays (struct RentalT *all_rentals, int total_rentals);





int main (void)
{
    //Variable Declaration
    char init_setup;
    struct CarT all_cars[20];       //list of cars
    struct RentalT all_rentals[60]; //list of rentals
    int menu_selection, total_cars, inv_size, total_rentals = 0, rental_size, x = 0;

    char search_name[20];
    char search_car_make[20];
    int car_search_results;
    struct RentalT res_search_results;
    float avg_days_rented;

    do
    {
        printf("Would you like to complete initial setup (y or n)? ");
        scanf("%c", &init_setup);
        if ((init_setup != 'y') && (init_setup != 'Y') && (init_setup != 'n') && (init_setup != 'N'))
            printf("\nINVALID RESPONSE\n");
    } while ((init_setup != 'y') && (init_setup != 'Y') && (init_setup != 'n') && (init_setup != 'N'));

    if ((init_setup == 'y') || (init_setup == 'Y'))
    {
        total_cars = CreateInventory (all_cars);
    }
    else
    {
        printf("\n\nNO INVENTORY ON FILE");
        return 0;
    }

    inv_size = total_cars;


    //Switch block to dictate user selection
    do
    {
        menu_selection = OpsMenu();
        switch (menu_selection)
        {
            //Add car to inventory
            case 1:
                total_cars = AddNewCar (all_cars, total_cars, inv_size);
                break;
            //Make new reservation
            case 2:
                total_rentals = AddNewRental (all_cars, total_cars, all_rentals, total_rentals, rental_size);
                break;
            //Find reservation and print to screen
            case 3:
                printf("Please enter the name of the reservation: ");
                fflush(stdin);
                fgets(search_name, 20, stdin);
                int b = 0;
                for (b; b < 20; b++)
                {
                    if (search_name[b] == '\n')
                        search_name[b] = '\0';
                }
                res_search_results = all_rentals[FindReservation(all_rentals, total_rentals, search_name)];
                printf("Renter name: %s\n", res_search_results.renter_name);
                printf("Days renting: %d\n", res_search_results.days_renting);
                int found = FindCarByID (all_cars, total_cars, res_search_results.car_ID);
                if (found == -1)
                    printf("UNABLE TO IDENTIFY CAR RESERVED");
                else
                {
                    printf("Car ID: %d", all_cars[found].car_Id);
                    int k = 0;
                    printf("\nCar make: %s", all_cars[found].car_make);
                    printf("\nCar Model: %s", all_cars[found].car_model);
                    printf("\nNumber of doors: %d", all_cars[found].num_doors);
                    printf("\nDaily rate: $%f", all_cars[found].rate);

                }

                break;
            //Print all rental info
            case 4:
                PrintAllRentals (all_rentals, total_rentals, all_cars, total_cars);
                break;
            //Print car info using make of car to search inv
            case 5:
                printf("Please enter the make of the car to search: ");
                fflush(stdin);
                fgets(search_car_make, 20, stdin);
                for (x; x < sizeof(search_car_make); x++)
                    if (search_car_make[x] == '\n')
                        search_car_make[x] = '\0';
                car_search_results = FindCarIDByName (all_cars, total_cars, search_car_make);
                if (car_search_results == -1)
                    printf("CAR NOT FOUND");
                else
                {
                    printf("Car ID: %d", all_cars[car_search_results].car_Id);
                    int k = 0;
                    printf("\nCar make: %s", all_cars[car_search_results].car_make);
                    printf("\nCar Model: %s", all_cars[car_search_results].car_model);
                    printf("\nNumber of doors: %d", all_cars[car_search_results].num_doors);
                    printf("\nDaily rate: \$%f", all_cars[car_search_results].rate);

                }
                break;
            //Calculate avg number of days rented
            case 6:
                avg_days_rented = GetAverageRentalDays (all_rentals, total_rentals);
                printf("The average days rented is: %f", avg_days_rented);
                break;
        }


    } while (menu_selection != 7);

    return 0;
}

int OpsMenu ()
{
    int selection;
    printf("\n\nPlease make a selection: ");
    printf("\n\t1. Add a Car to Inventory");
    printf("\n\t2. Make a Reservation");
    printf("\n\t3. Find Reservation");
    printf("\n\t4. View All Rental Information");
    printf("\n\t5. Print Car Information Using Make of Car to Search");
    printf("\n\t6. Calculate the Average Number of Days Rented");
    printf("\n\t7. Exit Program");

    do
    {
        printf("\nOption: ");
        scanf("%d", &selection);
        printf("\n");

        if ((selection < 1) || (selection > 7))
            printf("INVALID SELECTION! Select option 1-7.\n\n");
    } while ((selection < 1) || (selection > 7));

    return selection;
}

int CreateInventory (struct CarT *all_cars)
{
    //The for loops following the make and model ensure that the string only contains the characters that were specifically input
    int i = 0;

    all_cars[0].car_Id = 1234;
    all_cars[0].car_make[0] = 'V';
    all_cars[0].car_make[1] = 'W';
    i = 2;
    for (i; i < 20; i++)
    {
        all_cars[0].car_make[i] = '\0';
    }
    all_cars[0].car_model[0] = 'G';
    all_cars[0].car_model[1] = 'o';
    all_cars[0].car_model[2] = 'l';
    all_cars[0].car_model[3] = 'f';
    i = 4;
    for (i; i < 20; i++)
    {
        all_cars[0].car_model[i] = '\0';
    }
    all_cars[0].num_doors = 2;
    all_cars[0].rate = 66.00;

    all_cars[1].car_Id = 2241;
    all_cars[1].car_make[0] = 'F';
    all_cars[1].car_make[1] = 'o';
    all_cars[1].car_make[2] = 'r';
    all_cars[1].car_make[3] = 'd';
    i = 4;
    for (i; i < 20; i++)
    {
        all_cars[1].car_make[i] = '\0';
    }
    all_cars[1].car_model[0] = 'F';
    all_cars[1].car_model[1] = 'o';
    all_cars[1].car_model[2] = 'c';
    all_cars[1].car_model[3] = 'u';
    all_cars[1].car_model[4] = 's';
    i = 5;
    for (i; i < 20; i++)
    {
        all_cars[1].car_model[i] = '\0';
    }
    all_cars[1].num_doors = 4;
    all_cars[1].rate = 45.00;

    all_cars[2].car_Id = 3445;
    all_cars[2].car_make[0] = 'B';
    all_cars[2].car_make[1] = 'M';
    all_cars[2].car_make[2] = 'W';
    i = 3;
    for (i; i < 20; i++)
    {
        all_cars[2].car_make[i] = '\0';
    }
    all_cars[2].car_model[0] = 'X';
    all_cars[2].car_model[1] = '3';
    i = 2;
    for (i; i < 20; i++)
    {
        all_cars[2].car_model[i] = '\0';
    }
    all_cars[2].num_doors = 4;
    all_cars[2].rate = 128.00;

    return 3;
}

int AddNewCar (struct CarT *all_cars, int total_cars, int inv_size)
{
    int i = 0;
    if (inv_size >= 19)
    {
        printf("INVENTORY IS FULL");
        return total_cars;
    }

    //Retrieves the ID of the car
    printf("Please input the vehicle ID number: ");
    scanf("%d", &all_cars[inv_size].car_Id);

    //Retrieves the make of the car
    printf("Please input the make of the vehicle: ");
    fflush(stdin);
    fgets(all_cars[inv_size].car_make, 20, stdin);
    for (i; i < 20; i++)
    {
        if (all_cars[inv_size].car_make[i] == '\n')
            all_cars[inv_size].car_make[i] = '\0';
    }

    //Retrieves the model of the car
    printf("Please input the model of the vehicle: ");
    fflush(stdin);
    fgets(all_cars[inv_size].car_model, 20, stdin);
    i = 0;
    for (i; i < 20; i++)
    {
        if (all_cars[inv_size].car_model[i] == '\n')
            all_cars[inv_size].car_model[i] = '\0';
    }

    /*for debugging
    printf("\n\nmake of the car is %s", all_cars[inv_size].car_make);
    printf("\nmodel of the car is %s", all_cars[inv_size].car_model);*/

    //Retrieves number of doors
    printf("Please input the number of doors (2 or 4): ");
    scanf("%d", &all_cars[inv_size].num_doors);

    //Retrieves daily rental rate
    printf("Please input the daily rental rate: ");
    fflush(stdin);
    scanf("%f", &all_cars[inv_size].rate);

    total_cars += 1;

    return total_cars;
}

int AddNewRental (struct CarT *all_cars, int total_cars, struct RentalT *all_rentals, int total_rentals, int rental_size)
{
    int i = 0;
    if (total_rentals >= 60)
    {
        printf("Business is booming, unable to accept new reservations");
        return total_rentals;
    }

    int new_rental = total_rentals;
    char add_another;

    printf("Please enter the name of the customer: ");
    fflush(stdin);
    fgets(all_rentals[new_rental].renter_name, 20, stdin);
    for (i; i < 20; i++)
    {
        if (all_rentals[new_rental].renter_name[i] == '\n')
        {
            all_rentals[new_rental].renter_name[i] = '\0';
        }
    }

    printf("Please enter the number of days to reserve: ");
    scanf("%d", &all_rentals[new_rental].days_renting);

    printf("Please enter the Car ID of the vehicle rented: ");
    scanf("%d", &all_rentals[new_rental].car_ID);

    total_rentals += 1;

    return total_rentals;
}

void PrintAllRentals (struct RentalT *all_rentals, int total_rentals, struct CarT *all_cars, int total_cars)
{
    int i = 0;

    for (i; i < total_rentals; i++)
    {
        printf("\nCustomer Name: ");
        printf(" %s", all_rentals[i].renter_name);
        printf("\nDays Reserved: %d", all_rentals[i].days_renting);
        printf("\nCar ID Reserved: %d\n", all_rentals[i].car_ID);
    }

    return;
}

void PrintCarInfo (struct CarT *all_cars, int total_cars, int car_ID)
{
    int i = 0;
    bool car_found;

    for (i; i < total_cars; i++)
    {
        if (car_ID == all_cars[i].car_Id)
        {
            int j = 0;
            printf("Car make: ");
            for (j; all_cars[i].car_make[j] != '\0'; j++)
                printf("%c", all_cars[i].car_make[j]);

            j = 0;
            printf("\nCar model: ");
            for (j; all_cars[i].car_model[j] != '\0'; j++)
                printf("%c", all_cars[i].car_make[j]);

            printf("\nNumber of doors: %d", all_cars[i].num_doors);
            printf("\nDaily rate: %f", all_cars[i].rate);

            car_found = true;
        }

        else
            car_found = false;
    }

    if (car_found == false)
        printf("Car ID %d not found", car_ID);

    return;
}

int FindCarIDByName (struct CarT *all_cars, int total_cars, char *search_car_make)
{
    int i = 0;
    bool car_found;

    for (i; i < total_cars; i++)
    {
        if (strcmp(search_car_make, all_cars[i].car_make) == 0)
            return i;
        else
            car_found = false;
    }

    if (car_found == false)
        return -1;
}

int FindCarByID (struct CarT *all_cars, int total_cars, int car_ID)
{
    int i = 0;
    bool car_found;

    for (i; i < total_cars; i++)
    {
        if (car_ID == all_cars[i].car_Id)
            return i;
        else
            car_found = false;
    }

    if (car_found == false)
        return -1;
}

float GetAverageRentalDays (struct RentalT *all_rentals, int total_rentals)
{
	int i = 0;
	float results = 0;

	for (i; i < total_rentals; i++)
    {
        results = results + all_rentals[i].days_renting;

	}
	results = results / total_rentals;

	return results;
}

int FindReservation (struct RentalT *all_rentals, int total_rentals, char *search_name)
{
    int i = 0;

	for(i; i < total_rentals; i++)
    {
		if (strcmp(search_name, all_rentals[i].renter_name)==0) {
			return i;
		}
	}
	return -1;
}


