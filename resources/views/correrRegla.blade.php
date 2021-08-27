@extends('layouts.app')

@section('content')
<div class="container">

    <!-- Start Content-->
    <div class="container-fluid">

        <div class="row">
            <div class="col-12">
                <div class="page-title-box">
                    <h4 class="page-title">Snort </h4>
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
    
       <div class="row">
            <div class="container">
                <div class="card-box">
                    <h4 class="header-title mb-4"> Ver estado</h4>

      
        <div class="row d-flex justify-content-center">
            <div class="alert alert-primary d-flex align-items-center" role="alert">
                <svg class="bi flex-shrink-0 me-2" width="24" height="24" role="img" aria-label="Info:">
                    <use xlink:href="#info-fill" /></svg>
                <div class="m-3">
                    Ejecutando Reglas
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
</div> 

    </div>
</div>

@endsection
