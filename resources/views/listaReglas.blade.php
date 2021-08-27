@extends('layouts.app')

@section('content')
<div class="container">

    <!-- Start Content-->
    <div class="container-fluid">


        <div class="row">
            <div class="col-12">
                <div class="page-title-box">
                    <h4 class="page-title">Reglas </h4>
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
    
        {{-- <div class="row">
            <div class="container">
                <div class="card-box">
                    <h4 class="header-title mb-4">Lista</h4>

                </div>

            </div>
        </div> --}}

        <div class="row">
            <div class="container">
                <div class="card-box">
                    <h4 class="header-title mb-4">Lista</h4>

                    <table class="table">
                        <thead>
                          <tr>                           
                            <th scope="col">Regla</th>
                            <th scope="col">Estado</th>
                            <th scope="col">Detalle</th>
                            <th scope="col">Fecha Activada</th>
                            <th scope="col">Acciones</th>
                          </tr>
                        </thead>
                        <tbody>
                            @foreach ($reglas as $regla)
                            <tr>
                           
                                <td>{{$regla->nombre}}</td>
                                <td>
                                    @if ($regla->estado==true)
                                    <span class="badge rounded-pill bg-success">Activada</span>
                                    @else
                                    <span class="badge rounded-pill bg-warning text-dark">Desactivada</span>
                                    @endif
                                </td>
                                {{-- <td>{{$regla->regla}}</td> --}}
                                <td>{{$regla->detalle}}</td>
                                <td>{{$regla->fecha_activada}}</td>
                                <td> 
                                    @if ($regla->estado==true)

                                    <a  href="{{ URL::action('App\Http\Controllers\InstalarReglasController@descativar',$regla->id) }}" title="Desactivar" class="btn btn-danger btn-sm">
                                        <i class="ion ion-md-checkmark-circle"></i>
                                    </a>

                                    @else

                                    <a  href="{{ URL::action('App\Http\Controllers\InstalarReglasController@activar',$regla->id) }}" title="Activar" class="btn btn-info btn-sm">
                                        <i class="ion ion-md-checkmark-circle"></i>
                                    </a>
                                    
                                    @endif

                                </td>
                                
                              </tr>
                                
                            @endforeach
                         
                          
                        </tbody>
                      </table>

                </div>

            </div>
        </div>





    </div>
</div>
</div>

@endsection
