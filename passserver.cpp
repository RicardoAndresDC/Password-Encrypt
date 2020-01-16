
#include "passserver.h"

PassServer::PassServer(std::size_t size)
{
        table = new cop4530::HashTable<std::string, std::string>(size);
        tablesize = 0;
	password = 0;
}

PassServer::~PassServer()
{
	if (password != 0) delete password;
        delete table;
}

bool PassServer::load(const char* filename)
{
        return table->load(filename);
}

bool PassServer::addUser(std::pair<std::string, std::string> & kv)
{
        if (table->contains(kv.first)) return false;
	++tablesize;
        return table->insert(make_pair(kv.first, encrypt(kv.second)));
}

bool PassServer::addUser(std::pair<std::string, std::string> && kv)
{
        if (table->contains(kv.first)) return false;
        return table->insert(make_pair(std::move(kv.first), encrypt(std::move(kv.second))));
        ++tablesize;
}

bool PassServer::removeUser(const std::string & k)
{
        return table->remove(k);
        --tablesize;
}

bool PassServer::changePassword(const std::pair<std::string, std::string> &p, const std::string & newpassword)
{
        if (table->match(make_pair(p.first, encrypt(p.second))))                //provided username/pass must be in the list
        {
                if (encrypt(p.second) == encrypt(newpassword))                  //newpassword can't be the same as the last one
                {
                    return false;    
                } 
                table->insert(make_pair(p.first, encrypt(newpassword)));
                return true;
        }
        return false;
}

bool PassServer::find(const std::string & user) const
{
        return table->contains(user);
}

void PassServer::dump() const
{
        table->dump();
}

std::size_t PassServer::size() const
{
        return table->size();
}

bool PassServer::write_to_file(const char* filename) const
{
        table->write_to_file(filename);
}

std::string PassServer::encrypt(const std::string &str)
{
	if (password != 0) delete password;

	char salt[] = "$1$########";
	std::string key = str;

	password = new char [100];
	strcpy(password, crypt(key.c_str(), salt));
	std::string result(password);
        return result;
}
