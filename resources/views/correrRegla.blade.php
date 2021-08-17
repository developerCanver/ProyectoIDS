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
            
  
            echo '<pre style="height: 400px;background: #111;color: #b2dd87;width: 80%;">';
                print_r($correrRegla);
            echo '</pre>';

    
            @endphp



        </div>
    </div>
</div>

@endsection
