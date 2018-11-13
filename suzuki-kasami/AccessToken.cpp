#include "AccessToken.h"

AccessToken::AccessToken(int pr) {
	
	side_id_with_token = 0;
	sequence_array = new int[pr];

	for (int count = 0; count < pr; count++)
	{
		sequence_array[count] = 0;
	}
}