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

       // exec('sh bash/installSnortConfig.sh', $snortConfig);

        foreach ($snortConfig as $key => $value) {
                $value= trim($value);
               // echo ($key ." : ".$value."<br>");
            }
        @endphp



        <div class="row d-flex justify-content-center">
            @if ($snortConfig == "ERROR")
            <div class="alert alert-danger d-flex align-items-center" role="alert">
                <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Danger:">
                    <use xlink:href="#exclamation-triangle-fill" /></svg>
                <div class="m-3">
                    Se interrumpiò la Instalaciòn <strong> vuelve a intertarlo!</strong>
                </div>
            </div>

            @else
            <div class="alert alert-success d-flex align-items-center" role="alert">
                <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Success:">
                    <use xlink:href="#check-circle-fill" /></svg>
                <div class="m-3">
                    Snort <strong> Instalado sastifactoriamente</strong>
                </div>
            </div>
            @endif
        </div>

    </div>
</div>

@endsection
