#ifndef ADDOPERATOR_H
#define ADDOPERATOR_H

#include "operator/Operator.h"

class AddOperator : public Operator {
public:
	AddOperator(const Tensor& tensor1, const Tensor& tensor2);
	Tensor operator()() override;
	void backward(Tensor& result) override;
};

#endif //ADDOPERATOR_H
