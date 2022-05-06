// GCC extensions
#include <bits/extc++.h>
using namespace __gnu_pbds;

// order stats tree
// find_by_order(i) returns ptr
// order_of_key(key) return int
typedef tree<K, V, less<K>,
rb_tree_tag, tree_order_statistics_node_update> set_t;

//hash table
gp_hash_table<K, V>

