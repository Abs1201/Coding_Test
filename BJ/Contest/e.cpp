#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int N,A,B,C,D;

struct Point{
    ll x, 
    ll y;
}

bool compare(Point a, Point b){
    return a.y < b.y;
}

ll getSum(int p, int s, int e, int N){
    ll sum=0;
    for(int i=0; i<=N; i++){
        sum += 
    }
}

int main() {
    cin >> N >> A >> B >> C>> D;
    vector<Point> points(N);
    for(int i=0; i<N; i++){
        cin >> points[i].x >> points[i].y;
    }

    //x
    sort(points.begin(), points.end());
    ll s = points.begin() -> x;
    ll e = points.rbegin()->x;
    ll midX =s;
    ll sumX = getSum(s, s, e, N);
    for(ll i=s; i<=e; i++){

    }

    //y
    sort(points.begin(), points.end(), compare);



    return 0;
}
