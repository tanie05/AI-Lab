#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> G1, G2, G3, G4;
    G1.push_back(95);
    G2.push_back(90);
    G3.push_back(85);
    G4.push_back(80);

    int lr = 60, ur = 100, numN = ur-lr, num[numN], n=0;

    for(int i=0;i<numN;i++)
    {
        num[i] = rand()%(numN+1) + lr;
        cout << num[i] << " ";
    }

    while(1)
    {
        vector<int> S1, S2, S3, S4;
        S1.push_back(G1[n]);
        S2.push_back(G2[n]);
        S3.push_back(G3[n]);
        S4.push_back(G4[n]);

        int sum1=S1[0], sum2=S2[0], sum3=S3[0], sum4=S4[0];
        int n1=1, n2=1, n3=1, n4=1;

        for(int i=0;i<numN;i++)
        {
            if(abs(S1[0]-num[i])<=abs(S2[0]-num[i]) && abs(S1[0]-num[i])<=abs(S3[0]-num[i]) && abs(S1[0]-num[i])<=abs(S4[0]-num[i]))
            {
                S1.push_back(num[i]);
                sum1 += num[i];
                n1++;
                S1[0] = sum1/n1;
            }
            else if(abs(S2[0]-num[i])<=abs(S1[0]-num[i]) && abs(S2[0]-num[i])<=abs(S3[0]-num[i]) && abs(S2[0]-num[i])<=abs(S4[0]-num[i]))
            {
                S2.push_back(num[i]);
                sum2 += num[i];
                n2++;
                S2[0] = sum2/n2;
            }
            else if(abs(S3[0]-num[i])<=abs(S1[0]-num[i]) && abs(S3[0]-num[i])<=abs(S2[0]-num[i]) && abs(S3[0]-num[i])<=abs(S4[0]-num[i]))
            {
                S3.push_back(num[i]);
                sum3 += num[i];
                n3++;
                S3[0] = sum3/n3;
            }
            else
            {
                S4.push_back(num[i]);
                sum4 += num[i];
                n4++;
                S4[0] = sum4/n4;
            }
        }

        if(G1[n]==S1[0] && G2[n]==S2[0] && G3[n]==S3[0] && G4[n]==S4[0])
        {
            cout << "\n\nS1: ";
            for(int i=0;i<S1.size();i++)
            cout << S1[i] << " ";
            cout << "\n\n";

            cout << "S2: ";
            for(int i=0;i<S2.size();i++)
            cout << S2[i] << " ";
            cout << "\n\n";

            cout << "S3: ";
            for(int i=0;i<S3.size();i++)
            cout << S3[i] << " ";
            cout << "\n\n";

            cout << "S4: ";
            for(int i=0;i<S4.size();i++)
            cout << S4[i] << " ";
            cout << "\n\n";

            break;
        }

        
        G1.push_back(S1[0]);
        G2.push_back(S2[0]);
        G3.push_back(S3[0]);
        G4.push_back(S4[0]);
        n++;
    }
}