
class HistoryCommands 
{
private:
   char* listcommands[10]; // max. 10 commands
   // this has been moved to the C file.
   // char lastCommand [256]; 
public:
   HistoryCommands();
   ~HistoryCommands();
   void insert(char* command);
   void reset();
   void getCurrentCommand(char* buffer);
   void pushBackCurrent();
   void pushFrontCurrent();
   void post();
   void report(char* command);
};





