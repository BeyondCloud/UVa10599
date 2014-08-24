/*
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <vector>
int array[10001][2];

using namespace std;
int LIS(vector<int>& s)
{
    // 不得不判斷的特例
    if (s.size() == 0) return 0;

    // 先放入一個數字，免得稍後 v.back() 出錯。
    vector<int> v;
    v.push_back(s[0]);

    for (unsigned int i = 1; i < s.size(); ++i)
    {
        int n = s[i];

        if (n >= v.back())
            v.push_back(n);
        else
            *lower_bound(v.begin(), v.end(), n) = n;
    }

    return v.size();
}
int main()
{
    int cases = 1;
    int array_x , array_y;
    int litter_x,litter_y;
    bool litter_id[10001];
    int point[10001][2];
    while(scanf ( "%d%d" ,  & array_x ,  & array_y ))
    {
           memset(litter_id, 0, sizeof(litter_id));
        int *store = new int [array_x * array_y],count_store =0;
         memset(store, 0, sizeof(store));

     while(scanf ( "%d%d" ,  & litter_x ,  & litter_y )&& litter_x > 0)
        {
                point[count_store][0] = litter_x;
                point[count_store][1] = litter_y;
                count_store++;
        }


         vector<int> count_LIS(count_store );
         for(int i = 0; i < count_store;i++ )
         {
            count_LIS[i] = point[i][0];
         }
        int max_litter = LIS(count_LIS);
         int index = 0;
         int current_data;
         int solution = 0;
         int end_of_lis = 0;
         int *answer = new int [max_litter];
          memset(answer, 0 , sizeof(answer));
         if(max_litter == 1)
         {
              solution = count_store;
              answer[0] = store[0];
         }
         else
         {
              for(int i =0 ; i < count_store-1; i++)
          {
             index = 1;
             current_data = point[i][0];
                for(int j = i + 1 ; j < count_store ; j++)
              {
                        if(point[j][0] >= current_data)
                      {
                          index++;
                          if(index != max_litter)
                          current_data = point[j][0];
                      }
                      if(index == max_litter)
                   {
                       end_of_lis = point[j][0] ;
                       solution++;
                       index--;
                   }

              }
           }
               int answer_index = max_litter;
                    answer_index--;
                   current_data = end_of_lis;
               for(int i = count_store;i >=1;i--)
               {
                   if(point[i-1][0] <= current_data)
                   {
                     answer[answer_index] = point[i-1][1] + (point[i-1][0]-1)*array_y;
                     answer_index--;
                     current_data = point[i-1][0];
                   }
                    if(answer_index == -1)
                    {
                       break;
                    }
               }
           }
                printf("CASE#%d: %d %d", cases++, max_litter, solution);
               for(int i = 0;i < max_litter;i++)
                          printf(" %d", answer[i]);
                        puts("");
                        delete answer;
                        delete store;
       }
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    int i, j, k;
    int x, y;
    bool g[105][105];
    int cases = 0;
    int ret[10005];
    while(scanf("%d %d", &n, &m) && n > 0) {
        memset(g, 0, sizeof(g));
       while(scanf("%d %d", &x, &y)  && x > 0)
            g[x][y] = 1;


        int nextL[105][105], nextD[105][105];
        //build ignore link
        for(i = 1; i <= n; i++) {
            int next = m+1;
            for(j = m; j >= 1; j--) {
                nextL[i][j] = next;
                if(g[i][j]) next = j;
            }
        }
        for(i = 1; i <= n; i++) {

            for(j = 1; j <= m; j++) {
                cout<<nextL[i][j]<<" ";
            }
            cout<<endl;
        }

            cout<<"=============="<<endl;



        for(j = 1; j <= m; j++) {
            int next = n+1;
             for(i = n; i >= 1; i--) {
                nextD[i][j] = next;
                if(nextL[i][j] >= j && nextL[i][j] <= m || g[i][j])
                    next = i;
            }
        }



            for(i = 1; i <= n; i++) {

            for(j = 1; j <= m; j++) {
                cout<<nextD[i][j]<<" ";
            }
            cout<<endl;
            }
        cout<<"=============="<<endl;



        int dp1[105][105] = {}, dp2[105][105] = {};// max, path
        int arg[105][105][2];
        memset(arg, -1, sizeof(arg));
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {

                if(g[i][j] == 0)    continue;
                if(dp1[i][j] == 0)  dp1[i][j] = 1, dp2[i][j] = 1;
                x  = i;
                //printf("%d %d ---- %d %d\n", i, j, dp1[i][j], dp2[i][j]);
                while(x <= n) {
                    if(g[x][j] == 0 || x == i)
                        y = nextL[x][j];
                    else
                        y = j;
                    //printf("%d %d\n", x, y);
                    if(dp1[x][y] < dp1[i][j]+1) {
                        dp1[x][y] = dp1[i][j]+1, dp2[x][y] = 0;
                        arg[x][y][0] = i;
                        arg[x][y][1] = j;
                    }
                    if(dp1[x][y] == dp1[i][j]+1)
                        dp2[x][y] += dp2[i][j];
                    x = nextD[x][j];
                }

                         for(k = 1; k <= n; k++) {

            for(int l = 1; l <= m; l++) {
                cout<<dp1[l][k]<<" ";
            }
            cout<<endl;
            }
        cout<<"=============="<<endl;

        for(k = 1; k <= n; k++) {

            for(int l = 1; l <= m; l++) {
                cout<<dp2[l][k]<<" ";
            }
            cout<<endl;
            }



            }
        }


        int mx = 0, path;
        int rx, ry;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                if(dp1[i][j] > mx)
                    mx = dp1[i][j], path = 0, rx = i, ry = j;
                if(dp1[i][j] == mx)
                    path += dp2[i][j];
            }
        }
        int idx = 0;
        while(rx != -1 && ry != -1) {
            ret[idx++] = (rx-1)*m+(ry-1)+1;
            x = arg[rx][ry][0];
            y = arg[rx][ry][1];
            rx = x, ry = y;
        }
        printf("CASE#%d: %d %d", ++cases, mx, path);
        for(i = idx-1; i >= 0; i--)
            printf(" %d", ret[i]);
        puts("");
    }
  return 0;
}
*/
#include <stdio.h>
#include <string.h>
const  int  N = 105;
const  int  MAX = 10005;

