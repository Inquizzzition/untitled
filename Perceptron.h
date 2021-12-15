#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "inqmath.h"
#include <vector>

class Perceptron{
private:
    double learning_rate;
    double output;
    double offset;
    std::vector<double> weight;
    std::vector<double> inputs;
public:
    Perceptron(int input_size);
    Perceptron(int input_size, double learning_rate);
    void predict(std::vector<double> &inp);
    void fit(std::vector<double> &inp, double ideal);
    double get_output();
};


#endif
