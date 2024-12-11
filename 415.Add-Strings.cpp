class Solution {
public:
    string addStrings(string num1, string num2) {
        string res="";
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        while(i>=0 || j>=0 || carry>0){
            int n1=i>=0?num1[i]-'0':0;
            int n2=j>=0?num2[j]-'0':0;
            int sum=n1+n2+carry;
            carry=sum/10;
            sum=sum%10;
            res+=to_string(sum);
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
