/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */

class Trie {

    Trie[] children;
    boolean isEnd;
    long wordCount = 0;

    /** Initialize your data structure here. */
    public Trie() {
        this.children = new Trie[26];
        this.isEnd= false;
        this.wordCount = 0;
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        if(word.length() == 0){
            return;
        }else{
            Trie iterator = this;
            for(int iter = 0;iter< word.length(); iter++){
                if(iterator.children[word.charAt(iter) - 'a'] == null){
                    iterator.children[word.charAt(iter) - 'a'] = new Trie();
                }
                iterator = iterator.children[word.charAt(iter)-'a'];
            }
            iterator.isEnd = true;
            this.wordCount = this.wordCount + 1;
        }
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        if(word.length() == 0){
            return false;
        }else{
            StringBuffer currentWord = new StringBuffer("");
            Trie iterator = this;
            for(int iter = 0;iter< word.length(); iter++){
                if(iterator.children[word.charAt(iter)- 'a'] == null){
                    return false;
                }else{
                    currentWord.append(word.charAt(iter));
                    iterator = iterator.children[word.charAt(iter)-'a'];
                }
            }
            if(word.contentEquals(currentWord) == true){
                if(iterator.isEnd == true) return true;
            }
            return false;
        }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        if(prefix.length() == 0) return false;
        else{
            Trie iterator = this;
            for(int iter =0; iter< prefix.length(); iter++){
                if(iterator.children[prefix.charAt(iter) - 'a'] == null){
                    return false;
                }else{
                    iterator = iterator.children[prefix.charAt(iter)- 'a'];
                }
            }
            return true;
        }
    }

    public void printAllWords(){
        Trie iterator = this;
        printAllWordsUtil(iterator,new String(""));
        System.out.println("Total Words : "+ this.wordCount);
    }

    public void printAllWordsUtil(Trie node, String str){
        if(node == null){
            return;
        }else{
            if(node.isEnd == true){
                System.out.println(str);   
            }
            for(int iter = 0;iter<26;iter++){
                if(node.children[iter] != null){
                    printAllWordsUtil(node.children[iter],str+ Character.toString((char)('a'+iter)));
                }
            }
        }
    }

    public long getWordCount(){
        return this.wordCount;
    }
}

