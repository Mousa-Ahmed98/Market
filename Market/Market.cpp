#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

COORD coord = { 0,0 };
typedef struct Product Product;
typedef struct Category Category;
typedef struct CategoryMapper Mapper;

struct Product
{
    char name[20];
    int id;
    int quantity;
    int price;
    int categoryId;
    char categoryName[20];
};

struct Category
{
    char name[20];
    int id;
    int arr[10];
};
int catCounter = 0;
int catArrSize = 3;

int prdCounter = 0;
int prdArrSize = 3;

Category* catArr;
Product* prdArr;
int main()
{


    catArr = malloc(catArrSize * sizeof(Category));
    prdArr = malloc(prdArrSize * sizeof(Product));



    welcome();
    int selection = 0;
    //ShowConsoleCursor(0);
    displayFirstTimeOptions();
    displayOptions(selection);

    gotoxy(0, selection);
    char key = getch();
    while (key - 0 == 13)
    {
        system("cls");
        addCategory();
        system("cls");
        displayFirstTimeOptions();
        displayOptions(selection);
        gotoxy(0, 0);
        key = getch();
    }

    while (key - 0 == -32 || key - 0 == 13)
    {
        if (key - 0 != 13)
            key = getch();
        if (key - 0 == 72)
        {
            selection--;
            if (selection < 0)
            {
                selection = 6;
            }
            gotoxy(0, selection);
            displayOptions(selection);
        }

        else if (key - 0 == 80)
        {
            selection++;
            if (selection > 6)
            {
                selection = 0;
            }
            gotoxy(0, selection);
            displayOptions(selection);
        }

        if (key - 0 != 13)
            key = getch();
        if (key - 0 == 13)
        {
            system("cls");
            switch (selection)
            {
            case 0:
                addCategory();
                break;
            case 1:
                displayAllCats();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                displayAllPrds();
                break;
            case 4:
                move();
                break;
            case 5:
                makeOrder();
                break;
            case 6:
                return;
            }
            system("cls");
            displayFirstTimeOptions();
            displayOptions(selection);
            gotoxy(0, selection);
            key = getch();
        }

    }
    system("cls");

}

void welcome() {
    ShowConsoleCursor(0);
    char phrase[40];
    gotoxy(40, 6);
    strcpy(phrase, "Welcome on board");
    int i = 0;
    int j;
    SetColor(10);
    while (i < 16) {
        printf("%c", phrase[i]);
        j = 0;
        while (j < 20000000) {
            j++;
        }
        i++;
    }

    i = 0;
    while (i < 400000000) {
        i++;
    }
    system("cls");
    ShowConsoleCursor(1);
}
void addProduct()
{
    if (catCounter == 0)
    {
        SetColor(12);
        char phrase[100];
        strcpy(phrase, "There are no categories so you can't add a product");
        //getch();
        int i = 0;
        int j;
        while (i < 50) {

            printf("%c", phrase[i]);
            j = 0;
            while (j < 20000000) {
                j++;
            }
            i++;
        }
        getch();
        return;
    }
    ShowConsoleCursor(1);
    printf("First choose the product's category:\n");
    for (int i = 0; i < catCounter; i++)
    {
        printf("\t-> %s\n", catArr[i].name);
    }
    int selection = 1;
    gotoxy(7, selection);
    char key = getch();

    if (key - 0 == 13)
    {
        ////////////////////////////////////////////////////
        ////////////////////////////////////////////////////
        system("cls");
        printf("Category %s\t:\n", catArr[selection - 1].name);
        char name[20];
        int price;
        int quantity;

        printf("\tName: ");
        scanf("%s", &name);
        printf("\n");

        printf("\tPrice: ");
        do {
            if (scanf("%d", &price) == 1 && price > 0) {
                break;
            }
            else {
                SetColor(12);
                printf("Please enter a valid number.");
                SetColor(10);
                while (getchar() != '\n');
            }
        } while (1);

        printf("\n");

        printf("\tQuantity: ");
        do {
            if (scanf("%d", &quantity) == 1 && quantity > 0) {
                break;
            }
            else {
                SetColor(12);
                printf("Please enter a valid number.");
                SetColor(10);
                while (getchar() != '\n');
            }
        } while (1);
        printf("\n");
        prdArr[prdCounter].categoryId = catArr[selection - 1].id;
        //printf("Category Array\t %d", catArray[selection-1].id);
        strcpy(prdArr[prdCounter].categoryName, catArr[selection - 1].name);
        strcpy(prdArr[prdCounter].name, name);
        prdArr[prdCounter].id = prdCounter;
        prdArr[prdCounter].price = price;
        prdArr[prdCounter].quantity = quantity;
        prdCounter++;

        if (prdCounter == prdArrSize)
        {
            prdArrSize *= 2;

            prdArr = realloc(prdArr, prdArrSize * sizeof(Product));


        }
    }

    while (key - 0 == -32)
    {

        key = getch();
        if (key - 0 == 72)
        {
            selection--;
            if (selection < 1)
            {
                selection = catCounter;
            }
            gotoxy(7, selection);
        }

        else if (key - 0 == 80)
        {
            selection++;
            if (selection > catCounter)
            {
                selection = 1;
            }
            gotoxy(7, selection);

        }
        else
        {

        }

        key = getch();
        if (key - 0 == 13)
        {
            system("cls");
            printf("Category %s\t:\n", catArr[selection - 1].name);
            char name[20];
            int price;
            int quantity;

            printf("\tName: ");
            scanf("%s", &name);
            printf("\n");

            printf("\tPrice: ");
            scanf("%d", &price);
            printf("\n");

            printf("\tQuantity: ");
            scanf("%d", &quantity);
            printf("\n");
            prdArr[prdCounter].categoryId = catArr[selection - 1].id;

            strcpy(prdArr[prdCounter].categoryName, catArr[selection - 1].name);
            strcpy(prdArr[prdCounter].name, name);
            prdArr[prdCounter].id = prdCounter;
            prdArr[prdCounter].price = price;
            prdArr[prdCounter].quantity = quantity;
            prdCounter++;

            if (prdCounter == prdArrSize)
            {
                prdArrSize *= 2;
                prdArr = realloc(prdArr, prdArrSize * sizeof(Product));
            }
            getch();

        }
    }

    ShowConsoleCursor(0);

}

