#!/bin/bash/bash
#	
#	Permite o usuario Não-root acessar a porta serial do chip FTDI / FT232BRL
#
#
sudo cp ./udevrules  /etc/udev/rules.d/10-local-override.rules
echo "instalado"
echo "Testar FTDI use: screen /dev/ttyUSB0"
echo "Criado arquivo  /etc/udev/rules.d/10-local-override.rules"