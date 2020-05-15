class Solution {
    public List<String> fizzBuzz(int n1) {
        ArrayList<String> result = new ArrayList<String>();
        for(int n = 1; n<= n1; n++){
            if(n%3 == 0 && n%5 == 0)
                result.add("FizzBuzz");
            else if(n%3 == 0)
                result.add("Fizz");
            else if(n%5 == 0)
                result.add("Buzz");
            else
                result.add(Integer.toString(n));
        }
        return result;
        
    }
}