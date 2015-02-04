//Name: Dalibor Labudovic 
//Prof: J.Higgins
//Assignment: Assign4
//Course: CS3450

#include "bank_account.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int is_all_digits(const char* acct)
{
	assert(acct != NULL);
	int i = 0;
	while(i < strlen(acct) && isdigit(acct[i]))
	i++;
	return i == strlen(acct);
}
int is_valid_name(const char* name)
{
	return name != NULL && strlen(name) > 0;
}
int is_valid_account(const char* acct_num)
{
	return acct_num != NULL && strlen(acct_num) > 0 && is_all_digits(acct_num);
}
int is_valid_balance(double bal)
{
	return 0 <= bal;
}
char* create_copy(char* acct)
{
	char* cpy = NULL;
	if(acct != NULL)
	{
		cpy = malloc((strlen(acct)+1)*sizeof(char));
		strcpy(cpy, acct);
		cpy[strlen(acct)] = 0;
	}return cpy;
}

bank_account* create_account(char* acct_owner, double init_balance, char* acct_num)
{
	bank_account* acct = NULL;
	if(is_valid_name(acct_owner) && is_valid_balance(init_balance) && is_valid_account(acct_num))
	{
		acct = malloc(sizeof(bank_account));
		acct -> owner = create_copy(acct_owner);
		acct -> balance = init_balance;
		acct -> num = create_copy(acct_num);
	}return acct;
}

int withdraw(bank_account* acct, double amount)

{
	int result = 0;
	if(acct != NULL)
		if(amount >= 0 && amount <= acct -> balance)
		{
			acct -> balance -= amount;
		result = 1;
		}
	return result;
}

int deposit(bank_account* acct, double amount)
{
	int result = 0;
	if(acct != NULL)
		if(amount >= 0 && amount <= acct -> balance)
		{
			acct -> balance += amount;
		result = 1;
		}
	return result;
}

void display_account(bank_account* acct)
{
	printf("Name: %s\n", acct -> owner);
	printf("Account Number: %s\n", acct -> num);
	printf("Balance: %g", acct -> balance);
}

void delete_account(bank_account* acct)
{
	if(acct != NULL)
	{
		free(acct -> owner);
		free(acct -> num);
		free(acct);
	}
}

