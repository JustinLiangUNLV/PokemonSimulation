#ifndef RND_H
#define RND_H
//create the rnd object to use this
class rnd
{
public:
    rnd() : seed(0) {}
    rnd(unsigned long s): seed(s) {}
    unsigned long generateRandomNumber() { return (a * seed++ + c) % m; }
private:
    unsigned long seed;
    const unsigned long a = 1664525;
    const unsigned long c = 1013904223;
    const unsigned long m = 4294967296; 
};
#endif