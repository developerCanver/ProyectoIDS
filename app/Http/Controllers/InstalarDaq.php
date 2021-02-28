<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class InstalarDaq extends Controller
{
    public function index() {

        echo(" <br><br>Instalando componentes DAQ <br>");

        exec('sh bash/installDaq.sh', $daqConfig);
        
        
       $flex=0;
       $libpcap=0;
        foreach ($daqConfig as $key => $value) {
           echo ($key ." : ".$value."<br>");
           if ($value=='checking for flex... no') {
               echo('*********************************');
               
               exec('autoreconf -f -i ');
               exec('sudo dpkg --configure -a');
               exec('sudo apt-get install bison flex -y');
              
               
           }
           if ($value=='checking for pcap_lib_version... checking for pcap_lib_version in -lpcap... (cached) no') {
               echo('*************Encontro el error********************<br>');
               echo shell_exec('sh bash/libpcap.sh');
               
              
           }

       }
    
       $findaqConfig=end($daqConfig);
       echo($findaqConfig);
       if ($findaqConfig == "ERROR") {
           exec('autoreconf -f -i ');
           //exec('sudo dpkg --configure -a');
           exec('sudo apt-get install build-essential -y', $daqError);
         
           foreach ($daqError as $key => $value) {
           echo ($value."<br>");
           }
          
       }

       
    return view('instalardaq');
    }
}
