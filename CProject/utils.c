#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "itemdata.h"

// integer that stores net number of elements in the cart
static int idx = 0;

void printItemsInCategory(char type[][20], unsigned int price[])
{
    /*
    Function to print items in a category. 
    Parameters: char type[][20], unsigned int price[], unsigned int quantity[]
    Return type: void
    */
    puts("\nTYPE\t| PRICE");
    for (int i = 0; i < 5; i++)
        printf("%s\t|%5d\t\n", type[i], price[i]);
}

void printCategories(char categories[5][15])
{
    /*
    Function to print all categories
    Parameters: char categories[][10]
    Return type: void
    */
    puts("\nHere are categories you could choose from.");
    puts("------------------------------------------");
    for (int i = 0; i < 5; i++)
        printf("%d. %s\n", i+1, categories[i]);
    printf("\n");

}

void showItemsBasedOnCategories(int* category)
{
    /*
    Function to accept user input
    Parameter: int* category (pointer to address of category variable)
    Return type: void
    */
    printCategories(categories);

    printf("> Enter a number that represents the category you want to shop in: ");
    scanf("%ud\n", category);

    switch (*category)
    {
    case 1: 
        printItemsInCategory(foodType, foodPrice); 
        break;
    case 2: 
        printItemsInCategory(drinkType, drinkPrice); 
        break;
    case 3: 
        printItemsInCategory(cleanerType, cleanerPrice); 
        break;
    case 4: 
        printItemsInCategory(stationeryType, stationeryPrice); 
        break;
    case 5: 
        printItemsInCategory(healthType, healthPrice); 
        break;
    default: 
        puts("Invalid input!"); 
        break;
    }
    
    printf("\nYou are in category: %d\n", *category);
}

void choice(int* selectedOption)
{
    /*
    Function to show options
    Parameter: int* selectedOption (pointer to the selectedOption variable)
    */

    puts("\n+-----------------------------+");
    puts("| Your options:               |");
    puts("| 1. Browse categories        |");
    puts("| 2. Add items to cart        |");
    puts("| 3. View items in cart       |");
    puts("| 4. Exit program             |");
    puts("+-----------------------------+");

    printf("\n> Enter your option: ");
    scanf("%d", selectedOption);
    printf("\n");
}

void addItems(char type[20][20], int quantity[20], int price[20])
{
    /*
    Function to add item to the cart.
    Parameter: char type[20][20], int quantity[20], int price[20]
    Return type: void
    */
    int unitprice;
    puts("Add item to cart.");
    puts("-----------------");
    printf("> Enter item [name quantity unitprice]: ");
    scanf("%s %d %d", type[idx], &quantity[idx], &unitprice);

    // stores the net price of the item based on its unit price.
    *(price+idx) = unitprice * *(quantity+idx);

    printf("\nItem added:\nName: %s, Quantity: %d, Price: %d\n\n", type[idx], quantity[idx], price[idx]);
    idx++;
}

void viewItemsInCart(char type[20][20], int quantity[20], int price[20])
{
    /*
    Function to view items in the cart
    Parameters: char type[20][20], int quantity[20], int price[20]
    Return type: void
    */
    puts("View items in cart.");
    puts("-------------------\n");

    if (idx < 1) // no items in the cart condition
        puts("There are no items yet... Go buy something!");
    else 
    {
        printf("No. Name, Qty, Price\n");
        for (int i = 0; i < (idx); i++) 
        {
            printLines(strlen("No. Name, Qty, Price\n"));
            printf("%d. %s, %d, %d\n", (i+1), type[i], quantity[i], price[i]);
        }
    }
    printf("\n");
}

void showCartOptions(char type[20][20], int quantity[20], int price[20])
{
    /*
    Function to show cart options
    Parameters: char type[20][20], int quantity[20], int price[20]
    Return type: void
    */
    int option;
    do
    {
        puts("\n+-------------------------+");
        puts("| 1. Remove item.         |");
        puts("| 2. Checkout.            |");
        puts("| 3. Back to options.     |");
        puts("--------------------------+\n");  

        printf("\n> Enter your option: ");
        scanf("%d", &option);
        printf("\n");

        switch (option)  
        {
        case 1:
            removeItemFromCart(type, quantity, price);
            break;
        
        case 2:
            checkOut(type, quantity, price);
            break;
        }

    } while (option != 3);    
}

void removeItemFromCart(char type[20][20], int quantity[20], int price[20])
{
    /*
    Function to remove item from the cart cart
    Parameters: char type[20][20], int quantity[20], int price[20]
    Return type: void
    */
    int itemcode;

    puts("Remove item from cart...");
    puts("------------------------\n");
    printf("> Enter item code: ");
    scanf("%d", &itemcode);

    if (itemcode < 0 || itemcode > idx) // checks the input from the user to see if the idx value is valid
        printf("\nItem code invalid. It could be because it isn't in the cart.\n");
    else
    {
        for (int i = itemcode-1; i <= idx; i++) // begin iteration from itemcode-1 cause the indexing starts from 0 but user will input beginning from 1
        {
            /*
                to remove the item, the original value of the item will be overwritten by the adjacent value. Then the process continues until the last item. Basically, starting from the item to be removed the value to the right of the item are shifted one place to the left. Then the idx value is decremented by one since the cart now has one item less.
                [a,b,c,d] -> remove 'b'
                Step 1: [a,c, ,d] -> b is overwritten with c
                Step 2: [a,c,d, ] -> c's old position is overwritten with d
            */
            strcpy(type[i], type[i+1]);
            quantity[i] = quantity[i+1];
            price[i] = price[i+1];
        }
        idx--; // [a,c,d]
    }
}

void checkOut(char type[20][20], int quantity[20], int price[20])
{
    /*
    Function to check out items in the cart
    Parameters: char type[20][20], int quantity[20], int price[20]
    Return type: void
    */

    int total, cash;
    char ch;
    puts("\nCheckout information.");
    puts("---------------------\n");
    if (idx > 0)
    {
        printf("No. Name, Qty, Price\n");
        for (int i = 0; i < (idx); i++)
        {
            printLines(strlen("No. Name, Qty, Price\n"));
            printf("%d. %s, %d, %d\n", (i+1), type[i], quantity[i], price[i]);
        }

        total = findTotalPrice(price);

        printf("\nTotal: %dks\n", total);

        puts("\n> Enter your cash payment amount: ");
        scanf("%d", &cash);
        
        if (cash >= total)
        {
            printf("\nReceived: %dks | Total: %dks | Change: %dks\n", cash, total, (cash - total));
            idx = 0; // this resets the idx value making the cart start to start filling from 0 again, overwriting any old values. I believe there might be a better way to reset the cart but I'm not proficient in C enough yet so this is just a workaround that solved my problem.
            puts("\n+--------------------------------------------------+");
            puts("|     Thank you for shopping at XYZ SUPERMARKET.   |");
            puts("|     --Choose option 3 to begin new purchase--    |");
            puts("+--------------------------------------------------+\n");
        }
        else
            printf("\nPayment is not enough.\n");    
    }
    else 
    {
        puts("There are no items yet... Go buy something!\n"); 
    }
}

int findTotalPrice(int price[20])
{
    /*
    Function to find total price of items in the cart
    Parameters: int price[20]
    Return type: void
    */
    int sum = 0;
    for (int i = 0; i < idx; i++)
        sum += price[i];
    return sum;
}

void printLines(int length)
{
    /*
    Function to view items in the cart
    Parameters: int length
    Return type: void
    */
    for (int i = 0; i < length; i++)
        printf("-");
    printf("\n");
}
