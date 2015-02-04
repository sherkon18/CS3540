//Name: Dalibor Labudovic
//Prof: J.Higgins
//Assignment: Assign4
//Course: CS3450

#ifndef _BANK_ACCOUNT_H
#define _BANK_ACCOUNT_H

typedef struct 
{
	double balance;
	char* owner;
	char* num;
}bank_account;

bank_account* create_account(char* acct_owner, double init_balance, char* acct_num);

int deposit(bank_account* acct, double amount);

int withdraw(bank_account* acct, double amount);

void display_account(bank_account* acct);

void delete_account(bank_account* acct);

#endif
