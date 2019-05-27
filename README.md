# keyStrikeHook
This program uses a compromising approach to solve mechanical keyboards' continuous strike problem on windows.
## Usage
Download the main file and compile it using g++ or create a vs-project for the code and build it.

## Note
Remember to close the anti-virus software or add the execution program to its white-list, or there may be problems. 

## Run automatically 
There are many ways to set a routing runs at start-up. One approach on Windows7 is 
1. win+R
2. enter `regedit`
3. find `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run`
4. right click, choose `New--String`
5. rename it whatever you like and set the value as the program path.

