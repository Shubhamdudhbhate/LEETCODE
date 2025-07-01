#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution
{

public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    int r;
    int c;

    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j < c;
    }

    int CovidSpread(vector<vector<int>> Hospital)
    {

        r = Hospital.size();
        c = Hospital[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++)
        {

            for (int j = 0; j < c; j++)
            {

                if (Hospital[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }

        int timer = 0;

        while (!q.empty())
        {
            bool infected = false;
            int curr_patient = q.size();

            while (curr_patient--)
            {

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++)
                {

                    if (valid(i + row[k], j + col[k]) && Hospital[i + row[k]][j + col[k]] == 1)

                    {

                        Hospital[i + row[k]][j + col[k]] = 2;
                        q.push(make_pair(i + row[k], j + col[k]));
                        infected = true;
                    }
                }

                // // up
                // if (Hospital[i - 1][j] == 1)
                // {

                // }

                // // down
                // if (Hospital[i + 1][j] == 1)
                // {
                // }

                // // left
                // if (Hospital[i][j - 1] == 1)
                // {
                // }

                // // right
                // if (Hospital[i][j + 1] == 1)
                // {
                // }
            }

            if (infected)
            {

                timer++;
            }
        }



        for (int i = 0; i < r; i++)
        {

            for (int j = 0; j < c; j++)
            {
                if (Hospital[i][j] == 1)
                {

                    return -1;
                }
            }
        }

        return timer;
    }
};

int main()
{   
    Solution obj;

    vector<vector<int>> hospital = {
        {2, 2 , 2, 2},
        {2, 2 , 2, 2},
        {2, 2 , 2, 2},
        {2, 2 , 2, 2}

    
    };

    int timeRequired = obj.CovidSpread(hospital);

    if (timeRequired == -1)
        cout << "Not all people can be infected." << endl;
    else
        cout << "Time required to infect everyone: " << timeRequired << endl;

    return 0;
}
