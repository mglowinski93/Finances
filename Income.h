#ifndef ADRESAT_H
#define ADRESAT_H
#include <string>

using namespace std;

class Income
{
    private:
        int id;
        int userId;
        string name;
        string surname;
        string phoneNumber;
        string email;
        string adres;

    public:
        int getId();
        int getUserId();
        string getName();
        string getSurname();
        string getPhoneNumber();
        string getEmail();
        string getAddress();
        void setId(int);
        void setUserId(int);
        void setName(string);
        void setSurname(string);
        void setPhoneNumber(string);
        void setEmail(string);
        void setAddress(string);
};

#endif // ADRESAT_H
