@extends('layouts.app')

@section('content')
<div class="container">

    <!-- Start Content-->
    <div class="container-fluid">
        
        <div class="row">
            <div class="col-12">
                <div class="page-title-box">
                    <h4 class="page-title">resultados </h4>
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
                    <h4 class="header-title mb-4">Ir</h4>

                    <center>
                        <button class="btn-sm btn-info">Ver resultados</button>
                    </center>

                </div>

            </div>
        </div> 

        </div>
    </div>
</div>

@endsection
