int reverse(int x){
   long  int rev=0;
    
    while(x!=0)
    {
    int n=x%10;
   if(rev>INT_MAX/10||rev<INT_MIN/10)
    {
        return 0;
        }
     rev=rev*10+n;
    x=x/10;
    }
   

return rev;
}
// Brute Force Approach
/**
int reverse(int x) {
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        if (reversed > (INT_MAX - digit) / 10 || reversed < (INT_MIN - digit) / 10) {
            return 0; 
        }

        reversed = reversed * 10 + digit;
    }

    return reversed;
}**/