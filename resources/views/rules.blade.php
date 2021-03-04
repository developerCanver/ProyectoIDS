@extends('layouts.app')

@section('content')
<div class="container">

    <!-- Start Content-->
    <div class="row">
        <div class="col-lg-6">
            <div class="card">
                <div class="card-body">
                    <h4 class="header-title mb-4">Cear Reglas</h4>

                    <form action="{{ url('/regla') }}" class="parsley-examples" method="POST" >
                        @csrf 
                        <div class="form-group">
                            <label for="userName">Action<span class="text-danger">*</span></label>
                           <select class="custom-select mt-3" name="acccion" id="acccion">
                               {{-- <option selected>Selecione...</option> --}}
                               <option value="alert">Alert</option>
                               <option value="log">Log</option>
                               <option value="pass">pass</option>
                              
                           </select>
                        </div>
                        <div class="form-group">
                            <label for="userName">Proto<span class="text-danger">*</span></label>
                           <select class="custom-select mt-3" name="proto" id="proto">
                               {{-- <option selected>Selecione...</option> --}}
                               <option value="ip">IP</option>
                               <option value="tcp">TCP</option>
                               <option value="udp">UDP</option>
                              
                           </select>
                        </div>
                        <div class="form-group">
                            <label for="emailAddress">IP<span class="text-danger">*</span></label>
                            <input type="text" name="ip" parsley-trigger="change" required value="192.168.0.0" class="form-control" id="emailAddress">
                        </div>
                        <div class="form-group">
                            <label for="pass1">Mascara<span class="text-danger">*</span></label>
                            <input id="pass1" type="number" name="mascara" value="24" required class="form-control">
                        </div>
                        <div class="form-group">
                            <label for="userName">Direction<span class="text-danger">*</span></label>
                           <select class="custom-select mt-3" name="direction" id="direction">
                               {{-- <option selected>Selecione...</option> --}}
                               <option value="->">-></option>
                               <option value="<>"><></option>                              
                           </select>
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
        <!-- end col -->

        <div class="col-lg-6">
            <div class="card">
                <div class="card-body">
                    <h4 class="header-title mb-4">Content:</h4>

                    <form class="parsley-examples">
                        <div class="form-group row">
                            <label for="inputEmail3" class="col-md-4 col-form-label">Url<span class="text-danger">*</span></label>
                            <div class="col-md-7">
                                <input type="text" required class="form-control" id="inputEmail3" placeholder="www.facebook.com">
                            </div>
                        </div>
                        {{-- <div class="form-group row">
                            <label for="hori-pass1" class="col-md-4 col-form-label">Password<span class="text-danger">*</span></label>
                            <div class="col-md-7">
                                <input id="hori-pass1" type="password" placeholder="Password" required class="form-control">
                            </div>
                        </div>
                        <div class="form-group row">
                            <label for="hori-pass2" class="col-md-4 col-form-label">Confirm Password
                                <span class="text-danger">*</span></label>
                            <div class="col-md-7">
                                <input data-parsley-equalto="#hori-pass1" type="password" required placeholder="Password" class="form-control" id="hori-pass2">
                            </div>
                        </div>

                        <div class="form-group row">
                            <label for="webSite" class="col-md-4 col-form-label">Web Site<span class="text-danger">*</span></label>
                            <div class="col-md-7">
                                <input type="url" required parsley-type="url" class="form-control" id="webSite" placeholder="URL">
                            </div>
                        </div>
                        <div class="form-group row">
                            <div class="col-md-8 offset-md-4">
                                <div class="checkbox checkbox-purple">
                                    <input id="checkbox6" type="checkbox">
                                    <label for="checkbox6">
                                        Remember me
                                    </label>
                                </div>
                            </div>
                        </div>
                        <div class="form-group row mb-0">
                            <div class="col-md-8 offset-md-4">
                                <button type="submit" class="btn btn-primary waves-effect waves-light mr-1">
                                    Register
                                </button>
                                <button type="reset" class="btn btn-secondary waves-effect waves-light">
                                    Cancel
                                </button>
                            </div>
                        </div> --}}
                    </form>
                </div>
            </div>
            <!-- end card -->
        </div>
        <!-- end col -->
    </div>

</div>

@endsection
