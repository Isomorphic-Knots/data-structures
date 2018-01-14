#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>

void getnumber(std::string & s,std::vector<std::string> & numvector);
void getcharandword(std::string & collect, std::vector<std::string> & charvector,std::vector<std::string> & wordvector);
void mostnumbers(std::vector<std::string> & numbervector);
void mostword(std::vector<std::string> & charvector);
void mostchar(std::vector<std::string> & wordvector);

int main()
{
	std::vector<std::string> wordvector, charvector, numbervector;
	std::string collect;	


	//clock_t start = clock();

	//reads the file in, line by line and stores into collect
	//each line is iterated through by getnumber()
	//and getcharandword();
	while(getline(std::cin,collect))
	{

		getnumber(collect,numbervector);
		getcharandword(collect, charvector, wordvector);
	}


	/*
	    clock_t stop = clock();
        double elapsed = (double)(stop - start) * 1000.0 / 				CLOCKS_PER_SEC;
        printf("Time elapsed in ms: %f", elapsed);
        std::cout << "\n\n\n";
        */

	mostnumbers(numbervector);
	mostword(wordvector);
	mostchar(charvector);
	return 0;
}



































//function definitions!!!!!!!!!
void getnumber(std::string & collect,std::vector<std::string> & numvector)
{

	
	unsigned int hold1,hold2;

	//iterates through the string that was passed in.
	for(unsigned int i = 0; i < collect.size(); i++)
	{
		hold2 = i;

		//if digit is found the put it into hold1 to push
		//into the numbervector
		if(isdigit(collect[i]) == true)
			{
				for(unsigned int j = hold2; isdigit(collect[j]);j++)
				{
					hold1 = j;
					i = j;

				}
		//push the found number into digit
		numvector.push_back(collect.substr(hold2, hold1 - (hold2-1)));
			}
	}
}

void getcharandword(std::string & collect, std::vector<std::string> & charvector,std::vector<std::string> & wordvector)
{

	unsigned int hold1,hold2;
	std::string substringhold, charhold;

	for(unsigned int i=0; i<=collect.size();i++){
		charhold = collect[i];
		charvector.push_back(charhold);}

	//iterates through passed string		
	for(unsigned int i = 0; i < collect.size(); i++)
	{
		hold2 = i;


		//is a character is found
		if(isalpha(collect[i]))
		{

			//while collect[j] is character keep looping
			//hold1 is used afterward for substring purposes
			//i=j is used to return the loop to appropriate index
			for(unsigned int j = hold2; isalpha(collect[j]);j++)
			{
				hold1 = j;
				i = j;

			}

			//hold the created substring
			substringhold = collect.substr(hold2, hold1 - (hold2-1));

			for(unsigned int k = 0;k<=substringhold.size();k++)			
			{
				//then make everything lowercase
				substringhold[k] = tolower(substringhold[k]);
			}
			
			//pushes all chars to vector
			

			//push lowercase string into wordvector
			wordvector.push_back(substringhold);
		}
	}
}


void mostnumbers(std::vector<std::string> & numbervector)
{

	int mycount = 0, mostnumbers = 0, count = 0, total = 0, unique = 0;
	std::string s;

	std::cout<< "top numbers used: \n";	


	//go to ten numbers or until the vector is empty
	while(!numbervector.empty() && count != 10)
	{
		//count for unique numbers in the file 
		unique++;

	//iterate through the vector
	for(unsigned int i = 0; i <= numbervector.size(); i++)
		{

			//count how many times each string is found
			//within the string for each index of the vector
			mycount = std::count(numbervector.begin(), numbervector.end(), numbervector[i]);

			//if the index is zero, that is the most found word initially
			//otherwise if i>0 and a string is found the occurs more than
			//the previously greatest, store it in s.
			if( (i==0) || ((i>0) && (mycount > mostnumbers)))
				{
					s = numbervector[i];
					mostnumbers = mycount;
				}
		}
	
		//erase the most found string in order to find next greatest
		numbervector.erase(std::remove(numbervector.begin(), numbervector.end(), s),numbervector.end());

		//count to ten
		count++;

		//total words in the file
		total = total + mostnumbers;
		std::cout << count << ". \t" << s << "\t\tused ";
		std::cout << mostnumbers << " times" << std::endl;
		
	}
	
	//similar to the loop before, but keeps going in order to find
	//how many unique numbers are in the file overall, not restricted
	//to ten loops...
	while(!numbervector.empty())
	{
		unique++;

		for(unsigned int i = 0; i <= numbervector.size(); i++)
		{
			mycount = std::count(numbervector.begin(), numbervector.end(), numbervector[i]);

			if( (i==0) || ((i>0) && (mycount > mostnumbers)))
				{
					s = numbervector[i];
					mostnumbers = mycount;
				}
		}
		numbervector.erase(std::remove(numbervector.begin(), numbervector.end(), s),numbervector.end());

	}

	if(total==0)
		std::cout << "none found\n\n";

	if(total > 0){
	std::cout << "total unique in file overall: \t" << unique << "\n\n";}
}



