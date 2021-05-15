@extends('layouts.app')

@section('content')
<div class="container">

    <!-- Start Content-->
    <div class="container-fluid">
        @include('layouts.menu')

        <div class="row d-flex justify-content-center">
            <div class="alert alert-primary d-flex align-items-center" role="alert">
                <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Info:">
                    <use xlink:href="#info-fill" /></svg>
                <div class="m-3">
                    Iniciando Descarga Snort segundo componente
                </div>
            </div>
        </div>


        @php

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
        //echo ($key ." : ".$value."<br>");

        if ($value=='checking for pcre.h... no') {
        // echo('*************ERROR LIBPCRE********************');
        $SnoortPCRE=1;

        }
        if ($value=='checking for dumbnet.h... no') {
        //echo('*************ERROR LIBPCRE********************');
        $Snotrlibdumbnet=1;
        }
        if ($value=='checking for zlib.h... no') {
        //echo('*************ERROR zlib********************');
        $Snotrzlib=1;
        }
        if ($value=='checking for luajit... no') {
        //echo('*************ERROR Libreria LuaJIT********************');
        $SnotrLuaJIT=1;
        }
        }

        /* encontrado fallas y darles soluciones*/
        if ($SnoortPCRE==1) {
        //echo('*************Ejecutando solucion********************');
        exec('sh bash/ErrorSnoortPCRE.sh', $ErrorSnoortPCRE);
        foreach ($ErrorSnoortPCRE as $key => $value) {
        //echo ($key ." : ".$value."<br>");
        }
        }

        if ($Snotrlibdumbnet==1) {
        //echo('*************Ejecutando solucion**** Snotrlibdumbnet****************');
        exec('sh bash/ErrorSnotrlibdumbnet.sh', $ERRSnotrlibdumbnet);

        foreach ($ERRSnotrlibdumbnet as $key => $value) {
        //echo ($key ." : ".$value."<br>");
        }
        }

        if ($Snotrzlib==1) {
        // echo('*************Ejecutando solucion**** Snotrzlib****************');
        exec('sh bash/ErrorSnotrzlib.sh', $Snotrzlibs);

        foreach ($Snotrzlibs as $key => $value) {
        //echo ($key ." : ".$value."<br>");
        }
        }
        if ($SnotrLuaJIT==1) {
        //echo('*************Ejecutando solucion**** Snotrzlib****************');
        exec('sh bash/ErrorSnortSnotrLuaJIT.sh', $SnotrLuaJITs);

        foreach ($SnotrLuaJITs as $key => $value) {
        echo ($key ." : ".$value."<br>");
        }
        }

        //echo($SnoortPCRE.'<br>');
        //echo($Snotrlibdumbnet.'<br>');
        //echo($Snotrzlib.'<br>');
       // echo($SnotrLuaJIT.'<br>');

        @endphp




        <div class="row d-flex justify-content-center">
            @if ($SnoortPCRE == 0 && $Snotrlibdumbnet == 0 && $Snotrzlib == 0 && $SnotrLuaJIT == 0)
            <div class="alert alert-success d-flex align-items-center" role="alert">
                <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Success:">
                    <use xlink:href="#check-circle-fill" /></svg>
                <div class="m-3">
                    Segundo componente <strong> Instalado sastifactoriamente</strong>
                </div>
            </div>
            @else
            <div class="alert alert-danger d-flex align-items-center" role="alert">
                <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Danger:">
                    <use xlink:href="#exclamation-triangle-fill" /></svg>
                <div class="m-3">
                    Se interrumpiò la Instalaciòn <strong> vuelve a intertarlo!</strong>
                </div>
            </div>

            @endif
        </div>

    </div>
</div>

@endsection
