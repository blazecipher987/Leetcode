class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }

        return newFunc(n);
    }

    void recurr(int n, int &count){

        if(n==0){
            count++;
            return ;
        }


        recurr(n-1, count);
        if(n>=2)
            recurr(n-2,count);

    }

    int newFunc(int n){

        int base1 = 1;
        int base2 =2;

        n = n-2;

        while(n!=0){
            
            int result = base1+base2;
            base1 =base2;
            base2 = result;

            n--;
        }

        return base2;
    }
};