#include<iostream>
#include <fstream>
#include <map>
class  Q1
{
public:
    std::string cmd;
    int number = -1;
};

class  Q2
{
public:
    int number = -1;
    char ch;
    std::string cmd;
};

std::ifstream& operator>> (std::ifstream& in, Q1& A)
{
    in >> A.cmd;
    in >> A.number;
    return in;
}

std::ostream& operator<< (std::ostream& out, Q1& A)
{
    out << A.cmd << " ";
    out << A.number;
    return out;
}

std::ifstream& operator>> (std::ifstream& in, Q2& B)
{
    in >> B.number;
    in >> B.ch;
    in >> B.cmd;
    return in;
}

std::ostream& operator<< (std::ostream& out, Q2& B)
{
    out << B.number << " ";
    out << B.ch << " ";
    out << B.cmd;
    return out;
}



bool operator<(const Q1& l, const Q1& r) {
    return (l.cmd < r.cmd || (l.cmd == r.cmd && l.number < r.number));
}


      