// header guard
#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
private:
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zipCode;
    string phoneNumber;

public:
    // Constructors
    User() = default;
    User(string firstName, string lastName, string address, string city, string state, string zipCode, string phoneNumber)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zipCode = zipCode;
        this->phoneNumber = phoneNumber;
    };

    // setters and getters (these will be accessed by the Account class)
    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }
    string getFirstName() const
    {
        return firstName;
    }

    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }
    string getLastName() const
    {
        return lastName;
    }

    void setAddress(string address)
    {
        this->address = address;
    }
    string getAddress() const
    {
        return address;
    }

    void setCity(string city)
    {
        this->city = city;
    }
    string getCity() const
    {
        return city;
    }

    void setState(string state)
    {
        this->state = state;
    }
    string getState() const
    {
        return state;
    }

    void setZipCode(string zipCode)
    {
        this->zipCode = zipCode;
    }
    string getZipCode() const
    {
        return zipCode;
    }

    void setPhoneNumber(string phoneNumber)
    {
        this->phoneNumber = phoneNumber;
    }
    string getPhoneNumber() const
    {
        return phoneNumber;
    }
};

#endif
