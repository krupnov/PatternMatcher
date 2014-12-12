#include "letterpoint.h"

LetterPoint::LetterPoint(int i, int j, wchar_t letter)
{
    this->x = i;
    this->y = j;
    this->letter = letter;
    this->used = false;
}

int LetterPoint::getX() const
{
    return x;
}

int LetterPoint::getY() const
{
    return y;
}

wchar_t LetterPoint::getLetter() const
{
    return letter;
}

void LetterPoint::setUsed(bool used)
{
    this-> used = used;
}

bool LetterPoint::isUsed() const
{
    return used;
}
