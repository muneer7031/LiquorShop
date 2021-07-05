int counter = 10; //amount of seconds
                while (counter >= 0)
                {
                    cout << " \r TERMINATING SOFTWARE IN " << counter << " SECONDS" ;//<< flush;
                    Sleep(1000);
                    counter--;
                }