#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int x[62] = {0, 2, 1, 22, 2, 1, 3, 5, 9, 15, 8, 10, 10, 11, 10, 14, 20, 25, 27, 58, 78, 69, 94, 74, 86, 73, 153, 136, 120, 187, 309, 424, 486, 560, 579, 609, 484, 573, 565, 813, 871, 854, 758, 1243, 1031, 886, 1061, 922, 1371, 1580, 1239, 1537, 1292, 1667, 1408, 1835, 1607, 1568, 1902, 1705, 1801, 2391};

    // 1. Average, variance and Standard Deviation
    int avg = 0, var = 0, sD = 0;
    for(int i=0;i<62;i++)
        avg += x[i];

    avg = avg / 62;

    for(int i=0; i<62; i++)
        var += (x[i] - avg)*(x[i] - avg);

    var = var/62;

    sD = pow(var, 1/2);

    cout << "Average: " << avg;
    cout << "\nVariance: " << var;
    cout << "\nStandard Deviation: " << sD;



    cout << "\n----------------------------------------\n";



    // 2. Gradient and Laplacian of data
    int gradient[61], laplacian[60];
    for(int i=1;i<62;i++)
        gradient[i-1] = x[i] - x[i-1];

    for(int i=1;i<61;i++)
        laplacian[i-1] = gradient[i] - gradient[i-1];

    cout << "Gradient: ";
    for(int i=0;i<61;i++)
        cout << gradient[i] << " ";

    cout << "\nLaplacian: ";
    for(int i=0;i<60;i++)
        cout << laplacian[i] << " ";
    


    cout << "\n----------------------------------------\n";



    // 3. Smoothening
    int filter[5] = {-4, -2, 1, 2, 4}, xT[62];

    xT[0] = x[1]*filter[0] + x[0]*filter[1] + x[0]*filter[2] + x[1]*filter[3] + x[2]*filter[4];
    xT[1] = x[0]*filter[0] + x[0]*filter[1] + x[1]*filter[2] + x[2]*filter[3] + x[3]*filter[4];

    for(int i=2;i<60;i++)
    {
        xT[i] = x[i-2]*filter[0] + x[i-1]*filter[1] + x[i]*filter[2] + x[i+1]*filter[3] + x[i+2]*filter[4];
    }

    xT[60] = x[58]*filter[0] + x[59]*filter[1] + x[60]*filter[2] + x[61]*filter[3] + x[61]*filter[4];
    xT[61] = x[59]*filter[0] + x[60]*filter[1] + x[61]*filter[2] + x[61]*filter[3] + x[60]*filter[4];


    cout << "Smoothening: ";
    for(int i=0;i<62;i++)
        cout << xT[i] << " ";



    cout << "\n----------------------------------------\n";


    // 4. Moving Average
    float b = 0.9;
    int movAvg[63];
    movAvg[0] = 0;

    for(int i=1;i<63;i++)
        movAvg[i] = b*x[i-1] + (1-b)*movAvg[i-1];

    cout << "Moving Average: ";
    for(int i=1;i<63;i++)
        cout << movAvg[i] << " ";



    cout << "\n----------------------------------------\n";



    // 5. Mean Score Normalization and Adam optimization
    float xMSN[62], xAD[62], a = 0.01, e = 0.1; 
    int m = x[0], M = x[0];

    for(int i=0;i<62;i++)
    {
        m = min(m, x[i]);
        M = max(M, x[i]);
    }

    for(int i=0;i<62;i++)
    {
        xMSN[i] = float(abs(x[i] - avg))/(M - m);
    }

    cout << "Mean Score Normalization: ";
    for(int i=0;i<62;i++)
        cout << xMSN[i] << " ";

    

    for(int i=0;i<62;i++)
    {
        if(i==0)
        xAD[0] = x[0] - a*(gradient[0]/(pow(laplacian[0],1/2) + e));
        else if(i==61)
        xAD[61] = x[61] - a*(gradient[60]/(pow(laplacian[59],1/2) + e));
        else
        xAD[i] = x[i] - a*(gradient[i-1]/(pow(laplacian[i-1],1/2) + e));
    }

    cout << "\nAdam Optimization: ";
    for(int i=0;i<62;i++)
        cout << xAD[i] << " ";

    

    return 0;
}      