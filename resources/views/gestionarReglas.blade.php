@extends('layouts.app')


@section('content')
<div class="container">
    <style>
        .desactiva_link:hover{
            background: #ffffff;
            border-radius: 15px 15px 0px 0px;
           
        }
        
        .desactiva_a:hover{
            color: rgb(116, 167, 143);
        }
    </style>

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

        <ul class="nav nav-tabs">
            <li class="nav-item desactiva_link">
                <a class="nav-link desactiva_a" style="border: 1px solid #1a29421a;
                border-radius: 15px 15px 0px 0px;" href="{{Url('instalarReglas')}}">Configuración</a>
              </li>
            <li class="nav-item">
              <a class="nav-link "  style=" background: #1a2942;color:#fff;border: 2px solid transparent;
              border-radius: 15px 15px 0px 0px;" aria-current="page" href="{{Url('gestionarReglas')}}">Gestionar Reglas</a>
            </li>
           
       
          </ul>
    



        @include('message.message_flash')


        <div class="row">
            <div class="container">
                <div class="card-box">
                    <h4 class="header-title mb-4">Crear regla</h4>
                 
                    <form action="{{url('/gstionarRegla.store')}}" method="POST" enctype="multipart/form-data">
                        @csrf
                        <div class="form-row">
                          <div class="form-group col-md-3">
                            <label >Nombre</label>
                            <input type="text" class="form-control" value="nombre" placeholder="Nombre Regla">
                          </div>
                          <div class="form-group col-md-9">
                            <label for="inputPassword4">Regla</label>
                            <input type="text" class="form-control"  value="regla"  placeholder="Codigo de la Regla">
                          </div>
                        </div>
                        <div class="form-group">
                          <label for="inputAddress">Detalle</label>
                          <input type="text" class="form-control"  value="detalle"  placeholder="funcionalidad de la Regla">
                        </div>

                        <button class="btn btn-primary btn-sm">Guardar</button>
                       
                    </form>
                

                    <table class="table">
                        <thead>
                          <tr>                           
                            <th scope="col">Nombre</th>
                            <th scope="col">Regla</th>
                            <th scope="col">Detalle</th>
                            <th scope="col">Estado</th>
                            <th scope="col">Fecha Activada</th>
                            <th scope="col">Acciones</th>
                          </tr>
                        </thead>
                        <tbody>
                            @foreach ($reglas as $regla)
                            <tr>
                           
                                <td>{{$regla->nombre}}</td>
                                <td>{{$regla->regla}}</td> 
                                <td>{{$regla->detalle}}</td>
                                <td>  <span class="badge rounded-pill bg-warning text-dark">Desactivada</span></td>
                                <td>{{$regla->created_at}}</td>
                                <td> 
                                  
                                   <a  href="{{ URL::action('App\Http\Controllers\InstalarReglasController@descativar',$regla->id) }}" title="Desactivar" class="btn btn-danger btn-sm">
                                        <i class="ion ion-md-checkmark-circle"></i>
                                    </a> 

                                 
                                    
                                  
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
