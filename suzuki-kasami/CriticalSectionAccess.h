#pragma once
#include "Site.h"
#include "AccessToken.h"

using namespace std;

class CriticalSectionAccess {

public:

	//Request to access the critical section
	void request_critical_section(int pr,AccessToken* token, Site* arrSite[], int proccess_id);
	
	//Release the critical section
	void release_critical_section(AccessToken* token, Site* arrSite[], int proccess_id);
};