#include "Expense.h"

int Expense::getId() const
{
    return id;
}

int Expense::getUserId() const
{
    return userId;
}

string Expense::getTitle() const
{
    return title;
}

string Expense::getAmount() const
{
    return amount;
}

string Expense::getDate() const
{
    return date;
}

void Expense::setId(int id)
{
  this -> id = id;
}

void Expense::setUserId(int userId)
{
    this -> userId = userId;
}

void Expense::setTitle(string title)
{
    this -> title = title;
}

void Expense::setAmount(string amount)
{
    this -> amount = amount;
}

void Expense::setDate(string date)
{
    this -> date = date;
}
