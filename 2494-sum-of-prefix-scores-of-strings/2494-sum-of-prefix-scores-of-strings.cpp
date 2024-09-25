class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(const string& word: words){
            trie.insert(word);
        }

        vector<int> result;
        result.reserve(words.size());
        for(const string& word : words){
            result.push_back(trie.getPrefixScore(word));
        }

        return result;
    }

private:
    struct TrieNode{
        unordered_map<char, TrieNode*> children;
        int count;
        TrieNode() : count(0) {}
    };

    class Trie {
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode();
        }

        void insert(const string& word){
            TrieNode* node = root;
            for(char c : word){
                if (node->children.find(c) == node->children.end()){
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
                node->count++;
            }
        }

        int getPrefixScore(const string& word){
            TrieNode* node = root;
            int score = 0;
            for(char c : word){
                if(node->children.find(c) == node->children.end()){
                    break;
                }
                node = node->children[c];
                score += node->count;
            }
            return score;
        }
    };
};