#include <iostream>
#include <cmath>

float GetRowSum(float x)
{
    float sum = 0;
    int d = 1;

    for(int i = 0; i < 15; i++)
    {
        sum += 1 / (d * pow(x, d));
        d += 2;
    }

    return sum;
}

int main() {
    while(true)
    {
        float x = 0;
        std::cout << "Enter X:";
        std::cin >> x;

        if(std::abs(x) < 1 || std::abs(x) > 3) {break;}

        std::cout << "Row sum: " << GetRowSum(x) << std::endl;
    }
    return 0;
}
