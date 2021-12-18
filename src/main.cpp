#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
#include "merge_sort.h"
using namespace std;

int main()
{
    string line;
    ifstream ds_file("input/ds.txt");
    ifstream qry_file("input/qry.txt");
    ofstream output_file ("output/output.txt");

    if (ds_file.is_open())
    {
        while ( getline (myfile,line) )
        {
        cout << line << '\n';
        }
        ds_file.close();
    }
}