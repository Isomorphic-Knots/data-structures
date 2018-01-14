#include "passserver.h"
#include <cstring>

PassServer::PassServer(size_t size):hash(size)
{}

//destructor
PassServer::~PassServer()
{
	hash.clear();
}

bool PassServer::load(const char *filename)
{
	return hash.load(filename);
}

bool PassServer::addUser(std::pair<std::string,std::string>& kv)
{
	//need to create a new pair to encrypt the pw
	std::pair<std::string,std::string> p;
	p.first = kv.first;
	p.second = encrypt(kv.second);
	return hash.insert(p);
}

bool PassServer::addUser(std::pair<std::string,std::string>&& kv)
{
	//need to create a new pair to encrypt the pw
	std::pair<std::string,std::string> p;
	p.first = kv.first;
	//encrypt
	p.second = encrypt(kv.second);
	return hash.insert(std::move(p));
}

//removeuser from hash object
bool PassServer::removeUser(const std::string & k)
{
	return hash.remove(k);
}	

bool PassServer::changePassword(const std::pair<std::string,std::string> &p, const std::string& newpassword)
{


	//return false if hash object does not contain the key or if the
	//old password is the same as the new password
	if((hash.contains(p.first) == false) || p.second == newpassword)
		return false;
	else
	{	
		//a new pair needed for encryption
		std::pair<std::string,std::string> newp;
		newp.first = p.first;
		newp.second = encrypt(newpassword);

		//insert fancy new pair
		return hash.insert(newp);
	}

}


bool PassServer::find(const std::string & user)

{
	//return true if hash object contains key	
	if(hash.contains(user))
		{std::cout << "\nuser found!\n";return true;}
	else
		std::cout << "\nuser not found! :(\n"; return false;
}

//print table
void PassServer::dump()
{
	hash.dump();
}
	
//return currentsize
size_t PassServer::size()
{
	return hash.getsize();
}

bool PassServer::write_to_file(const char *filename)
{
	return hash.write_to_file(filename);
}


//encrypt password
std::string PassServer::encrypt(const std::string & str)
{
	char salt[] = "$1$########";
	char * password = new char [50];
	std::strcpy(password, crypt(str.c_str(), salt));
	std::string pwreturn = password;
	
	//set string to return string after salt
	pwreturn = pwreturn.substr(12);


	return pwreturn;
}

//private helper function
size_t PassServer::HowManyBuckets()
{
	return hash.bucketsize();
}










