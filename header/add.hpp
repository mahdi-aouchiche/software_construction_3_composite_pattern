#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base
{
    private:
		string addition;	/* holds the expression of the addition on the operands */      
    	double result;		/* holds the result of the addition operation */
	
    public:
		/* Constructor */
       	Add(Base* leftOperand, Base* rightOperand) : Base()
		{
			this->result   = leftOperand->evaluate() +  rightOperand->evaluate();
			this->addition = leftOperand->stringify() + " + " + rightOperand->stringify();	
		}

		/* Implement virtual functions from the Base class*/
		virtual double evaluate() {
			return this->result;	/* Return the addition result */
		}
 
		virtual string stringify() {
			return this->addition;	/* Return the addition expression */
		}
};

#endif //__ADD_HPP__
