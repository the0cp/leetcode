class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>s={-1,-1};
        vector<int>a;
        int k=0;
        a=judge(right,left,k);
        int ans=10000;
        for(int i=k+1; i<a.size(); i++){
            if(a[i]-a[i-1]<ans){
                ans=a[i]-a[i-1];
                s[0]=a[i-1];
                s[1]=a[i];
            }
            if(a[i]-a[i-1]==1) break;   
        }
        return s;
    }
    // Sieve of Eratosthenes
    vector<int> judge(int val,int left,int &k){
        vector<int>prime;
        vector<bool>not_prime(val+5);
        for(long long i=2; i<=val; i++){
            if(!not_prime[i]){ 
                prime.push_back(i);
                if(i<left) k++;
            }
            for(long long j=i*i; j<=val; j+=i)  not_prime[j]=1;
        }
        return prime;
    }
};
