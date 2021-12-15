#include "Perceptron.h"

Perceptron::Perceptron(int input_size):
    output(0),
    weight(std::vector<double>(input_size, 0.5)),
    inputs(std::vector<double>(input_size))
{
    for (int i = 0; i < weight.size(); i++)
        weight[i] = (double)(rand() % 1000 - 500) / 1000;
    offset = (double)(rand() % 1000 - 500) / 1000;
}

Perceptron::Perceptron(int input_size, double learning_rate):
    weight(std::vector<double>(input_size, 0.5)),
    inputs(std::vector<double>(input_size)),
    learning_rate(learning_rate),
    output(0)
{
    for (int i = 0; i < weight.size(); i++)
        weight[i] = (double)(rand() % 1000 - 500) / 1000;
    offset = (double)(rand() % 1000 - 500) / 1000;
}

double Perceptron::get_output(){
    return output;
}

void Perceptron::predict(std::vector<double> &inp){
    inputs = inp;
    output = activation(dot(inputs, weight) + offset);
}

void Perceptron::fit(std::vector<double> &inp, double ideal){
    inputs = inp;
    double sum = dot(inputs, weight) + offset;
    output = activation(sum);
    double error = ideal - sum;
    for (int i = 0; i < weight.size(); i++) {
        weight[i] += inputs[i] * error * dActivation(sum) * learning_rate;
    }
}
