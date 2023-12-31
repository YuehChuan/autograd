#ifndef TENSOR_H
#define TENSOR_H

#include <eigen3/Eigen/Core>
#include <memory>
#include <iostream>

using std::shared_ptr;
using std::static_pointer_cast;
using Eigen::Matrix;
using Eigen::Dynamic;
using Eigen::RowMajor;

class Operator;

class Tensor {
public:
	Tensor(double value);
	Tensor(int rowNum, int colNum);
	template<int rowNum, int colNum>
	Tensor(Matrix<double, rowNum, colNum, RowMajor> value);
	Tensor(shared_ptr<Matrix<double, Dynamic, Dynamic, RowMajor>>, shared_ptr<Operator> op);
	Tensor(const Tensor& t) = default;
	Tensor(Tensor&& t) = default;
	Tensor& operator=(const Tensor& t) = default;
	Tensor& operator=(Tensor&& t) = default;
	~Tensor() = default;
	double operator()(int row, int col);
	void backward();
	void clearGradient();
	void setZero();
	void setOnes();
	void setIdentity();
	void setRandom();
	bool isConstant() const;
	int row() const;
	int col() const;
	Matrix<double, Dynamic, Dynamic, RowMajor>& operator*();
	Matrix<double, Dynamic, Dynamic, RowMajor>& grad();
	Tensor operator+(const Tensor& t) const;
	Tensor& operator+=(const Tensor& t);
	Tensor& operator++();
	Tensor operator++(int);
	Tensor operator-(const Tensor& t) const;
	Tensor& operator-=(const Tensor& t);
	Tensor& operator--();
	Tensor operator--(int);
	Tensor operator*(const Tensor& t) const;
	Tensor& operator*=(const Tensor& t);
	Tensor operator/(const Tensor& t) const;
	Tensor& operator/=(const Tensor& t);
	Tensor log(double t=std::exp(1.0)) const;
	Tensor pow(double t) const;
	Tensor exp() const;
private:
	friend std::ostream& operator<<(std::ostream &out, const Tensor& t);
	void _backward();
private:
	bool constant;
	shared_ptr<Matrix<double, Dynamic, Dynamic, RowMajor>> value;
	shared_ptr<Matrix<double, Dynamic, Dynamic, RowMajor>> gradient;
	shared_ptr<Operator> op;
};

template<int rowNum, int colNum> inline
Tensor::Tensor(Matrix<double, rowNum, colNum, RowMajor> value) : op(nullptr), constant(false) {
	this->value = std::make_shared<Matrix<double, Dynamic, Dynamic, RowMajor>>(value);
	gradient = std::make_shared<Matrix<double, Dynamic, Dynamic, RowMajor>>(value);
	gradient->setZero();
}

std::ostream& operator<<(std::ostream &out, const Tensor& t);

#endif //TENSOR_H
