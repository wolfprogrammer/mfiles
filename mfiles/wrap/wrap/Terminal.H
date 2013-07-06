
class Terminal 
{
private:
   struct termios oldsettings;
   char prompt[16];
   struct termios stored_settings;
   struct termios new_settings;
   bool editingMode;
   HistoryCommands* hc;
public:
   Terminal();
   ~Terminal(){}
   void restore(void);
   void set_charmode(void);
   void set_stringmode(void);
   void echo_on(void);
   void echo_off(void);
   void refresh(char* buffer, int count, char* temp, int counttemp, int inipos);
   int readstring(char* buffer, int size);
   void blockEditing();
   void allowEditing();
   void setPrompt(char* newPrompt);
};
