#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point
{
	int x;
	int y;
};

int getDist(Point p1, Point p2)
{
	int xd = abs(p1.x - p2.x);
	int yd = abs(p1.y - p2.y);
	return max(xd, yd);
}

int numDiag(Point p1, Point p2)
{
	return min(abs(p1.x-p2.x), abs(p1.y-p2.y));
}

void move(Point cur, Point next, vector<Point>& path, vector<vector<int> >& costGrid)
{
	int diaMove = numDiag(cur, next);
	while(diaMove >= 0) {
		if (cur.x > next.x && cur.y > next.y)
		{
			cur.x--;
			cur.y--;
			path.push_back(cur);
		}
		else if (cur.x < next.x && cur.y > next.y)
		{
			cur.x++;
			cur.y--;
			path.push_back(cur);
		}
		else if (cur.x > next.x && cur.y < next.y)
		{
			cur.x--;
			cur.y++;
			path.push_back(cur);
		}
		else if (cur.x < next.x && cur.y < next.y)
		{
			cur.x++;
			cur.y++;
			path.push_back(cur);
		}
		diaMove--;
	}
	while (cur.x > next.x)
	{
		cur.x--;
		path.push_back(cur);
	}
	while (cur.y > next.y)
	{
		cur.y--;
		path.push_back(cur);
	}
	while (cur.x < next.x)
	{
		cur.x++;
		path.push_back(cur);
	}
	while (cur.y < next.y)
	{
		cur.y++;
		path.push_back(cur);
	}
}

void getMoney(vector<string> typeGrid,
              vector<vector<int> > costGrid)
{
  /* Enter your code here. Print output to STDOUT */
	Point S;
	vector<Point> Bs;
	vector<Point> Cs;
	for (int i = 0; i < typeGrid.size(); ++i)
	{
		for (int j = 0; j < typeGrid[i].size(); ++j)
		{
			if (typeGrid[i][j] == 'S')
			{
				S.y = i; S.x = j;
			} else if (typeGrid[i][j] == 'C') {
				Cs.push_back(Point{j,i});
			} else if (typeGrid[i][j] == 'B') {
				Bs.push_back(Point{j,i});
			}
		}
	}

	std::vector<Point> path;
	Point cur = S;
	path.push_back(cur);
	std::vector<bool> collected(Cs.size(), false);
	int numCollected = 0;
	while (numCollected != Cs.size()) {
		Point next;
		int approx_min = INT_MAX;
		int min_index = -1;
		for (int i = 0; i < Cs.size(); ++i)
		{
			if (!collected[i])
			{
				int dist = getDist(cur, Cs[i]);
				if (dist < approx_min)
				{
					approx_min = dist;
					next = Cs[i];
					min_index = i;
				}
			}
		}

		move(cur, next, path, costGrid);
		collected[min_index] = true;
		numCollected++;
		cur = next;
	}

	int dist1 = getDist(cur, Bs[0]);
	int dist2 = getDist(cur, Bs[1]);
	Point final = dist1 < dist2 ? Bs[0] : Bs[1];
	move(cur, final, path, costGrid);

	for (int i = 0; i < path.size(); ++i)
	{
		cout << path[i].x << ',' << path[i].y << endl;
	}
}

int main() {
  string gridLine(25, '.');
  vector<string> typeGrid(25, gridLine);
  
  vector<int> costLine(25);
  vector<vector<int> > costGrid(25, costLine);
  
  string line;
  while (getline(cin, line)) {
    int comma1 = line.find(',', 0);
   	int comma2 = line.find(',', comma1 + 1);
   	int comma3 = line.find(',', comma2 + 1);
    
    char type = line[0];
    int x = atoi(line.c_str() + comma1 + 1);
    int y = atoi(line.c_str() + comma2 + 1);
    typeGrid[y][x] = type;
    
    int cost = 1;
    if (type == 'O') {
      cost = atoi(line.c_str() + comma3 + 1);
    }
    costGrid[y][x] = cost;
  }
      
  getMoney(typeGrid, costGrid);

  return 0;
}