#pragma once
#include <queue>

using namespace std;

class AccessToken
{
public:
	int side_id_with_token;								//Id of the site having token
	queue <int> token_queue;							//Token queue  
	int token_holder;									//Proccess Holding Token
	int* sequence_array;								//Token Array for sequence no 
	
	AccessToken(int pr);
};