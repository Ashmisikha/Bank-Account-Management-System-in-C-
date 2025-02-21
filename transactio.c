#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "database.txt"

struct Account {
    int account_number;
    char name[50];
    float balance;
};

void deposit(int account_number, float amount) {
    struct Account acc;
    FILE *file = fopen(FILE_NAME, "r+");
    
    if (!file) {
        printf("❌ Error opening file!\n");
        return;
    }

    while (fread(&acc, sizeof(struct Account), 1, file)) {
        if (acc.account_number == account_number) {
            acc.balance += amount;
            fseek(file, -sizeof(struct Account), SEEK_CUR);
            fwrite(&acc, sizeof(struct Account), 1, file);
            fclose(file);
            printf("✅ Deposited $%.2f successfully!\n", amount);
            return;
        }
    }

    printf("❌ Account not found!\n");
    fclose(file);
}

void withdraw(int account_number, float amount) {
    struct Account acc;
    FILE *file = fopen(FILE_NAME, "r+");

    if (!file) {
        printf("❌ Error opening file!\n");
        return;
    }

    while (fread(&acc, sizeof(struct Account), 1, file)) {
        if (acc.account_number == account_number) {
            if (acc.balance < amount) {
                printf("❌ Insufficient funds!\n");
                fclose(file);
                return;
            }
            acc.balance -= amount;
            fseek(file, -sizeof(struct Account), SEEK_CUR);
            fwrite(&acc, sizeof(struct Account), 1, file);
            fclose(file);
            printf("💸 Withdrawn $%.2f successfully!\n", amount);
            return;
        }
    }

    printf("❌ Account not found!\n");
    fclose(file);
}
