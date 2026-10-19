class Node{
    public : 
    Node* links[26];
    bool flag = false;

     Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    bool containsKey(char ch){
        return(links[ch-'a'] != NULL);
    }
    
    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
        Node* root;

    public:
       Trie(){
         root = new Node();
       }

      void insert(string  word){
         Node* node = root;
         for(int i=0; i<word.size(); i++){
             if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
             }
             node = node->get(word[i]);
         }       
         node->setEnd();
       }
     
     bool checkIfAllPrefixExists(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                if(!node->isEnd()){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
     }
};

class Solution {
public:
    string completeString(vector<string>& nums) {
        //your code goes here
      Trie trie;

      for(auto it: nums){
           trie.insert(it);
      }
      string longest = "";
      for(int i=0; i<nums.size(); i++){
        if(trie.checkIfAllPrefixExists(nums[i])){
            if(longest.size() < nums[i].size()){
                longest = nums[i];
            }
            else if(nums[i].size() == longest.size() && nums[i]<longest){
                longest = nums[i];
            }
        }
      }
      return longest.empty() ? "None":longest;
    }
};