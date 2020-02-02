#include "Income.h"

int Income::getId() const
{
    return id;
}

int Income::getUserId() const
{
    return userId;
}

string Income::getTitle() const
{
    return title;
}

string Income::getAmount() const
{
    return amount;
}

int Income::getDate() const
{
    return date;
}

void Income::setId(int id)
{
  this -> id = id;
}

void Income::setUserId(int userId)
{
    this -> userId = userId;
}

void Income::setTitle(string title)
{
    this -> title = title;
}

void Income::setAmount(string amount)
{
    this -> amount = amount;
}

void Income::setDate(int date)
{
    this -> date = date;
}

