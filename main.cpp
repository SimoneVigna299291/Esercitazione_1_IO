// Esercizio 2 esercitazione 1
#include <iomanip>
#include <fstream>
#include <iostream>

double mapInterval(double N) // funzione che mappa i valori da [1,5] nell'intervallo [-1,2]
{
    return (3./4.)*N-(7./4.); // la funzione ritorna il valore mappato
}

int main()
{
    std::string fileName="data.csv"; //nome del file da aprire
    std::ifstream ifstr(fileName); //apro il file
    if(ifstr.fail()) // controllo esistenza file
    {
        std::cerr << "Il file non esiste." << std::endl;

        return 1;
    }
    std::ofstream outFile("result.csv");
    outFile << "# N mean" << std::endl; // header del file output
    // setto la formattazione dell'output
    outFile << std::setprecision(16);
    outFile.setf(std::ios_base::scientific);
    // inizializzo le variabili
    double val=0.0;
    double mean=0.0;
    double sum=0.0;
    int count=0;

    while(ifstr >> val) // leggo e assegno la riga i-esima alla variabile val
    {
        double map=mapInterval(val); // mappo il valore
        sum+=map;
        count++;
        mean=sum/count; // calcolo la media
        outFile << count << " " << mean << std::endl;

    }
    // chiudo i file
    outFile.close();
    ifstr.close();
    return 0;
}
