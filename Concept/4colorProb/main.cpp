#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  static random_device rd;
  static mt19937_64 gen(rd());

  int n, m, color_num; // n: 행 개수, m: 열 개수, color_num : color 개수
  cin >> n >> m;
  cin >> color_num;
  vector<vector<int>> v(n + 2, vector<int>(m + 2, -1));
  vector<int> color;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      color.clear();
      for (int k = 0; k < color_num; k++)
      {
        if (k != v[i - 1][j] && k != v[i][j - 1])
          color.push_back(k);
      }
      uniform_int_distribution<int>
          dis(0, color.size() - 1);
      v[i][j] = color[dis(gen)];
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}