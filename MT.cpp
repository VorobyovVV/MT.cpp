#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "mt.h"

int main()
{
    try 
    {
        const char* mtname = "mt.txt";
        const char* cmdname = "input.txt";
        const char* outname = "output.txt";
        std::map <Q1, Q2> tmp;
        std::map <Q1, bool> mtb;
        int head_pos = 1000000;
        Q1 C;
        std::ifstream mtFile(mtname);
        std::ofstream outFile(outname);
        if (!mtFile)
        {
            throw "Error";
        }
        std::ifstream cmdFile(cmdname);
        if (!cmdFile)
        {
            throw "Error";
        }
        std::string str,s;
        mtFile >> str;
        for (int i = 0; i < 1000000; ++i)
        {
            s += '0';
        }
        s += str;
        for (int dimlen = 2000000 - s.length(); dimlen  < 2000000; ++dimlen )
        {
            s += '0';
        }
        str = "";
        while (cmdFile.peek() != EOF)
        {
            Q1 A;
            str = "";
            Q2 B;
            cmdFile >> A;
            cmdFile >> str;
            cmdFile >> B;
            if (C.number == -1) C = A;

            mtb[A] = true;
            tmp[A] = B;
        }
        
        C.number = s[head_pos] - 48;
        int counter=0;
        while (mtb[C])
        {
            Q2 B = tmp[C];
            s[head_pos] = B.number + 48;
            if (B.ch == 'L')
            {
                head_pos--;
                if (head_pos == 0) throw "out of memory";
            }
            if (B.ch == 'R')
            {
                head_pos++;
                if (head_pos == 1999999) throw "out of memory";
            }
            C.cmd = B.cmd;
            C.number = s[head_pos] - 48;
            ++counter;
            if (counter == 10000001) throw "not applicable";
        }
        int l = -1, r = -1;
        int length = s.length();
        l = s.find_first_of('1');
        r = s.find_last_of('1');
        
        for (int dimlen  = std::min(l,head_pos); dimlen  <= std::max(head_pos,r); ++dimlen )
            outFile << s[dimlen];
        outFile << std::endl;
        if (l < head_pos)
        {
            for (int i = 0; i < head_pos-l; ++i)
                outFile << " ";
        }
        outFile << "^" << std::endl;
        mtFile.close();
        cmdFile.close();
        outFile.close();
    }
    catch (const char* str)
    {
        std::cout << "Error! " << str << std::endl;
    }
}