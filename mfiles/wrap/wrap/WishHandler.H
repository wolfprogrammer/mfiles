
class WishHandler: public Pthread
{
private:
   char numvar[4];         // widgets counter, 000...999
   int wishcallbackpid;    // for receiving wish asynchronous output, as callbacks
   bool valid(char* buffer);
   char* translate(char* cad, char* numvar);
   void sig(char* cad);
   char* firstword(char* cad, char c);
   char* limpiar(char* cad);
   char* quitaparent(char* cad);
   char* getrest(char* cad);
   char* limpiafin(char* cad);
   void execute();         // overwrite the virtual method of Pthread
   // int run();           // method to launch the thread. The real code is in execute().
   // is not redefined. Is inherited from Pthread
public:
   int toWish[2];          // for speaking with the son (wish)
   int fromWish[2];
   bool apagado;
   WishHandler();
   virtual ~WishHandler(){}
   void displayWidget(char* buffer);
   void showEmpty();
   void emptyAndHide();
};


