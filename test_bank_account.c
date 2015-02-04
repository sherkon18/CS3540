//Name: Dalibor Labudovic 
//Prof: J.Higgins
//Assignment: Assign4
//Course: CS3450

#include "bank_account.h"

char* name = "Dalibor Labudovic";
double initial_amount = 20;
double withdraw_amount = 10;
double deposit_amount = 50;
char* account_number = "465060";


int main()

{
		bank_account* acct = create_account(name, initial_amount, account_number);

		deposit(acct, deposit_amount);
		display_account(acct);
		delete_account(acct);
	
		bank_account* acct2 = create_account("", 50,465060);
		
		bank_account* acct3 = create_account(name, -2, 465060);
		
		bank_account* acct4 = create_account(name, initial_amount, -200);

		bank_account* acct5 = create_account(name, initial_amount,account_number);
		display_account(acct5);
		
		withdraw(acct5, withdraw_amount);
		display_account(acct5);
		delete_account(acct5);

	return 0;
}
