
// Description: A wishMonitor owns a list of wishhandlers and acts as a common interface to all of
// them. If we want to send a command to the active wish we will send it here, and same if we wanna
// change the active wish.


class WishMonitor
{
public:
   WishMonitor();
   ~WishMonitor(){};
   void end();
   void process(char* command); // passes the command to the active wishhandler.
};


