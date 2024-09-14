#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 20

struct Customer
{
    int accountNumber;
    char name[50];
    float balance;
    int age;
};

struct Customer bank[MAX_CUSTOMERS];
int numCustomers = 0;

void insertRecord()
{
    if (numCustomers < MAX_CUSTOMERS)
    {
        struct Customer newCustomer;
        printf("Enter account number: ");
        scanf("%d", &newCustomer.accountNumber);
        printf("Enter name: ");
        scanf("%s", &newCustomer.name);
        printf("Enter balance: ");
        scanf("%f", &newCustomer.balance);
        printf("Enter age: ");
        scanf("%d", &newCustomer.age);
        bank[numCustomers] = newCustomer;
        numCustomers++;
        printf("Record inserted successfully.\n");
    }
    else
    {
        printf("Cannot insert record. Maximum number of customers reached.\n");
    }
}

void deleteRecord()
{
    int accountNumber, found = 0;
    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numCustomers; i++)
    {
        if (bank[i].accountNumber == accountNumber)
        {
            for (int j = i; j < numCustomers - 1; j++)
            {
                bank[j] = bank[j + 1];
            }
            numCustomers--;
            found = 1;
            printf("Record deleted successfully.\n");
            break;
        }
    }

    if (!found)
    {
        printf("Record not found.\n");
    }
}

