#include <iostream>
#include "../header/base.hpp"
#include "../header/op.hpp"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/add.hpp"
#include "../header/sub.hpp"
#include "../header/pow.hpp"
#include "../header/rand.hpp"

using namespace std;


int main() {
   /* create a few trees to see if classes are */ 
    Base* _two    = new Op(-2);
    Base* zero    = new Op(0);
    Base* pt_five = new Op(.5);
    Base* two     = new Op(2);
    Base* three   = new Op(3);
    Base* four    = new Op(4);
    Base* seven   = new Op(7);

    Base* mult  = new Mult(seven, four);
    Base* add   = new Add(three, mult);
    Base* minus = new Sub(add, two);
    Base* rand  = new Rand();
    Base* tree1 = new Mult(rand, minus);
    cout << tree1->stringify() << " = " << tree1->evaluate() << endl;

    Base* add1  = new Add(pt_five,three);
    Base* add2  = new Add(_two, seven);
    Base* div   = new Div(three, four);
    Base* pow   = new Pow(seven, pt_five);
    Base* mult1 = new Mult(div, add1);
    Base* sub   = new Sub(add2, pow);
    Base* tree2 = new Div(sub, mult1);
    cout << tree2->stringify() << " = " << tree2->evaluate() << endl;

    return 0;
}
