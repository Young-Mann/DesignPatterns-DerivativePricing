#include "SimpleMC7.h"
#include <iostream>
#include "MCStatistics.h"
#include "../ch4-BridgeWithAVirtualConstructor/Vanilla3.h"
#include "ConvergenceTable.h"
using namespace std;

int main()
{
    double        Expiry;
    double        Strike;
    double        Spot;
    double        Vol;
    double        r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nStrike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    PayOffCall         thePayOff(Strike);
    VanillaOption      theOption(thePayOff, Expiry);
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    StatisticsMean     gatherer;
    ConvergenceTable   gathererTwo(gatherer);
    SimpleMonteCarlo7(theOption, Spot, VolParam, rParam, NumberOfPaths, gathererTwo);

    vector<vector<double>> results = gatherer.GetResultsSoFar();
    cout << "\nFor the call price the results are \n";
    for (unsigned long i = 0; i < results.size(); i++) {
        for (unsigned long j = 0; j < results[i].size(); j++) cout << results[i][j] << " ";
        cout << "\n";
    }

    double tmp;
    cin >> tmp;

    return 0;
}
