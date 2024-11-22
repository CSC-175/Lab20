#include <iostream>
#include <fstream>
using namespace std;


int main() {
    char rowLabel[5] = {'F','E','D','C','B'};//ascii value for E which is first row map
    int colLabel[6] = {7,6,5,4,3, 2};// 7 is the first column of map
    int map[6][7];
    int peak=0, valley=0;
    ifstream dataIn;

    //cout<<"CSC 175\nLab21\nBrian McBride\n\n";
    string fileName;
    cout << "Enter the map file to read: ";
    cin >> fileName;
    cout << fileName << endl;
    dataIn.open(fileName.c_str());
    if (dataIn.fail())
    {
        cout << "Failed to open data file!" << endl;
        exit(1);
    }
    for (int row=0; row<6; row++)
    {
        for (int col=0; col<7; col++)
        {
            dataIn >> map[row][col];
        }
    }

    dataIn.close();

    for (int row=4; row>0; row--)
    {
        for (int col=5; col>0; col--)
        {
            if(map[row-1][col] < map[row][col] and
               map[row][col+1] < map[row][col] and
               map[row+1][col] < map[row][col] and
               map[row][col-1] < map[row][col] )
            {
                peak++;
                cout << "Peak " << peak << " is at coordinate " << rowLabel[row] <<  colLabel[col] << endl;
            }
        }
    }
    cout << endl;
    for (int row=4; row>0; row--)
    {
        for (int col=5; col>0; col--)
        {
            if(map[row-1][col] > map[row][col] and
               map[row][col+1] > map[row][col] and
               map[row+1][col] > map[row][col] and
               map[row][col-1] > map[row][col] )
            {
                valley++;
                cout << "Valley " << valley << " is at coordinate " << rowLabel[row] <<  colLabel[col] << endl;
            }
        }
    }
    cout << "\n\n\n";
    return 0;
}
