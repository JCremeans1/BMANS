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
#include <stdlib.h>

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

int points = 10;
double valx;
double valy;
double evalx;
double evaly;
double evaltotal;
double evalxtotal = 0;
double evalytotal = 0;
double sumx = 0;
double sumy = 0;


vector<agent>agents(5);



void agent::initialize(int range)
{
    if(range==1){
    fstream fs;
    fs.open ("Novelty_Points.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    archivex.clear();
    archivey.clear();
    for (int j = 0; j < points; j++)
    {
        valx = 0.0 + ((double)(rand())/ double((RAND_MAX)) * (10.0 - 0.0) );
        archivex.push_back(valx);

        fs << valx << " \t";

        valy = 0.0 + ((double)(rand())/ double((RAND_MAX)) * (10.0 - 0.0) );
        archivey.push_back(valy);

        fs << valy << " \n";

    }
    cout << "X and Y point pushed back: " << endl;
    cout << " " << endl;
    for(int i = 0; i < points; i++)
    {
        //cout << "X value: " << i << " is " << archivex.at(i) << endl;
        //cout << " " << endl;
        //cout << "Y value: " << i << " is " << archivey.at(i) << endl;
        //cout << " " << endl;
    }

    fs << " " << "\n";
    fs.close();
    }
    else{

    }
}

void agent::evaluate()
{

    fstream fr;
    fr.open ("Novelty_Vector.txt", std::fstream::in | std::fstream::out | std::fstream::app);

     //for (int i = 0; i < points; i++)
     //{
    for(unsigned int m = 0; m < agents.size(); m++)
    {
        for  (unsigned int j =1; j < archivex.size(); j++)
        {

            int p;
            p = (rand() % agents[m].archivex.size());

            //cout << " " << endl;
            //cout << "The current vector element selected: " << p << endl;

            evalx = abs(archivex.at(j)- agents[m].archivex.at(j-1));
            evalxtotal = evalxtotal + evalx;

            int q;
            q = (rand() % agents[m].archivey.size());

            //cout << " " << endl;
            //cout << "The current vector element selected: " << q << endl;

            evaly = abs(archivey.at(j) - agents[m].archivey.at(j-1));
            evalytotal = evalytotal + evaly;


    noveltyofx.push_back(evalxtotal);
    noveltyofy.push_back(evalytotal);

    sumx = accumulate(noveltyofx.begin(), noveltyofx.end(), 0.0);
    sumy = accumulate(noveltyofy.begin(), noveltyofy.end(), 0.0);
    novelty = (sumx+sumy)/(agents.size() * points * points);


    noveltyvector.push_back(novelty);
    //fr << noveltyvector.at(j-1) << " \n";


        }

    }

//}



    for (unsigned int r  = 0; r < noveltyvector.size(); r++)
    {
        cout << " " << endl;
        cout << "Novelty Vector Element: " << r << " is " << noveltyvector.at(r) << endl;
    }

    fr << novelty << "\n";
    fr << " " << "\n";
    fr.close();
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

        cout << " " << endl;
        cout << "End of Run: " << i << endl;
        cout << " " << endl;
    }

}

int main()
{

    cout << "Program Initialization:" << endl;
    cout << " " << endl;
    _sleep(2000);

    fstream fs;

    fs.open ("Novelty_Points.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
    fs.clear();
    fs.close();

    fs.open ("Novelty_Vector.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
    fs.clear();
    fs.close();

    srand(time(NULL));

    for (int i = 0; i < 1; i++)
    {
        agentcreation();
    }

    cout << " " << endl;
    cout << "Done"<< endl;

    return 0;
}
