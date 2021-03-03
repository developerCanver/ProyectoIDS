@extends('layouts.app')

@section('content')
<div class="container">

    <!-- Start Content-->
    <div class="container-fluid">

        <!-- start page title -->
        <div class="row">
            <div class="col-12">
                <div class="page-title-box">
                    <h4 class="page-title">IDS</h4>
                    <div class="page-title-right">
                        <ol class="breadcrumb p-0 m-0">
                            <li class="breadcrumb-item"><a href="{{ url('/') }}">Inicio</a></li>
                            {{-- <li class="breadcrumb-item"><a href="#">Dashboard</a></li>
                            <li class="breadcrumb-item active">Dashboard 1</li> --}}
                        </ol>
                    </div>
                    <div class="clearfix"></div>
                </div>
            </div>
        </div>
        <!-- end page title -->

        <div class="row">
            <div class="col-xl-3 col-sm-6">
                <div class="card bg-pink">
                    <a href="{{ url('/descargar') }}" class="media-body ">
                        <div class="card-body widget-style-2">
                            <div class="text-white media">
                                <div class="media-body align-self-center">
                                    {{-- <h2 class="my-0 text-white"><span data-plugin="counterup">50</span></h2> --}}
                                    <p class="mb-0">Descargar paquetes</p>
                                </div>
                                <i class="ion-md ion-md-download"></i>
                            </div>
                        </div>
                    </a>
                </div>
            </div>

            <div class="col-xl-3 col-sm-6">

                <div class="card bg-purple">
                    <a href="{{ url('/instalardaq') }}" class="media-body ">
                        <div class="card-body widget-style-2">
                            <div class="text-white media">
                                <div class="media-body align-self-center">
                                    {{-- <h2 class="my-0 text-white"><span data-plugin="counterup">12056</span></h2> --}}
                                    <p class="mb-0">Instalar DAQ</p>
                                </div>
                                <i class="ion-md ion-md-send"></i>
                            </div>
                        </div>
                    </a>
                </div>

            </div>

            <div class="col-xl-3 col-sm-6">
                <div class="card bg-info">
                    <a href="{{ url('/instalarsnort') }}" class="media-body ">
                        <div class="card-body widget-style-2">
                            <div class="text-white media">
                                <div class="media-body align-self-center">
                                    {{-- <h2 class="my-0 text-white"><span data-plugin="counterup">1268</span></h2> --}}
                                    <p class="mb-0">Instalar Snort</p>
                                </div>
                                <i class="ion-md ion-md-send"></i>
                            </div>
                        </div>
                    </a>
                </div>
            </div>

            <div class="col-xl-3 col-sm-6">
                <div class="card bg-primary">
                    <a href="{{ url('/reiniciar') }}" class="media-body ">
                    <div class="card-body widget-style-2">
                        <div class="text-white media">
                            <div class="media-body align-self-center">
                                <h2 class="my-0 text-white"><span data-plugin="counterup">145</span></h2>
                                <p class="mb-0">Reiniciar instalacióm</p>
                            </div>
                            <i class="ion-md ion-ios-git-compare"></i>
                        </div>
                    </div>
                </a>
                </div>
            </div>
        </div>
    </div>
    @php
echo(" <br> <br> Instalando componentes SNORT <br>");
        

exec('sh bash/installSnortConfig.sh', $snortConfig);


$flex=0;
$libpcap=0;
$msjConfig='';
$msjMake='';
$msjSudoMake='';
$SnoortPCRE=0;
$Snotrlibdumbnet=0;

foreach ($snortConfig as $key => $value) {
    $value= trim($value);
   echo ($key ." : ".$value."<br>");
  if ($value=='checking for pcre.h... no') {
        echo('*************ERROR LIBPCRE********************');
        $SnoortPCRE=1;

    }
    if ($value=='checking for dumbnet.h... no') {
        echo('*************ERROR LIBPCRE********************');
        $Snotrlibdumbnet=1;

    }
    
}
   if ($SnoortPCRE==1) {
        echo('*************Ejecutando solucion********************');
        exec('sh bash/ErrorSnoortPCRE.sh', $ErrorSnoortPCRE);

        foreach ($ErrorSnoortPCRE as $key => $value) {
        echo ($key ." : ".$value."<br>");
        }
   }

   if ($Snotrlibdumbnet==1) {
        echo('*************Ejecutando solucion**** Snotrlibdumbnet****************');
        exec('sh bash/ErrorSnotrlibdumbnet.sh', $ERRSnotrlibdumbnet);

        foreach ($ERRSnotrlibdumbnet as $key => $value) {
        echo ($key ." : ".$value."<br>");
        }
   }
 

   /*
   if ($value=='checking for pcap_lib_version... checking for pcap_lib_version in -lpcap... (cached) no') {
       echo('*************Encontro el error********************<br>');
       echo shell_exec('sh bash/libpcap.sh');       
      
   }
   if ($value=='Build netmap DAQ module.... : no') {
    $msjConfig='CONFIG INSTALADO CON Exito!.';
   }*/


/*
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
*/

    @endphp
</div>

@endsection
