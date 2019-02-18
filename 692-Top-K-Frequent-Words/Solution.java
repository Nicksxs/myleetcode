class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        List<String> result = new LinkedList<>();
        Map<String, Integer> topKCount = new HashMap<>();
        PriorityQueue<Map.Entry<String, Integer>> priorityQueue = new PriorityQueue<>((a,
                b) -> a.getValue() == b.getValue() ? b.getKey().compareTo(a.getKey()) : a.getValue() - b.getValue());
        for (int i = 0; i < words.length; i++) {
            if (topKCount.containsKey(words[i])) {
                topKCount.put(words[i], topKCount.get(words[i]) + 1);
            } else {
                topKCount.put(words[i], 1);
            }
        }
        for (Map.Entry<String, Integer> entry : topKCount.entrySet()) {
            priorityQueue.offer(entry);
            if (priorityQueue.size() > k) {
                priorityQueue.poll();
            }
        }
        while (!priorityQueue.isEmpty()) {
            result.add(0, priorityQueue.poll().getKey());
        }
        return result;

    }
}