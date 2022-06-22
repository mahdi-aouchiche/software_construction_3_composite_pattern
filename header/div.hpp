#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <stdexcept>

class Div : public Base
{
    private:
        string division;  	/*holds the expression of the division on the operands*/
        double result;      /*holds the result of the division operation*/
        bool flag = false;  /*set to true if denominator is Zero*/
    
    public:
        /* Constructor */
        Div(Base* leftOperand, Base* rightOperand) : Base() 
        {
            if(rightOperand->evaluate() == 0){
                this->flag = true;
            }
            this->result   = leftOperand->evaluate() /  rightOperand->evaluate();
            this->division = "(" + leftOperand->stringify() + ") / (" + rightOperand->stringify() + ")";
        }

        /* Return the addition result */
        virtual double evaluate() {
            /* If denominator is Zero throw runtime_error */
            if (flag) {
                throw runtime_error("Math error: Attempted to divide by Zero\n");
            }
            
            return this->result;
        }

        /* Return the addition expression */
        virtual string stringify() { 
            return this->division;
        }
};

#endif //__DIV_HPP__