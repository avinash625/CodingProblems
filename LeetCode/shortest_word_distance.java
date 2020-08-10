class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int left = Integer.MAX_VALUE;
        int right = Integer.MAX_VALUE;

        for(int iter = 0 ;iter< words.length; iter++){
            if(words[iter].equals(word1)){
                //System.out.println("word at " + iter + " is same as "+ word1);
                for(int l = iter-1; l >=0 ; l--){
                    if(words[l].equals(word2)){
                        //System.out.println("word at " + l + " is same as "+ word2);
                        if(iter-l < left){
                            left = iter-l;
                            break;
                        }
                    }
                }
                for(int r = iter+1; r< words.length; r++){
                    if(words[r].equals(word2)){
                        //System.out.println("word at " + r + " is same as "+ word2);
                        if(r-iter < right){
                            right = r - iter;
                            break;
                        }
                    }
                }
            }
        }
        return Integer.min(left, right);
    }
}