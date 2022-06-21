#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base
{
    private:	   
        /* create a local variable */
	    double operand; 
    
    public:
        /* Constructor */
        Op(double value) : Base()
        {   
            /* saved value into local variable */
            this->operand = value;
        } 

        /* implement virtual functions for the Base class */
        virtual double evaluate() { 
            /* return the local saved variable */
            return this->operand;
        }

        virtual string stringify() { 
            /* convert output to string */
            return to_string(this->operand);
        } 
};

#endif //__OP_HPP__