int  row, col, n, dp[MAX], cnt[MAX], rec[MAX], flag, map[N][N];
int  g[MAX];


void  init() {
    int  a, b;
    memset(map, 0,  sizeof (map));
    while  (scanf( "%d%d" , &a, &b), a && b) {
        map[a][b] = 1;
    }

    n = 0;
    memset(g, 0,  sizeof (g));
    for  ( int  i = 1; i <= row; i++) {
        for  ( int  j = 1; j <= col; j++)
            if  (map[i][j])
                g[n++] = (i - 1) * col + j - 1;
    }

    if  (g[n - 1] != row * col - 1)
        g[n++] = row * col - 1;
}

void  solve() {

    for  ( int  i = 0; i < n; i++) {
        dp[i] = 1, cnt[i] = 1, rec[i] = -1;
        for  ( int  j = 0; j < i; j++)
        {
            if  ((g[j] % col) <= (g[i] % col)) //if the sequence is LIS
            {
                if  (dp[i] == dp[j] + 1)      //if we get only one more step to current state
                    cnt[i] += cnt[j];         //let total solution + 1
                else  if  (dp[i] < dp[j] + 1)  //if we get more or  one step  current state
                    dp[i] = dp[j] + 1, cnt[i] = cnt[j], rec[i] = j; //rec: record the path
            }
        }
    }
    if  (!map[row][col])
        dp[n - 1]--;
}

void  put( int  cur) {
    if  (rec[cur] != -1)
        put(rec[cur]);
    if  (cur != n - 1 || map[row][col])
        printf( " %d" , g[cur] + 1);
}

int  main () {
    int  cas = 1;
    while  (scanf( "%d%d" , &row, &col) == 2) {
        if  (row == -1 && col == -1)  break ;
        init();
        solve();
        printf( "CASE#%d: %d %d" , cas++, dp[n - 1], cnt[n - 1]);
        put(n - 1);
        for(int i = 0;i<n;i++)
            printf( "  %d" ,rec[i] );
        printf( "\n" );
    }
    return  0;
}
