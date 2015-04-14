#include <cstdlib>
#include <iostream>
#include "GAQueen.h"

using namespace std;

int main(int argc, char *argv[])
{
    int total = 0;
    
    int population = 1000;
    int boardLength = 30;
    float mutRate = 0.05;
    int iteration = 50;
    
    CGAQueen gaqueen = CGAQueen(population, iteration, mutRate, boardLength);
    gaqueen.InitialPopulation();
    for(int j=0; j<100; j++){
        for(int i=0;i<population;i++){
            gaqueen.FillArea(i);
            gaqueen.CostMatrix[i] = gaqueen.CostFunc(i);
            total += gaqueen.CostMatrix[i];
        }
        printf("%d\n", total);
        gaqueen.PopulationSort();
        gaqueen.GenerateCrossOverMatrix();
        gaqueen.Mating();
        gaqueen.ApplyMutation();        
    }

    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}