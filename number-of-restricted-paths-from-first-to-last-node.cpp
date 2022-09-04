
// There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.

// A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.

// The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.

// Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> gp;
        for (auto &edge: edges){
            gp[edge[0]].push_back({edge[1], edge[2]});
            gp[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii> > pq; 
        pq.push({0, n});
        dist[n] = 0;

        int u, v, w;
        while( !pq.empty()){
            pii p = pq.top(); pq.pop();
            u = p.second;
            for (auto &to: gp[u]){
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<int> dp(n+1, -1);
        return dfs(gp, n, dp, dist);
    }

    int dfs(unordered_map<int, vector<pii>> &gp, int s, vector<int> &dp, vector<int> &dist){
        int mod = 1e9+7;
        if (s == 1) return 1;
        if (dp[s] != -1) return dp[s];
        int sum = 0, weight, val;
        for (auto& n: gp[s]){
            weight = dist[s];
            val = dist[n.first];
            if (val > weight){
                sum = (sum % mod + dfs(gp, n.first, dp, dist) % mod) % mod;
            }
        }
        return dp[s] = sum % mod;
    }
};