void displayAllPrds()
{

    //Red
    SetColor(12);
    if (prdCounter == 0)
    {
        char phrase[100];
        strcpy(phrase, "There are no products.");
        int i = 0;
        int j;
        while (i < 22) {

            printf("%c", phrase[i]);
            j = 0;
            while (j < 20000000) {
                j++;
            }
            i++;
        }
        getch();
        return;
    }
    SetColor(10);

    for (int i = 0; i < prdCounter; i++)
    {
        printf("%s\n", prdArr[i].name);
        printf("\t-> Id: %d", prdArr[i].id);
        printf("\t-> Price: %d", prdArr[i].price);
        printf("\t-> Quantity: %d", prdArr[i].quantity);
        printf("\t-> Category Id: %d", prdArr[i].categoryId);
        printf("\t-> Category Name: %s\n", prdArr[i].categoryName);
    }
    getch();

}

void displayOptions(int selection)
{


    char arr[7][30];
    strcpy(arr[0], "\tAdd a category        \n");
    strcpy(arr[1], "\tDisplay all categories\n");
    strcpy(arr[2], "\tAdd a product         \n");
    strcpy(arr[3], "\tDisplay all products  \n");
    strcpy(arr[4], "\tMove a product        \n");
    strcpy(arr[5], "\tMake an order         \n");
    strcpy(arr[6], "\tExit\n");
    //Yellow
    SetColor(14);
    if (selection == 0) {
        gotoxy(0, 1);
        printf("%s", arr[1]);
        gotoxy(0, 6);
        printf("%s", arr[6]);
        SetColor(10);
        gotoxy(0, selection);
        printf("%s", arr[selection]);
        gotoxy(0, selection);
    }
    else if (selection == 6) {
        gotoxy(0, 0);
        printf("%s", arr[0]);
        gotoxy(0, 5);
        printf("%s", arr[5]);
        SetColor(10);
        gotoxy(0, selection);
        printf("%s", arr[selection]);
        gotoxy(0, selection);
    }
    else {
        gotoxy(0, selection - 1);
        printf("%s", arr[selection - 1]);
        gotoxy(0, selection + 1);
        printf("%s", arr[selection + 1]);
        SetColor(10);
        gotoxy(0, selection);
        printf("%s", arr[selection]);
        gotoxy(0, selection);
    }
}

void displayFirstTimeOptions()
{
    ShowConsoleCursor(0);
    //Yellow = 14;
    SetColor(14);
    //printf("\tAdd a category        \n");
    //printf("\tDisplay all categories\n");
    //printf("\tAdd a product         \n");
    //printf("\tDisplay all products  \n");
    //printf("\tMove a product        \n");
    //printf("\tMake an order         \n");
    //printf("\tExit\n");

    printWithDelay("\tAdd a category        \n", 24, 1000000);
    printWithDelay("\tDisplay all categories\n", 24, 1000000);
    printWithDelay("\tAdd a product         \n", 24, 1000000);
    printWithDelay("\tDisplay all products  \n", 24, 1000000);
    printWithDelay("\tMove a product        \n", 24, 1000000);
    printWithDelay("\tMake an order         \n", 24, 1000000);
    printWithDelay("\tExit\n", 6, 1000000);

}

