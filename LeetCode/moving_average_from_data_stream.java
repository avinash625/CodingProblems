class MovingAverage {

    private double windowSum = 0.00;
    private Deque<Integer> deque = new LinkedList<Integer>();
    private int totalSize = 0;
    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        this.totalSize = size;
    }
    
    public double next(int val) {
        if(deque.size() == this.totalSize){
            windowSum = windowSum - deque.getFirst();
            windowSum += val;  
            deque.removeFirst();
        }else{
            windowSum += val;
        }
        deque.addLast(val);
        return this.windowSum / deque.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */