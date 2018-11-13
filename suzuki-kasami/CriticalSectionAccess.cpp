#pragma once
#include "CriticalSectionAccess.h"
#include "Site.h"
#include "AccessToken.h"
#include <iostream>

//Function to send request to access the critical section
void CriticalSectionAccess::request_critical_section(int pr,AccessToken* token, Site* arrSite[], int proccess_id) {

	int i, seqno;
	seqno = ++arrSite[proccess_id]->site_sequence_array[proccess_id];
	//Checking whether it has already requested
	if (arrSite[proccess_id]->is_requesting == 1 || arrSite[proccess_id]->is_executing == 1)
	{
		cout << "SITE " << proccess_id << " is already requesting " << endl << endl;
		return;
	}
	arrSite[proccess_id]->is_requesting = 1;
	//Checking if it has the token
	if (token->token_holder == proccess_id)
	{
		arrSite[proccess_id]->is_requesting = 0;
		arrSite[proccess_id]->is_executing = 1;
		cout << "SITE " << proccess_id << " already has the token and it enters the critical section" << endl << endl;
		return;
	}

	//Sending Request
	if (token->token_holder != proccess_id)
	{
		for (i = 0; i < pr; i++)
		{
			if (i != proccess_id)
				arrSite[i]->execute_request(token,proccess_id, seqno);
		}
	}
	//Checking if it has got the token
	if (token->token_holder == proccess_id)
	{
		arrSite[proccess_id]->has_token = 1;
		arrSite[proccess_id]->is_executing = 1;
		arrSite[proccess_id]->is_requesting = 0;
		cout << "SITE " << proccess_id << " gets the token and it enters the critical section\n" <<  endl;
	}
	else
	{
		cout << "SITE " << token->token_holder << " is currently executing the critical section . Site " << proccess_id << " has placed its request" << endl;

	}
}

//Function to release the critical section access token
void CriticalSectionAccess::release_critical_section(AccessToken* token, Site* arrSite[], int proccess_id) {

	if (arrSite[proccess_id]->is_executing != 1)
	{
		cout << "SITE " << proccess_id << " is not currently executing the critical section." << endl << endl;
		return;
	}
	int i, siteid;
	token->sequence_array[proccess_id] = arrSite[proccess_id]->site_sequence_array[proccess_id];
	arrSite[proccess_id]->is_executing = 0;
	cout << "SITE " << proccess_id << " releases the critical section." << endl;
	//Checking if deffred requests are there by checking token queue
	//And Passing the token if queue is non empty 
	if (!token->token_queue.empty())
	{
		siteid = token->token_queue.front();
		token->token_queue.pop();
		token->side_id_with_token = siteid;
		arrSite[proccess_id]->has_token = 0;
		token->token_holder = siteid;
		arrSite[siteid]->has_token = 1;
		arrSite[siteid]->is_executing = 1;
		arrSite[siteid]->is_requesting = 0;
		cout << "SITE " << siteid << " gets the token and it enters the critical section" << endl << endl;
		return;
	}
	cout << "SITE " << proccess_id << " still has the token" << endl << endl;
}