//very similar to mostnumbers()
void mostword(std::vector<std::string> & charvector)
{
int mycount = 0, mostchar = 0, count = 0, total = 0, unique = 0;
	std::string s;

	std::cout<< "most words used: \n";	

	while(!charvector.empty() && count != 10)
	{unique++;
	for(unsigned int i = 0; i <= charvector.size(); i++)
		{
			mycount = std::count(charvector.begin(), charvector.end(), charvector[i]);

			if( (i==0) || ((i>0) && (mycount > mostchar)))
				{
					s = charvector[i];
					mostchar = mycount;
				}
		}
	
		charvector.erase(std::remove(charvector.begin(), charvector.end(), s), charvector.end());

		count++;
		total = total + mostchar;
		std::cout << count << ". \t";


		//used for formatting
		if(s.size() < 4)
			 std::cout << s <<"\t\t used ";
		else if(s.size() < 8)
			 std::cout << s  <<"\t\t used ";
		else if(s.size() >=8)
			 std::cout << s  <<"\t used ";
		std::cout << mostchar << " times" << std::endl;
		
	}

	while(!charvector.empty())
	{
		unique++;

		for(unsigned int i = 0; i <= charvector.size(); i++)
		{
			mycount = std::count(charvector.begin(), charvector.end(), charvector[i]);

			if( (i==0) || ((i>0) && (mycount > mostchar)))
				{
					s = charvector[i];
					mostchar = mycount;
				}
		}
		charvector.erase(std::remove(charvector.begin(), charvector.end(), s),charvector.end());
	}

	if(total==0)
		std::cout << "none found\n\n";
	if(total>0){
	std::cout << "total unique in file overall: \t" << unique << "\n\n";}
}

//very similar to most numbers
void mostchar(std::vector<std::string> & charvector)
{
int mycount = 0, mostchar = 0, count = 0, total = 0, unique = 0;
	std::string s;

	std::cout<< "most characters used: \n";	

	while(!charvector.empty() && count != 10)
	{unique++;
	for(unsigned int i = 0; i <= charvector.size(); i++)
		{

			mycount = std::count(charvector.begin(), charvector.end(), charvector[i]);

			if( (i==0) || ((i>0) && (mycount > mostchar)))
				{
					s = charvector[i];
					mostchar = mycount;
				}
		}
	
		charvector.erase(std::remove(charvector.begin(), charvector.end(), s), charvector.end());

		count++;
		total = total + mostchar;
		std::cout << count << ". \t" << s << "\t\tused ";
		std::cout << mostchar << " times" << std::endl;
		
	}

	while(!charvector.empty())
	{
		unique++;

		for(unsigned int i = 0; i <= charvector.size(); i++)
		{
			mycount = std::count(charvector.begin(), charvector.end(), charvector[i]);

			if( (i==0) || ((i>0) && (mycount > mostchar)))
				{
					s = charvector[i];
					mostchar = mycount;
				}
		}
		charvector.erase(std::remove(charvector.begin(), charvector.end(), s),charvector.end());
	}
	if(total==0)
		std::cout << "none found\n\n";
	if(total>0){
	std::cout << "total unique in file overall: \t" << unique << "\n\n";}
}














