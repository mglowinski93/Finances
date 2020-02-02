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
        string date;

    public:
        int getId() const;
        int getUserId() const;
        string getTitle() const;
        string getAmount() const;
        string getDate() const;

        void setId(int);
        void setUserId(int);
        void setTitle(string);
        void setAmount(string);
        void setDate(string);
};

#endif // EXPENSE_H
