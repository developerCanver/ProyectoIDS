@extends('layouts.app')

@section('content')
<div class="container">

    <!-- Start Content-->

    @if (Session::has('status'))
    <div class="alert alert-success" role="alert">
         <p>{{ Session::get('status') }}</p>
    </div>
@endif
    <div class="row">
        <div class="col-lg-12">
            <div class="card">
                <div class="card-body">
                    <h4 class="header-title mb-4">Cear Reglas</h4>

                    <form action="{{ url('/regla') }}" class="parsley-examples" method="POST">
                        @csrf
                        <div class="row">
                            <div class="col-lg-6">
                                <div class="form-group">
                                    <label for="userName">Accion<span class="text-danger">*</span></label>
                                    <select class="custom-select mt-3" name="acccion" id="acccion">
                                        {{-- <option selected>Selecione...</option> --}}
                                        <option value="alert">Alert</option>
                                        <option value="log">Log</option>
                                        <option value="pass">pass</option>
                                    </select>
                                </div>
                            </div>

                            <div class="col-lg-6">
                                <div class="form-group">
                                    <label for="userName">Protocolo<span class="text-danger">*</span></label>
                                    <select class="custom-select mt-3" name="protocolo" id="protocolo">
                                        <option selected value="icmp">ICMP</option>
                                        <option value="tcp">TCP</option>
                                        <option value="ip">IP</option>
                                        <option value="udp">UDP</option>

                                    </select>
                                </div>
                            </div>
                        </div>
                        <div class="row">
                            <div class="col-lg-4">
                                <div class="form-group">
                                    <label for="emailAddress">IP Origen<span class="text-danger">*</span></label>
                                    <input type="text" name="ipOrigen" required value="any" class="form-control">
                                </div>

                            </div>

                            <div class="col-lg-4">
                                <div class="form-group">
                                    <label>Puerto Origen<span class="text-danger">*</span></label>
                                    <input type="text" name="puertoOrigen" required value="any" class="form-control">
                                </div>
                            </div>
                            <div class="col-lg-4">
                                <div class="form-group">
                                    <label>Direciòn<span class="text-danger">*</span></label>
                                    <select class="custom-select" name="direccion" id="direction">
                                        {{-- <option selected>Selecione...</option> --}}
                                        <option selected value="->">-></option>
                                        <option value="<>">
                                            <>
                                        </option>
                                        <option value="<-">
                                            <-</option> </select> </div> </div> </div> <div class="row">
                                                <div class="col-lg-6">
                                                    <div class="form-group">
                                                        <label for="userName">Ip Destino<span
                                                                class="text-danger">*</span></label>
                                                        <input type="text" name="ipDestino" required value="any"
                                                            class="form-control">

                                                    </div>
                                                </div>

                                                <div class="col-lg-6">
                                                    <div class="form-group">
                                                        <label for="userName">Origen Destino<span
                                                                class="text-danger">*</span></label>
                                                        <input type="text" name="origenDestino" required value="any"
                                                            class="form-control">
                                                    </div>

                                                </div>
                                </div>

                                <div class="form-group text-right mb-0">
                                    <button class="btn btn-primary waves-effect waves-light mr-1" type="submit">
                                        Generar Archivo
                                    </button>
                                    <button type="reset" class="btn btn-secondary waves-effect waves-light">
                                        Cancelar
                                    </button>
                                </div>

                    </form>
                </div>
            </div>
            <!-- end card -->
        </div>

    </div>

</div>

@endsection
