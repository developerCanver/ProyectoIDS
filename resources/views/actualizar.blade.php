@extends('layouts.app')

@section('content')
<div class="container">

    <!-- Start Content-->
    <div class="container-fluid">

        @include('layouts.menu')
    </div>
    @php
        echo(" <br> <br> Instalando Sistema Ubuntu <br>");


exec('sh bash/actualizar.sh', $actualizar);
    foreach ($actualizar as $key => $value) {
                $value= trim($value);
                echo ($key ." : ".$value."<br>");
    }

    @endphp
</div>

@endsection
