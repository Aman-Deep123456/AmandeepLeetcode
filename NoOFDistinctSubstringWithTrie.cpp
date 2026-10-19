class Node{
     public : 
        Node* links[26];

        Node* get(char ch){
            return links[ch-'a'];
        }

        void put(char ch, Node* node){
            links[ch-'a'] = node;
        }

        bool containsKey(char ch){
            return (links[ch-'a'] != NULL);
        }
};

class Solution{	
	public:
		int countDistinctSubstring(string word){
			int cnt = 0;
            Node* root = new Node();
            for(int i=0; i<word.length(); i++){
                Node* node = root;
                for(int j=i; j<word.length(); j++){
                    if(!node->containsKey(word[j])){
                        cnt++;
                        node->put(word[j], new Node());
                    }
                    node = node->get(word[j]);
                }
            }
            return cnt+1;
		}
};