void updateRecord()
{
    int accountNumber, found = 0;
    printf("Enter account number to update: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numCustomers; i++)
    {
        if (bank[i].accountNumber == accountNumber)
        {
            printf("Enter new name: ");
            scanf("%s", &bank[i].name);
            printf("Enter new balance: ");
            scanf("%f", &bank[i].balance);
            printf("Enter age: ");
            scanf("%d", &bank[i].age);
            found = 1;
            printf("Record updated successfully.\n");
            break;
        }
    }

    if (!found)
    {
        printf("Record not found.\n");
    }
}

void displayRecords()
{
    printf("/////////////// Account Details ///////////////\n");
    for (int i = 0; i < numCustomers; i++)
    {
        printf("***********************************************\n");
        printf("* Account Number: %d                          \n", bank[i].accountNumber);
        printf("* Customer Name: %s                           \n", bank[i].name);
        printf("* Amount: %f                                  \n", bank[i].balance);
        printf("* Age: %d                                     \n", bank[i].age);
        printf("***********************************************\n");
    }
}

void saveRecordsToFile()
{
    FILE *file = fopen("bank_records.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < numCustomers; i++)
    {
        fprintf(file, "%d,%s,%.2f,%d\n", bank[i].accountNumber, bank[i].name, bank[i].balance, bank[i].age);
    }

    fclose(file);
    printf("Records saved to file.\n");
}

int main()
{
    int option;
    printf("***********************************************\n");
    printf("*          Enter 1 for Transactions.          *\n");
    printf("*          Enter 2 for CRUD Operations.       *\n");
    printf("***********************************************\n");
    scanf("%d", &option);
    if (option == 2)
    {
        int choice;

        do
        {
            printf("***********************************************\n");
            printf("*             //Banking System//              *\n");
            printf("*            1. Insert Record                 *\n");
            printf("*            2. Delete Record                 *\n");
            printf("*            3. Update Record                 *\n");
            printf("*            4. Display Records               *\n");
            printf("*            5. Save Records to File          *\n");
            printf("*            6. Exit                          *\n");
            printf("***********************************************\n");

            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                insertRecord();
                break;
            case 2:
                deleteRecord();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                displayRecords();
                break;
            case 5:
                saveRecordsToFile();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 6);
    }
    else if (option == 1)
    {
        long amount = 100000, deposit, withdraw;
        int choice, pin, fst_cash;
        char transaction, choose;
        printf("//////////////////////////////////////////////////////////////\n");
        printf("/            Welcome To Static Bank Of Pakistan.             /\n");
        printf("//////////////////////////////////////////////////////////////\n");

    menu:
        printf("\n ENTER YOUR PIN NUMBER:");
        scanf("%d", &pin);
        if (pin == 1112)
            goto choice;
        else
        {
            printf("\n\nPLEASE ENTER VALID PASSWORD\n");
            goto menu;
        }

    choice:
    label:
        printf("============= Welcome to ATM Service =============\n");
        printf("*             Please Choose transcation:         *\n");
        printf("*          1. Balance Enquiry                    *\n");
        printf("*          2. Withdraw Cash                      *\n");
        printf("*          3. Deposit Cash                       *\n");
        printf("*          4. Fast Cash Withdraw                 *\n");
        printf("*          5. Quit                               *\n");
        printf("==================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        system("cls");

        switch (choice)
        {

        case 1:
            printf("\n YOUR BALANCE Is Rs : %ld ", amount);

            time_t tm;
            time(&tm);

            printf("\n\n\t%s", ctime(&tm));
            break;

        case 2:
            printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
            scanf("%ld", &withdraw);

            if (withdraw < amount && withdraw <= 25000)
            {

                amount = amount - withdraw;
                printf("\n\n PLEASE COLLECT CASH OF RS:%ld", withdraw);

                time_t tm;
                time(&tm);
                printf("\n\n\t%s", ctime(&tm));
                printf("\n");

                printf("\n\n\nDO U WANT TO KNOW YOUR REMAINING BALANCE?\n(Press 'y' For Yes)\n(Press 'n' For No): \n");
                scanf("%s", &choose);

                system("cls");

                if (choose == 'y' || choose == 'Y')
                {

                    printf("\nNOW YOUR CURRENT BALANCE IS:%ld", amount);

                    time_t tm;
                    time(&tm);

                    printf("\n\n\t%s", ctime(&tm));
                }
            }

            else if (withdraw >= 25000)
            {
                printf("Your Limit is 25,000\nPlease Donot Exceed the Limit");
            }

            else
                printf("\n INSUFFICENT BALANCE");

            break;

        case 3:
            printf("\n ENTER THE AMOUNT TO DEPOSIT: ");
            scanf("%ld", &deposit);
            amount = amount + deposit;
            printf("YOUR BALANCE IS %ld", amount);
            time_t t;
            time(&t);

            printf("\n\n\t%s", ctime(&t));

            break;

        case 4:
            printf("++++++++++++++++++++++++\n");
            printf("+  Press 1 For 5,000   +\n");
            printf("+  Press 2 For 10,000  +\n");
            printf("+  Press 3 For 15,000  +\n");
            printf("+  Press 4 For 20,000  +\n");
            printf("+  Press 5 For 25,000  +\n");
            printf("++++++++++++++++++++++++\n");
            printf("Please Choose Fast Cash Options:\n");
            scanf("%d", &fst_cash);

            system("cls");
            if (fst_cash == 1 && 5000 < amount)
            {
                printf("Please Take Cash:Rs 5000\n\n");

                amount = amount - 5000;
                printf("\n\n\nDO U WANT TO KNOW YOUR REMAINING BALANCE?\n(Press 'y' For Yes)\n(Press 'n' For No): \n");
                scanf("%s", &choose);
                system("cls");

                if (choose == 'y' || choose == 'Y')
                {
                    printf("\n Now Your Balance Is Rs : %ld ", amount);

                    time_t t;
                    time(&t);

                    printf("\n\n\t%s", ctime(&t));
                }
            }

            else if (fst_cash == 2 && 10000 < amount)
            {
                printf("Please Take Cash:Rs 10000\n\n");

                amount = amount - 10000;
                printf("\n\n\nDO U WANT TO KNOW YOUR REMAINING BALANCE?\n(Press 'y' For Yes)\n(Press 'n' For No): \n");
                scanf("%s", &choose);
                system("cls");

                if (choose == 'y' || choose == 'Y')
                {

                    printf("\n Now Your Balance Is Rs : %ld ", amount);

                    time_t tm;
                    time(&tm);
                    printf("\n\n\t%s", ctime(&tm));
                }
            }

            else if (fst_cash == 3 && 15000 < amount)
            {
                printf("Please Take Cash:Rs 15000\n\n");

                amount = amount - 15000;
                printf("\n\n\nDO U WANT TO KNOW YOUR REMAINING BALANCE?\n(Press 'y' For Yes)\n(Press 'n' For No): \n");
                scanf("%s", &choose);
                system("cls");

                if (choose == 'y' || choose == 'Y')
                {

                    printf("\n Now Your Balance Is Rs : %ld ", amount);

                    time_t tm;
                    time(&tm);

                    printf("\n\n\t%s", ctime(&tm));
                }
            }

            else if (fst_cash == 4 && 20000 < amount)
            {
                printf("\nPlease Take Cash:Rs 20000\n\n");

                amount = amount - 20000;
                printf("\n\n\nDO U WANT TO KNOW YOUR REMAINING BALANCE?\n(Press 'y' For Yes)\n(Press 'n' For No): \n");
                scanf("%s", &choose);
                system("cls");

                if (choose == 'y' || choose == 'Y')
                {
                    printf("\nNow Your Balance Is Rs : %ld ", amount);

                    time_t tm;
                    time(&tm);
                    printf("\n\n\t%s", ctime(&tm));
                }
            }

            else if (fst_cash == 5 && 25000 < amount)
            {
                printf("\nPlease Take Cash:Rs 25000\n\n");

                amount = amount - 25000;
                printf("\n\n\nDO U WANT TO KNOW YOUR REMAINING BALANCE?\n(Press 'y' For Yes)\n(Press 'n' For No): \n");
                scanf("%s", &choose);
                system("cls");

                if (choose == 'y' || choose == 'Y')
                {
                    printf("\nNow Your Balance Is Rs : %ld ", amount);

                    time_t tm;
                    time(&tm);
                    printf("\n\n\t%s", ctime(&tm));
                }
            }

            else
                printf("Invalid fast cash option\n");

        case 5:
            printf(".....................................\n");
            printf(".                                   .\n");
            printf(".  THANK You FOR USING ATM SERVICE  .\n");
            printf(".                                   .\n");
            printf(".....................................\n");
            exit(0);
            break;

        default:
            printf("\n INVALID CHOICE");
        }

        printf("\n\n\nDO U WISH TO HAVE ANOTHER TRANSCATION?\n(Press 'y' For Yes)\n(Press 'n' For No): \n");
        scanf("%s", &transaction);
        system("cls");

        if (transaction == 'y' || transaction == 'Y')
        {
            goto label;
        }
        printf(".....................................\n");
        printf(".                                   .\n");
        printf(".  THANK You FOR USING ATM SERVICE  .\n");
        printf(".                                   .\n");
        printf(".....................................\n");
    }

    return 0;
}
