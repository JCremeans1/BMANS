#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <time.h>
#include <numeric>
#include <algorithm>
#include <assert.h>
#include <conio.h>



using namespace std;

class agent
{
public:
    vector<double> archivex;
    vector<double> archivey;
    vector<double> evaluationx;
    vector<double> evaluationy;
    vector<double> noveltyofx;
    vector<double> noveltyofy;
    vector<double> noveltyvector;
    double novelty;

    void initialize();
    void evaluate();
    void print();

};

int points = 2;
int valx;
int valy;
int evalx;
int evaly;
int evaltotal;
double evalxtotal = 0;
double evalytotal = 0;
double sumx = 0;
double sumy = 0;

vector<agent>agents(2);

void agent::initialize()
{
    archivex.clear();
    archivey.clear();
    for (int j = 0; j < points; j++)
    {
        valx = (rand() % 10 + 1);
        archivex.push_back(valx);

        valy = (rand() % 10 + 1);
        archivey.push_back(valy);
    }
    cout << "X and Y point pushed back: " << endl;
    cout << " " << endl;
    for(int i = 0; i < points; i++)
    {
        cout << "X value: " << i << " is " << archivex.at(i) << endl;
        cout << " " << endl;
        cout << "Y value: " << i << " is " << archivey.at(i) << endl;
        cout << " " << endl;
    }
}

void agent::print()
{



}

void agent::evaluate()
{

    for (int i = 0; i < points; i++)
    {
        for  (unsigned int j =0; j < i; j++)
        {

            for(unsigned int m = 0; m < agents.size(); m++)
            {
                int p;
                p = (rand() % agents[m].archivex.size());

                cout << " " << endl;
                cout << "The current vector element selected: " << p << endl;

                evalx = abs(archivex.at(i)- agents[m].archivex.at(j));
                evalxtotal = evalxtotal + evalx;
                cout << " " << endl;
                cout << "Evalx = " << evalx << endl;
                getch();


                int q;
                q = (rand() % agents[m].archivey.size());

                cout << " " << endl;
                cout << "The current vector element selected: " << q << endl;

                evaly = abs(archivey.at(i) - agents[m].archivey.at(j));
                evalytotal = evalytotal + evaly;


            }

        }
            noveltyofx.push_back(evalxtotal);
            noveltyofy.push_back(evalytotal);
    }

    sumx = accumulate(noveltyofx.begin(), noveltyofx.end(), 0.0);
    sumy = accumulate(noveltyofy.begin(), noveltyofy.end(), 0.0);
    novelty = sumx+sumy;

    noveltyvector.push_back(novelty);

    cout << " " << endl;
    cout << "Novelty: "<< novelty << endl;

}

void agentcreation()
{

    for (unsigned int m = 0; m < agents.size(); m++)
    {
        agents[m].initialize();
    }

    for (unsigned int i = 0; i < agents.size(); i++)
    {
        evalx = 0;
        evaly =0;
        evaltotal = 0;
        evalxtotal = 0;
        evalytotal = 0;

        agents[i].evaluate();
        agents[i].print();

        cout << " " << endl;
        cout << "End of Run: " << i << endl;
        cout << " " << endl;
    }

}

int main()
{
    srand(time(NULL));

    cout << "Program Initialization:" << endl;
    cout << " " << endl;

    agentcreation();

    cout << " " << endl;
    cout << "Done"<< endl;

    return 0;
}
