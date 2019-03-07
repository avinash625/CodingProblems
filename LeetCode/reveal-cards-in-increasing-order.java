class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int[] result = new int[deck.length];
        Arrays.fill(result,-1);
        Arrays.sort(deck);
        int position = 0;
        for(int iter = 0 ;iter < deck.length; iter++){
            while(result[position%deck.length] != -1){
                position++;
            }
            result[position%deck.length] = deck[iter];
            position++;
            while(result[position%deck.length] != -1){
                position++;
                if(iter == deck.length -1) break;
            }
            if(result[position%deck.length] == -1){
                position++;
            }
        }
        return result;
    }
}