#include <iostream>
#include <queue>
using namespace std;

class Solution {
    public:
        int minMutation(string start, string end, vector<string>& bank) {
            queue<string> q;
            q.push(start);
            int step = 0;
            while (!q.empty()){
                for (int i = 0; i < q.size(); i++){
                    string temp = q.front();
                    q.pop();
                    if (temp.compare(end) == 0){
                        return step;
                    }
                    for (auto &element: bank){
                        if (isMutation(element, temp)){
                            q.push(element);
                        }
                    }
                }
                step ++;
            }
        }
        
        bool isMutation(string A, string B){
            int sum = 0;
            for (int i=0; i < 8; i++){
                if (A[i] != B[i]) sum++;
            }
            return sum == 1;
        }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