void addCategory()
{
    ShowConsoleCursor(1);
    char name[20];
    //printf("Category name:\t");
    printWithDelay("Category name:\t", 15, 6000000);
    scanf("%s", name);
    strcpy(catArr[catCounter].name, name);
    catArr[catCounter].id = catCounter;
    catCounter++;
    if (catCounter == catArrSize)
    {
        catArrSize *= 2;
        catArr = realloc(catArr, catArrSize * sizeof(Category));
    }
    ShowConsoleCursor(0);
}

void displayAllCats()
{

    if (catCounter == 0)
    {

        // printf("There are no categories.");
        SetColor(12);
        char phrase[100];
        strcpy(phrase, "There are no categories.");
        //SetColor(7);
        //getch();
        int i = 0;
        int j;
        while (i < 24) {

            printf("%c", phrase[i]);
            j = 0;
            while (j < 20000000) {
                j++;
            }
            i++;
        }
        getch();
        return;
    }
    for (int i = 0; i < catCounter; i++)
    {
        printf("Id: %d\tName: %s\n", catArr[i].id, catArr[i].name);
    }
    getch();
}

void move()
{
    if (catCounter < 2)
    {
        SetColor(12);
        char phrase[100];
        strcpy(phrase, "There must be more than 2 categories at least.");

        //getch();
        int i = 0;
        int j;
        while (i < 46) {

            printf("%c", phrase[i]);
            j = 0;
            while (j < 20000000) {
                j++;
            }
            i++;
        }
        getch();
        return;
    }

    ShowConsoleCursor(1);
    printf("First choose the category:\n");
    int i;
    for (i = 0; i < catCounter; i++)
    {
        printf("Category: %s\n", catArr[i].name);
    }

    gotoxy(0, 1);
    char key = getch();
    int selection = 1;
    while (key - 0 == -32)
    {
        key = getch();
        if (key - 0 == 72)
        {
            selection--;
            if (selection < 1)
            {
                selection = catCounter;
            }
            gotoxy(0, selection);
        }
        else if (key - 0 == 80)
        {
            selection++;
            if (selection > catCounter)
            {
                selection = 1;
            }
            gotoxy(0, selection);
        }
        key = getch();
        if (key - 0 == 8)
        {
            return;
        }
        else if (key - 0 == 13)
        {
            system("cls");
        }
        else
        {

        }

    }

    i = 0;
    int filteredArr[prdCounter];
    int filterCounter = 0;
    for (i = 0; i < prdCounter; i++)
    {
        if (prdArr[i].categoryId == catArr[selection - 1].id)
        {
            filteredArr[filterCounter++] = i;
        }
    }

    system("cls");
    gotoxy(0, 0);
    for (i = 0; i < filterCounter; i++)
    {
        printf("%s\n", prdArr[filteredArr[i]].name);
        printf("\t-> Id: %d", prdArr[filteredArr[i]].id);
        printf("\t-> Category Name: %s\n", prdArr[filteredArr[i]].categoryName);
    }

    gotoxy(0, 0);
    selection = 0;
    key = getch();
    while (key - 0 == -32)
    {
        key = getch();
        if (key - 0 == 72)
        {
            selection -= 2;
            if (selection < 0)
            {
                selection = (filterCounter - 1) * 2;
            }
            gotoxy(0, selection);
        }
        else if (key - 0 == 80)
        {
            selection += 2;
            if (selection > (filterCounter - 1) * 2)
            {
                selection = 0;
            }
            gotoxy(0, selection);
        }

        else if (key - 0 == 8)
        {
            return;
        }

        else
        {

        }
        key = getch();

    }
    system("cls");
    int temp = selection / 2;
    printf("Choose the new product category:\n");



    for (i = 0; i < catCounter; i++)
    {
        printf("Category: %s\n", catArr[i].name);
    }

    gotoxy(0, 1);
    key = getch();
    selection = 1;
    while (key - 0 == -32)
    {
        key = getch();
        if (key - 0 == 72)
        {
            selection--;
            if (selection < 1)
            {
                selection = catCounter;
            }
            gotoxy(0, selection);
        }
        else if (key - 0 == 80)
        {
            selection++;
            if (selection > catCounter)
            {
                selection = 1;
            }
            gotoxy(0, selection);
        }
        key = getch();
        if (key - 0 == 8)
        {
            return;
        }
        else if (key - 0 == 13)
        {
            break;
        }
        else
        {

        }
        key = getch();

    }

    prdArr[filteredArr[temp]].categoryId = catArr[selection - 1].id;

    strcpy(prdArr[filteredArr[temp]].categoryName, catArr[selection - 1].name);
    while (i < 40000000)i++;
    system("cls");
    i = 0;
    char phrase[40] = "Product is moved successfully";
    gotoxy(50, 5);
    while (i < 29) {
        printf("%c", phrase[i]);
        int j = 0;
        while (j < 20000000)j++;
        i++;
    }
    i = 0;
    while (i < 100000000)i++;

    ShowConsoleCursor(0);
}

