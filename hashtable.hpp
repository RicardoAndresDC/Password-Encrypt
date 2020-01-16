
bool HashTable<K, V>::insert(const std::pair<K, V> & kv)
{
        if (match(kv)) return false;            //if kv is already in the list, return false

        if (currentsize == table.size()) rehash();

        auto i = myhash(kv.first);
        if (table[i].empty())                   //if the slot is empty, just push_back into the list
        {
                table[i].push_back(kv);
                currentsize++;
                return true;
        }
        else
        {
                //otherwise, see if the key is already inside the list
                for (auto itr = table[i].begin(); itr != table[i].end(); itr++)
                {
                        //std::cout << "are we in a loop rn";
                        if (itr->first == kv.first)             //if we find a matching key, replace the value.
                        {
                                itr->second = kv.second;
                                currentsize++;
                                return true;
                        }
                }
                table[i].push_back(kv);         //if we didn't find a match, just insert a new pair
                currentsize++;
                return true;
        }
}

template <class K, class V>
bool HashTable<K, V>::insert (std::pair<K,  V> && kv)
{
        if (match(kv)) return false;            //if kv is already in the list, return false

        if (currentsize == table.size()) rehash();

        auto i = myhash(kv.first);
        if (table[i].empty())                   //if the slot is empty, just push_back into the list
        {
                table[i].push_back(std::move(kv));
                currentsize++;
                return true;
        }
        else
        {
                //otherwise, see if the key is already inside the list
                for (auto itr = table[i].begin(); itr != table[i].end(); itr++)
                {
                        if (itr->first == kv.first)             //if we find a matching key, replace the value.
                        {
                                itr->second = std::move(kv.second);     //NOTE - this does not update size variable,
                                return true;                            //as it does not actually add an element
                        }
                }
                table[i].push_back(std::move(kv));         //if we didn't find a match, just insert a new pair
                currentsize++;
                return true;
        }
}








