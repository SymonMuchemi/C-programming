#include <stdio.h>

int main(void){

    int pin =0000, balance = 0;

    void change_pin()
    {
        int p1, p2;
        printf("Enter new pin");
        scanf("%d", &p1);
        printf("Confirm pin: \n");
        scanf("%d", &p2);

        if (p1 == p2){
            pin = p1;
            printf("Pin created successfully.\n");
        }
        else printf("Pin mismatch\n\n");
    
    }

    void deposit(){
        int amount;
        printf("Enter amount to deposit: ");
        scanf("%d", &amount);
        
        if (amount <= 0)
        {
            printf("Cannot complete transaction!\n");
        }
        
        balance += amount;
        printf("Transaction successful.\nNew balance: Ksh %d\n", balance);
    }

    void withdraw(){
        int amount;
        printf("Enter amount to withdraw: ");
        scanf("%d", &amount);
        int chkpin;
        printf("Enter pin: \n");
        scanf("%d", &chkpin);

        if (chkpin == pin)
        {
            if (amount <= 0)
        {
            printf("Cannot complete transaction!\n");
        }
        
        if (amount > balance){
            printf("Insufficient balance!\n");
        }
        else{
            balance -= amount;
            printf("Transaction successfull\nNew balance: Ksh %d\n", balance);
        }
        }else printf("Invalid pin!\n");
        
    }

    void check_balance(){
        int chkpin;
        printf("Enter pin: \n");
        scanf("%d", &chkpin);

        if (chkpin == pin)
        {
            printf("Your account balance is: Ksh %d\n", balance);
        }
        else printf("Invalid pin!\n"); 
    }

    void options(){
        int opt;
        int chkpin;
        printf("Enter pin: \n");
        scanf("%d", &chkpin);

        if (chkpin == pin)
        {
            printf("Select from the menu below:\n1. Deposit\n2.Withdraw\n3.Check balance\n4.Change pin\nOption: ");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                deposit();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                check_balance();
                break;
            case 4:
                change_pin();
                break;
            default:
                printf("Invalid option!\n");
                break;
            }
        }
        else printf("Invalid pin!\n"); 
        
    }
    
    options();
    
}