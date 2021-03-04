@extends('layouts.app')

@section('content')
<div class="container">

    <!-- Start Content-->
    <div class="container-fluid">
        @include('layouts.menu')

        <div class="row">


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
            $Snotrzlib=0;
            $SnotrLuaJIT=0;



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
            if ($value=='checking for zlib.h... no') {
            echo('*************ERROR zlib********************');
            $Snotrzlib=1;
            }
            if ($value=='checking for luajit... no') {
            echo('*************ERROR Libreria LuaJIT********************');
            $SnotrLuaJIT=1;
            }

            }
            /* encontrado fallas y darles soluciones*/
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

            if ($Snotrzlib==1) {
            echo('*************Ejecutando solucion**** Snotrzlib****************');
            exec('sh bash/ErrorSnotrzlib.sh', $Snotrzlibs);

            foreach ($Snotrzlibs as $key => $value) {
            echo ($key ." : ".$value."<br>");
            }
            }
            if ($SnotrLuaJIT==1) {
            echo('*************Ejecutando solucion**** Snotrzlib****************');
            exec('sh bash/ErrorSnortSnotrLuaJIT.sh', $SnotrLuaJITs);

            foreach ($SnotrLuaJITs as $key => $value) {
            echo ($key ." : ".$value."<br>");
            }
            }


            /*//instalacion sactifactoria de primer paquete daq


            if (empty(!$msjConfig)) {
            echo('instalacion 2 paquete DAQ:<br>:<br>:<br>');
            exec('sh bash/installDaqmake.sh', $daqmake);

            foreach ($daqmake as $key => $value) {
            echo ($key ." : ".$value."<br>");
            if ($key>=134) {
            $msjMake=' MAKE INSTALADO COMPLETO:<br>:<br>:<br>';

            }
            }

            echo('instalacion 3 paquete DAQ:<br>:<br>:<br>');
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
    </div>
</div>

@endsection
