#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    string filename(argv[1]);
    int64_t size = stoi(string(argv[2]));

    ofstream lif;
    lif.open(filename, ios::trunc);
    if (!lif.is_open())
    {
        cout << "Open file failed!" << endl;
        return -1;
    }
    srand(time(0));

    int cnt = 0;
    lif << "#Life 1.06\n";
    for (int64_t i = -size; i <= size; i++)
    {
        for (int64_t j = -size; j <= size; j++)
        {
            if (rand() % 2 == 1)
            {
                lif << i << " " << j << "\n";
                ++cnt;
            }
        }
    }
    lif.flush();
    lif.close();

    cout << cnt << endl;

    return 0;
}