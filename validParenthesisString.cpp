class Solution { 
public:     
    bool checkValidString(string s) {         
        int minOpen = 0;         
        int maxOpen = 0;         

        for (char c : s) {             
            if (c == '(') {                 
                minOpen++;                 
                maxOpen++;                      
            } else if (c == ')') {                 
                minOpen--;                 
                maxOpen--;              
            } else { // c == '*'                 
                minOpen--; // Treat as ')'                 
                maxOpen++; // Treat as '('              
            }              
            
            // If maxOpen is negative, even treating every '*' as '(' couldn't save it
            if (maxOpen < 0) return false;          

            // Reset minOpen to 0 if it drops below 0
            if (minOpen < 0) minOpen = 0;
        }         
        // Valid only if we can fully balance the brackets (min required open is 0)
        return minOpen == 0;      
    } 
};
