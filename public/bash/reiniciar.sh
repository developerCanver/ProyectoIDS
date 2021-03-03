#Carlos 1Ruiz
#!/bin/bash

sudo fuser -vki /var/lib/dpkg/lock-frontend 
sudo rm -f /var/lib/dpkg/lock-frontend
sudo dpkg --configure -a
sudo apt autoremove

#for dir in $@
#do
#  if [ -d $dir ]
#  then
#    echo “La capeta $dir ya existe.”
#Else
#    mkdir $dir
 #   if [ $? -eq 0 +
#    then
 #     echo “$dir se ha creaco con éxito”
#    else
#      echo “Ups! Algo ha fallado al crear $dir”
#    fi
#  fi
#done