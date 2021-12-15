#include <iostream>
#include "Perceptron.h"
/*
10
123 123
321 321
12 13
31 32
58 56
9093 9092
9029 9029
9901 9900
22314 22315
12312 12333
 */
int main()
{
    Perceptron p(2, 0.1);
    std::vector<std::vector<double>> tofit;
    std::vector<double> idealtofit;
    for(int i = 0; i < 100000; ++i){
        std::vector<double> tin(2);
        tin[0] = (double)(rand() % 1000000);
        tin[1] = (double)(rand() % 1000000);
        double max = std::max(tin[0],tin[1]);
        if(tin[0]>tin[1])
            idealtofit.emplace_back(1);
        else
            idealtofit.emplace_back(0);
        tin[0] /= max;
        tin[1] /= max;
        tofit.emplace_back(tin);
    }

    for(int i = 0; i < 1000; ++i){
        std::vector<double> in(2);
        in[0] = (double)(rand() % 20);
        in[1] = (double)(rand() % 20 + 1);
        double max = std::max(in[0],in[1]);
        if(in[0]>in[1])
            idealtofit.emplace_back(1);
        else
            idealtofit.emplace_back(0);
        in[0] /= max;
        in[1] /= max;
        tofit.emplace_back(in);
    }

    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::vector<double> in(2);
        std::cin >> in[0] >> in[1];
        double max = std::max(in[0],in[1]);
        if(in[0]>in[1])
            idealtofit.emplace_back(1);
        else
            idealtofit.emplace_back(0);
        in[0] /= max;
        in[1] /= max;
        tofit.emplace_back(in);
    }

    for(int i = 0; i < tofit.size() && i < idealtofit.size(); ++i){
        p.fit(tofit[i], idealtofit[i]);
    }

    while(true){
        std::vector<double> in(2);
        std::cin >> in[0] >> in[1];
        p.predict(in);
        if(p.get_output() > 0.6)
            std::cout << "a > b";
        else
            std::cout << "a <= b";
    }
    return 0;
}
