class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int x=max(x1,min(x2,xc));//nearest x to cirecle center
        int y=max(y1,min(y2,yc));//nearest t to circle center

        int d1=x-xc;
        int d2=y-yc;
        return ((d1*d1)+(d2*d2))<=(r*r);
    }
};