import java.util.List;
import java.util.Set;
import java.util.*;

class GottaSnatchEmAll {

    static Set<String> newCollection(List<String> cards) {
        Set<String> set = new HashSet<>();
        for(String str : cards){
            set.add(str);
        }
        return set;
    }

    static boolean addCard(String card, Set<String> collection) {
        return collection.add(card);
    }

    static boolean canTrade(Set<String> myCollection, Set<String> theirCollection) {
        boolean canTrade = false;
        for(String myCard : myCollection){
            if (!theirCollection.contains(myCard)){
                for(String theirCard : theirCollection){
                    if (!myCollection.contains(theirCard)){
                        canTrade = true;
                    }
                }
            }
        }
        
        return canTrade;
    }

    static Set<String> commonCards(List<Set<String>> collections) {
        if (collections.isEmpty()) {
            return new HashSet<>();
        }

        // Start with a copy of the first set
        Set<String> common = new HashSet<>(collections.get(0));

        // Intersect it with every subsequent set
        for (int i = 1; i < collections.size(); i++) {
            common.retainAll(collections.get(i));
        }

        return common;
    }

    static Set<String> allCards(List<Set<String>> collections) {
        Set<String> allCards = new HashSet<>();

        for(Set<String> set : collections){
            for(String card : set){
                allCards.add(card);
            }
        }
        return allCards;
    }
}
