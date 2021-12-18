#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"

#define MAX_NUM 1000000
#define MIN_INT -2147483648

using namespace std;

int main()
{
    string line;
    int data_set[MAX_NUM];
    int data_set_len = 0;
    bool read_data_success = false;

    ifstream ds_file("input/ds.txt");
    ifstream qry_file("input/qry.txt");
    ofstream output_file ("output/output.txt");

    // Read data
    if (ds_file.is_open())
    {
        int i = 0;
        while(getline(ds_file, line) )
        {
            data_set[i] = stoi(line);
            i++;
            data_set_len++;
        }
        ds_file.close();
        read_data_success = true;
    }

    if (!read_data_success)
    {
        cout << "Errors occured when reading input files.\n";
        cout << "Program terminated.\n";
        return 0;
    }

    // initialize BST with the data set
    BST binary_search_tree (data_set, data_set_len);

    if (output_file.is_open())
    {
        if (qry_file.is_open())
        {
            while(getline(qry_file, line) )
            {
                int target = stoi(line.substr(4));
                int temp = binary_search_tree.predecessor_query(target);
                if (temp == MIN_INT)
                {
                    output_file << "no\n";
                }
                else 
                {
                    output_file << temp << '\n';
                } 
            }
            qry_file.close();
        }
        else
        {
            cout << "Errors occured when reading input files.\n";
            cout << "Program terminated.\n";
        }
        output_file.close();
    }
    else
    {
        cout << "Errors occured when opening output files.\n";
        cout << "Program terminated.\n";
    }
    return 0;
}