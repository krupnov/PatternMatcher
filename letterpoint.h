#ifndef LETTERPOINT_H
#define LETTERPOINT_H

class LetterPoint
{
private:
    int x,y;
    wchar_t letter;
    bool used;
public:
    LetterPoint(int x, int y, wchar_t letter);

    int getX() const;
    int getY() const;
    wchar_t getLetter() const;
    void setUsed(bool used);
    bool isUsed() const;
};

#endif // LETTERPOINT_H
