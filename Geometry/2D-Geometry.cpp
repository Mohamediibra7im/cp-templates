#include<bits/stdc++.h>
using namespace std;
typedef double ld;
typedef long long ll;
const ld EPS = 1e-9;

typedef ld T;
typedef complex<T> pt;
#define x real()
#define y imag()

//////////////////////////////////////////  BASICS   //////////////////////////////////////////
bool operator==(pt a, pt b) { return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS; }
bool operator!=(pt a, pt b) { return !(a == b); }

int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

T sq(pt p) { return p.x * p.x + p.y * p.y; }

ld abs(pt p) { return sqrt(sq(p)); }

pt perp(pt p) { return {-p.y, p.x}; }

T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

bool isPerp(pt v, pt w) { return dot(v, w) == 0; }

//////////////////////////////////////  TRANSFORMIONS   //////////////////////////////////////

// scale point p by a factor around c
pt scale(pt c, T factor, pt p)
{
    return c + (p - c) * factor;
}

// To rotate point p by a certain angle ϕ around center c
pt rot(pt p, pt c, ld a)
{
    pt v = p - c;
    return {c.x + v.x * cos(a) - v.y * sin(a), c.y + v.x * sin(a) + v.y * cos(a)};
}

// point p has image fp, point q has image fq then what is image of point r
pt linearTransfo(pt p, pt q, pt r, pt fp, pt fq)
{
    pt pq = q - p, num{cross(pq, fq - fp), dot(pq, fq - fp)};
    return fp + pt{cross(r - p, num), dot(r - p, num)} / sq(pq);
}

//////////////////////////////////////////  ANGLES   //////////////////////////////////////////

//(AB X AC) --> relative to AB: if(C right) ret neg else if (C left) pos
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

// check p in between angle(bac) counter clockwise
bool inAngle(pt a, pt b, pt c, pt p)
{
    T abp = orient(a, b, p), acp = orient(a, c, p), abc = orient(a, b, c);
    if (abc < 0)
        swap(abp, acp);
    return (abp >= 0 && acp <= 0) ^ (abc < 0);
}

// Get angle between V, W
ld angle(pt v, pt w)
{
    return acos(clamp(dot(v, w) / abs(v) / abs(w), (T)-1.0, (T)1.0));
}

// calc BAC angle
ld orientedAngle(pt a, pt b, pt c)
{
    if (orient(a, b, c) >= 0)
        return angle(b - a, c - a);
    else
        return 2 * M_PI - angle(b - a, c - a);
}

// amplitude travelled around point A, from P to Q
ld angleTravelled(pt a, pt p, pt q)
{
    double ampli = angle(p - a, q - a);
    if (orient(a, p, q) > 0)
        return ampli;
    else
        return -ampli;
}

bool half(pt p)
{
    return p.y > 0 || (p.y == 0 && p.x < 0);
}

//////////////////////////////////////////  LINES   //////////////////////////////////////////

struct line
{
    pt v;
    T c;

    // From direction vector v and offset c
    line(pt v, T c) : v(v), c(c) {}

    // From equation ax+by=c
    line(T a, T b, T _c)
    {
        v = {b, -a};
        c = _c;
    }

    // From points P and Q
    line(pt p, pt q)
    {
        v = q - p, c = cross(v, p);
    }

    // - these work with T = int
    T side(pt p) { return cross(v, p) - c; }
    double dist(pt p) { return abs(side(p)) / abs(v); }
    double sqDist(pt p) { return side(p) * side(p) / (T)sq(v); }
    line perpThrough(pt p) { return {p, p + perp(v)}; }
    bool cmpProj(pt p, pt q)
    {
        return dot(v, p) < dot(v, q);
    }
    line translate(pt t) { return {v, c + cross(v, t)}; }

    // - these require T = double
    line shiftLeft(double dist) { return {v, c + dist * abs(v)}; }
    pt proj(pt p) { return p - perp(v) * side(p) / sq(v); }
    pt refl(pt p) { return p - perp(v) * (T)2.0 * side(p) / sq(v); }
};

// Two lines Intersection
bool inter(line l1, line l2, pt &out)
{
    T d = cross(l1.v, l2.v);
    if (fabs(d) <= EPS)
        return false;
    out = (l2.v * l1.c - l1.v * l2.c) / d; // requires floating-point coordinates
    return true;
}

// Bisector of Two lines (interior da hatl)
line bisector(line l1, line l2, bool interior)
{
    assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
    T sign = interior ? 1 : -1;
    return {l2.v / (T)abs(l2.v) + l1.v / (T)abs(l1.v) * sign,
            l2.c / abs(l2.v) + l1.c / abs(l1.v) * sign};
}

//////////////////////////////////////////  SEGMENTS   //////////////////////////////////////////

bool inDisk(pt a, pt b, pt p)
{
    return dot(a - p, b - p) <= EPS;
}

bool onSegment(pt a, pt b, pt p)
{
    return fabsl(orient(a, b, p)) <= EPS && inDisk(a, b, p);
}

