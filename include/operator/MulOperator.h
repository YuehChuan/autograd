#ifndef MULOPERATOR_H
#define MULOPERATOR_H

#include "operator/Operator.h"

class MulOperator : public Operator {
public:
	MulOperator(const Tensor& tensor1, const Tensor& tensor2);
	Tensor operator()() override;
	void backward(Tensor& result) override;
};


#endif //MULOPERATOR_H
