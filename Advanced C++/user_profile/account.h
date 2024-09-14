// header guard
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "user.h"
using namespace std;

class Account
{
private:
    // The Account class contains an instance of the User class
    User user;
    int bankAccountNumber;
    double amount;

public:
    // Constructors
    Account() = default;
    Account(int accountNumber, double amount, User &user)
    {
        bankAccountNumber = accountNumber;
        this->amount = amount;
        this->user = user;
    };

    // user setters and getters
    // the user object's member variables are accessed through the setters and getters of the User class
    void setUserFirstName(string &firstName)
    {
        user.setFirstName(firstName);
    }
    string getUserFirstName() const
    {
        return user.getFirstName();
    }

    void setUserLastName(string &lastName)
    {
        user.setLastName(lastName);
    }
    string getUserLastName() const
    {
        return user.getLastName();
    }

    void setUserAddress(string &address)
    {
        user.setAddress(address);
    }
    string getUserAddress() const
    {
        return user.getAddress();
    }

    void setUserCity(string &city)
    {
        user.setCity(city);
    }
    string getUserCity() const
    {
        return user.getCity();
    }

    void setUserState(string &state)
    {
        user.setState(state);
    }
    string getUserState() const
    {
        return user.getState();
    }

    void setUserZipCode(string &zipCode)
    {
        user.setZipCode(zipCode);
    }
    string getUserZipCode() const
    {
        return user.getZipCode();
    }

    void setUserPhoneNumber(string &phoneNumber)
    {
        user.setPhoneNumber(phoneNumber);
    }
    string getUserPhoneNumber() const
    {
        return user.getPhoneNumber();
    }

    // account setters and getters
    void setBankAccountNumber(int accountNumber)
    {
        bankAccountNumber = accountNumber;
    }
    int getBankAccountNumber() const
    {
        return bankAccountNumber;
    }

    void setAmount(double amount)
    {
        this->amount = amount;
    }
    double getAmount() const
    {
        return amount;
    }
};

#endif