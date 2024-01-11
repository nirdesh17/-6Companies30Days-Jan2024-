class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> lookup;
        return shopping_offers(price, special, needs, lookup);
    }

private:
    int shopping_offers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& lookup) {
        string key = "";
        for (int val : needs) {
            key += to_string(val) + ",";
        }

        if (lookup.find(key) != lookup.end()) {
            return lookup[key];
        }

        int min_price = inner_product(needs.begin(), needs.end(), price.begin(), 0);

        for (vector<int>& offer : special) {
            bool validOffer = true;
            for (size_t i = 0; i < needs.size(); ++i) {
                if (offer[i] > needs[i]) {
                    validOffer = false;
                    break;
                }
            }

            if (validOffer) {
                vector<int> new_needs(needs.size());
                for (size_t i = 0; i < needs.size(); ++i) {
                    new_needs[i] = needs[i] - offer[i];
                }
                min_price = min(min_price, offer.back() + shopping_offers(price, special, new_needs, lookup));
            }
        }

        lookup[key] = min_price;
        return min_price;
    }
};
