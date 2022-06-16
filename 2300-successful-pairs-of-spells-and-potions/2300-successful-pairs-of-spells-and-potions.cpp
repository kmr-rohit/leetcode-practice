class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(begin(potions), end(potions));
    for (int i = 0; i < spells.size(); ++i) {
        long long comp = (success + spells[i] - 1) / spells[i];
        spells[i] = potions.size() - (lower_bound(begin(potions), end(potions), comp) - begin(potions));
    }
    return spells;
}
};