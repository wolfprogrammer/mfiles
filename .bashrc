# Add nano as default editor
export EDITOR=vim


alias ls='ls --color=auto'
alias rm='rm --interactive'

alias open='xdg-open > /dev/null 2>&1'

alias dosbox='dosbox -c  "mount c `pwd`" -c  "KEYB br" -c "C:" -c "/mouse"'

alias wiki='xdg-open  http://localhost:8080/wiki/doku.php'

alias wikiw='w3m http://localhost:8080/wiki/doku.php'

alias path='printf ${PATH//:/\\n}'    

alias  https='hostname -i && python -m SimpleHTTPServer'


# Set w3m browser home page
export HTTP_HOME="www.google.co.uk"    
alias browser='w3m -graph -cookie http://www.google.co.uk'

export CSCOPE_EDITOR=`which emacs`


#-------------------------------------------------------------------
#  UBUNTU SPECIFIC COMMANDS
#
#-------------------------------------------------------------------
# Install package
alias install='sudo apt-get install'
# Search package
alias search='apt-cache search'


search_web() {
	search=""
	echo "Googling: $@"
	sleep 0.5
	ss1=$@" -ehow -wikihow"
	for term in $ss1; do
		search="$search%20$term"
	done

		w3m -graph -cookie "http://www.google.co.uk/search?q=$search"
}



currency_convert() {   wget -qO- "http://www.google.com/finance/converter?a=$1&from=$2&to=$3&hl=es" |  sed '/res/!d;s/<[^>]*>//g'; }    



#Ten years of bash history 
HISTFILESIZE=1000000000
HISTSIZE=1000000         

#Autocorreção no bash
shopt -s cdspell

# enable bash completion in interactive shells
if [ -f /etc/bash_completion ]; then
. /etc/bash_completion
fi
                          
 
#Volta ao diretório anterior
alias back='cd $OLDPWD'
                          
#Sobe ao diretório pai(parent directory)
alias up='cd ..'

alias grep='grep --color=auto'      



 compact() {
     if [ "$#" -ge "1" ]; then
        case "$1" in
          *.[tT][aA][rR].[bB][zZ]|*.[tT][bB][zZ])
                  local file="$1"; shift; tar jcvf "$file" "$@" ;;
          *.[tT][aA][rR].[bB][zZ]2|*.[tT][bB][zZ]2)
                   local file="$1"; shift; tar jcvf "$file" "$@" ;;
          *.[tT][aA][rR].[gG][zZ]|*.[tT][gG][zZ]) 
                   local file="$1"; shift; tar zcvf "$file" "$@" ;;
          *.[gG][tT][gG][zZ]) 
                   local file="$1"; shift; tar zcvf "$file" "$@" ;;
          *[bB][zZ]2)                           
                   shift; bzip2 -z -k "$@"  ;;
          *.[rR][aA][rR])
                    local file="$1"; shift; rar a -r "$file"  "$@" ;;
          *[gG][zZ])                           
                     shift; gzip -r "$@"  ;;
          *.[tT][aA][rR]) 
                     local file="$1"; shift; tar cvf "$file" "$@" ;;
          *.[zZ][iI][pP])
                     local file="$1"; shift; zip -r "$file" "$@" ;;
          *.7[zZ])
                     local file="$1"; shift; 7z a -r "$file" "$@" ;;
          *.[xX][zZ]) 
                     local file="$1"; shift; tar Jcvf "$file" "$@" ;;
          *)    echo "don't know how to compact '$i' ..." ;;
        esac
      else
        echo "Insufficient arguments."
 fi ; }





extract () {
   if [ -f $1 ] ; then
       case $1 in
	*.tar.bz2)	tar xvjf $1 && cd $(basename "$1" .tar.bz2) ;;
	*.tar.gz)	tar xvzf $1 && cd $(basename "$1" .tar.gz) ;;
	*.tar.xz)	tar Jxvf $1 && cd $(basename "$1" .tar.xz) ;;
	*.bz2)		bunzip2 $1 && cd $(basename "$1" /bz2) ;;
	*.rar)		unrar x $1 && cd $(basename "$1" .rar) ;;
	*.gz)		gunzip $1 && cd $(basename "$1" .gz) ;;
	*.tar)		tar xvf $1 && cd $(basename "$1" .tar) ;;
	*.tbz2)		tar xvjf $1 && cd $(basename "$1" .tbz2) ;;
	*.tgz)		tar xvzf $1 && cd $(basename "$1" .tgz) ;;
	*.zip)		unzip $1 && cd $(basename "$1" .zip) ;;
	*.Z)		uncompress $1 && cd $(basename "$1" .Z) ;;
	*.7z)		7z x $1 && cd $(basename "$1" .7z) ;;
	*)		echo "don't know how to extract '$1'..." ;;
       esac
   else
       echo "'$1' is not a valid file!"
   fi
 }



