import java.text.*;
class Solution {
    public int romanToInt(String s) {
        int value = 0;
        
        CharacterIterator it = new StringCharacterIterator(s);
        char previous = it.current();
        value += getValue(it.current());
        it.next();
        
        while(it.current() != CharacterIterator.DONE){
            if(getValue(previous) >= getValue(it.current())){
                value += getValue(it.current());
            }else{
                value -= getValue(previous);
                value += (getValue(it.current()) - getValue(previous));
            }
            previous = it.current();
            it.next();
        }
        
        return value;
    }
    
    public int getValue(char c){
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else if(c == 'M') return 1000;
        return 0;
    }
}