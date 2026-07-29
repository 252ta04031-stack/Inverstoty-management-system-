#include <stdio.h>
#include <string.h>

#define MAX 100

struct Product
{
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Product p[MAX];
int count = 0;

// Function to add a product
void addProduct()
{
    printf("\nEnter Product ID: ");
    scanf("%d", &p[count].id);

    printf("Enter Product Name: ");
    scanf("%s", p[count].name);

    printf("Enter Quantity: ");
    scanf("%d", &p[count].quantity);

    printf("Enter Price: ");
    scanf("%f", &p[count].price);

    count++;
    printf("\nProduct Added Successfully!\n");
}

// Function to display products
void displayProducts()
{
    int i;

    if (count == 0)
    {
        printf("\nNo Products Available!\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%d\t%s\t\t%d\t\t%.2f\n",
               p[i].id,
               p[i].name,
               p[i].quantity,
               p[i].price);
    }
}

// Function to search product
void searchProduct()
{
    int id, i, found = 0;

    printf("\nEnter Product ID to Search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (p[i].id == id)
        {
            printf("\nProduct Found\n");
            printf("ID       : %d\n", p[i].id);
            printf("Name     : %s\n", p[i].name);
            printf("Quantity : %d\n", p[i].quantity);
            printf("Price    : %.2f\n", p[i].price);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nProduct Not Found!\n");
}

// Function to update quantity
void updateQuantity()
{
    int id, qty, i, found = 0;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (p[i].id == id)
        {
            printf("Enter New Quantity: ");
            scanf("%d", &qty);

            p[i].quantity = qty;
            printf("\nQuantity Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nProduct Not Found!\n");
}

// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n========== Inventory Management System ==========\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateQuantity();
                break;

            case 5:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}
