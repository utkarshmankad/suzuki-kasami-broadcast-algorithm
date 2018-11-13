#pragma once
#include "Site.h"

Site::Site(int pr) {
	
	site_sequence_array = new int[pr];
	is_executing = 0;
	is_requesting = 0;
	has_token = 0;
	
	for (int count = 0; count < pr; count++)
	{
		site_sequence_array[count] = 0;
	}
}

//Execute the request
void Site::execute_request(AccessToken* token,int proccess_id, int sequence_no) {

	site_sequence_array[proccess_id] = max(site_sequence_array[proccess_id], sequence_no);
	
	if (has_token == 1)
	{
		if (is_executing == 0 && token->sequence_array[proccess_id] + 1 == site_sequence_array[proccess_id])
		{
			has_token = 0;
			token->token_holder = proccess_id;
		}
		else if (token->sequence_array[proccess_id] + 1 == site_sequence_array[proccess_id])
		{
			token->token_queue.push(proccess_id);
		}
	}
}