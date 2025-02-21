#include <stdio.h>
#include <stdlib.h>
#include "accounts.h"
#include "transactions.h"

void menu() {
    printf("\n🏦 Bank Account Management System");
    printf("\n1️⃣ Create Account");
    printf("\n2️⃣ Deposit Money");
    printf("\n3️⃣ Withdraw Money");
    printf("\n4️⃣ Check Balance");
    printf("\n5️⃣ View Transactions");
    printf("\n6️⃣ Exit");
    printf("\nEnter choice: ");
}

int main() {
    int choice, account_number;
    float amount;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_number);
                printf("Enter Amount to Deposit: ");
                scanf("%f", &amount);
                deposit(account_number, amount);
                break;
            case 3:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_number);
                printf("Enter Amount to Withdraw: ");
                scanf("%f", &amount);
                withdraw(account_number, amount);
                break;
            case 4:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_number);
                check_balance(account_number);
                break;
            case 5:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_number);
                view_transactions(account_number);
                break;
            case 6:
                printf("🚀 Exiting...\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Try again.\n");
        }
    }
    return 0;
}
