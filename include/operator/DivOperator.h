#ifndef DIVOPERATOR_H
#define DIVOPERATOR_H

#include "operator/Operator.h"

class DivOperator : public Operator {
public:
	DivOperator(const Tensor& tensor1, const Tensor& tensor2);
	Tensor operator()() override;
	void backward(Tensor& result) override;
};


#endif //DIVOPERATOR_H
