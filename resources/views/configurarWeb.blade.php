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
                    Configuración Red
                </div>
            </div>
        </div>
        <div class="row d-flex justify-content-center">
            @php

            $snort = shell_exec('sh bash/configuracionWeb.sh');
               //print_r($snort);
         
            @endphp


          @if ($snort != 'ERROR')
            <div class="alert alert-success d-flex align-items-center" role="alert">
                <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Success:">
                    <use xlink:href="#check-circle-fill" /></svg>
                <div class="m-3">
                    Snort aplicó <strong> sastifactoriamente</strong> la configuración 
                </div>
            </div>
            @else
            <div class="alert alert-danger d-flex align-items-center" role="alert">
                <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Danger:">
                    <use xlink:href="#exclamation-triangle-fill" /></svg>
                <div class="m-3">
                    Se interrumpiò la configuración <strong> vuelve a intertarlo</strong>, Por favor!
                </div>
            </div>
            @endif 
        </div>
    </div>
</div>

@endsection
