@extends('layouts.app')

@section('content')
<div class="container">

    <!-- Start Content-->
    <div class="container-fluid">



      
        <div class="row">
            <div class="col-12">
                <div class="page-title-box">
                    <h4 class="page-title">Ayuda </h4>
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
                    <h4 class="header-title mb-4">Video</h4>

                    <center>
                        <button class="btn-sm btn-info" data-toggle="modal"
                        data-target="#ModalDescargar">Ver Video</button>
                    </center>

                </div>

            </div>
        </div> 
          <!-- Modal -->
          <div class="modal fade" id="ModalDescargar" tabindex="-1" aria-labelledby="ModalDescargarLabel"
          aria-hidden="true">
          <div class="modal-dialog modal-lg"">
              <div class="modal-content">
                  <div class="modal-header" style="background: #1a2942;">
                      <h5 class="modal-title" style="color:#fff;" id="ModalDescargarLabel">
                        Guía de instalación y manejo de herramienta EASY IDS</h5>
                      <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                          <span aria-hidden="true">&times;</span>
                      </button>
                  </div>
                  <div class="modal-body">
                      <div class="alert alert-primary" role="alert">
                      
                        
                          <div class="embed-responsive embed-responsive-16by9">
                            <iframe width="560" height="315" src="https://www.youtube.com/embed/lET_IDOdXB8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
                          </div>
                      </div>
                  </div>
                  <div class="modal-footer">
                      <button type="button" class="btn btn-secondary" data-dismiss="modal">cancelar</button>
                      
                  </div>
              </div>
          </div>
      </div>
      <!-- Fin Modal -->

        </div>
    </div>
</div>

@endsection
