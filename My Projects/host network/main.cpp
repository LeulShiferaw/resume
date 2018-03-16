#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
    string ssid, key;
    cout << "Enter ssid: ";
    cin >> ssid;
    cout << "Enter key: ";
    cin >> key;
    string command = "netsh wlan set hostednetwork mode=allow ssid="+ssid+" key="+key;
    char* commandChar = new char[command.size()];
    for (unsigned int i = 0; i<command.size(); i++)
        commandChar[i]=command[i];
    system(commandChar);
    system("netsh wlan start hostednetwork");
    cout << "Press Enter to Stop...";
    cin.get();
    cin.get();
    system("netsh wlan stop hostednetwork");
}
