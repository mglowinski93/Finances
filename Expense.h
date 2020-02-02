#ifndef EXPENSE_H
#define EXPENSE_H
#include <string>

using namespace std;

class Expense
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
        bool operator < (const Expense &compareExpense)
        {
            return this -> getDate() < compareExpense.getDate();
        }
};

#endif // EXPENSE_H
