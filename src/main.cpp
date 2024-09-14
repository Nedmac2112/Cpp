#include "bank_account.hpp"
#include <iostream>

i32 main()
{
    // Dont name variables single characters
    Bank::CheckingAccount checking_account(12345, 1000, "John Doe");

    std::cout << "Account ID: " << checking_account.GetAccountId() << std::endl;
    std::cout << "Account Holder Name: " << checking_account.GetName() << std::endl;

    checking_account.ViewBalance();
    std::cout << std::endl;

    checking_account.Withdraw(500);

    checking_account.ViewBalance();
    std::cout << std::endl;

    checking_account.Deposit(1000);

    checking_account.ViewBalance();
    std::cout << std::endl;

    return 0;
}