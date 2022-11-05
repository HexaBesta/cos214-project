#include "Transport.h"

Transport::Transport(int supply)
{
    this->supply = supply;
}

bool Transport::isEmpty()
{
    return (this->supply == 0);
}

int Transport::getAmount()
{
    srand(time(0));

    int max = (this->supply < 10) ? this->supply : 10;
    int amount = rand() % max + 1;

    this->supply -= amount;

    return amount;
}