void makeOrder()
{
    if (prdCounter == 0) {
        SetColor(12);
        char phrase[100];
        strcpy(phrase, "There are no products to be sold.");
        int i = 0;
        int j;
        while (i < 33) {

            printf("%c", phrase[i]);
            j = 0;
            while (j < 20000000) {
                j++;
            }
            i++;
        }
        getch();
        return;
    }

    ShowConsoleCursor(1);
    /*int i = 0;
    int j;
    int spacer = 25;

    for(i = 0; i < prdCounter; i++)
    {
        spacer = 25;
        SetColor(6);
        printf("%s", prdArr[i].name);
        j = 0;
        while(prdArr[i].name[j] != '\0')
        {
            spacer--;
            j++;
        }
        while(spacer > 0)
        {
            printf(" ");
            spacer--;
        }
        SetColor(11);
        printf("      ->  Price: %d   |   Quantity:  %d.\n", prdArr[i].price, prdArr[i].quantity);
    }*/

    int yPosition = 0;
    int xPosition = 2;
    gotoxy(xPosition, yPosition);
    SetColor(14);
    for (int i = 0; i < prdCounter; i++) {
        printf("->  %s", prdArr[i].name);
        xPosition += 30;
        gotoxy(xPosition, yPosition);
        printf("  |  ");
        xPosition += 5;

        printf("Price: %d", prdArr[i].price);
        xPosition += 30;

        gotoxy(xPosition, yPosition);
        printf("  |  ");
        xPosition += 5;

        gotoxy(xPosition, yPosition);
        printf("Quantity:  %d.\n", prdArr[i].quantity);
        xPosition += 30;
        yPosition++;
        xPosition = 2;
        gotoxy(xPosition, yPosition);
        //yPosition+=1;
        xPosition = 2;
    }

    printf("Order now");
    int orderQuantities[prdCounter];
    for (int i = 0; i < prdCounter; i++) {
        orderQuantities[i] = 0;
    }
    int selection = 0;
    gotoxy(0, 0);
    char key = getch();
    while (key - 0 == -32 || key - 0 == 13)
    {
        if (key - 0 == -32)
            key = getch();
        if (key - 0 == 72)
        {
            selection--;
            if (selection < 0)
            {
                selection = prdCounter;
            }
            gotoxy(0, selection);
        }
        else if (key - 0 == 80)
        {
            selection++;
            if (selection > prdCounter)
            {
                selection = 0;
            }
            gotoxy(0, selection);
        }

        else if (key - 0 == 8)
        {
            return;
        }
        else if (key - 0 == 13)
        {
            if (selection != prdCounter)
            {
                gotoxy(100, selection);
                SetColor(10);
                printf("Enter quantity: ");
                int q;

                //scanf("%d", &q);
                do {
                    if (scanf("%d", &q) == 1 && q > 0 && q <= prdArr[selection].quantity) {
                        break;
                    }
                    else {
                        gotoxy(100, selection);
                        SetColor(10);
                        printf("Enter quantity:      ");
                        gotoxy(100, selection);
                        printf("Enter quantity: ");
                        while (getchar() != '\n');
                    }
                } while (1);
                /*if(q <= prdArr[selection].quantity)break;
                gotoxy(100,selection);
                SetColor(10);
                printf("Enter quantity:      ");
                gotoxy(100,selection);
                printf("Enter quantity: ");*/

                orderQuantities[selection] = q;

                gotoxy(0, selection);
            }
            else
            {
                gotoxy(0, selection + 1);
                SetColor(11);
                printf("*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n");
                printf("Your order is:\n");
                int total = 0;
                for (int i = 0; i < prdCounter; i++) {
                    if (orderQuantities[i] > 0) {
                        printf("%s and ordered quantity = %d\n", prdArr[i].name, orderQuantities[i]);
                        prdArr[i].quantity -= orderQuantities[i];
                        total += orderQuantities[i] * prdArr[i].price;
                    }
                }
                SetColor(14);
                printf("Total:\t\t\t%d.\n", total);
                SetColor(11);
                printf("*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n");
                getch();
                return;
            }
            //key = getch();
        }
        else
        {

        }
        key = getch();

    }
    getch();
    ShowConsoleCursor(0);
}

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void ShowConsoleCursor(int showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void printWithDelay(char phrase[], int size, int time) {
    int i = 0;
    int j = 0;
    while (i < size) {
        printf("%c", phrase[i]);
        j = 0;
        while (j < time)j++;
        i++;
    }

    return;
}
