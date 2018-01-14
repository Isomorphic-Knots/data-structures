#ifndef PASSSERVER_H
#define PASSSERVER_H

#include <iostream>
#include <string>
#include <utility>
#include <crypt.h>
#include "hashtable.h"


using namespace cop4530;

class PassServer
{
	public:
		PassServer(size_t size = 101);
		~PassServer();
		bool load(const char *filename);
		bool addUser(std::pair<std::string,std::string>& kv);
		bool addUser(std::pair<std::string,std::string>&& kv);
		bool removeUser(const std::string & k);
	
		bool changePassword(const std::pair<std::string,std::string> &p, const std::string& newpassword);

		bool find(const std::string & user);
		void dump();
	
		size_t size();
		size_t HowManyBuckets();


		bool write_to_file(const char *filename);
	private:
		std::string encrypt(const std::string & str);
		HashTable<std::string,std::string> hash;
};

#endif
