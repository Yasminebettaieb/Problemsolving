#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define __ ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define ll long long
#define ul unsigned long long int
using namespace std;


struct point{
    long x,y;
    bool operator<(const point &r)const{
        if(x!=r.x)
            return x<r.x;
        return y<r.y;
    }
}v[200000],a[200000],b[200000];

long n,m;
set<point> s;
set<point>b_;
bool right(point &p,point &r,point &q){
    return ((ll)q.x*r.y-(ll)q.y*r.x)-(ll)p.x*(r.y-q.y)+(ll)p.y*(r.x-q.x)<=0;
}
long convexHull(){
    sort(v,v+n);
    long l=0,r;
    for(long i=0;i<n;++i){
        a[l++]=v[i];
        while(l>2 && !right(a[l-3],a[l-2],a[l-1])){
            --l;
            a[l-1]=a[l];
        }
    }
    r=0;
    for(long i=n-1;i>=0;--i){
        b[r++]=v[i];
        while(r>2 && !right(b[r-3],b[r-2],b[r-1])){
            --r;
            b[r-1]=b[r];
        }
    }
    for(long i=r-2;i>0;--i)
        a[l++]=b[i];
    return l;
}

int main(){

    cin >> n ;
    for(long i=0;i<n;++i){
        cin >> v[i].x >> v[i].y;
        s.insert(v[i]);
    }
    cin >> m ;
    for(long i=n;i<n+m;++i)
       {
        cin >> v[i].x >> v[i].y;
        b_.insert(v[i]) ;     }
    n+=m;
    long q=convexHull();
    double res=0.0;
    for(long i=0;i<q;++i)
        if((s.find(a[i])==s.end())||(b_.find(a[i])!=b_.end()) ){
            cout << "NO" << endl ;
            return 0;
        }

    cout << "YES" << endl ;

}
 
