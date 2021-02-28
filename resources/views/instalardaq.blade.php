@extends('layouts.app')

@section('content')
<div class="container">

    <!-- Start Content-->
    <div class="container-fluid">

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
                    <a href="{{ url('/descargar') }}" class="media-body ">
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

            <div class="col-xl-3 col-sm-6">

                <div class="card bg-purple">
                    <a href="{{ url('/instalardaq') }}" class="media-body ">
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

            <div class="col-xl-3 col-sm-6">
                <div class="card bg-info">
                    <a href="{{ url('/instalarsnort') }}" class="media-body ">
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
                    <a href="{{ url('/reiniciar') }}" class="media-body ">
                    <div class="card-body widget-style-2">
                        <div class="text-white media">
                            <div class="media-body align-self-center">
                                <h2 class="my-0 text-white"><span data-plugin="counterup">145</span></h2>
                                <p class="mb-0">Reiniciar instalacióm</p>
                            </div>
                            <i class="ion-md ion-ios-git-compare"></i>
                        </div>
                    </div>
                </a>
                </div>
            </div>
        </div>
    </div>
</div>

@endsection
