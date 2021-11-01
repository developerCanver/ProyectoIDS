sudo service Splunkd start


if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi