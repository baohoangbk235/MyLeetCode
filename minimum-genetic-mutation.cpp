
// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

// Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.

// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

// Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.

// Note that the starting point is assumed to be valid, so it might not be included in the bank.

#include <iostream>
#include <queue>
using namespace std;

class Solution
{ // BFS
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        queue<string> q;
        q.push(start);
        int step = 0;
        vector<int> check(bank.size(), 0);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string temp = q.front();
                q.pop();
                if (temp.compare(end) == 0)
                    return step;
                for (int index = 0; index < bank.size(); index++)
                {
                    if (check[index] == 0 && isMutation(bank[index], temp))
                    {
                        check[index] = 1;
                        q.push(bank[index]);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    bool isMutation(string A, string B)
    {
        int sum = 0;
        for (int i = 0; i < 8; i++)
        {
            if (A[i] != B[i])
                sum++;
        }
        return sum == 1;
    }
};