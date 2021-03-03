@extends('layouts.app')

@section('content')
<div class="container">


    <!-- Start Content-->
    <div class="container-fluid">

       
        @include('layouts.menu')

        <div class="row">
            @php
            echo(" <br><br>Instalando componentes DAQ <br>");
                    
            
            exec('sh bash/installDaq.sh', $daqConfig);
            
            
            $flex=0;
            $libpcap=0;
            $msjConfig='';
            $msjMake='';
            $msjSudoMake='';
            
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
               if ($value=='Build netmap DAQ module.... : no') {
                $msjConfig='CONFIG INSTALADO CON Exito!.';
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
            
            //instalacion sactifactoria de primer paquete daq
            
            
            if (empty(!$msjConfig)) {
                echo('instalacion 2 paquete  DAQ:<br>:<br>:<br>');
                exec('sh bash/installDaqmake.sh', $daqmake);
            
                foreach ($daqmake as $key => $value) {
                echo ($key ." : ".$value."<br>");
                if ($key>=134) {
                    $msjMake=' MAKE INSTALADO COMPLETO:<br>:<br>:<br>';
                    
                }
                }
            
                echo('instalacion 3 paquete  DAQ:<br>:<br>:<br>');
                exec('sh bash/installDaqsudomake.sh', $daqsudomake);
            
                foreach ($daqsudomake as $key => $value) {
                echo ($key ." : ".$value."<br>");
                if ($key>=140) {
                    $msjSudoMake='SUDO MAKE INSTALADO COMPLETO:<br>:<br>:<br>';
                    
                }
                }
            
                echo('<br> <br><br>');
                if (empty(!$msjConfig)) {
                    echo($msjConfig.'<br>');
                }
                if (empty(!$msjMake)) {
                    echo($msjMake.'<br>');
                }
                if (empty(!$msjSudoMake)) {
                    echo($msjSudoMake.'<br>');
                }
            
            
            }
            
            
                @endphp

        </div>
           
    </div>
</div>

@endsection
