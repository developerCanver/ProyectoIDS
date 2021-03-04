#Carlos 1Ruiz
#!/bin/bash

if [ -f local.rules ]
then
  rm -f local.rules
  echo "Eliminado"
else
  echo "No encontro"
fi

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