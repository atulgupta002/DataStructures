// LeetCode 1338: You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

// Return the minimum size of the set so that at least half of the integers of the array are removed.


class Node{
    int item;
    int count;
    
    Node(int item, int value){
        this.item = item;
        this.count = value;
    }
};

class NodeComparator implements Comparator<Node> {
    @Override
    public int compare(Node node1, Node node2) {
        // Compare nodes based on priority in a custom way (e.g., descending order)
        return Integer.compare(node2.count, node1.count);
    }
};

class Solution {
    public int minSetSize(int[] arr) {
        Map<Integer, Integer> counts = new HashMap<>();
        PriorityQueue<Node> heap = new PriorityQueue<>(new NodeComparator());
        for (int num: arr){
            int currCount = counts.getOrDefault(num,0) + 1;
            counts.put(num,currCount);
        }
        
        for(Map.Entry<Integer, Integer> entry: counts.entrySet()){
            int key = entry.getKey();
            int value = entry.getValue();
            Node newNode = new Node(key,value);
            heap.offer(newNode);
        }
        
        int currSize = 0, size = arr.length, ans = 0;
        
        while (!heap.isEmpty()){
            Node top = heap.poll();
            int count = top.count;
            if (currSize < size/2){
                currSize += count;
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
}
