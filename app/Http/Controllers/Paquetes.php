<?php

namespace App\Http\Controllers;

use App\Models\Btn;
use Illuminate\Http\Request;

class Paquetes extends Controller
{
        
    public function index(Request $request)
    {

        $descargarPaquetes = shell_exec('sh bash/descargarPaquetes.sh');
            

        $guardar = Btn::first();
        $consulta = Btn::first();

        
      if ($descargarPaquetes != "ERROR"){
            $guardar->paquetes   = 'disabled';
            $guardar->daq   = '';
            $guardar->update();

        }


    return view('descargar', [
        'descargarPaquetes'    => $descargarPaquetes,
        'consulta'    => $consulta,
    ]);
    }

}
