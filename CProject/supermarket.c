#include <stdio.h>
#include "itemdata.h"
#include "utils.h"

int main(void)
{       
    puts("+----------------------------+");
    puts("| WELCOME TO XYZ SUPERMARKET |");
    puts("+----------------------------+");
    
    int selectedOption, category;
    // these variables are static because I want their values/data to persist throughout the entire execution of the program.
    static char selectedType[20][20];
    static int selectedQuantity[20], selectedPrice[20];

    do
    {
        choice(&selectedOption);

        switch (selectedOption)
        {
        case 1:
            showItemsBasedOnCategories(&category);
            break;

        case 2:
            addItems(selectedType, selectedQuantity, selectedPrice);
            break;

        case 3:
            viewItemsInCart(selectedType, selectedQuantity, selectedPrice);
            showCartOptions(selectedType, selectedQuantity, selectedPrice);
            break;

        default: 
            puts("Bye bye.\n");
            break;
        }
    } while (selectedOption != 4);


    return 0;
}



