#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "database.txt"

struct Account {
    int account_number;
    char name[50];
    float balance;
};

void create_account() {
    struct Account acc;
    FILE *file = fopen(FILE_NAME, "a");

    if (!file) {
        printf("❌ Error opening file!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &acc.account_number);
    printf("Enter Name: ");
    scanf("%s", acc.name);
    acc.balance = 0.0;

    fwrite(&acc, sizeof(struct Account), 1, file);
    fclose(file);

    printf("✅ Account created successfully for %s!\n", acc.name);
}

void check_balance(int account_number) {
    struct Account acc;
    FILE *file = fopen(FILE_NAME, "r");

    if (!file) {
        printf("❌ Error opening file!\n");
        return;
    }

    while (fread(&acc, sizeof(struct Account), 1, file)) {
        if (acc.account_number == account_number) {
            printf("💰 Account Balance: $%.2f\n", acc.balance);
            fclose(file);
            return;
        }
    }

    printf("❌ Account not found!\n");
    fclose(file);
}
