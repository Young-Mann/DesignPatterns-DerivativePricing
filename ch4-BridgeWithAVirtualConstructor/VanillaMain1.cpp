#include "SimpleMC3.h"
#include "../ch3-InheritanceAndVirtualFunction/DoubleDigital.h"
#include "Vanilla1.h"
#include <iostream>
using namespace std;

int main()
{
    double        Expiry;
    double        Low, Up;
    double        Spot;
    double        Vol;
    double        r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter low barrier\n";
    cin >> Low;
    cout << "\nEnter up barrier\n";
    cin >> Up;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    PayOffDoubleDigital thePayOff(Low, Up);
    VanillaOption       theOption(thePayOff, Expiry);
    double              result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);

    cout << "\nThe price is " << result << ".\n";

    double tmp;
    cin >> tmp;

    return 0;
}