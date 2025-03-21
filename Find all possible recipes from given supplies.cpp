class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Map<String, Integer> inDegree = new HashMap<>();
        Map<String, List<String>> graph = new HashMap<>();
        Set<String> supplySet = new HashSet<>(Arrays.asList(supplies));

        // Initialize graph and in-degree count
        for (int i = 0; i < recipes.length; i++) {
            String recipe = recipes[i];
            int count = 0;
            
            for (String ingredient : ingredients.get(i)) {
                if (!supplySet.contains(ingredient)) {
                    graph.computeIfAbsent(ingredient, k -> new ArrayList<>()).add(recipe);
                    count++; // Increase count only if ingredient is NOT in supplies
                }
            }
            inDegree.put(recipe, count);
        }

        // Queue for processing recipes that can be made
        Queue<String> queue = new LinkedList<>();
        for (String recipe : recipes) {
            if (inDegree.get(recipe) == 0) {
                queue.offer(recipe);
                supplySet.add(recipe); // Mark this recipe as available
            }
        }

        // Process recipes using BFS
        List<String> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            String curr = queue.poll();
            result.add(curr);

            if (!graph.containsKey(curr)) continue;

            for (String dependent : graph.get(curr)) {
                inDegree.put(dependent, inDegree.get(dependent) - 1);
                if (inDegree.get(dependent) == 0) {
                    queue.offer(dependent);
                    supplySet.add(dependent); // Mark this dependent recipe as available
                }
            }
        }

        return result;
    }
}
