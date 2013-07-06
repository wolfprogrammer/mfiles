/* magichash.cpp */
#include<ostream>
#include<octave/oct.h>
#include<vector>
#include<string>
using namespace std;
DEFUN_DLD(magichash, //Function Name
args, //input arguments
, //output arguments
"A Magic Hash Generation Functions:")//document string
{
string strval;
static int hash=0;
if((args.length() < 1 ) || !args(0).is_string())
{
cout<<"Usage: magichash(string)"<<endl;
return octave_value();
}
strval=args(0).string_value();
cout<<"Im Magic Hash"<<endl;
for(int i=0;i<strval.length();i++)
{
hash=(int)strval[i]+hash;
hash=hash%0xffff;
}
return octave_value(hash);
}
/* mkoctfile magichash.cpp -o magichash.oct */