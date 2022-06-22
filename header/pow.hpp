#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "math.h"
#include <stdexcept>

class Pow : public Base
{
    private:
	    double result;
		string pow_expression;
		bool flag = false;	// true if base = 0 and exponent < 0 

    public:
		/*Constructor*/
        Pow(Base* base, Base* exp) : Base()
		{
			if(base->evaluate() == 0 && exp->evaluate() < 0) {
				this->flag = true;
			}

			this->result = pow(base->evaluate(), exp->evaluate());
			this->pow_expression = "("+ base->stringify() +") ** (" + exp->stringify()+")";	
		}

		/*Virtual functions inherited from Base class*/
		virtual double evaluate() { 
			/* If base is Zero and exponent is negative throw runtime_error */
            if (flag) {
                throw runtime_error("Math error: exponent cannot be negative when base is zero.\n");
            }
			return this->result;
		}
		
		virtual string stringify() {
			return this->pow_expression;
		}
};

#endif //__POW_HPP__
