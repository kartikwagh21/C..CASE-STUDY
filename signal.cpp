#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

bool running = false;

void signalSystem()
{
    while (running)
    {
        cout << "Signal: GREEN (Go!)" << endl;
        this_thread::sleep_for(chrono::seconds(3));

        if (!running) break;

        cout << "Signal: YELLOW (Slow Down)" << endl;
        this_thread::sleep_for(chrono::seconds(2));

        if (!running) break;

        cout << "Signal: RED (Stop)" << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
}

int main()
{
    int choice;
    thread signalThread;

    cout << "===== Traffic Signal Simulation =====" << endl;

    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Start Signal" << endl;
        cout << "2. Stop Signal" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (!running)
            {
                running = true;
                signalThread = thread(signalSystem);
                cout << "Signal Started...\n";
            }
            else
            {
                cout << "Signal already running!\n";
            }
        }
        else if (choice == 2)
        {
            running = false;

            if (signalThread.joinable())
                signalThread.join();

            cout << "Signal Stopped.\n";
        }
        else if (choice == 3)
        {
            running = false;

            if (signalThread.joinable())
                signalThread.join();

            cout << "Exiting program...\n";
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}