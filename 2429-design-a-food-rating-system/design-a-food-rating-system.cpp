
class FoodRatings {
    struct Food {
        string name;
        int rating;
        bool operator<(const Food& other) const {
            if (rating == other.rating) 
                return name < other.name; // smaller lexicographic wins
            return rating > other.rating; // higher rating first
        }
    };

    unordered_map<string, string> foodToCuisine; // food -> cuisine
    unordered_map<string, int> foodToRating;     // food -> rating
    unordered_map<string, set<Food>> cuisineToFoods; // cuisine -> ordered foods

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;
            cuisineToFoods[cuisine].insert({food, rating});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];

        // Remove old entry
        cuisineToFoods[cuisine].erase({food, oldRating});

        // Insert new entry
        cuisineToFoods[cuisine].insert({food, newRating});
        foodToRating[food] = newRating;
    }

    string highestRated(string cuisine) {
        return cuisineToFoods[cuisine].begin()->name;
    }
};
