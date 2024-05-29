#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<pair <int, int>, null_type,greater<pair <int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
#define indexed_multi_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