# Monta imagem iso em /tmp com um nome iso-xxx
#
#	Uso:  argumento nome da image
#
function mntiso (){

mkdir -p /tmp/iso1
sudo mount -o loop $1 /tmp/iso1
cd /tmp/iso1
}
                    

#----------------------------------------#
#		Calculadora no bash
#
#
calc(){ awk "BEGIN{ print $* }" ;}   


 
#--------------------------------------#
#		Gera password/senha aleatório  #
#									   #
alias genpass="< /dev/urandom tr -dc A-Za-z0-9_ | head -c8"      


#-----------------------------------#
#
#		Obtem IP externo
#
function IP(){
echo "External IP"
curl -s 'http://checkip.dyndns.org' | sed 's/.*Current IP Address: \([0-9\.]*\).*/\1/g'
echo "Internal IP"
hostname -i
echo "MAC address"
ifconfig wlan0 | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}'  
}
             

#--------------------------------#
#		webcam
#
#	Vê imagems da webacam no mplayer
#
function webcam(){
mplayer tv:// -tv driver=v4l2:width=640:height=480:device=/dev/video0:fps=30:outfmt=yuy2
}
                        


#-----------------------------------#
#
#		Obtem ultimos comandos do
# www.commandlinefu.com
function commandfu(){

wget -O - http://www.commandlinefu.com/commands/browse/rss 2>/dev/null | awk '/\s*<title/ {z=match($0, /CDATA\[([^\]]*)\]/, b);print b[1]} /\s*<description/ {c=match($0, /code>(.*)<\/code>/, d);print d[1]"\n"} '
}


##Manda arquivo para o pastebin
function pastebin(){
	
	cat $1 | curl -F "sprunge=<-" http://sprunge.us | xclip
	xclip -o
}

#    xdg-open "http://www.google.com/search?q=$search"
google() {
    search=""
    echo "$1"
    for term in $*; do
        search="$search%20$term"
    done
#    xdg-open "http://www.google.com/search?q=$search"
    google-chrome  "http://www.google.co.uk/search?q=$search"
}                       


alias zh='cmd= $(history|cut -c 8-|zenity  --list --column History)' 



 
#Faz backup de dado arquivo
function backup (){

	echo "Backup com nome $1.back"
	cp "$1" "$1.back"

}      



function prompt
{
local WHITE="\[\033[1;37m\]"
local GREEN="\[\033[0;32m\]"
local CYAN="\[\033[0;36m\]"
local GRAY="\[\033[0;37m\]"
local BLUE="\[\033[0;34m\]"
local RED="\[\033[0;31m\]"
export PS1="
${RED}\u${CYAN}@${BLUE}\h ${CYAN}\w${GRAY}
$ "
}
prompt


#############################################################
#	Encripta arquivo com openssl
#
#	Uso:    $encrypt arquivo
#	saída:  arquivo.enc
#
encrypt(){
	openssl aes-256-cbc -a -salt -in $1 -out $1.enc
	echo "Remova o  arquivo original"
	echo "Mude o nome para algo menos sujestivo, nome atual  "
        #rm -rf $1
}


###########################################################
#      Desencript arquivo com o openssl
#      Uso:    $encrypt
#      Saída   arquivo.out
#
#

decrypt(){ 
	openssl aes-256-cbc -d -a -in $1 -out $1.out
	"Desencriptado, nome do arquivo "$1.out
}


##############################################
#        Edita banco de senhas de mdo seguro
# copia o arquivo ~/.bin/lepassmot.enc
# para /tmp e desencripta
#
editpass(){
	addrs=~/Dropbox/lepassmot.enc
	cp $addrs /tmp
	cd /tmp
	openssl aes-256-cbc -d -a -in lepassmot.enc  -out lepassmot.out
 	echo "Editando passwords em /tmp"
	leafpad lepassmot.out  & 

}


##################################
#	Faz update do banco de password
#  e encripta o arquivo
#
#
updatepass(){
	cd /tmp
	rm lepassmot.enc
	openssl aes-256-cbc -a -salt -in lepassmot.out -out lepassmot.enc
        cp lepassmot.enc ~/Dropbox
	echo "Operação finalizada disco encriptado movido para Dropbox"

}




matrix(){
(set -o noglob;while sleep 0.05;do for r in `grep -ao '[[:print:]]' /dev/urandom|head -$((COLUMNS/3))`;do [ $((RANDOM%6)) -le 1 ] && r=\ ;echo -ne "\e[$((RANDOM%7/-6+2));32m $r ";done;echo;done)    
}

#--------------- P A T H --------------#
PATH=$PATH:$HOME/bin:$HOME/usr/bin:$HOME/.apps

xhost local:caio > /dev/null
