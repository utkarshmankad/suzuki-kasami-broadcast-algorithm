#pragma once
#include <string>
#include "AccessToken.h"

class Site {

public:

	int* site_sequence_array;					//Site's Array for sequence no. 
	bool is_executing;							//For checking whether site is executing
	bool is_requesting;							//For checking whether site is  requesting
	bool has_token;								//For checking whether site has token

	//Constructor
	Site(int pr);

	//Execute Request
	void execute_request(AccessToken* token,int proccess_id, int sequence_no);
};