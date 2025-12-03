class Solution {
public:
    template<typename T>
    static inline void hash_combine(size_t &seed, const T &val){
        seed^=hash<T>()(val)+0x9e3779b9+(seed<<6)+(seed>>2);
    }

    template<typename T>
    static inline void hash_val(size_t &seed, const T &val){
        hash_combine(seed, val);
    }

    template<typename T, typename... Types>
    static inline void hash_val(size_t &seed, const T &val, const Types &... args){
        hash_combine(seed, val);
        hash_val(seed, args...);
    }

    template<typename... Types>
    static inline size_t hash_val(const Types&... args){
        size_t seed=0;
        hash_val(seed, args...);
        return seed;
    }

    struct pair_hash{
        template<class T1, class T2>
        size_t operator()(const pair<T1, T2>&p) const{
            return hash_val(p.first, p.second);
        }
    };

    pair<int,int> getSlope(int dx, int dy){
        if(dx==0&&dy==0)    return {0,0};
        if(dx==0)   return {0,1};
        if(dy==0)   return {1,0};
        int gcd=std::gcd(abs(dx),abs(dy));
        dx/=gcd;
        dy/=gcd;
        if(dx<0){
            dx=-dx;
            dy=-dy;
        }
        return {dx,dy};
    }

    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        if(n<4) return 0;
        unordered_map<pair<int,int>, unordered_map<long long, int>, pair_hash>mp;
        unordered_map<pair<int,int>, unordered_map<long long, unordered_map<long long, int>>, pair_hash> lenMp;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];
                pair<int,int>slope=getSlope(dx, dy);
                long long intercept=(long long)slope.first*points[i][1]-(long long)slope.second*points[i][0];
                long long lenSq=(long long)dx*dx+(long long)dy*dy;
                mp[slope][intercept]++;
                lenMp[slope][lenSq][intercept]++;
            }
        }
        long long ans=0;
        long long para=0;

        for(auto&[slope, lines]:mp){
            if(lines.size()<2)  continue;
            int totalSeg=0;
            for(auto&[intercept, cnt]:lines)    totalSeg+=cnt;
            for(auto&[intercept, cnt]:lines)    ans+=cnt*(totalSeg-cnt);
        }
        for(auto&[slope, len_map]:lenMp){
            for(auto&[len, lines]:len_map){
                if(lines.size()<2) continue;
                long long totalSeg=0;
                for(auto&[intercept, cnt]:lines)    totalSeg+=cnt;
                for(auto&[intercept, cnt]:lines)    para+=(long long)cnt*(totalSeg-cnt);
            }
        }
        return (ans-para/2)/2;
    }
};
