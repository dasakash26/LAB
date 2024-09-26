#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <vector>
using namespace std;
#define device 10
#define rng 20

class Position
{
protected:
    int x, y, z;

public:
    Position(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    int dist(Position p)
    {
        return sqrt((pow((x - p.x), 2) + pow((y - p.y), 2) + pow((z - p.z), 2)));
    }
    int cngPosition()
    {
        x = rand() % 100;
        y = rand() % 100;
        z = rand() % 100;
    }
};

class Transmitter : public Position
{
    int tId, range;

public:
    Transmitter(int x, int y, int z, int tId, int range) : Position(x, y, z)
    {
        this->tId = tId;
        this->range = range;
    }
    int getTid()
    {
        return tId;
    }
    int getRange()
    {
        return range;
    }
    void printInfo()
    {
        cout << "Transmitter Id: " << tId << ' ' << " Position: (" << x << ", " << y << ", " << z << ')' << endl;
    }
};

int main()
{
    srand(time(0));
    vector<Transmitter> t;

    cout << "----------- Initializing transmitters -------------" << endl
         << endl;
    for (int i = 0; i < device; i++)
    {
        t.push_back(Transmitter(rand() % 100, rand() % 100, rand() % 100, i, rng));
        t[i].printInfo();
    }
    for (int i = 0; i < device; i++)
    {
        for (int j = 0; j < device; j++)
        {
            if (i == j)
                continue;
            if (t[i].dist(t[j]) <= t[i].getRange())
            {
                cout << "Device " << i << " is in range of device " << j << endl;
            }
        }
    }
    cout << endl;

    cout << "---------- Changing transmitter positions ----------" << endl
         << endl;
    for (int i = 0; i < device; i++)
    {
        t[i].cngPosition();
        t[i].printInfo();
    }
    for (int i = 0; i < device; i++)
    {
        for (int j = 0; j < device; j++)
        {
            if (i == j)
                continue;
            if (t[i].dist(t[j]) <= t[i].getRange())
            {
                cout << "Device " << i << " is in range of device " << j << endl;
            }
        }
    }
    cout << endl;
}
