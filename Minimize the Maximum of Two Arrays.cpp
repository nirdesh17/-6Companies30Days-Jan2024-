class Solution {
public:

    int gcd(long long a, long long b)  
    {
        if (!b) return a;
        return gcd(b, a % b);
    }
    int lcm(long long a, long long b) 
    {
        long long temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }
    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long l=1,h=1e17;
        while(h>l+1)
        {
            long long mid=(l+h)>>1;
            if(check(d1,d2,u1,u2,mid))
                h=mid;
            else
                l=mid;
        }

        return l+1;
    }

    bool check(long long d1,long long d2,long long u1, long long u2, long long m)
    {
        long long a=m-(m/d1);// elements not are divisible by d1
        long long b=m-(m/d2);// elements not are divisible by d2
        long long l=lcm(d1,d2);
        long long c=m-(m/d1)-(m/d2)+(m/l);// elements not are divisible by d1 && d2

        if(a>=u1 && b>=u2 && a+b-c>=u1+u2)
            return true;
        else
            return false;
    }
};