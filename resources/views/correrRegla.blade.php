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
                    Ejecutando Regla Creada Exitosamente
                </div>
            </div>
        </div>



        <div class="row d-flex justify-content-center">
            @php

            $correrRegla = shell_exec('sh bash/correrRegla.sh');
            
  
            echo '<pre>';
                print_r($correrRegla);
                echo '</pre>';

    
            @endphp


            {{-- @if ()
            <div class="alert alert-success d-flex align-items-center" role="alert">
                <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Success:">
                    <use xlink:href="#check-circle-fill" /></svg>
                <div class="m-3">
                    Snort sea descargado <strong> sastifactoriamente</strong>
                </div>
            </div>
            @else
            <div class="alert alert-danger d-flex align-items-center" role="alert">
                <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Danger:">
                    <use xlink:href="#exclamation-triangle-fill" /></svg>
                <div class="m-3">
                    Se interrumpiò la descargar <strong> vuelve a intertarlo</strong>, Por favor!
                </div>
            </div>
            @endif  --}}
        </div>
    </div>
</div>

@endsection
