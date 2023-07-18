#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Defining structure 
struct items
{
    char itemsName[30];
    float price, quantity, Total;
};
struct customer
{
    int items;
    char name[50], address[60], date[30];
    struct items it[60];
};

// create function for the layout of bill
void formatlayout(char date[30], char Name[50], char Address[30])
{
    printf("\n\n");
    printf("\t*********************************************************\n\n");
    printf("\t\t=========================================\n");
    printf("\t\t\tFaith the supreme restro\t\t\t\n");
    printf("\t\t==========================================\n");
    printf("\n\t\t\t\t\tDate:%s ", date);
    printf("\n \tName : %s ", Name);
    printf("\n \tAddress : %s ", Address);
    printf("\t=========================================================\n");
    printf("\tItems\t\t Qty\t\tPrice\t\tTotal");
    printf("\n\t=========================================================");
    printf("\n");
}

void datalayout(char items[30], float quantity, float price, float Total)
{
    printf("\n\t%s\t", items);
    printf("\t\t%.2f\t", quantity);
    printf("\t%.2f\t", price);
    printf("\t%.2f\t", Total);
    printf("\n\n");
}

void discountcalculation(float GrossTotal)
{
    printf("\n");
    float dis = 0.1 * GrossTotal;
    float nettotal = GrossTotal - dis;
    float tax = 0.13 * nettotal, grandtotal = nettotal + tax;
    printf("\t---------------------------------------------------------\n");
    printf("\tGross-Total:\t\t\t\t\t%.2f", GrossTotal);
    printf("\n\t---------------------------------------------------------\n");
    printf("\tDiscont @ 10%s:\t\t\t\t\t-%.2f ", "%", dis);
    printf("\n\t\t\t\t\t\t\t---------\n");
    printf("\tNet-Total :\t\t\t\t\t%.2f", nettotal);
    printf("\n\tVAT @ 13%s :\t\t\t\t\t+%.2f", "%", tax);
    printf("\n\t==========================================================\n");
    printf("\tGrand-Total :\t\t\t\t\t%.2f", grandtotal);
    printf("\n\t==========================================================\n");
    printf("\n\t\t  *** Thanks For Visiting Us ***\n\n\n"); //just for buttom design
}

int main()
{
    struct customer c;
    float GrossTotal;
    int opt;

    printf("\t\t\tFaith the supreme restro\t\t\t\n");
    printf("\t\t==========================================\n");
    printf("\n\n");
    printf("* Please slect the perfered operation:\n\n");
    printf("1.General Invoice\n");
    printf("2.Exit");
    printf("\n\nYour choice:\t");
    scanf("%d", &opt);
    printf("\n\n");
    fgetc(stdin);

    //Switch statement
    switch (opt)
    {
    case 1:
        strcpy(c.date, __DATE__);
        printf(" Name of the customer: ");
        fgets(c.name, sizeof(c.name), stdin);

        printf(" Address             : ");
        fgets(c.address, sizeof(c.address), stdin);

        printf(" No. of items ordered: ");
        scanf("%d%*c", &c.items);
        printf("\t\t==========================================\n");

        for (int i = 0; i < c.items; i++)
        {
            printf(" Name of item no. %d: ", i + 1);
            fgets(c.it[i].itemsName, sizeof(c.it[i].itemsName), stdin);

            printf(" Quantity          : ");
            scanf("%f", &c.it[i].quantity);

            printf(" Price as per      : ");
            scanf("%f", &c.it[i].price);

            c.it[i].Total = c.it[i].quantity * c.it[i].price;
            printf("\t\t---------------------\n");

            printf("\t\tTotal\t= %f\n", c.it[i].Total);
            printf("\t\t---------------------\n");
            GrossTotal += c.it[i].Total;
            while (getchar() != '\n');
        }
        break;
    case 2:
        printf("Thank you!!");
        exit(1);
        break;

    default:
        break;
    }
    formatlayout(c.date, c.name, c.address);
    for (int i = 0; i < c.items; i++)
    {
        datalayout(c.it[i].itemsName, c.it[i].quantity, c.it[i].price, c.it[i].Total);
    }
    discountcalculation(GrossTotal);

    return 0;
}
