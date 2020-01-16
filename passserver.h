
#ifndef PASSSERVER_H
#define PASSSERVER_H

#include <utility>
#include <unistd.h>
#include <crypt.h>
#include <string>
#include <cstring>
#include "hashtable.h"

class PassServer
{
	public:
	        PassServer(size_t size = 101);
		~PassServer();
        	bool load(const char* filename);
        	bool addUser(std::pair<std::string, std::string> & kv);
        	bool addUser(std::pair<std::string, std::string> && kv);
        	bool removeUser(const std::string & k);
        	bool changePassword(const std::pair<std::string, std::string> &p, const std::string & newpassword);
        	bool find(const std::string & user) const;
        	void dump() const;
        	size_t size() const;
        	bool write_to_file(const char* filename) const;

	private:
        	cop4530::HashTable<std::string, std::string>* table;
		char* password;
        	size_t tablesize;

        	std::string encrypt(const std::string &str);
};


#endif
