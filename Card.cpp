#include "Card.h"

Card::Card(int suit, int num)
{
    _seqNo = suit * 13;
    _seqNo += (num - 1);

    setCard(_seqNo);
}

Card::Card(int seq) {
    setCard(seq);
}

Card::Card() {
    setCard(-1);
}

std::string Card::toString() const
{
    if (_mark < 0 || _mark >=NoMark || _num < 1 || _num > 13)
        return std::string("??");

    std::string str(1, "schd"[_mark]);
    str += "?A23456789TJQK"[_num];
    return str;
}

void Card::setCard(int seq)
{
    if (seq >= 0 && seq <= 52)
    {
        _seqNo = seq;
        _mark = seq / 13;
        _num = seq % 13 + 1;
    }
    else
    {
        _seqNo = -1;
        _mark = NoMark;
        _num = 0;
    }
}