bool properInter(pt a, pt b, pt c, pt d, pt &out)
{
    T oa = orient(c, d, a),
      ob = orient(c, d, b),
      oc = orient(a, b, c),
      od = orient(a, b, d);
    // Proper intersection exists iff opposite signs
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
    {
        out = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}

set<pair<ld, ld>> inters(pt a, pt b, pt c, pt d)
{
    set<pair<ld, ld>> s;
    pt out;
    if (a == c || a == d)
    {
        s.insert(make_pair(a.x, a.y));
    }
    if (b == c || b == d)
    {
        s.insert(make_pair(b.x, b.y));
    }
    if (s.size())
        return s;

    if (properInter(a, b, c, d, out))
        return {make_pair(out.x, out.y)};
    if (onSegment(c, d, a))
        s.insert(make_pair(a.x, a.y));
    if (onSegment(c, d, b))
        s.insert(make_pair(b.x, b.y));
    if (onSegment(a, b, c))
        s.insert(make_pair(c.x, c.y));
    if (onSegment(a, b, d))
        s.insert(make_pair(d.x, d.y));

    return s;
}

ld segPoint(pt a, pt b, pt p)
{
    if (a != b)
    {
        line l(a, b);
        if (l.cmpProj(a, p) && l.cmpProj(p, b)) // if closest to projection
            return l.dist(p);                   // output distance to line
    }
    return min(abs(p - a), abs(p - b)); // otherwise distance to A or B
}

ld segSeg(pt a, pt b, pt c, pt d)
{
    pt dummy;
    if (properInter(a, b, c, d, dummy))
        return 0;
    return min({segPoint(a, b, c), segPoint(a, b, d),
                segPoint(c, d, a), segPoint(c, d, b)});
}

//////////////////////////////////////////  POLYGONS   //////////////////////////////////////////

bool isConvex(vector<pt> p)
{
    bool hasPos = false, hasNeg = false;
    for (int i = 0, n = p.size(); i < n; i++)
    {
        int o = orient(p[i], p[(i + 1) % n], p[(i + 2) % n]);
        if (o > 0)
            hasPos = true;
        if (o < 0)
            hasNeg = true;
    }
    return !(hasPos && hasNeg);
}

ld areaTriangle(pt a, pt b, pt c)
{
    return abs(cross(b - a, c - a)) / 2.0;
}

ld areaPolygon(vector<pt> p)
{
    ld area = 0.0;
    for (int i = 0, n = p.size(); i < n; i++)
    {
        area += cross(p[i], p[(i + 1) % n]); // wrap back to 0 if i == n - 1
    }
    return abs(area) / 2.0;
}

// true if P at least as high as A
bool above(pt a, pt p)
{
    return p.y >= a.y;
}

// check if [PQ] crosses ray from A
bool crossesRay(pt a, pt p, pt q)
{
    return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}

// if strict, returns false when A is on the boundary
bool inPolygon(vector<pt> p, pt a, bool strict = true)
{
    int numCrossings = 0;
    for (int i = 0, n = p.size(); i < n; i++)
    {
        if (onSegment(p[i], p[(i + 1) % n], a))
            return !strict;
        numCrossings += crossesRay(a, p[i], p[(i + 1) % n]);
    }
    return numCrossings & 1; // inside if odd number of crossings
}

//////////////////////////////////////////  CIRCLES   //////////////////////////////////////////

pair<pt, T> circumCircle(pt a, pt b, pt c)
{
    b = b - a, c = c - a;     // consider coordinates relative to A
    assert(cross(b, c) != 0); // no circumcircle if A,B,C aligned
    return {a + perp(b * sq(c) - c * sq(b)) / cross(b, c) / (T)2, abs(perp(b * sq(c) - c * sq(b)) / cross(b, c) / (T)2)};
}

int circleLine(pt o, double r, line l, pair<pt, pt> &out)
{
    double h2 = r * r - l.sqDist(o);
    if (h2 >= 0)
    {                                          // the line touches the circle
        pt p = l.proj(o);                      // point P
        pt h = l.v * (T)(sqrt(h2) / abs(l.v)); // vector parallel to l, of length h
        out = {p - h, p + h};
    }
    return 1 + sgn(h2);
}

int circleCircle(pt o1, T r1, pt o2, T r2, pair<pt, pt> &out)
{
    pt d = o2 - o1;
    T d2 = sq(d);
    if (d2 == 0)
    {
        assert(r1 != r2);
        return 0;
    }                                    // concentric circles
    T pd = (d2 + r1 * r1 - r2 * r2) / 2; // = |O_1P| * d
    T h2 = r1 * r1 - pd * pd / d2;       // = hˆ2
    if (h2 >= 0)
    {
        pt p = o1 + d * pd / d2, h = perp(d) * sqrt(h2 / d2);
        out = {p - h, p + h};
    }
    return 1 + sgn(h2);
}

int tangents(pt o1, T r1, pt o2, T r2, bool inner, vector<pair<pt, pt>> &out)
{
    if (inner)
        r2 = -r2;
    pt d = o2 - o1;
    T dr = r1 - r2, d2 = sq(d), h2 = d2 - dr * dr;
    if (d2 == 0 || h2 < 0)
    {
        assert(h2 != 0);
        return 0;
    }
    for (T sign : {-1, 1})
    {
        pt v = (d * dr + perp(d) * sqrt(h2) * sign) / d2;
        out.push_back({o1 + v * r1, o2 + v * r2});
    }
    return 1 + (h2 > 0);
}

int main()
{
    
    
}