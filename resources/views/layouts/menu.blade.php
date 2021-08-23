  <style>
      a.disabled{
          background: #999;
      }
  </style>
  <!-- start page title -->

  <div class="row">
      <div class="col-12">
          <div class="page-title-box">
              <h4 class="page-title">IDS</h4>
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
  <!-- end page title -->
 
  <div class="row">
      <div class="col-xl-3 col-sm-6">
          <div class="card bg-pink">
              <a    href="{{ url('/actualizar') }}" class="btn {{$consulta->sistema}}">
                  <div class="card-body widget-style-2">
                      <div class="text-white media">
                          <div class="media-body align-self-center">
                              {{-- <h2 class="my-0 text-white"><span data-plugin="counterup">50</span></h2> --}}
                              <p class="mb-0">Actualizar sistema</p>
                          </div>
                          <i class="ion-md ion-md-download"></i>
                      </div>
                  </div>
              </a>
          </div>
      </div>
      <div class="col-xl-3 col-sm-6">
          <div class="card bg-pink">
              <a href="{{ url('/librerias') }}" class=" media-body btn {{$consulta->libreria}}">
                  <div class="card-body widget-style-2">
                      <div class="text-white media">
                          <div class="media-body align-self-center">
                              {{-- <h2 class="my-0 text-white"><span data-plugin="counterup">50</span></h2> --}}
                              <p class="mb-0">Descargar Libreria</p>
                          </div>
                          <i class="ion-md ion-md-download"></i>
                      </div>
                  </div>
              </a>
          </div>
      </div>
      <!-- Button trigger modal -->


      <!-- Modal -->
      <div class="modal fade" id="ModalDescargar" tabindex="-1" aria-labelledby="ModalDescargarLabel"
          aria-hidden="true">
          <div class="modal-dialog">
              <div class="modal-content">
                  <div class="modal-header" style="background: #1a2942;">
                      <h5 class="modal-title" style="color:#fff;" id="ModalDescargarLabel">Descargar paquetes</h5>
                      <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                          <span aria-hidden="true">&times;</span>
                      </button>
                  </div>
                  <div class="modal-body">
                      <div class="alert alert-primary" role="alert">
                          <h5 style="color: #ae3d3d;">
                              La descarga puede tardar varias Horas!
                          </h5>
                          <br>
                          <br>
                          <center>

                              <strong>Desea Continuar?</strong>
                          </center>
                      </div>
                  </div>
                  <div class="modal-footer">
                      <button type="button" class="btn btn-secondary" data-dismiss="modal">cancelar</button>
                      <a href="{{ url('/descargar') }}" style="background: #1a2942;" class="btn "> SI </a>
                  </div>
              </div>
          </div>
      </div>
      <!-- Fin Modal -->

      <div class="col-xl-3 col-sm-6">
          <div class="card bg-pink">
              <a href="#"  class="media-body btn {{$consulta->paquetes}}" type="button" data-toggle="modal" data-target="#ModalDescargar">
                  <div class="card-body widget-style-2">
                      <div class="text-white media">
                          <div class="media-body align-self-center">
                              {{-- <h2 class="my-0 text-white"><span data-plugin="counterup">50</span></h2> --}}
                              <p class="mb-0">Descargar paquetes</p>
                          </div>
                          <i class="ion-md ion-md-download"></i>
                      </div>
                  </div>
              </a>
          </div>
      </div>

      <!-- Modal -->
      <div class="modal fade" id="ModalDaq" tabindex="-1" aria-labelledby="ModalDaqLabel" aria-hidden="true">
          <div class="modal-dialog">
              <div class="modal-content">
                  <div class="modal-header" style="background: #1a2942;">
                      <h5 class="modal-title" style="color:#fff;" id="ModalDaqLabel">Instalar DAQ</h5>
                      <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                          <span aria-hidden="true">&times;</span>
                      </button>
                  </div>
                  <div class="modal-body">
                      <div class="alert alert-primary" role="alert">
                          <h5 style="color: #ae3d3d;">
                              La instalación de Daq puede tardar varios minutos!
                          </h5>
                          <br>
                          <br>
                          <center>

                              <strong>Desea Continuar?</strong>
                          </center>
                      </div>
                  </div>
                  <div class="modal-footer">
                      <button type="button" class="btn btn-secondary" data-dismiss="modal">cancelar</button>
                      <a href="{{ url('/instalardaq') }}" style="background: #1a2942;" class="btn "> SI </a>
                  </div>
              </div>
          </div>
      </div>
      <!-- Fin Modal -->
      <div class="col-xl-3 col-sm-6">

          <div class="card bg-purple">
              <a href="#" class="media-body btn {{$consulta->daq}}" type="button" data-toggle="modal" data-target="#ModalDaq">
                  <div class="card-body widget-style-2">
                      <div class="text-white media">
                          <div class="media-body align-self-center">
                              {{-- <h2 class="my-0 text-white"><span data-plugin="counterup">12056</span></h2> --}}
                              <p class="mb-0">Instalar DAQ</p>
                          </div>
                          <i class="ion-md ion-md-send"></i>
                      </div>
                  </div>
              </a>
          </div>
      </div>
  </div>

  <!-- Modal -->
  <div class="modal fade" id="ModalSnort" tabindex="-1" aria-labelledby="ModalSnortLabel" aria-hidden="true">
      <div class="modal-dialog">
          <div class="modal-content">
              <div class="modal-header" style="background: #1a2942;">
                  <h5 class="modal-title" style="color:#fff;" id="ModalSnortLabel">Instalar Snort</h5>
                  <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                      <span aria-hidden="true">&times;</span>
                  </button>
              </div>
              <div class="modal-body">
                  <div class="alert alert-primary" role="alert">
                      <h5 style="color: #ae3d3d;">
                          La instalación de Snort puede tardar varios minutos!
                      </h5>
                      <br>
                      <br>
                      <center>

                          <strong>Desea Continuar?</strong>
                      </center>
                  </div>
              </div>
              <div class="modal-footer">
                  <button type="button" class="btn btn-secondary" data-dismiss="modal">cancelar</button>
                  <a href="{{ url('/instalarsnort') }}" style="background: #1a2942;" class="btn "> SI </a>
              </div>
          </div>
      </div>
  </div>
  <!-- Fin Modal -->

  <div class="row">
      <div class="col-xl-3 col-sm-6">
          <div class="card bg-info">
              <a href="#"  class="media-body btn {{$consulta->snort}}"  type="button" data-toggle="modal" data-target="#ModalSnort">
                  <div class="card-body widget-style-2">
                      <div class="text-white media">
                          <div class="media-body align-self-center">
                              {{-- <h2 class="my-0 text-white"><span data-plugin="counterup">1268</span></h2> --}}
                              <p class="mb-0">Instalar Snort</p>
                          </div>
                          <i class="ion-md ion-md-send"></i>
                      </div>
                  </div>
              </a>
          </div>
      </div>


      <div class="col-xl-3 col-sm-6">
          <div class="card bg-primary">
              <a href="{{ url('/configurarweb') }}" class="media-body btn {{$consulta->red}}">
                  <div class="card-body widget-style-2">
                      <div class="text-white media">
                          <div class="media-body align-self-center">
                              {{-- <h2 class="my-0 text-white"><span data-plugin="counterup">145</span></h2> --}}
                              <p class="mb-0">Configurarciòn Red</p>
                          </div>
                          <i class="ion-md ion-ios-git-compare"></i>
                      </div>
                  </div>
              </a>
          </div>
      </div>
      <div class="col-xl-3 col-sm-6">
          <div class="card bg-primary">
              <a href="{{ url('/requisitos') }}" class="media-body btn {{$consulta->prequisitos}}">
                  <div class="card-body widget-style-2">
                      <div class="text-white media">
                          <div class="media-body align-self-center">
                              {{-- <h2 class="my-0 text-white"><span data-plugin="counterup">145</span></h2> --}}
                              <p class="mb-0">Prerequisitos de Reglas</p>
                          </div>
                          <i class="ion-md ion-ios-git-compare"></i>
                      </div>
                  </div>
              </a>
          </div>
      </div>
  </div>
