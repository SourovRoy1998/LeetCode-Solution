//https://leetcode.com/problems/fruit-into-baskets/
//I have to do it after exam

class Solution {
public:
    int totalFruit( vector<int>& tree ){
	unordered_map<int, int> baskets;
	int maxFruitCount = 0;
	const int nBaskets = 2;

	for ( int left = 0, right = 0; right < tree.size(); ++right )
	{
		// if fruit would go in an empty basket
		if ( baskets.find( tree[right] ) == baskets.end() )
		{
			// dump fruit until have a free basket
			while ( baskets.size() == nBaskets )
			{
				baskets[tree[left]]--;
				if ( baskets.find( tree[left] ) != baskets.end() && baskets[tree[left]] == 0 )
					baskets.erase( tree[left] );
				left++;
			}
		}
		// add fruit to basket
		baskets[tree[right]]++;
		maxFruitCount = max( maxFruitCount, right - left + 1 );
	}
	return maxFruitCount;
}
};
