#ifndef SUBOPERATOR_H
#define SUBOPERATOR_H

#include "operator/Operator.h"

class SubOperator : public Operator {
public:
	SubOperator(const Tensor& tensor1, const Tensor& tensor2);
	Tensor operator()() override;
	void backward(Tensor& result) override;
};


#endif //SUBOPERATOR_H
