class MyCalendarTwo {
    List<int[]> events;
    List<int[]> overlap;
    public MyCalendarTwo() {
        events = new ArrayList<>();        
    }
    
    public boolean book(int start, int end) {
        overlap = new ArrayList<>();
        for(int[] e: events){
            if(Math.max(e[0], start)<Math.min(e[1], end)){
                if(!doubleBooking(Math.max(e[0], start),Math.min(e[1],end)))
                    return false;
            }
        }
        events.add(new int[]{start, end});
        return true;
        
    }
    private boolean doubleBooking(int start, int end){
        for(int[] o: overlap){
            if(Math.max(o[0], start)<Math.min(o[1],end)){
                return false;
            }
        }
        overlap.add(new int[]{start, end});
        return true;
    }
}
