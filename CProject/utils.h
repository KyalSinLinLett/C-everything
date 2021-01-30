// function to print the list of items in a category
void printItemsInCategory(char type[][20], unsigned int price[]);
// function to print categories
void printCategories(char categories[5][15]);
// function to allow user to input the number that is associated with the category
void showItemsBasedOnCategories(int* category);
// function to allow user to choose options after picking a category
void choice(int* selectedOption);
// function to add items to cart
void addItems(char type[20][20], int quantity[20], int price[20]);
// function to view items in cart
void viewItemsInCart(char type[20][20], int quantity[20], int price[20]);
// function to get index of an item in the cart
int getIndexOfItem(char arr[20][20], char* elemment);
// function to show options in cart
void showCartOptions(char type[20][20], int quantity[20], int price[20]);
// function to remove item from cart
void removeItemFromCart(char type[20][20], int quantity[20], int price[20]);
// function to check out
void checkOut(char type[20][20], int quantity[20], int price[20]);
// function to find sum
int findTotalPrice(int price[20]);
// function to print lines
void printLines(int length);