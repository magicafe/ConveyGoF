#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    string filename(argv[1]);
    int64_t size = strtoll(argv[2], nullptr, 10);

    ofstream lif;
    lif.open(filename, ios::trunc);
    if (!lif.is_open())
    {
        cout << "Open file failed!" << endl;
        return -1;
    }
    srand(time(0));

    double step = 0;
    int64_t cnt = 0;
    lif << "#Life 1.06\n";
    for (int64_t i = -size; i <= size; i++)
    {
        for (int64_t j = -size; j <= size; j++)
        {
            if (rand() % 50 == 1)
            {
                lif << i << " " << j << "\n";
                ++cnt;
            }
        }

        if ((i / (double)size + 1 - step) >= 0.1)
        {
            step += 0.1;
            cout << step << endl;
        }
    }
    lif.flush();
    lif.close();

    cout << cnt << endl;

    return 0;
}