//==>> Method 1 Brute force

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
    {
      if (matrix[i][0] == 0)
        col0 = 0;
      for (int j = 1; j < cols; j++)
        if (matrix[i][j] == 0)
          matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--)
    {
      for (int j = cols - 1; j >= 1; j--)
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
          matrix[i][j] = 0;
      if (col0 == 0)
        matrix[i][0] = 0;
    }
  }
};

//===>>Method 2 optimal approach

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> dummy1(rows, -1), dummy2(cols, -1);
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (matrix[i][j] == 0)
        {
          dummy1[i] = 0;
          dummy2[j] = 0;
        }
      }
    }
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (dummy1[i] == 0 || dummy2[j] == 0)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

//=== >> Method 3 Best Approach

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
    {
      if (matrix[i][0] == 0)
        col0 = 0;
      for (int j = 1; j < cols; j++)
        if (matrix[i][j] == 0)
          matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--)
    {
      for (int j = cols - 1; j >= 1; j--)
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
          matrix[i][j] = 0;
      if (col0 == 0)
        matrix[i][0] = 0;
    }
  }
};