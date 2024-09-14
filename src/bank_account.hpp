// Added header guards
#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP

// Everything on this page added by Camden K. on 9/10/2024
// Also you never included anything, also you are doing using namespace std, dont do this
// it is horrible practice
// also moved declarations to a source file

#include "types.hpp"
#include <string>

// Also added namespace
namespace Bank
{
    // We should use an enum class for types instead of inheritance but I guess this is fine
    class BankAccount
    {
    // Moved public up to top
    public:
        BankAccount() : m_account_id(0), m_balance(0) {}
        BankAccount(i32 account_id, f64 balance) : m_account_id(account_id), m_balance(balance) {}
        // Use default here
        virtual ~BankAccount() = default;

        // both checkings and savings accounts will have these methods
        // we might want to make these virtual, since the checkings and savings account classes may have their own implementation
        void Withdraw(f64 amount);
        void Deposit(f64 amount);

        // pure virtual function, the checking and saving account classess will display their own balance
        virtual void ViewBalance() const = 0;

        // getters and setters
        i32  GetAccountId() const;
        void SetAccountId(i32  accountID);
        f64 GetBalance() const;
        void SetBalance(f64 balance);

    private:
        // Changed these to m_ so we dont have to use this-> (which is bad practice)
        i32 m_account_id;
        f64 m_balance;
    };

    // child class for checking account
    class CheckingAccount : public BankAccount
    {
    public:
        // Use default here
        CheckingAccount() = default;
        // pass name by const& to avoid copy
        CheckingAccount(i32 account_id, f64 balance, const std::string& name) : BankAccount(account_id, balance), m_account_holder_name(name) {}
        // Use default here
        ~CheckingAccount() override = default;

        void ViewBalance() const;
        const std::string& GetName() const;
    private:
        std::string m_account_holder_name;
    };

    // child class for saving account
    class SavingAccount : public BankAccount
    {
    public:
        SavingAccount() = default;
        // pass name by const& so its not copied
        SavingAccount(i32 account_id, f64 balance, const std::string& name) : BankAccount(account_id, balance), m_account_holder_name(name) {}
        // Use default here
        ~SavingAccount() override = default;

        void ViewBalance() const;
		const std::string& GetName() const;
    private:
		std::string m_account_holder_name;
    };
}

#endif