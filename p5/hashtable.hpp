
//sets currentsize to zero.
//then if size is between 0 and max prime then use the primebelow size
//else use default size
template <typename K, typename V>
HashTable<K, V>::HashTable(size_t size)
{
	currentsize = 0;	
	
	if(size > 0 && size < max_prime+1) 
		bucket.resize(prime_below(size));
	else
		bucket.resize(prime_below(default_capacity));
}

//destructor for hashtable class
template <typename K, typename V>
HashTable<K, V>::~HashTable()
{
	makeEmpty();
}

template <typename K, typename V>
bool HashTable<K, V>::contains(const K & k)
{
	//iterates through the buckets/vector
    for(auto & itr : bucket)
		{
			//iterates through the list
        	for(auto & itr1 : itr)
				{
					//returns true if k is found
					if(itr1.first == k)
						return true;
        		}
		}

	return false;
}

template <typename K, typename V>
bool HashTable<K, V>::match(const std::pair<K,V> & kv)
{

    for(auto & itr : bucket)
		{
        	for(auto & itr1 : itr)
				{
					//returns true if kv is a match
					if(itr1.first == kv.first && itr1.second == kv.second)
						return true;
        		}
		}

	return false;
}

template <typename K, typename V>
bool HashTable<K, V>::insert(const std::pair<K,V> & kv)
{
	//returns false if kv is found
	if(match(kv))
		return false;
	else if(contains(kv.first))
	{
		//iterates through the buckets/vector
		for(auto & itr : bucket)
		{
			//iterates through the lists
        	for(auto & itr1 : itr)
				{
					//returns true if passwords dont match
					if(itr1.first == kv.first && itr1.second != kv.second)
						{itr1.second = kv.second;return true;}
					//returns false if passwords match
					else if(itr1.first == kv.first && itr1.second == kv.second)
						return false;        		
				}
		}
	}
	else
	{
		auto & gonnainsert = bucket[myhash(kv.first)];

		//inserts kv
		gonnainsert.push_back(kv);
		//increases size
		currentsize++;

		//rehash if needed
		if(getsize() > bucketsize())
			rehash();
	}	
		return true;
}


//similar to above but uses std::move
template <typename K, typename V>
bool HashTable<K, V>::insert(const std::pair<K,V> && kv)
{
	if(match(kv))
		return false;
	else if(contains(kv.first))
	{
		for(auto & itr : bucket)
		{
        	for(auto & itr1 : itr)
				{
					if(itr1.first == kv.first && itr1.second != kv.second)
						{itr1.second = kv.second;return true;}
					else if(itr1.first == kv.first && itr1.second == kv.second)
						return false;        		
				}
		}
	}
	else
	{
		auto & gonnainsert = bucket[myhash(kv.first)];

		gonnainsert.push_back(std::move(kv));

		currentsize++;
		if(getsize() > bucketsize())
			rehash();
	}	
		return true;
}


template <typename K, typename V>
bool HashTable<K, V>::remove(const K & k)
{
	//if the table doesnt contain k return false;
	if(contains(k) == false)
		return false;
	else
	{
		
		auto & gonnadelete = bucket[myhash(k)];
		auto itr = gonnadelete.begin();

		//iterate through the table;
		while(itr != gonnadelete.end())
		{
			//when appropriate key is found delete it.
			if(itr->first == k)
				{
					gonnadelete.erase(itr);
					currentsize--;
					return true;
				}
					itr++;
		}
		
	}
return false;
}

//public function to delete
template <typename K, typename V>
void HashTable<K, V>::clear()
{
	makeEmpty();
}

template <typename K, typename V>
bool HashTable<K, V>::load(const char * filename)
{
	std::ifstream filen;
	filen.open(filename);

	if(filen.is_open())
		{
			std::pair<K,V> p;
			do
			{
				filen >> p.first >> p.second;
				insert(p);
			}
			while(!(filen.eof()));
			filen.close();
		}
	return false;
}

template <typename K, typename V>
void HashTable<K, V>::dump()
{
 	size_t i = 0;
	//iterates through the buckets/vector
    for(auto & itr : bucket)
		{
        	std::cout << "\nv[" << i << "]: ";i++;
			
			size_t listcount=0;
			//iterates through the list
        	for(auto & itr1 : itr)
				{
					//prints : if list size is greater than 1
					listcount++;
            		if(2 <= listcount)
                		{std::cout << ":";}
            
					std::cout << itr1.first << " " << itr1.second;
        		}
		}
}

template <typename K, typename V>
bool HashTable<K, V>::write_to_file(const char * filename)
{
	std::ofstream o;

	o.open(filename);

	//dont know how to unencrypt the passwords when written to file
	if(o.fail())
		return false;
	else
    	for(auto & itr : bucket)
		{
			//iterates through the list
        	for(auto & itr1 : itr)
				{
					o << itr1.first << " " << itr1.second << std::endl;
        		}
		}

	return true;
}

//private deletion of the bucket data
template <typename K, typename V>
void HashTable<K, V>::makeEmpty()
{
	bucket.clear();
}

//increases the size of the vector
template <typename K, typename V>
void HashTable<K, V>::rehash()
{
	//approximately doubles the size of the vector
	size_t i = prime_below(bucketsize()*2);
	bucket.resize(i);
}

template <typename K, typename V>
size_t HashTable<K, V>::myhash(const K & k)
{
	std::hash<K> uhash; //from functional library
	size_t h = uhash(k) % bucketsize();

	return h;
}

// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below(unsigned long n)
{
 	if (n > max_prime)
	{
		std::cerr << "** input too large for prime_below()\n";
		return 0;
    }

  	if (n == max_prime)
    {
      	return max_prime;
    }

  	if (n <= 1)
    {
		std::cerr << "** input too small \n";
      	return 0;
    }

  	// now: 2 <= n < max_prime
  	std::vector <unsigned long> v (n+1);
  	setPrimes(v);

  	while (n > 2)
    {
      	if (v[n] == 1)
		return n;
      	--n;
    }

  	return 2;
}

//Sets all prime number indexes to 1. Called by method prime_below(n) 
template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long> & vprimes)
{
  	int i = 0;
  	int j = 0;

  	vprimes[0] = 0;
  	vprimes[1] = 0;
  	int n = vprimes.capacity();

  	for (i = 2; i < n; ++i)
    	vprimes[i] = 1;

  	for( i = 2; i*i < n; ++i)
    {
     	if (vprimes[i] == 1)
        for(j = i + i ; j < n; j += i)
          	vprimes[j] = 0;
    }
}


//helper functions
template <typename K, typename V>
size_t HashTable<K,V>::getsize()
{
	return currentsize;
}
template <typename K, typename V>
size_t HashTable<K,V>::bucketsize()
{
	return bucket.size();
}





