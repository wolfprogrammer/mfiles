
class Octawrap
{
private:
   Terminal term;

   void console2octave(int* toOctave);
   int analizebuffer(char* buffer, int* toOctave);
   void octave2console(int* fromOctave);
public:
   Octawrap();
   ~Octawrap(){}
   void run();
};

