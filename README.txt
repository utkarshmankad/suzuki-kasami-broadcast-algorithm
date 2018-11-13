READ ME for Suzuki-Kasami Broadcast Based Algorithm

---Source Code Files----

The file names are as follows - 
->AccessToken.h  ->AccessToken.cpp
->Site.h	 ->Site.cpp
->CriticalSectionAccess.h	->CriticalSectionAccess.cpp
->main.cpp

The files are compiled using Visual Studio 2017 community edition.

---Execution instructions---

Execute the code directly from suzuki-kasami.exe file.

Enter the number of proccesses ---> input an integer value greater than 1

Enter Input Event in this format, and observe the output (event commands are case sensitive)

REQ <pid> eg - REQ 0, REQ 1 etc... to request the critical section by <pid> (pid starts from 0, max pid must be one less than total proccesses)
REL <pid> eg - REL 0, REL 1 etc... to release the critical section by <pid> (pid starts from 0, max pid must be one less than total proccesses)

CLOSE to exit the program.

----Sample Input-----

Enter the number of proccesses
5

Events

REQ 1
REQ 2
REL 1
REQ 3
REQ 0
REL 2
REL 3
REL 0
REQ 0
REL 0
REQ 2
REL 2
CLOSE
