#ifndef INCOME_H
#define INCOME_H
#include <string>

using namespace std;

class Income
{
    private:
        int id;
        int userId;
        string title;
        string amount;
        int date;

    public:
        int getId() const;
        int getUserId() const;
        string getTitle() const;
        string getAmount() const;
        int getDate() const;

        void setId(int);
        void setUserId(int);
        void setTitle(string);
        void setAmount(string);
        void setDate(int);
        bool operator < (const Income &compareIncome)
        {
            return this -> getDate() < compareIncome.getDate();
        }

};

#endif // INCOME
