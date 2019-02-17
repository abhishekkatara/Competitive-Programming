    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define lld long long int 
     
    int main()
    {   
        //ios::sync_with_stdio(false);
        //cin.tie(NULL);
        int t;
        scanf("%d", &t);
        while(t--)
    {       
            double n,k,uttar;
            scanf("%lf %lf", &n, &k);
            uttar = 2.0 + 2.0*(n-1.0)*(k-1.0)/k;
            printf("%lf\n", uttar);
        }
    } 