//
//  main.cpp
//  f-HDU-1233-还是畅通工程
//
//  Created by ZYJ on 2016/10/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;

/*
 * Prim求MST
 * 耗费矩阵cost[][]，初始化为INF，标号从0开始，0 ~ n－1
 * 返回最小生成树的权值，返回-1表示原图不连通
 */

const int INF = 0x3f3f3f3f;
const int MAXN = 110;
bool vis[MAXN];
int lowc[MAXN];
int cost[MAXN][MAXN];

//  修正cost（添加边）
void updata(int x, int y, int v)
{
    cost[x - 1][y - 1] = v;
    cost[y - 1][x - 1] = v;
    return ;
}

int Prim(int cost[][MAXN], int n)   //  0 ~ n - 1
{
    int ans = 0;
    memset(vis, false, sizeof(vis));
    vis[0] = true;
    for (int i = 1; i < n; i++)
    {
        lowc[i] = cost[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        int minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        }
        if (minc == INF)
        {
            return -1;  //  原图不连通
        }
        ans += minc;
        vis[p] = true;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j];
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    int N;
    int A, B, C;
    
    while (cin >> N && N != 0)
    {
        mem(cost, 0x3f);
        mem(vis, 0);
        
        int M = N * (N - 1) / 2;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &A, &B, &C);
            cost[A - 1][B - 1] = cost[B - 1][A - 1] = C;
        }
        
        int ans = Prim(cost, N);
        cout << ans << '\n';
    }
    
    return 0;
}
