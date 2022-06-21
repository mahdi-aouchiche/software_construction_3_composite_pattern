#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "math.h"

class Sub : public Base 
{
    private:
        double sub_result;
        string sub_expression;
    
    public:
        /* Constructor */
        Sub(Base* leftOperand, Base* rightOperand) : Base()
        {
            this->sub_result = leftOperand->evaluate() - rightOperand->evaluate();
            this->sub_expression = leftOperand->stringify() + " - " + rightOperand->stringify();
        }

        /* virtual functions of Base class */
        virtual double evaluate() {
            return this->sub_result;
        }

        virtual string stringify() {
            return this->sub_expression;
        }

};

#endif //__SUB_HPP__
