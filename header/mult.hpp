#ifndef __Mult_HPP__
#define __Mult_HPP__

#include "base.hpp"

class Mult : public Base 
{
    private:
        string mult_expression;  
        double mult_result;      

    public:
        /* Constructor */
        Mult(Base* leftOperand, Base* rightOperand) : Base() 
        {
            this->mult_result  = leftOperand->evaluate() * rightOperand->evaluate();
            this->mult_expression = "(" + leftOperand->stringify() + ") * (" + rightOperand->stringify() + ")";
        }

        /* Implement virtual function from Base class*/
        virtual double evaluate() { 
            /* Return the multiplication result */
            return this->mult_result;
        }

        virtual string stringify() { 
            /* Return the multiplication expression */
            return this->mult_expression; }
};

#endif //__ADD_HPP__