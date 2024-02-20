#include <iostream>
#include <vector>

using namespace std;

int Round(float a) 
{
    return (int)(0.5+a);
}

void DDA(int xa, int xb, int ya, int yb, vector<vector<int>>&arr)
{
    int dx = xb - xa;
    int dy = yb - ya;

    int steps;

    float ix, iy, x = xa, y = ya;
    if(abs(dx) > abs(dy)) steps = abs(dx);
    else steps = abs(dy);

    ix = dx/(float)steps;
    iy = dy/(float)steps;

    int interx = round(x);
    int intery = round(y);
    arr[intery][interx] = 1;

    for(int k=0; k<steps; k++)
    {
        x += ix;
        y += iy;
        int iterx = round(x);
        int itery = round(y);
        arr[itery][iterx] = 1;
    }

}
int main()
{
    int n; cin>> n;
    vector<vector<int>> arr(n, vector<int>(n,0));

    cout << "ENTER xa, xb, ya, yb" << endl;
    int xa, xb, ya, yb;
    cin >> xa >> xb >> ya >> yb;

    DDA(xa, xb, ya, yb, arr);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}