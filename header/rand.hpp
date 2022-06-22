#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base
{
    private:
        /* create a local varariable */
        double random; 
    
    public:
        /* Constructor */
        Rand() : Base()
        {
            /* use a seed generate random numbers each time Rand object is created */
            srand(time(0));
            /* save generated value into local variable */
            this->random = rand() % 100;
        } 

        /* Implement virtual functions from Base class */
        virtual double evaluate() {
            /* return the local variable */
            return this->random;
        } 

        virtual string stringify() {
            /* convert local variable to a string */
            return to_string(this->random);
        }
};

#endif //__RAND_HPP__
