@extends('layouts.app')

@section('content')
<div class="container">


    <!-- Start Content-->
    <div class="container-fluid">


        @include('layouts.menu')

        <div class="row d-flex justify-content-center">
            @php

            exec('sh bash/installDaq.sh', $daqConfig);


            $flex=0;
            $libpcap=0;
            $msjConfig='';
            $msjMake='';
            $msjSudoMake='';
            $finmake='';
            $finSudomake='';

            foreach ($daqConfig as $key => $value) {
            //echo ($key ." : ".$value."<br>");
            if ($value=='checking for flex... no') {
            //echo('*********************************');

                    exec('autoreconf -f -i ');
                    exec('sudo dpkg --configure -a');
                    exec('sudo apt-get install bison flex -y');


            }
            if ($value=='checking for pcap_lib_version... checking for pcap_lib_version in -lpcap... (cached) no') {
            //echo('*************Encontro el error********************<br>');
             shell_exec('sh bash/libpcap.sh');

            }
            if ($value=='Build netmap DAQ module.... : no') {
                $msjConfig='CONFIG INSTALADO CON Exito!.';
            }

            }

            $findaqConfig=end($daqConfig);
            //echo($findaqConfig);

            //if ($findaqConfig == "ERROR") {
            // exec('autoreconf -f -i ');
            // //exec('sudo dpkg --configure -a');
            // echo('*****************asd****************');
            // exec('sudo apt-get install build-essential -y', $daqError);

            // foreach ($daqError as $key => $value) {
            // echo ($value."<br>");
            // }

            //}

            //instalacion sactifactoria de primer paquete daq


            if (empty(!$msjConfig)) {
                //echo('instalacion 2 paquete DAQ:<br>:<br>:<br>');
                exec('sh bash/installDaqmake.sh', $daqmake);
                $finmake=end($daqmake);

                    foreach ($daqmake as $key => $value) {
                    //echo ($key ." : ".$value."<br>");

                    if ($key>=134) {
                        $msjMake=' MAKE INSTALADO COMPLETO:<br>:<br>:<br>';

                    }
                }

                //echo('instalacion 3 paquete DAQ:<br>:<br>:<br>');
                exec('sh bash/installDaqsudomake.sh', $daqsudomake);
                $finSudomake=end($daqsudomake);

                foreach ($daqsudomake as $key => $value) {
                    //echo ($key ." : ".$value."<br>");

                    if ($key>=140) {
                        $msjSudoMake='SUDO MAKE INSTALADO COMPLETO:<br>:<br>:<br>';

                    }
                }
            }


            @endphp

            <div class="row d-flex justify-content-center">
                @if ($findaqConfig == "ERROR" || $finmake == "ERROR" || $finSudomake == "ERROR" )
                <div class="alert alert-danger d-flex align-items-center" role="alert">
                    <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Danger:">
                        <use xlink:href="#exclamation-triangle-fill" /></svg>
                    <div class="m-3">
                        Se interrumpiò la Instalaciòn <strong> vuelve a intertarlo!</strong>
                    </div>
                </div>

                @else

                    @if ((empty(!$msjConfig)) && (empty(!$msjMake)) && (empty(!$msjSudoMake)) )
                    <div class="alert alert-success d-flex align-items-center" role="alert">
                        <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Success:">
                            <use xlink:href="#check-circle-fill" /></svg>
                        <div class="m-3">
                            Primer componente <strong> Instalado sastifactoriamente</strong>
                        </div>
                    </div>
                    @endif
                @endif
            </div>

        </div>

    </div>
</div>

@endsection
