
class Pthread {
private:
   virtual void execute(){}
   int sonpid;
protected:
   int count;
   int toSon[2]; // the pipe call give us two pipes
   int fromSon[2];
public:
   Pthread(){
      count = 0;
      pipe(toSon);  // with two fds each one
      pipe(fromSon); 
   }
   virtual ~Pthread(){}
   void run();
   void end();
   void restart();
   void join();
};



