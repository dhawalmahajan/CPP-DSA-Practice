/*
Aterp is the head nurse at a city hospital.City hospital contains R *C number
of wards and the structure of a hospital is in the form of a 2 -
D matrix.Given a matrix of dimension R *C where each cell in the matrix can
have values 0,
1, or 2 which has the following meaning : 0 : Empty ward 1
: Cells have uninfected patients 2
: Cells have infected patients

An infected patient at ward[i, j] can infect other uninfected patient
at indexes[i - 1, j],
[ i + 1, j ], [ i, j - 1 ],
[ i, j + 1 ](up, down, left and right) in unit time
.Help Aterp determine the minimum units of time after which there won't
remain any uninfected patient i.e all patients would be infected. If all
patients are not infected after infinite units of time then simply return -1.
*/
#include <bits/stdc++.h>
using namespace std;
int r, c;
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool valid(int i, int j) { return i >= 0 && i < r && j >= 0 && j < c; }
int helpaterp(vector<vector<int>> hospital) {
  // code here
  r = hospital.size();
  c = hospital[0].size();
  int timer = 0;
  queue<pair<int, int>> q;
  bool hasInfected = false;
  bool hasUninfected = false;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (hospital[i][j] == 2) {
        hasInfected = true;
        q.push(make_pair(i, j));
      }
      if (hospital[i][j] == 1) {
        hasUninfected = true;
      }
    }
  }
  // If there are no uninfected patients, return 0
  if (!hasUninfected) {
    return 0;
  }

  // If there are uninfected patients but no infected patients, return -1
  if (!hasInfected) {
    return -1;
  }

  while (!q.empty()) {
    timer++;
    int curr_patient = q.size();
    while (curr_patient--) {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();

      for (int k = 0; k < 4; k++) {
        if (valid(i + row[k], j + col[k]) &&
            hospital[i + row[k]][j + col[k]] == 1) {
          hospital[i + row[k]][j + col[k]] = 2;
          q.push(make_pair(i + row[k], j + col[k]));
        }
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (hospital[i][j] == 1) {
        return -1;
      }
    }
  }
  return timer - 1;
}

int main() {
  cout << "Enter the number of rows and columns: ";
  cin >> r >> c;
  vector<vector<int>> hospital(r, vector<int>(c));
  cout << "Enter the matrix (0 for empty, 1 for uninfected, 2 for infected): ";
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> hospital[i][j];
    }
  }
  int result = helpaterp(hospital);
  cout << "Minimum time to infect all patients: " << result << endl;
  return 0;
}