class Solution {
    
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

        /** Returns if the word is inthe trie. */
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
        
    public  List<String> findWords(char[][] board, String[] words) {
        Trie t = new Trie();
        for(String word: words){
            t.insert(word);
        }

        int[][] visited = new int[board.length][board[0].length];
        ArrayList<String> result = new ArrayList<String>();

        for(int row = 0; row< board.length; row++){
            for(int col =0; col<board[0].length; col++){
                visited[row][col] = 1;
                findWordsUtil(board,t.children[board[row][col] - 'a'],row,col,result,visited, String.valueOf(board[row][col]));
                visited[row][col] = 0;
            }
        }
        TreeSet<String> wordsSet = new TreeSet<String>(result);
        return new ArrayList<String>(wordsSet);
    }

    public  void findWordsUtil(char[][] board, Trie t,int currentRow,int currentCol,ArrayList<String> result, int[][] visited, String str){
        if(t != null){
            if(t.isEnd == true){
                result.add(str);
            }
        }
        int[] x = {0,-1,0,1};
        int[] y = {-1,0,1,0};
        for(int iter = 0; iter< 4;iter++){
            str.concat(String.valueOf(board[currentRow][currentCol]));
            if(isValidPosition(board,t,currentRow+ x[iter] , currentCol + y[iter], visited)){
                visited[currentRow+x[iter]][currentCol+y[iter]] = 1;
                findWordsUtil(board,t.children[board[currentRow+x[iter]][currentCol+y[iter]] - 'a'], currentRow+x[iter], currentCol+y[iter], result, visited,(str+board[currentRow+x[iter]][currentCol+y[iter]]));
                visited[currentRow+x[iter]][currentCol+y[iter]] = 0;
            }
        }
    }

    public  boolean isValidPosition(char[][] board, Trie t, int currentRow, int currentCol, int[][] visited){
        if(t == null) return false;
        if(currentRow < 0 || currentRow >= board.length) return false;
        if(currentCol < 0 || currentCol >= board[0].length) return false;
        if(visited[currentRow][currentCol] == 1) return false;
        if(t.children[ board[currentRow][currentCol] -'a'] == null) return false;
        return true;
    }
}