class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int actualIndex = 0;
        int longIndex = 0;
        
        if(typed.length() < name.length()) return false;
        else{
            while(actualIndex < name.length() && longIndex < typed.length()){
                if(name.charAt(actualIndex) == typed.charAt(longIndex)){
                    actualIndex++;
                    longIndex++;
                    //System.out.println("actualIndex : "+ actualIndex);
                    //System.out.println("longIndex : "+ longIndex);
                }else{
                    if(actualIndex == 0 || longIndex == 0){
                        return false;
                    }else{
                        if(typed.charAt(longIndex) == typed.charAt(longIndex-1)){
                            char previous = typed.charAt(longIndex-1);
                            while(longIndex < typed.length() && typed.charAt(longIndex) == previous ){
                                longIndex++;
                            }
                        }else{
                            return false;
                        }
                    }
                }
            }
            if(actualIndex == name.length() && longIndex == typed.length()){
                return true;
            }else{
                if(longIndex >= typed.length()) return false;
                if(typed.charAt(longIndex) == typed.charAt(longIndex-1)){
                            char previous = typed.charAt(longIndex-1);
                            while(longIndex < typed.length() && typed.charAt(longIndex) == previous ){
                                longIndex++;
                            } 
                        }else{
                            return false;
                        }
                if(actualIndex == name.length() && longIndex == typed.length()){
                return true;
            }
            }return false;
        }
    }
}