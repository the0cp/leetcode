class Bank {
private:
    vector<long long> bal;
    int n;
    
    bool isValid(int a){
        return a>0&&a<=n;
    }
public:
    Bank(vector<long long>& balance) {
        bal=balance;
        n=balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!isValid(account1)||!isValid(account2)||bal[account1-1]<money) return false;
        bal[account1-1]-=money;
        bal[account2-1]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!isValid(account))   return false;
        bal[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValid(account)||bal[account-1]<money) return false;
        bal[account-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
