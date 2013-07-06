sudo apt-get install openjdk-6-jre openjdk-6-jdk
sudo apt-get install libjogl-java
sudo apt-get install mesa-common-dev

cd /usr/lib
sudo cp -s /usr/lib/mesa/libGL.so.1 libGL.so 

cd /usr/bin
sudo cp -s /usr/share/java/jogl.jar .
sudo cp -s /usr/share/java/gluegen-rt.jar .
