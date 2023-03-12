//
// Created by DELL on 2023/3/7.
//

#ifndef WORDLIST_PARAMETER_H
#define WORDLIST_PARAMETER_H


class Parameter {
private:
    bool n = false;
    bool w = false;
    bool c = false;
    char h = 0;
    char t = 0;
    char j = 0;
    bool r = false;
public:
    bool isN() const;

    void setN(bool n);

    bool isW() const;

    void setW(bool w);

    bool isC() const;

    void setC(bool c);

    char getH() const;

    void setH(char h);

    char getT() const;

    void setT(char t);

    char getJ() const;

    void setJ(char j);

    bool isR() const;

    void setR(bool r);
};


#endif //WORDLIST_PARAMETER_H
