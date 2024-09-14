#include "bank_account.hpp"
#include <iostream>
#include <cassert>

namespace Bank
{
    // both checkings and savings accounts will have these methods
    // we might want to make these virtual, since the checkings and savings account classes may have their own implementation
    void BankAccount::Withdraw(f64 amount)
    {
	    // Changed this to be in a single if statement
        if (amount > m_balance || amount < 0)
            // Dont use exceptions, use asserts
            assert(false && "Insufficient funds");

        m_balance -= amount;
        std::cout << "You withdrew $" << amount << " from your account" << std::endl;
    }

    void BankAccount::Deposit(f64 amount)
    {
        if (amount <= 0)
            assert(false &&"Invalid amount");

        m_balance += amount;
        std::cout << "You deposited $" << amount << " to your account" << std::endl;
    }

    // getters and setters
    i32 BankAccount::GetAccountId() const
    {
        return m_account_id;
    }

    void BankAccount::SetAccountId(i32  accountID)
    {
        accountID = accountID;
    }

    f64 BankAccount::GetBalance() const
    {
        return m_balance;
    }

    void BankAccount::SetBalance(f64 balance)
    {
        m_balance = balance;
    }

	void CheckingAccount::ViewBalance() const
	{
		std::cout << "Your checking account balance is: $" << GetBalance() << std::endl;
	}

	void SavingAccount::ViewBalance() const
	{
		std::cout << "Your saving account balance is: $" << GetBalance() << std::endl;
	}

	const std::string& CheckingAccount::GetName() const
	{
		return m_account_holder_name;
	}

	const std::string& SavingAccount::GetName() const
	{
		return m_account_holder_name;
	}
}
